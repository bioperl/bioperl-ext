#include "dpalign.h"

int hoxd[4][4] = {
{  91,-114, -31,-123},
{-114, 100,-125, -31},
{ -31,-125, 100,-114},
{-123, -31,-114,  91}
};

int blosum62[24][24] = {
{ 4, -1, -2, -2,  0, -1, -1,  0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -3, -2,  0, -2, -1,  0, -4},
{-1,  5,  0, -2, -3,  1,  0, -2,  0, -3, -2,  2, -1, -3, -2, -1, -1, -3, -2, -3, -1,  0, -1, -4},
{-2,  0,  6,  1, -3,  0,  0,  0,  1, -3, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3,  3,  0, -1, -4},
{-2, -2,  1,  6, -3,  0,  2, -1, -1, -3, -4, -1, -3, -3, -1,  0, -1, -4, -3, -3,  4,  1, -1, -4},
{ 0, -3, -3, -3,  9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, -3, -3, -2, -4},
{-1,  1,  0,  0, -3,  5,  2, -2,  0, -3, -2,  1,  0, -3, -1,  0, -1, -2, -1, -2,  0,  3, -1, -4},
{-1,  0,  0,  2, -4,  2,  5, -2,  0, -3, -3,  1, -2, -3, -1,  0, -1, -3, -2, -2,  1,  4, -1, -4},
{ 0, -2,  0, -1, -3, -2, -2,  6, -2, -4, -4, -2, -3, -3, -2,  0, -2, -2, -3, -3, -1, -2, -1, -4},
{-2,  0,  1, -1, -3,  0,  0, -2,  8, -3, -3, -1, -2, -1, -2, -1, -2, -2,  2, -3,  0,  0, -1, -4},
{-1, -3, -3, -3, -1, -3, -3, -4, -3,  4,  2, -3,  1,  0, -3, -2, -1, -3, -1,  3, -3, -3, -1, -4},
{-1, -2, -3, -4, -1, -2, -3, -4, -3,  2,  4, -2,  2,  0, -3, -2, -1, -2, -1,  1, -4, -3, -1, -4},
{-1,  2,  0, -1, -3,  1,  1, -2, -1, -3, -2,  5, -1, -3, -1,  0, -1, -3, -2, -2,  0,  1, -1, -4},
{-1, -1, -2, -3, -1,  0, -2, -3, -2,  1,  2, -1,  5,  0, -2, -1, -1, -1, -1,  1, -3, -1, -1, -4},
{-2, -3, -3, -3, -2, -3, -3, -3, -1,  0,  0, -3,  0,  6, -4, -2, -2,  1,  3, -1, -3, -3, -1, -4},
{-1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4,  7, -1, -1, -4, -3, -2, -2, -1, -2, -4},
{ 1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -2,  0, -1, -2, -1,  4,  1, -3, -2, -2,  0,  0,  0, -4},
{ 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1,  1,  5, -2, -2,  0, -1, -1,  0, -4},
{-3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1,  1, -4, -3, -2, 11,  2, -3, -4, -3, -2, -4},
{-2, -2, -2, -3, -2, -1, -2, -3,  2, -1, -1, -2, -1,  3, -3, -2, -2,  2,  7, -1, -3, -2, -1, -4},
{ 0, -3, -3, -3, -1, -2, -2, -3, -3,  3,  1, -2,  1, -1, -2, -2,  0, -3, -1,  4, -3, -2, -1, -4},
{-2, -1,  3,  4, -3,  0,  1, -1,  0, -3, -4,  0, -3, -3, -2,  0, -1, -4, -3, -3,  4,  1, -1, -4},
{-1,  0,  0,  1, -3,  3,  4, -2,  0, -3, -3,  1, -1, -3, -1,  0, -1, -3, -2, -2,  1,  4, -1, -4},
{ 0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2,  0,  0, -2, -1, -1, -1, -1, -1, -4},
{-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,  1}
};

