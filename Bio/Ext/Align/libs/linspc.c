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
static void find_endsfree(sw_AlignStruct *);
static dpAlign_AlignOutput * traceback(sw_AlignStruct *);

/*
  dpAlign_Local_DNA_MillerMyers uses Gotoh algorithm to find the 
  start points and end points of a local alignment. Then extracts
  the sequences within the end points to use Miller-Myers algorithm
  to run an global alignment for the subsequences to obtain the 
  actual alignment between the end points.
  It takes two character string sequences seq1 and seq2, together 
  with the scoring parameters for match, mismatch, gap opening and 
  gap extension as arguments. At the end, it returns the 
  dpAlign_AlignOutput data structure which can be translated into a 
  Bio::SimpleAlign object pretty easily.
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

    if (as->score < 0)
	return NULL;

/* align the subsequences bounded by the end points */
    as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);
    return traceback(as);
}

/*
  dpAlign_EndsFree_DNA_MillerMyers uses a modified Gotoh algorithm 
  to find the edge points of an ends-free alignment. The modified
  algorithm doesn't give penalty to gaps starting from the ends.
  After the edge points are located, the gaps at starting from the
  ends can be calculated and then put into the gap arrays. Then it
  extracts the sequences within the edge points to use Miller-Myers 
  algorithm to run an global alignment for the subsequences to obtain
  the actual alignment between the edge points.
  It takes two character string sequences seq1 and seq2, together 
  with the scoring parameters for match, mismatch, gap opening and 
  gap extension as arguments. At the end, it returns the 
  dpAlign_AlignOutput data structure which can be translated into a 
  Bio::SimpleAlign object pretty easily.
 */
dpAlign_AlignOutput *
dpAlign_EndsFree_DNA_MillerMyers(char * seq1, char * seq2, int match, int mismatch, int gap, int ext)
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
    find_endsfree(as);

/* align the subsequences bounded by the end points */
   as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1 + as->start1 - 1, as->spc2 + as->start2 - 1);
/* make it a global alignment */
   as->start1 = 1;
   as->end1 = as->len1;
   as->start2 = 1;
   as->end2 = as->len2;  
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

/*
   maxn0 = max(3*n0/2,MIN_RES);         
   if ((res = (int *)calloc((size_t)maxn0,sizeof(int)))==NULL) {
     fprintf(stderr,"cannot allocate alignment results array %d\n",maxn0);
     exit(1);
   }
    as->score = align2(as->s1, as->s2, as->len1, as->len2, -as->gap, -as->gap, as->s, as->gap, as->ext, as->FF, as->RR);
printf("%d\n", as->score);
exit(0);
*/
/*
    for (i = 0; i < 17; ++i) {
       free(as->s[i]);
    }
    free(as->s);
*/
/* set start and end for global alignment */
    as->start1 = 1;
    as->end1 = as->len1;
    as->start2 = 1;
    as->end2 = as->len2;
    return traceback(as);
}

/*
    new_dpAlign_ScoringMatrix instantiate a dpAlign_ScoringMatrix object
    with a alphabet string, gap opening penalty and gap extension penalty.
    The dpAlign_ScoringMatrix object created will have alphabet mapping
    array, gap penalities initialized. Memory will be allocated for the
    scoring matrix s and initialized to zeros.
 */
dpAlign_ScoringMatrix *
new_dpAlign_ScoringMatrix(char * alphabet, int gap, int ext)
{
    int i;
    dpAlign_ScoringMatrix * matrix;

    matrix = (dpAlign_ScoringMatrix *) malloc(sizeof(dpAlign_ScoringMatrix));
    if (matrix == NULL)
        dpAlign_fatal("Can't allocate memory for dpAlign_ScoringMatrix!\n");
    matrix->sz = strlen(alphabet);
    matrix->s = (int **) malloc(matrix->sz*sizeof(int *));
    if (matrix->s == NULL)
        dpAlign_fatal("Can't allocate memory for dpAlign_ScoringMatrix's s!\n");
    for (i = 0; i < matrix->sz; ++i) {
        matrix->s[i] = (int *) calloc(matrix->sz, sizeof(int));
        if (matrix->s[i] == NULL) 
            dpAlign_fatal("Can't allocate memory for dpAlign_ScoringMatrix's s!\n");
    }
    matrix->gap = gap;
    matrix->ext = ext;
    for (i = 0; i < matrix->sz; ++i) 
         matrix->a[alphabet[i]] = i;
    return matrix;
}

