#ifndef DYNAMITEwiseoverlayHEADERFILE
#define DYNAMITEwiseoverlayHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  start_overlay(over)
 *
 * Descrip:    actually starts on overlay system
 *             on the FILE*. Should really by stderr...
 *             nothing else makes sense.
 *
 *
 * Arg:        over [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_start_overlay(FILE * over);
#define start_overlay bp_sw_start_overlay


/* Function:  stop_overlay(void)
 *
 * Descrip:    finishes an overlay system by putting in a
 *             newline and clearing the static variables
 *
 *
 *
 */
void bp_sw_stop_overlay(void);
#define stop_overlay bp_sw_stop_overlay


/* Function:  print_overlay(msg,)
 *
 * Descrip:    Does the business. Deletes the previous
 *             message with \b and then prints the current
 *             one ontop. 
 *
 *             don't put in \n's otherwise this is going to 
 *             look yukky ;)
 *
 *
 * Arg:        msg [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_print_overlay(char * msg, ... );
#define print_overlay bp_sw_print_overlay


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
