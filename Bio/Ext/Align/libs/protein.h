#ifndef DYNAMITEproteinHEADERFILE
#define DYNAMITEproteinHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "sequence.h"



struct bp_sw_Protein {  
    int dynamite_hard_link;  
    Sequence * baseseq;  
    } ;  
/* Protein defined */ 
#ifndef DYNAMITE_DEFINED_Protein
typedef struct bp_sw_Protein bp_sw_Protein;
#define Protein bp_sw_Protein
#define DYNAMITE_DEFINED_Protein
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  truncate_Protein(pro,start,stop)
 *
 * Descrip:    Truncates a protein sequence. Basically uses
 *             the /trunc_Sequence function (of course!)
 *
 *             It does not alter pro, rather it returns a new
 *             sequence with that truncation
 *
 *
 * Arg:          pro [READ ] Protein that is truncated [Protein *]
 * Arg:        start [UNKN ] Undocumented argument [int]
 * Arg:         stop [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_truncate_Protein(Protein * pro,int start,int stop);
#define truncate_Protein bp_sw_truncate_Protein


/* Function:  read_fasta_file_Protein (filename)
 *
 * Descrip:    Reads a fasta file assumming that it is protein. 
 *             Will complain if it is not, and return NULL.
 *
 *
 * Arg:        filename [UNKN ] filename to be opened and read [char *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_read_fasta_file_Protein (char * filename);
#define read_fasta_file_Protein  bp_sw_read_fasta_file_Protein 


/* Function:  read_fasta_Protein (ifp)
 *
 * Descrip:    Reads a fasta file assumming that it is protein. 
 *             Will complain if it is not, and return NULL.
 *
 *
 * Arg:        ifp [UNKN ] file point to be read from [FILE *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_read_fasta_Protein (FILE * ifp);
#define read_fasta_Protein  bp_sw_read_fasta_Protein 


/* Function:  read_efetch_Protein(estr)
 *
 * Descrip:    Reads a efetch specified query
 *             Uses, of course /read_efetch_Sequence
 *
 *
 * Arg:        estr [READ ] efetch string which is read [char *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_read_efetch_Protein(char * estr);
#define read_efetch_Protein bp_sw_read_efetch_Protein


/* Function:  read_SRS_Protein(srsquery)
 *
 * Descrip:    Reads a SRS sequence using srs4 syntax.
 *             Uses, of course, /read_SRS_Sequence
 *
 *
 *
 * Arg:        srsquery [READ ] string query representing SRS name [char *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_read_SRS_Protein(char * srsquery);
#define read_SRS_Protein bp_sw_read_SRS_Protein


/* Function:  Protein_name (pr)
 *
 * Descrip:    Returns the name of the protein
 *
 *
 * Arg:        pr [UNKN ] Undocumented argument [Protein *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_Protein_name (Protein * pr);
#define Protein_name  bp_sw_Protein_name 


/* Function:  Protein_length (pr)
 *
 * Descrip:    Returns the length of the protein
 *
 *
 * Arg:        pr [UNKN ] Undocumented argument [Protein *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_Protein_length (Protein * pr);
#define Protein_length  bp_sw_Protein_length 


/* Function:  Protein_seqchar(pr,pos)
 *
 * Descrip:    Returns sequence character at this position.
 *
 *
 * Arg:         pr [UNKN ] Protein [Protein *]
 * Arg:        pos [UNKN ] position in protein to get char [int]
 *
 * Return [UNKN ]  Undocumented return value [char]
 *
 */
char bp_sw_Protein_seqchar(Protein * pr,int pos);
#define Protein_seqchar bp_sw_Protein_seqchar


/* Function:  Protein_from_Sequence(seq)
 *
 * Descrip:    makes a new protein from a Sequence. It 
 *             owns the Sequence memory, ie will attempt a /free_Sequence
 *             on the structure when /free_Protein is called
 *
 *             If you want to give this protein this Sequence and
 *             forget about it, then just hand it this sequence and set
 *             seq to NULL (no need to free it). If you intend to use 
 *             the sequecne object elsewhere outside of the Protein datastructure
 *             then use Protein_from_Sequence(/hard_link_Sequence(seq))
 *
 *
 *
 * Arg:        seq [OWNER] Sequence to make protein from [Sequence *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_Protein_from_Sequence(Sequence * seq);
#define Protein_from_Sequence bp_sw_Protein_from_Sequence


/* Function:  hard_link_Protein(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [Protein *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_hard_link_Protein(Protein * obj);
#define hard_link_Protein bp_sw_hard_link_Protein


/* Function:  Protein_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_Protein_alloc(void);
#define Protein_alloc bp_sw_Protein_alloc


/* Function:  free_Protein(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [Protein *]
 *
 * Return [UNKN ]  Undocumented return value [Protein *]
 *
 */
Protein * bp_sw_free_Protein(Protein * obj);
#define free_Protein bp_sw_free_Protein


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_replace_baseseq_Protein(Protein * obj,Sequence * baseseq);
#define replace_baseseq_Protein bp_sw_replace_baseseq_Protein
Sequence * bp_sw_access_baseseq_Protein(Protein * obj);
#define access_baseseq_Protein bp_sw_access_baseseq_Protein

#ifdef _cplusplus
}
#endif

#endif