/*
    set_dpAlign_ScoringMatrix initilizes the scoring matrix s of a
    dpAlign_ScoringMatrix object. It only intializes one cell. Therefore
    to use this function, you need to wrap it with two loops over the 
    alphabet set to initialize all the fields.
 */
void
set_dpAlign_ScoringMatrix(dpAlign_ScoringMatrix * matrix, char * row, char * col, int val)
{
   matrix->s[matrix->a[row[0]]][matrix->a[col[0]]] = val;
}

/* 
    dpAlign_Protein_Profile creates a sequence profile from a protein 
    sequence.
 */
dpAlign_SequenceProfile *
dpAlign_Protein_Profile(char * seq1, dpAlign_ScoringMatrix * matrix)
{
    int i, j;
    unsigned char * s1;
    int gap = 7;
    int ext = 1;
    int sz = 24;
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
    if (matrix == NULL) {
        sp->a['A'] = 0x00; sp->a['R'] = 0x01; sp->a['N'] = 0x02; sp->a['D'] = 0x03;
        sp->a['C'] = 0x04; sp->a['Q'] = 0x05; sp->a['E'] = 0x06; sp->a['G'] = 0x07;
        sp->a['H'] = 0x08; sp->a['I'] = 0x09; sp->a['L'] = 0x0a; sp->a['K'] = 0x0b;
        sp->a['M'] = 0x0c; sp->a['F'] = 0x0d; sp->a['P'] = 0x0e; sp->a['S'] = 0x0f;
        sp->a['T'] = 0x10; sp->a['W'] = 0x11; sp->a['Y'] = 0x12; sp->a['V'] = 0x13;
        sp->a['B'] = 0x14; sp->a['Z'] = 0x15; sp->a['X'] = 0x16; sp->a['*'] = 0x17;
    }
    else {
       gap = matrix->gap;
       ext = matrix->ext;
       sz = matrix->sz;
       for (i = 0; i < 256; ++i)
           sp->a[i] = matrix->a[i];
    }
    for (i = 0; i < sp->len; ++i) {
	if (seq1[i] >= 'a' && seq1[i] <= 'z') seq1[i] -= 0x20;
        s1[i] = sp->a[seq1[i]];
    }

    sp->waa = (int *) malloc(sizeof(int)*sz*sp->len);
    if (sp->waa == NULL)
        dpAlign_fatal("Can't allocate memory for waa!\n");
    pwaa = sp->waa;
    if (matrix == NULL) {
        for (i = 0; i < sz; ++i) {
            smp = blosum62[i];
            for (j = 0; j < sp->len; ++j)
                *pwaa++ = smp[s1[j]];
        }
    }
    else {
        for (i = 0; i < sz; ++i) {
            smp = matrix->s[i];
            for (j = 0; j < sp->len; ++j) {
//printf("hi1\t%d\t%d\t%d\t%d\n", i, j, s1[j], smp[s1[j]]);
                *pwaa++ = smp[s1[j]];
}
        }
    }
    sp->gap = gap;
    sp->ext = ext;
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
        s2[i] = sp->a[seq2[i]];
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
    dpAlign_Local_DNA_PhilGreen compares a DNA sequence profile
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
  dpAlign_Local_Protein_MillerMyers uses Gotoh algorithm to find the 
  start points and end points of a local alignment. Then extracts
  the sequences within the end points to use Miller-Myers algorithm
  to run an global alignment for the subsequences to obtain the 
  actual alignment between the end points.
  It takes two character string sequences seq1 and seq2, together 
  with the scoring parameters for match, mismatch, gap opening and 
  gap extension as arguments. At the end, it returns the 
  dpAlign_AlignOutput data structure which can be translated into a 
  Bio::SimpleAlign object pretty easily.
 */
dpAlign_AlignOutput *
dpAlign_Local_Protein_MillerMyers(char * seq1, char * seq2, dpAlign_ScoringMatrix * matrix)
{
    sw_AlignStruct * as;
    int ** s;
    int * a; /* alphabet array */
    int gap = 7;
    int ext = 1;
    int sz = 24; /* size of alphabet */
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize the scoring matrix */
    if (matrix == NULL) {
    s = (int **) malloc(sz*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < sz; ++i) {
	s[i] = (int *) malloc(24*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < sz; ++j) {
	    s[i][j] = blosum62[i][j];
        }
    }
        a = (int *) malloc(256*sizeof(int));
        if (a == NULL)
            dpAlign_fatal("Cannot allocate memory for protein encoding array!\n");

        a['A'] = 0x00; a['R'] = 0x01; a['N'] = 0x02; a['D'] = 0x03;
        a['C'] = 0x04; a['Q'] = 0x05; a['E'] = 0x06; a['G'] = 0x07;
        a['H'] = 0x08; a['I'] = 0x09; a['L'] = 0x0a; a['K'] = 0x0b;
        a['M'] = 0x0c; a['F'] = 0x0d; a['P'] = 0x0e; a['S'] = 0x0f;
        a['T'] = 0x10; a['W'] = 0x11; a['Y'] = 0x12; a['V'] = 0x13;
        a['B'] = 0x14; a['Z'] = 0x15; a['X'] = 0x16; a['*'] = 0x17;
    }
    else {
       a = matrix->a;
       s = matrix->s;
       gap = matrix->gap;
       ext = matrix->ext;
       sz = matrix->sz;
    }

/* initialize alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, gap, ext);

/* uppercase the sequence and encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = a[as->seq1[i]];
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = a[as->seq2[i]];
    }

    if (matrix == NULL)
        free(a); /* free array after encoding */

/* locate the end points of the subsequence that results in the maximal score */
    find_ends(as);

    if (as->score < 0)
       return NULL;

/* align the subsequences bounded by the end points */
    as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);
    return traceback(as);
}

