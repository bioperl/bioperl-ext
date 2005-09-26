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
align(unsigned char * A, unsigned char * B, int M, int N, int ** s, int g, int e, struct swstr * F, struct swstr * R, int * spc1, int * spc2)
{
    int midi, midj, type;
    int midc;
    register struct swstr * swp;
    register int i, j;
    register int from, P, t;
    int c; /* score of a cell */
    int d; /* down value in Q array */
    int * ss; 
    int h = g + e;

/* if the mstrix to divide and conquer has size <= 1 */
    if (N <= 0) {
	if (M > 0) *spc2 += M;
	return -gap(M, g, e);
    }

    if (M <= 1) {
	if (M <= 0) {
	    *spc1 += N;
	    return -gap(N, g, e); 
	}
	midc = -h - gap(N, g, e);
	midj = 0;
	ss = s[A[0]];
	for (j = 1; j <= N; ++j) {
	    c = -gap(j-1, g, e) + ss[B[j-1]] - gap(N-j, g, e);
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
    for (swp = F+1; swp <= F+N; ++swp) 
	 swp->E = swp->H = t = t - e;

/* Calculate forward matrix cost */

    t = -g;
    midi = M/2;
    for (i = 0; i < midi; ++i) {
	from = F[0].H;
	F[0].H = c = P = t = t - e;
	ss = s[A[i]];
	for (swp = F+1, j = 0; j < N; ++swp, ++j) {
	    if ((c = c - h) > (P = P - e)) P = c;
	    if ((c = swp->H - h) > (d = swp->E - e)) d = c;
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
    for (swp = R+1; swp <= R+N; ++swp) 
	 swp->E = swp->H = t = t - e;

/* Calculate backward matrix cost */

    t = -g;
    for (i = M-1; i >=midi; --i) {
	from = R[0].H;
	R[0].H = P = c = t = t - e;
	ss = s[A[i]];
	for (swp = R+1, j = N-1; j >= 0; ++swp, --j) {
	    if ((c = c - h) > (P = P - e)) P = c;
	    if ((c = swp->H - h) > (d = swp->E - e)) d = c;
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
	if (c > midc) {
	    midc = c;
	    midj = j;
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
	align(A, B, midi, midj, s, g, e, F, R, spc1, spc2);
	align(A+midi, B+midj, M-midi, N-midj, s, g, e, F, R, spc1+midi, spc2+midj);
    }
    else {
	align(A, B, midi-1, midj, s, g, e, F, R, spc1, spc2);
	*(spc2+midj) += 2;
	align(A+midi+1, B+midj, M-midi-1, N-midj, s, g, e, F, R, spc1+midi+1, spc2+midj);
    }
    return midc;
}