/* 
  dpAlign_fatal prints the string s to STDERR and then exit
 */ 
void
dpAlign_fatal(char * s)
{
    fprintf(stderr, s);
    exit(-1);
}

/*
  align is an implementation of Miller-Myers' dynamic programming alignment
  algorithm using the gap array to represent the alignment result.
  There are two gap arrays, one for each sequence. Each of them consists of
  M+1 and N+1 cells where M is the length of sequence A and N is the length
  of sequence B. In general, spc1[i] will contain an integer that indicates
  how many gaps need to be inserted between A[i-1] and A[i]. For example, 
  spc1[1] will represent the number of gaps inserted between residues A[0] 
  and A[1]. s is the scoring matrix. g is the gap opening cost. e is the
  gap extension cost. F is the forward Gotoh array. R is the backward
  Gotoh array. Note that spc1 and spc2 gap arrays should be initilized to
  all zeros when you first call this function.
  align returns the score of the resulting alignment. At the end, the gap
  arrays spc1 and spc2 will also be set to the proper values.
 */ 
int
align(unsigned char * A, unsigned char * B, int M, int N, int ** s, int g, int h, struct swstr * F, struct swstr * R, int * spc1, int * spc2)
{
    int midi, midj, type;
    int midc;
    register struct swstr * swp;
    register int i, j;
    register int from, P, t;
    int c; /* score of a cell */
    int d; /* down value in Q array */
    int * ss; 
    int m = g + h;

/* if the mstrix to divide and conquer has size <= 1 */
    if (N <= 0) {
	if (M > 0) *spc2 += M;
	return -gap(M);
    }

    if (M <= 1) {
	if (M <= 0) {
	    *spc1 += N;
	    return -gap(N);
	}
	midc = -m - gap(N);
	midj = 0;
	ss = s[A[0]];
	for (j = 1; j <= N; ++j) {
	    c = -gap(j-1) + ss[B[j-1]] - gap(N-j);
	    if (c > midc) {
		midc = c;
		midj = j;
	    }
	}
	if (midj == 0) {
	    *(spc1+1) += N;
	    ++(*spc2);
	}
	else {
	    if (midj > 1) *spc1 += (midj-1);
	    if (midj < N) *(spc1+1) += (N-midj);
	}
	return midc;
    }

    swp = F;
    F[0].H = 0;
    t = -g;
    for (swp = F+1; swp <= F+N; ++swp) { 
	 swp->H = t = t - h;
         swp->E = swp->H - g; // Q[m][0]
    }

/* Calculate forward matrix cost */

    t = -g;
    midi = M/2;
    for (i = 0; i < midi; ++i) {
	from = F[0].H;
	F[0].H = c = t = t - h;
        P = c - g;
	ss = s[A[i]];
	for (swp = F+1, j = 0; j < N; ++swp, ++j) {
            if ((c = c - m) > (P = P - h)) P = c;
            if ((c = swp->H - m) > (d = swp->E - h)) d = c;
	    c = from + ss[B[j]];
	    if (P > c) c = P;
	    if (d > c) c = d;
	    swp->E = d;
	    from = swp->H;
	    swp->H = c;
	}
    }
    F[0].E = F[0].H;

    R[0].H = 0;
    t = -g;
    for (swp = R+1; swp <= R+N; ++swp) { 
	 swp->H = t = t - h;
         swp->E = swp->H - g; // P[m][0]
    }

/* Calculate backward matrix cost */

    t = -g;
    for (i = M-1; i >=midi; --i) {
	from = R[0].H;
	R[0].H = c = t = t - h;
        P = c - g;
	ss = s[A[i]];
	for (swp = R+1, j = N-1; j >= 0; ++swp, --j) {
            if ((c = c - m) > (P = P - h)) P = c;
            if ((c = swp->H - m) > (d = swp->E - h)) d = c;
	    c = from + ss[B[j]];
	    if (P > c) c = P;
	    if (d > c) c = d;
	    swp->E = d;
	    from = swp->H;
	    swp->H = c;
	}
    }
    R[0].E = R[0].H;

    midc = F[N].H + R[0].H;
    midj = N;
    type = 1;
/* see if it is type I or type II */

    for (j = N-1; j >= 0; --j) {
	c = F[j].H + R[N-j].H;
	if (c >= midc) {
            if (c > midc || F[j].H == F[j].E && R[N-j].H != R[N-j].E) {
	       midc = c;
	       midj = j;
            }
	}
    }

    for (j = N; j >= 0; --j) {
	c = F[j].E + R[N-j].E + g;
	if (c > midc) {
	    midc = c;
	    midj = j;
	    type = 2;
	}
    }

    if (type == 1) {
	align(A, B, midi, midj, s, g, h, F, R, spc1, spc2);
	align(A+midi, B+midj, M-midi, N-midj, s, g, h, F, R, spc1+midi, spc2+midj);
    }
    else {
	align(A, B, midi-1, midj, s, g, h, F, R, spc1, spc2);
	*(spc2+midj) += 2;
	align(A+midi+1, B+midj, M-midi-1, N-midj, s, g, h, F, R, spc1+midi+1, spc2+midj);
    }
    return midc;
}