/*
  dpAlign_EndsFree_Protein_MillerMyers uses a modified Gotoh algorithm 
  to find the edge points of an ends-free alignment. The modified
  algorithm doesn't give penalty to gaps starting from the ends.
  After the edge points are located, the gaps at starting from the
  ends can be calculated and then put into the gap arrays. Then it
  extracts the sequences within the edge points to use Miller-Myers 
  algorithm to run an global alignment for the subsequences to obtain
  the actual alignment between the edge points.
  It takes two character string sequences seq1 and seq2, together 
  with the scoring parameters for match, mismatch, gap opening and 
  gap extension as arguments. At the end, it returns the 
  dpAlign_AlignOutput data structure which can be translated into a 
  Bio::SimpleAlign object pretty easily.
 */
dpAlign_AlignOutput *
dpAlign_EndsFree_Protein_MillerMyers(char * seq1, char * seq2, dpAlign_ScoringMatrix * matrix)
{
    sw_AlignStruct * as;
    int ** s;
    int * a; /* alphabet array */
    int gap = 7;
    int ext = 1;
    int sz = 24; /* size of alphabet */
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize the scoring matrix */
    if (matrix == NULL) {
    s = (int **) malloc(sz*sizeof(int *));
    if (s == NULL)
        dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
    for (i = 0; i < sz; ++i) {
	s[i] = (int *) malloc(24*sizeof(int));
	if (s[i] == NULL)
	    dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
        for (j = 0; j < sz; ++j) {
	    s[i][j] = blosum62[i][j];
        }
    }
        a = (int *) malloc(256*sizeof(int));
        if (a == NULL)
            dpAlign_fatal("Cannot allocate memory for protein encoding array!\n");

        a['A'] = 0x00; a['R'] = 0x01; a['N'] = 0x02; a['D'] = 0x03;
        a['C'] = 0x04; a['Q'] = 0x05; a['E'] = 0x06; a['G'] = 0x07;
        a['H'] = 0x08; a['I'] = 0x09; a['L'] = 0x0a; a['K'] = 0x0b;
        a['M'] = 0x0c; a['F'] = 0x0d; a['P'] = 0x0e; a['S'] = 0x0f;
        a['T'] = 0x10; a['W'] = 0x11; a['Y'] = 0x12; a['V'] = 0x13;
        a['B'] = 0x14; a['Z'] = 0x15; a['X'] = 0x16; a['*'] = 0x17;
    }
    else {
       a = matrix->a;
       s = matrix->s;
       gap = matrix->gap;
       ext = matrix->ext;
       sz = matrix->sz;
    }

/* initialize alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, gap, ext);

/* uppercase the sequence and encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = a[as->seq1[i]];
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = a[as->seq2[i]];
    }

    if (matrix == NULL)
        free(a); /* free array after encoding */

/* locate the end points of the subsequence that results in the maximal score */
    find_endsfree(as);

/* align the subsequences bounded by the end points */
    as->score = align(as->s1 + as->start1 - 1, as->s2 + as->start2 - 1, as->end1 - as->start1 + 1, as->end2 - as->start2 + 1, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1 + as->start1 - 1, as->spc2 + as->start2 - 1);
/* make global alignment */
    as->start1 = 1;
    as->end1 = as->len1;
    as->start2 = 1;
    as->end2 = as->len2;
    return traceback(as);
}

