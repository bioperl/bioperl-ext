#include "dpalign.h"
#include <sys/time.h>

/* $Id$ */

typedef struct sw_alignstruct {
    char * seq1; /* NULL-terminated sequence 1 string */
    int len1; /* length of sequence 1 */
    char * seq2; /* NULL-terminated sequence 2 string */
    int len2; /* length of sequence 2 */
    unsigned char * s1; /* encoded sequence 1 */
    unsigned char * s2; /* encoded sequence 2 */
    int ** s; /* DNA/Protein scoring matrix */
    int gap; /* gap opening penalty. default is 3 */
    int ext; /* gap extension penalty, default is 1 for each gap */
    int score; /* total score of the result alignment */
    int start1; /* start point of aligned subsequence in sequence 1 */
    int start2; /* start point of aligned subsequence in sequence 2 */
    int end1; /* end point of aligned subsequence in sequence 1 */
    int end2; /* end point of aligned subsequence in sequence 2 */
    struct swstr * FF; /* forward Gotoh arrays */
    struct swstr * RR; /* reverse Gotoh arrays */
    int * spc1; /* gap array for sequence 1 */
    int * spc2; /* gap array for sequence 2 */
} sw_AlignStruct;

/* static functions */
static sw_AlignStruct * init_AlignStruct(char *, char *, int **, int, int);
static void find_ends(sw_AlignStruct *);
static dpAlign_AlignOutput * traceback(sw_AlignStruct *);

/*
  dpAlign_Local_DNA_MillerMyers implements the Miller-Myers algorithm
  to align DNA sequences as defined in their 1988 paper. It takes two
  character string sequences seq1 and seq2, together with the scoring
  parameters for match, mismatch, gap opening and gap extension as 
  arguments. At the end, it returns the dpAlign_AlignOutput data
  structure which can be translated into a Bio::SimpleAlign object
  pretty easily.
 */
dpAlign_AlignOutput *
dpAlign_Local_DNA_MillerMyers(char * seq1, char * seq2, int match, int mismatch, int gap, int ext)
{
    sw_AlignStruct * as;
    int ** s;
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize DNA scoring matrix */
    s = (int **) malloc(17*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < 17; ++i) {
	s[i] = (int *) malloc(17*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < 17; ++j) {
            if (i == 16 || j == 16) s[i][j] = mismatch; /* X mismatches all */
	    else if (i == j) s[i][j] = match;
            else s[i][j] = mismatch;
        }
    }

/* initialize the alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, gap, ext);

/* uppercase the sequence and then encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = dna_encode(as->seq1[i]);
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = dna_encode(as->seq2[i]);
    }

/* locate the end points of the subsequences that gives you the maximal 
   score */
    find_ends(as);

    if (as->score <= 0)
	return NULL;

/* align the subsequences bounded by the end points */
    as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);
    return traceback(as);
}

/*
  dpAlign_Global_DNA_MillerMyers implements the Miller-Myers algorithm
  to align DNA sequences as defined in their 1988 paper. It takes two
  character string sequences seq1 and seq2, together with the scoring
  parameters for match, mismatch, gap opening and gap extension as 
  arguments. At the end, it returns the dpAlign_AlignOutput data
  structure which can be translated into a Bio::SimpleAlign object
  pretty easily.
 */