/*
    pgreen runs Phil Green's algorithm to calculate alignment score between
    two sequences. The argument waa is a sequence profile derived from
    the query sequence and the scoring matrix. The second argument M is 
    the length of query sequence. B is the sequence to compare to. N is
    the length of the second sequence. gap is the gap opening cost. ext
    is the gap extension cost. ss is a preallocated array of struct swstr
    with a size of M.

    Most of the code in this function is copied from the do_work function
    in dropgsw.c inside the FASTA distribution.
 */
int
pgreen(int * waa, int M, unsigned char * B, int N, int gap, int ext, struct swstr * ss)
{
    int score;
    int e, f, h, p, i, temp;
    struct swstr * ssj;

    int * pwaa;

    gap = gap + ext;
    ext = -ext;
    ss[M].H = -1;
    ss[M].E = 1;
    score = 0;
    for (h = 0; h < M; ++h) {
	ss[h].H = ss[h].E = 0;
    }

    for (i = 0; i < N; ++i) {
	pwaa = waa + B[i]*M;
	ssj = ss;

	e = f = h = p = 0;
    zero_f:
	while (1) {
	    h = p + *pwaa++;
	    p = ssj->H;
	    if ((e = ssj->E) > 0) {
		if (p == -1) goto next_row;
		if (h < e) h = e;
		else if (h > gap) {
		    e += ext;
		    goto transition;
		}
		e += ext;
		ssj->E = (e > 0) ? e : 0;
		ssj++->H = h;
	    }
	    else {
		if (h > 0) {
		    if (h > gap) {
			e = 0;
			goto transition;
		    }
		    ssj++->H = h;
		}
		else ssj++->H = 0;
	    }
	}

    transition:
	if (score < h) score = h;

	temp = h - gap;
	if (f < temp) f = temp;
	if (e < temp) e = temp;
	ssj->E = (e > 0) ? e : 0;
	ssj++->H = h;
	e = 0;

	do {
	    h = p + *pwaa++;
	    p = ssj->H;

	    if (h < f) h = f;
	    f += ext;

	    if ((e = ssj->E) > 0) {
		if (p == -1) goto next_row;
		if (h < e) h = e;
		else if (h > gap) {
		    e += ext;
		    goto transition;
		}
		e += ext;	
		ssj->E = (e > 0) ? e : 0;
		ssj++->H = h;
	    }
	    else {
		if (h > gap) {
		    e = 0;
		    goto transition;
		}
		ssj++->H = h;
	    }
	} while (f > 0);
	goto zero_f;
    next_row:
	;
    }
	
	free(waa);
    return score;
}