/* 
  dpAlign_Global_Protein_MillerMyers implements the Miller-Myers algorithm
  that aligns protein sequences as defined in their 1988 paper. It takes
  two character strings seq1 and seq2, the name of a scoring matrix. 
  Currently, we only support "BLOSUM62" matrix.
  dpAlign_Global_Protein_MillerMyers returns a dpAlign_AlignOutput data
  structure that can be easily converted into a Bio::SimpleAlign object.
 */
dpAlign_AlignOutput *
dpAlign_Global_Protein_MillerMyers(char * seq1, char * seq2, dpAlign_ScoringMatrix * matrix)
{
    sw_AlignStruct * as;
    int ** s;
    int * a; /* alphabet array */
    int gap = 7;
    int ext = 1;
    int sz = 24; /* size of alphabet */
    int i, j;

    if (seq1 == NULL)
	dpAlign_fatal("Sequence 1 is a NULL pointer!\n");
    if (seq2 == NULL)
	dpAlign_fatal("Sequence 2 is a NULL pointer!\n");

/* initialize the scoring matrix */
    if (matrix == NULL) {
        s = (int **) malloc(sz*sizeof(int *));
        if (s == NULL)
            dpAlign_fatal("Cannot allocate memory for scoring matrix row!\n");
        for (i = 0; i < sz; ++i) {
	    s[i] = (int *) malloc(sz*sizeof(int));
	    if (s[i] == NULL)
	        dpAlign_fatal("Cannot allocate memory for scoring matrix col!\n");
            for (j = 0; j < sz; ++j) {
	        s[i][j] = blosum62[i][j];
            }
        }
        a = (int *) malloc(256*sizeof(int));
        if (a == NULL)
            dpAlign_fatal("Cannot allocate memory for protein encoding array!\n");

        a['A'] = 0x00; a['R'] = 0x01; a['N'] = 0x02; a['D'] = 0x03;
        a['C'] = 0x04; a['Q'] = 0x05; a['E'] = 0x06; a['G'] = 0x07;
        a['H'] = 0x08; a['I'] = 0x09; a['L'] = 0x0a; a['K'] = 0x0b;
        a['M'] = 0x0c; a['F'] = 0x0d; a['P'] = 0x0e; a['S'] = 0x0f;
        a['T'] = 0x10; a['W'] = 0x11; a['Y'] = 0x12; a['V'] = 0x13;
        a['B'] = 0x14; a['Z'] = 0x15; a['X'] = 0x16; a['*'] = 0x17;
    }
    else {
       a = matrix->a;
       s = matrix->s;
       gap = matrix->gap;
       ext = matrix->ext;
       sz = matrix->sz;
    }

/* initialize alignment data structure */
    as = init_AlignStruct(seq1, seq2, s, gap, ext);

/* uppercase the sequence and encode it */
    for (i = 0; i < as->len1; ++i) {
	if (as->seq1[i] >= 'a' && as->seq1[i] <= 'z') as->seq1[i] -= 0x20;
        as->s1[i] = a[as->seq1[i]];
    }
    for (i = 0; i < as->len2; ++i) {
	if (as->seq2[i] >= 'a' && as->seq2[i] <= 'z') as->seq2[i] -= 0x20;
        as->s2[i] = a[as->seq2[i]];
    }

    if (matrix == NULL)
        free(a); /* free array after encoding */

/* initialize the spaces arrays */
    as->spc1 = (int *) calloc(as->len1 + 1, sizeof(int));
    if (as->spc1 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 1!\n");
    as->spc2 = (int *) calloc(as->len2 + 1, sizeof(int));
    if (as->spc2 == NULL) 
	dpAlign_fatal("Can't allocate memory for spaces array for seq 2!\n");
/* align the subsequences bounded by the end points */
    as->score = align(as->s1, as->s2, as->len1, as->len2, as->s, as->gap, as->ext, as->FF, as->RR, as->spc1, as->spc2);

/* free scoring matrix 
    for (i = 0; i < sz; ++i) {
       free(as->s[i]);
    }
    free(as->s);
*/

/* set start and end for global alignment */
    as->start1 = 1;
    as->end1 = as->len1;
    as->start2 = 1;
    as->end2 = as->len2;

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
    free(as->s1);
    free(as->s2);
    free(as->FF);
    free(as->RR);

    ao = (dpAlign_AlignOutput *) calloc(1, sizeof(dpAlign_AlignOutput));
    if (ao == NULL)
	dpAlign_fatal("Can't allocate memory for AlignOutput!\n");

    ao->score = as->score;
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

static void
find_endsfree(sw_AlignStruct * as)
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

   for (i = 0; i < N; ++i)
      F[i].E = -g;

/* find end points */
   for (i = 0; i < M-1; ++i) {
      from = c = 0;
      P = -g;
      ss = s[A[i]];
      for (swp = F+1, j = 0; swp < F+N; ++swp, ++j) {
         if ((c = c - h) > (P = P - e)) P = c;
         if ((c = swp->H - h) > (d = swp->E - e)) d = c;
         c = from + ss[B[j]];
         if (P > c) c = P;
         if (d > c) c = d;
         swp->E = d;
         from = swp->H;
         swp->H = c;
      }
/* calculate last cell in the 2nd sequence */
      swp = F+N;
      if ((c = c - h) > (P = P - e)) P = c;
      if (swp->H > (d = swp->E)) d = swp->H; 
      c = from + ss[B[N-1]];
      if (P > c) c = P;
      if (d > c) c = d;
      swp->E = d;
      swp->H = c;
      if (c > score1) {
         score1 = c;
         as->end1 = i+1;
         as->end2 = N;
      }
   }

/* calculate last cell in the 1st sequence */
   from = c = 0;
   P = -g;
   ss = s[A[M-1]];
   for (swp = F+1, j = 0; swp < F+N; ++swp, ++j) {
      if (c > P) P = c;
      if ((c = swp->H - h) > (d = swp->E - e)) d = c;
      c = from + ss[B[j]];
      if (P > c) c = P;
      if (d > c) c = d;
      swp->E = d;
      from = swp->H;
      swp->H = c;
      if (c > score1) {
         score1 = c;
         as->end1 = M;
         as->end2 = j+1;
      } 
   }
/* calculate last cell for both sequences */
   swp = F+N;
   if (c > P) P = c;
   if (swp->H > (d = swp->E)) d = swp->H; 
   c = from + ss[B[N-1]];
   if (P > c) c = P;
   if (d > c) c = d;
   swp->E = d;
   swp->H = c;
   if (c > score1) {
      score1 = c;
      as->end1 = M;
      as->end2 = N;
   }

/* find start point */
   M = as->end1;
   N = as->end2;
   for (i = 0; i < N; ++i)
      R[i].E = -g;
   for (i = M-1; i > 0; --i) {
      from = c = 0;
      P = -g;
      ss = s[A[i]];
      for (swp = R+1, j = N-1; swp < R+N; ++swp, --j) {
         if ((c = c - h) > (P = P - e)) P = c;
         if ((c = swp->H - h) > (d = swp->E - e)) d = c;
         c = from + ss[B[j]];
         if (P > c) c = P;
         if (d > c) c = d;
         swp->E = d;
         from = swp->H;
         swp->H = c;
      }
/* calculate last cell in the 2nd sequence */
      swp = R+N;
      if ((c = c - h) > (P = P - e)) P = c;
      if (swp->H > (d = swp->E)) d = swp->H; 
      c = from + ss[B[0]];
      if (P > c) c = P;
      if (d > c) c = d;
      swp->E = d;
      swp->H = c;
      if (c > score2) {
         score2 = c;
         as->start1 = i+1;
         as->start2 = 1;
         if (c >= score1) goto found; // score same as before, done!
      } 
   }

/* calculate last cell in the 1st sequence */
   from = c = 0;
   P = -g;
   ss = s[A[0]];
   for (swp = R+1, j = N-1; swp < R+N; ++swp, --j) {
      if (c > P) P = c;
      if ((c = swp->H - h) > (d = swp->E - e)) d = c;
      c = from + ss[B[j]];
      if (P > c) c = P;
      if (d > c) c = d;
      swp->E = d;
      from = swp->H;
      swp->H = c;
      if (c > score2) {
         score2 = c;
         as->start1 = 1;
         as->start2 = j+1;
         if (c >= score1) goto found; // score same as before, done!
      } 
   }
/* calculate last cell for both sequences */
   swp = R+N;
   if (c > P) P = c;
   if (swp->H > (d = swp->E)) d = swp->H; 
   c = from + ss[B[0]];
   if (P > c) c = P;
   if (d > c) c = d;
   swp->E = d;
   swp->H = c;
   if (c > score2) {
      score2 = c;
      as->start1 = 1;
      as->start2 = 1;
      if (c >= score1) goto found; // score same as before, done!
   }

found:
   as->score = score1;
/* initialize the spaces arrays */
   as->spc1 = (int *) calloc(as->len1 + 1, sizeof(int));
   if (as->spc1 == NULL) 
      dpAlign_fatal("Can't allocate memory for spaces array for seq 1!\n");
   as->spc2 = (int *) calloc(as->len2 + 1, sizeof(int));
   if (as->spc2 == NULL) 
   dpAlign_fatal("Can't allocate memory for spaces array for seq 2!\n");
/* set the end gaps based on the start stop */
   as->spc1[0] += (as->start2 - 1);
   as->spc1[as->len1] += (as->len2 - as->end2);  
   as->spc2[0] += (as->start1 - 1); 
   as->spc2[as->len2] += (as->len1 - as->end1); 
}

