#ifndef DYNAMITEsw_wrapHEADERFILE
#define DYNAMITEsw_wrapHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "proteinsw.h"




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  Align_strings_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most *stupidly* abstracted view of two sequences
 *             getting aligned, being two strings.
 *
 *             It would be much better if you used Sequence objects or Protein
 *             objects to carry the proteins.
 *
 *
 * Arg:         one [UNKN ] string of the first sequence [char *]
 * Arg:         two [UNKN ] string of the second sequence [char *]
 * Arg:        comp [UNKN ] Comparison Matrix [CompMat *]
 * Arg:         gap [UNKN ] gap penalty [int]
 * Arg:         ext [UNKN ] extension penalty [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_Align_strings_ProteinSmithWaterman(char * one,char * two,CompMat * comp,int gap,int ext);
#define Align_strings_ProteinSmithWaterman bp_sw_Align_strings_ProteinSmithWaterman


/* Function:  Align_Sequences_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This function is a mid-level abstraction of
 *             comparing two sequences, which could be
 *             generic types (eg DNA!). This is tested
 *             for and warnings are given but the alignment
 *             is still calculated. To prevent this test
 *             warning either make sure the Sequence types
 *             are set to PROTEIN or, better still, use the
 *             high level abstraction Align_Proteins_SmithWaterman
 *
 *             Otherwise this performs a standard smith waterman
 *             protein alignment...
 *
 *             To display the alignment use  write_pretty_seq_align
 *
 *
 * Arg:         one [READ ] First sequence to compare [Sequence *]
 * Arg:         two [READ ] Second sequecne to compare [Sequence *]
 * Arg:        comp [READ ] Comparison matrix to use [CompMat *]
 * Arg:         gap [UNKN ] gap penalty. Must be negative or 0 [int]
 * Arg:         ext [UNKN ] ext penalty. Must be negative or 0 [int]
 *
 * Return [OWNER]  new AlnBlock structure representing the alignment [AlnBlock *]
 *
 */
AlnBlock * bp_sw_Align_Sequences_ProteinSmithWaterman(Sequence * one,Sequence * two,CompMat * comp,int gap,int ext);
#define Align_Sequences_ProteinSmithWaterman bp_sw_Align_Sequences_ProteinSmithWaterman


/* Function:  Align_Proteins_SmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most correct way of aligning two Proteins,
 *             using Protein objects, which can be assummed to be
 *             proteins with no objections
 *
 *             To display the alignment use write_pretty_Protein_align
 *
 *
 *
 * Arg:         one [UNKN ] Protein to align [Protein *]
 * Arg:         two [UNKN ] Protein to align [Protein *]
 * Arg:        comp [UNKN ] Comparison Matrix [CompMat *]
 * Arg:         gap [UNKN ] gap penalty [int]
 * Arg:         ext [UNKN ] extension penalty [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_Align_Proteins_SmithWaterman(Protein * one,Protein * two,CompMat * comp,int gap,int ext);
#define Align_Proteins_SmithWaterman bp_sw_Align_Proteins_SmithWaterman


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/

#ifdef _cplusplus
}
#endif

#endif
