#ifndef DYNAMITEdynlibcrossHEADERFILE
#define DYNAMITEdynlibcrossHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "dyna.h"





    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  std_bits_Hscore(cut_off_level,report_stagger)
 *
 * Descrip:    This gives you a standard Hscore 
 *             module with a cutoff in bits (assumming
 *             the score is being made from a standard
 *             Probability2Score type function).
 *
 *
 * Arg:         cut_off_level [UNKN ] Undocumented argument [double]
 * Arg:        report_stagger [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_std_bits_Hscore(double cut_off_level,int report_stagger);
#define std_bits_Hscore bp_sw_std_bits_Hscore


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_std_should_store_Hscore(int score,double cutoff);
#define std_should_store_Hscore bp_sw_std_should_store_Hscore
float bp_sw_std_score_to_his(int score);
#define std_score_to_his bp_sw_std_score_to_his

#ifdef _cplusplus
}
#endif

#endif
