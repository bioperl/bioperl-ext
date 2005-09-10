#ifndef _DPALIGN_H_
#define _DPALIGN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/* global variables */
extern int hoxd[4][4];
extern int blosum62[24][24];

struct swstr {
    int H; /* score for CC/RR matrix */
    int E; /* score for DD/SS matrix */   
};

#define gap(k, g, h) ((k) <= 0 ? 0 : (g)+(h)*(k)) /* gap cost */
/* a naive macro to encode DNA nucleotide */
#define dna_encode(c) (c == 'A' ? 0x00 : c == 'C' ? 0x01 : c == 'G' ? 0x02 : c == 'T' ? 0x03 : c == 'U' ? 0x04 : c == 'R' ? 0x05 : c == 'Y' ? 0x06 : c == 'M' ? 0x07 : c == 'W' ? 0x08 : c == 'S' ? 0x09 : c == 'K' ? 0x0a : c == 'D' ? 0x0b : c == 'H' ? 0x0c : c == 'V' ? 0x0d : c == 'B' ? 0x0e : c == 'N' ? 0x0f : c == 'X' ? 0x10 : -1)
/* a naive macro to encode amino acids */
#define prot_encode(c) (c == 'A' ? 0x00 : c == 'R' ? 0x01 : c == 'N' ? 0x02 : c == 'D' ? 0x03 : c == 'C' ? 0x04 : c == 'Q' ? 0x05 : c == 'E' ? 0x06 : c == 'G' ? 0x07 : c == 'H' ? 0x08 : c == 'I' ? 0x09 : c == 'L' ? 0x0a : c == 'K' ? 0x0b : c == 'M' ? 0x0c : c == 'F' ? 0x0d : c == 'P' ? 0x0e : c == 'S' ? 0x0f : c == 'T' ? 0x10 : c == 'W' ? 0x11 : c == 'Y' ? 0x12 : c == 'V' ? 0x13 : c == 'B' ? 0x14 : c == 'Z' ? 0x15 : c == 'X' ? 0x16 : c == '*' ? 0x17 : -1)

typedef struct _dpAlign_alnoutput {
   char * aln1; /* aligned subsequence of sequence 1 with space '-' inserted */
   int start1; /* start point of aligned subsequence 1 */
   int end1; /* end point of aligned subsequence 1 */
   char * aln2; /* aligned subsequence of sequence 2 with space '-' inserted */
   int start2; /* start point of aligned subsequence 2 */
   int end2; /* end point of aligned subsequence 2 */
   int score; /* score of this alignment */
} dpAlign_AlignOutput;

typedef struct _dpAlign_SequenceProfile {
   int * waa; /* sequence profile */
   int gap;
   int ext;
   int len; /* length of sequence */
   int type; /* 1 is DNA, 2 is Protein, 3 is RNA */
   int a[256]; /* alphabet array that maps a character in the alphabet to an integer index that indexes the columns and rows in the scoring matrix */
} dpAlign_SequenceProfile;

typedef struct _dpAlign_ScoringMatrix {
   int ** s; /* scoring matrix pointer */
   int a[256]; /* alphabet array that maps a character in the alphabet to an integer index that indexes the columns and rows in the scoring matrix */
   int gap; /* gap opening penalty for this matrix */
   int ext; /* gap extension penalty for this matrix */
   int sz; /* size of alphabet */
} dpAlign_ScoringMatrix;

dpAlign_AlignOutput * dpAlign_Local_DNA_MillerMyers(char *, char *, int, int, int, int);
dpAlign_AlignOutput * dpAlign_Global_DNA_MillerMyers(char *, char *, int, int, int, int);
dpAlign_AlignOutput * dpAlign_Local_Protein_MillerMyers(char *, char *, dpAlign_ScoringMatrix *);
dpAlign_AlignOutput * dpAlign_Global_Protein_MillerMyers(char *, char *, dpAlign_ScoringMatrix *);
dpAlign_SequenceProfile * dpAlign_Protein_Profile(char *, dpAlign_ScoringMatrix *);
int dpAlign_Local_Protein_PhilGreen(dpAlign_SequenceProfile *, char *);
dpAlign_SequenceProfile * dpAlign_DNA_Profile(char *, int, int, int, int);
int dpAlign_Local_DNA_PhilGreen(dpAlign_SequenceProfile *, char *);
dpAlign_ScoringMatrix * new_dpAlign_ScoringMatrix(char *, int, int);
void set_dpAlign_ScoringMatrix(dpAlign_ScoringMatrix *, char *, char *, int);
dpAlign_AlignOutput * dpAlign_Local_DNA_Green(char *, char *, int, int, int, int);
void dpAlign_fatal(char *);
int align(unsigned char *, unsigned char *, int, int, int **, int, int, struct swstr *, struct swstr *, int *, int *);
int pgreen(int *, int, unsigned char *, int, int, int, struct swstr *);
#endif