dpAlign_AlignOutput *
dpAlign_Global_DNA_MillerMyers(char * seq1, char * seq2, int match, int mismatch, int gap, int ext)
{
    sw_AlignStruct * as;
    int ** s;
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize DNA scoring matrix */
    s = (int **) malloc(17*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < 17; ++i) {
	s[i] = (int *) malloc(17*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < 17; ++j) {
            if (i == 16 || j == 16) s[i][j] = mismatch; /* X mismatches all */
	    else if (i == j) s[i][j] = match;
            else s[i][j] = mismatch;
        }
    }

/* initialize the alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, gap, ext);

/* uppercase the sequence and then encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = dna_encode(as->seq1[i]);
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = dna_encode(as->seq2[i]);
    }

/* initialize the spaces arrays */
    as->spc1 = (int *) calloc(as->len1 + 1, sizeof(int));
    if (as->spc1 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 1!\n");
    as->spc2 = (int *) calloc(as->len2 + 1, sizeof(int));
    if (as->spc2 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 2!\n");
/* align the subsequences bounded by the end points */
    as->score = align(as->s1, as->s2, as->len1, as->len2, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);

/* set start and end for global alignment */
    as->start1 = 1;
    as->end1 = as->len1;
    as->start2 = 1;
    as->end2 = as->len2;

    if (as->score <= 0)
	return NULL;
    else 
	return traceback(as);
}

/* 
    dpAlign_Protein_Profile creates a sequence profile from a protein 
    sequence.
 */
dpAlign_SequenceProfile *
dpAlign_Protein_Profile(char * seq1, char * matrix)
{
    int i, j;
    unsigned char * s1;
    int * smp; /* scoring matrix pointer */
    int * pwaa;
    dpAlign_SequenceProfile * sp;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    sp = (dpAlign_SequenceProfile *) malloc(sizeof(dpAlign_SequenceProfile));
    if (sp == NULL)
	dpAlign_fatal("Can't allocate memory for Sequence Profile!\n");
    sp->len = strlen(seq1);
    s1 = (unsigned char *) malloc(sp->len*sizeof(unsigned char));
    if (s1 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 1!\n");
    for (i = 0; i < sp->len; ++i) {
	if (seq1[i] >= 'a' && seq1[i] <= 'z') seq1[i] -= 0x20;
        s1[i] = prot_encode(seq1[i]);
    }
    sp->waa = (int *) malloc(sizeof(int)*24*sp->len);
    if (sp->waa == NULL)
        dpAlign_fatal("Can't allocate memory for waa!\n");
    pwaa = sp->waa;
    for (i = 0; i < 24; ++i) {
        smp = blosum62[i];
        for (j = 0; j < sp->len; ++j)
            *pwaa++ = smp[s1[j]];
    }
    sp->gap = 7;
    sp->ext = 1;
    sp->type = 2;
    free(s1);
    return sp;
}

/*
    dpAlign_Local_Protein_PhilGreen compares a protein sequence profile
    with a protein sequence and return the optimal local alignment score.
 */
int
dpAlign_Local_Protein_PhilGreen(dpAlign_SequenceProfile * sp, char * seq2)
{
    int i;
    int N;
    struct swstr * ss;
    int score;
    unsigned char * s2;

    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

    N = strlen(seq2);

    s2 = (unsigned char *) malloc(N*sizeof(unsigned char));
    if (s2 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 2!\n");

    for (i = 0; i < N; ++i) {
	if (seq2[i] >= 'a' && seq2[i] <= 'z') seq2[i] -= 0x20;
        s2[i] = prot_encode(seq2[i]);
    }

    ss = (struct swstr *) malloc(sizeof(struct swstr)*(sp->len+1));
    if (ss == NULL)
	dpAlign_fatal("Cannot allocate memory for ss array!\n");
    score = pgreen(sp->waa, sp->len, s2, N, sp->gap, sp->ext, ss);
    free(ss);
    free(s2);
    return score;
}

/* 
    dpAlign_Protein_Profile creates a sequence profile from a DNA sequence.
 */
dpAlign_SequenceProfile *
dpAlign_DNA_Profile(char * seq1, int match, int mismatch, int gap, int ext)
{
    int i, j;
    unsigned char * s1;
    int * pwaa;
    dpAlign_SequenceProfile * sp;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    sp = (dpAlign_SequenceProfile *) malloc(sizeof(dpAlign_SequenceProfile));
    if (sp == NULL)
	dpAlign_fatal("Can't allocate memory for Sequence Profile!\n");
    sp->len = strlen(seq1);
    s1 = (unsigned char *) malloc(sp->len*sizeof(unsigned char));
    if (s1 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 1!\n");
    for (i = 0; i < sp->len; ++i) {
	if (seq1[i] >= 'a' && seq1[i] <= 'z') seq1[i] -= 0x20;
        s1[i] = dna_encode(seq1[i]);
    }
    sp->waa = (int *) malloc(sizeof(int)*24*sp->len);
    if (sp->waa == NULL)
        dpAlign_fatal("Can't allocate memory for waa!\n");
    pwaa = sp->waa;
    for (i = 0; i < 17; ++i) 
        for (j = 0; j < sp->len; ++j)
            *pwaa++ = s1[j] == (unsigned char) i ? match : mismatch;
    sp->gap = gap;
    sp->ext = ext;
    sp->type = 1;
    free(s1);
    return sp;
}

/* 
    dpAlign_Local_Protein_PhilGreen compares a DNA sequence profile
    with a DNA sequence and return the optimal local alignment score.
 */
int
dpAlign_Local_DNA_PhilGreen(dpAlign_SequenceProfile * sp, char * seq2)
{
    int i;
    int N;
    struct swstr * ss;
    int score;
    unsigned char * s2;

    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

    N = strlen(seq2);

    s2 = (unsigned char *) malloc(N*sizeof(unsigned char));
    if (s2 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 2!\n");

    for (i = 0; i < N; ++i) {
	if (seq2[i] >= 'a' && seq2[i] <= 'z') seq2[i] -= 0x20;
        s2[i] = dna_encode(seq2[i]);
    }

    ss = (struct swstr *) malloc(sizeof(struct swstr)*(sp->len+1));
    if (ss == NULL)
	dpAlign_fatal("Cannot allocate memory for ss array!\n");
    score = pgreen(sp->waa, sp->len, s2, N, sp->gap, sp->ext, ss);
    free(ss);
    free(s2);
    return score;
}

/* 
  dpAlign_Local_Protein_MillerMyers implements the Miller-Myers algorithm
  that aligns protein sequences as defined in their 1988 paper. It takes
  two character strings seq1 and seq2, the name of a scoring matrix. 
  Currently, we only support "BLOSUM62" matrix.
  dpAlign_Local_Protein_MillerMyers returns a dpAlign_AlignOutput data
  structure that can be easily converted into a Bio::SimpleAlign object.
 */
dpAlign_AlignOutput *
dpAlign_Local_Protein_MillerMyers(char * seq1, char * seq2, char * matrix)
{
    sw_AlignStruct * as;
    int ** s;
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize the scoring matrix */
    s = (int **) malloc(24*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < 24; ++i) {
	s[i] = (int *) malloc(24*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < 24; ++j) {
	    s[i][j] = blosum62[i][j];
        }
    }

/* initialize alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, 7, 1);

/* uppercase the sequence and encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = prot_encode(as->seq1[i]);
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = prot_encode(as->seq2[i]);
    }

/* locate the end points of the subsequence that results in the maximal score */
    find_ends(as);

/* align the subsequences bounded by the end points */
    as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);
    return traceback(as);
}

/* 
  dpAlign_Global_Protein_MillerMyers implements the Miller-Myers algorithm
  that aligns protein sequences as defined in their 1988 paper. It takes
  two character strings seq1 and seq2, the name of a scoring matrix. 
  Currently, we only support "BLOSUM62" matrix.
  dpAlign_Local_Protein_MillerMyers returns a dpAlign_AlignOutput data
  structure that can be easily converted into a Bio::SimpleAlign object.
 */
dpAlign_AlignOutput *
dpAlign_Global_Protein_MillerMyers(char * seq1, char * seq2, char * matrix)
{
    sw_AlignStruct * as;
    int ** s;
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize the scoring matrix */
    s = (int **) malloc(24*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < 24; ++i) {
	s[i] = (int *) malloc(24*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < 24; ++j) {
	    s[i][j] = blosum62[i][j];
        }
    }

/* initialize alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, 7, 1);

/* uppercase the sequence and encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = prot_encode(as->seq1[i]);
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = prot_encode(as->seq2[i]);
    }

/* initialize the spaces arrays */
    as->spc1 = (int *) calloc(as->len1 + 1, sizeof(int));
    if (as->spc1 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 1!\n");
    as->spc2 = (int *) calloc(as->len2 + 1, sizeof(int));
    if (as->spc2 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 2!\n");
/* align the subsequences bounded by the end points */
    as->score = align(as->s1, as->s2, as->len1, as->len2, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);

/* set start and end for global alignment */
    as->start1 = 1;
    as->end1 = as->len1;
    as->start2 = 1;
    as->end2 = as->len2;

    if (as->score <= 0)
        return NULL;
    else
        return traceback(as);
}

/* 
  init_AlignStruct initializes the alignment data structure by allocating
  memory and setting values. It returns a sw_AlignStruct that is 
  initialized based on the two sequence strings seq1 and seq2, the
  scoring matrix s, the gap opening cost gap and gap extension cost ext.
 */
static sw_AlignStruct *
init_AlignStruct(char * seq1, char * seq2, int ** s, int gap, int ext)
{
    sw_AlignStruct * as = (sw_AlignStruct *) calloc(1, sizeof(sw_AlignStruct));

    if (as == NULL) 
	dpAlign_fatal("Cannot allocate memory for dpAlign_AlignStruct!\n");

    as->seq1 = seq1;
    as->len1 = strlen(seq1);
    if (as->len1 <= 0) 
	dpAlign_fatal("Sequence 1 is has non-positive length!\n");

    as->seq2 = seq2;
    as->len2 = strlen(seq2);
    if (as->len2 <= 0) 
	dpAlign_fatal("Sequence 2 is has non-positive length!\n");

/* allocate memory for Gotoh arrays */
    as->FF = (struct swstr *) calloc((as->len2+1), sizeof(struct swstr));
    if (as->FF == NULL)
        dpAlign_fatal("Can't allocate memory for forward swstr array!\n");
    as->RR = (struct swstr *) calloc((as->len2+1), sizeof(struct swstr));
    if (as->RR == NULL)
        dpAlign_fatal("Can't allocate memory for reverse swstr array!\n");

/* allocate memory for encoded sequence string */
    as->s1 = (unsigned char *) malloc(as->len1*sizeof(unsigned char));
    if (as->s1 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 1!\n");
    as->s2 = (unsigned char *) malloc(as->len2*sizeof(unsigned char));
    if (as->s2 == NULL)
        dpAlign_fatal("Cannot allocate memory for encoded sequence 2!\n");

    as->gap = gap;
    as->ext = ext;
    as->s = s;

    return as;
}

/* 
  traceback takes a sw_AlignStruct with the gap arrays computed by
  align and inserts gaps into the aligned subsequences. Then it
  returns the dpAlign_AlignOutput that is to be converted into a
  Bio::SimpleAlign object.
 */
static dpAlign_AlignOutput * 
traceback(sw_AlignStruct * as) 
{
    dpAlign_AlignOutput * ao;
    int aln1_len = as->end1 - as->start1 + 1;
    int aln2_len = as->end2 - as->start2 + 1;
    char aln_seq1[as->len1+as->len2+1];
    char aln_seq2[as->len1+as->len2+1];
    int i, j, k;

/* free all allocated memory before we exit this module */
    for (i = 0; i < 4; ++i)
	free(as->s[i]);
    free(as->s);
    free(as->s1);
    free(as->s2);
    free(as->FF);
    free(as->RR);

    ao = (dpAlign_AlignOutput *) calloc(1, sizeof(dpAlign_AlignOutput));
    if (ao == NULL)
	dpAlign_fatal("Can't allocate memory for AlignOutput!\n");

/* insert gaps to sequence 1 */
    k = 0;
    for (i = 0; i <= aln1_len; ++i) {
	for (j = 0; j < as->spc1[i]; ++j)
	    aln_seq1[k++] = '-';
	aln_seq1[k++] = as->seq1[i+as->start1-1];
    }
    aln_seq1[k-1] = '\0';

    ao->aln1 = (char *) malloc(k*sizeof(char));
    if (ao->aln1 == NULL)
        dpAlign_fatal("Can't allocate memory for aln1!\n");
    strcpy(ao->aln1, aln_seq1);

/* insert gaps to sequence 2 */
    k = 0;
    for (i = 0; i <= aln2_len; ++i) {
	for (j = 0; j < as->spc2[i]; ++j)
	    aln_seq2[k++] = '-';
	aln_seq2[k++] = as->seq2[i+as->start2-1];
    }
    aln_seq2[k-1] = '\0';

    ao->aln2 = (char *) malloc(k*sizeof(char));
    if (ao->aln2 == NULL)
        dpAlign_fatal("Can't allocate memory for aln1!\n");
    strcpy(ao->aln2, aln_seq2);

    ao->start1 = as->start1;
    ao->start2 = as->start2;
    ao->end1 = as->end1;
    ao->end2 = as->end2;      

/* free the rest of allocated memory */
    free(as->spc1);
    free(as->spc2);
    free(as);
    return ao;
}

/* 
  find_ends set the end points in the sw_AlignStruct by employing
  the Gotoh way of calculating alignment score. First it goes forward
  to find the end points. Then from there it goes backwards to find
  the start points. There are no return values, the end points 
  in sw_AlignStruct are set before the function returns.
 */
static void
find_ends(sw_AlignStruct * as)
{
    struct swstr * F = as->FF;
    struct swstr * R = as->RR;
    int M = as->len1;
    int N = as->len2;
    unsigned char * A = as->s1;
    unsigned char * B = as->s2;
    struct swstr * swp;
    int i, j;
    int from, P;
    int c; /* score of a cell */
    int d; /* down value in Q array */
    int ** s = as->s;
    int * ss; 
    int g = as->gap;
    int e = as->ext;
    int h = g + e;
    int score1 = 0, score2 = 0;

/* find end points */
    for (i = 0; i < M; ++i) {
	F[0].H = P = from = c = 0;
	ss = s[A[i]];
	for (swp = F+1, j = 0; swp <= F+N; ++swp, ++j) {
	    if ((c = c - h) > (P = P - e)) P = c;
	    if ((c = swp->H - h) > (d = swp->E - e)) d = c;
	    c = from + ss[B[j]];
	    if (c < 0) c = 0;
	    if (P > c) c = P;
	    if (d > c) c = d;
	    swp->E = d;
	    from = swp->H;
	    swp->H = c;
	    if (c > score1) {
		score1 = c;
		as->end1 = i+1;
		as->end2 = j+1;
	    } 
	}
    }

/* find start point */
    M = as->end1;
    N = as->end2;
    for (i = M-1; i >= 0; --i) {
	R[0].H = P = from = c = 0;
	ss = s[A[i]];
	for (swp = R+1, j = N-1; swp <= R+N; ++swp, --j) {
	    if ((c = c - h) > (P = P - e)) P = c;
	    if ((c = swp->H - h) > (d = swp->E - e)) d = c;
	    c = from + ss[B[j]];
	    if (c < 0) c = 0;
	    if (P > c) c = P;
	    if (d > c) c = d;
	    swp->E = d;
	    from = swp->H;
	    swp->H = c;
	    if (c > score2) {
		score2 = c;
		as->start1 = i+1;
		as->start2 = j+1;
		if (c >= score1) goto found; // score same as before, done!
	    } 
	}
    }

found:
    as->score = score1;
/* initialize the spaces arrays */
    as->spc1 = (int *) calloc(as->end1 - as->start1 + 2, sizeof(int));
    if (as->spc1 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 1!\n");
    as->spc2 = (int *) calloc(as->end2 - as->start2 + 2, sizeof(int));
    if (as->spc2 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 2!\n");
}
