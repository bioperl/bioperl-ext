#ifndef DYNAMITEproteindbHEADERFILE
#define DYNAMITEproteindbHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "sequencedb.h"
#include "hscore.h"
#include "complexsequence.h"
#include "complexevalset.h"



struct bp_sw_ProteinDB {  
    int dynamite_hard_link;  
    boolean is_single_seq;   
    ComplexSequence * single;    
    SequenceDB * sdb;    
    ComplexSequenceEvalSet * cses;   
    } ;  
/* ProteinDB defined */ 
#ifndef DYNAMITE_DEFINED_ProteinDB
typedef struct bp_sw_ProteinDB bp_sw_ProteinDB;
#define ProteinDB bp_sw_ProteinDB
#define DYNAMITE_DEFINED_ProteinDB
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  show_Hscore_ProteinDB(hs,ofp)
 *
 * Descrip:    shows the Hscore by the ProteinDB information
 *
 *
 *
 * Arg:         hs [UNKN ] High Score structure [Hscore *]
 * Arg:        ofp [UNKN ] output file [FILE *]
 *
 */
void bp_sw_show_Hscore_ProteinDB(Hscore * hs,FILE * ofp);
#define show_Hscore_ProteinDB bp_sw_show_Hscore_ProteinDB


/* Function:  dataentry_add_ProteinDB(de,cs,prodb)
 *
 * Descrip:    adds information to dataentry from ProteinDB
 *
 *             will eventually add file offset and format information
 *
 *
 * Arg:           de [UNKN ] Undocumented argument [DataEntry *]
 * Arg:           cs [UNKN ] Undocumented argument [ComplexSequence *]
 * Arg:        prodb [UNKN ] Undocumented argument [ProteinDB *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_dataentry_add_ProteinDB(DataEntry * de,ComplexSequence * cs,ProteinDB * prodb);
#define dataentry_add_ProteinDB bp_sw_dataentry_add_ProteinDB


/* Function:  init_ProteinDB(prodb,return_status)
 *
 * Descrip:    top level function which opens the protein database
 *
 *
 * Arg:                prodb [UNKN ] protein database [ProteinDB *]
 * Arg:        return_status [WRITE] the status of the open from database.h [int *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexSequence *]
 *
 */
ComplexSequence * bp_sw_init_ProteinDB(ProteinDB * prodb,int * return_status);
#define init_ProteinDB bp_sw_init_ProteinDB


/* Function:  reload_ProteinDB(last,prodb,return_status)
 *
 * Descrip:    function which reloads the database
 *
 *
 * Arg:                 last [UNKN ] previous complex sequence, will be freed [ComplexSequence *]
 * Arg:                prodb [UNKN ] Undocumented argument [ProteinDB *]
 * Arg:        return_status [WRITE] return_status of the load [int *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexSequence *]
 *
 */
ComplexSequence * bp_sw_reload_ProteinDB(ComplexSequence * last,ProteinDB * prodb,int * return_status);
#define reload_ProteinDB bp_sw_reload_ProteinDB


/* Function:  close_ProteinDB(cs,prodb)
 *
 * Descrip:    top level function which closes the protein database
 *
 *
 * Arg:           cs [UNKN ] last complex sequence  [ComplexSequence *]
 * Arg:        prodb [UNKN ] protein database [ProteinDB *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_close_ProteinDB(ComplexSequence * cs,ProteinDB * prodb) ;
#define close_ProteinDB bp_sw_close_ProteinDB


/* Function:  new_ProteinDB_from_single_seq(seq)
 *
 * Descrip:    To make a new protein database
 *             from a single Sequence with default amino acid mapping
 *
 *
 * Arg:        seq [UNKN ] sequence which as placed into ProteinDB structure. [Sequence *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_new_ProteinDB_from_single_seq(Sequence * seq);
#define new_ProteinDB_from_single_seq bp_sw_new_ProteinDB_from_single_seq


/* Function:  new_ProteinDB_from_single_cseq(cs)
 *
 * Descrip:    To make a new protein database
 *             from a single ComplexSequence
 *
 *
 * Arg:        cs [UNKN ] complex sequence which is held. [ComplexSequence *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_new_ProteinDB_from_single_cseq(ComplexSequence * cs);
#define new_ProteinDB_from_single_cseq bp_sw_new_ProteinDB_from_single_cseq


/* Function:  single_fasta_ProteinDB(filename)
 *
 * Descrip:    pre-packed single fasta protein database
 *
 *
 *
 * Arg:        filename [UNKN ] name of fasta file [char *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_single_fasta_ProteinDB(char * filename);
#define single_fasta_ProteinDB bp_sw_single_fasta_ProteinDB


/* Function:  new_ProteinDB(seqdb,cses)
 *
 * Descrip:    To make a new protein database
 *
 *
 * Arg:        seqdb [UNKN ] sequence database [SequenceDB *]
 * Arg:         cses [UNKN ] protein evaluation set [ComplexSequenceEvalSet *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_new_ProteinDB(SequenceDB * seqdb,ComplexSequenceEvalSet * cses);
#define new_ProteinDB bp_sw_new_ProteinDB


/* Function:  hard_link_ProteinDB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [ProteinDB *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_hard_link_ProteinDB(ProteinDB * obj);
#define hard_link_ProteinDB bp_sw_hard_link_ProteinDB


/* Function:  ProteinDB_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_ProteinDB_alloc(void);
#define ProteinDB_alloc bp_sw_ProteinDB_alloc


/* Function:  free_ProteinDB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [ProteinDB *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinDB *]
 *
 */
ProteinDB * bp_sw_free_ProteinDB(ProteinDB * obj);
#define free_ProteinDB bp_sw_free_ProteinDB


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_replace_single_ProteinDB(ProteinDB * obj,ComplexSequence * single);
#define replace_single_ProteinDB bp_sw_replace_single_ProteinDB
boolean bp_sw_replace_sdb_ProteinDB(ProteinDB * obj,SequenceDB * sdb);
#define replace_sdb_ProteinDB bp_sw_replace_sdb_ProteinDB
boolean bp_sw_access_is_single_seq_ProteinDB(ProteinDB * obj);
#define access_is_single_seq_ProteinDB bp_sw_access_is_single_seq_ProteinDB
SequenceDB * bp_sw_access_sdb_ProteinDB(ProteinDB * obj);
#define access_sdb_ProteinDB bp_sw_access_sdb_ProteinDB
ComplexSequence * bp_sw_access_single_ProteinDB(ProteinDB * obj);
#define access_single_ProteinDB bp_sw_access_single_ProteinDB
boolean bp_sw_replace_cses_ProteinDB(ProteinDB * obj,ComplexSequenceEvalSet * cses);
#define replace_cses_ProteinDB bp_sw_replace_cses_ProteinDB
boolean bp_sw_replace_is_single_seq_ProteinDB(ProteinDB * obj,boolean is_single_seq);
#define replace_is_single_seq_ProteinDB bp_sw_replace_is_single_seq_ProteinDB
ComplexSequenceEvalSet * bp_sw_access_cses_ProteinDB(ProteinDB * obj);
#define access_cses_ProteinDB bp_sw_access_cses_ProteinDB

#ifdef _cplusplus
}
#endif

#endif
