#ifdef _cplusplus
extern "C" {
#endif
#include "dynlibcross.h"


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
# line 21 "dynlibcross.dy"
Hscore * std_bits_Hscore(double cut_off_level,int report_stagger)
{
  Hscore * out;

  out = Hscore_alloc_std();
  out->his = new_Histogram(-1000,1000,100);
  out->score_level = cut_off_level;
  out->should_store = std_should_store_Hscore;
  out->score_to_his = std_score_to_his;
  out->report_level = report_stagger;

  return out;
}


/* Function:  std_should_store_Hscore(score,cutoff)
 *
 * Descrip:    This function is for the Hscore std constructor,
 *
 *
 * Arg:         score [UNKN ] Undocumented argument [int]
 * Arg:        cutoff [UNKN ] Undocumented argument [double]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
# line 40 "dynlibcross.dy"
boolean std_should_store_Hscore(int score,double cutoff)
{
  if( Score2Bits(score) > cutoff ) {
    return TRUE;
  }
  return FALSE;
}

/* Function:  std_score_to_his(score)
 *
 * Descrip:    This function is for the Hscore std constructor,
 *
 *
 * Arg:        score [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [float]
 *
 */
# line 52 "dynlibcross.dy"
float std_score_to_his(int score)
{
  return Score2Bits(score);
}
 
   



# line 70 "dynlibcross.c"

#ifdef _cplusplus
}
#endif
