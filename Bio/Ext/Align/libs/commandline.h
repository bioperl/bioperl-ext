#ifndef DYNAMITEcommandlineHEADERFILE
#define DYNAMITEcommandlineHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"








    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  strip_out_remaining_options_with_warning(argc,argv)
 *
 * Descrip:    This removes all remaining options, issuing warnings
 *             through warn
 *
 *
 * Arg:        argc [UNKN ] Undocumented argument [int *]
 * Arg:        argv [UNKN ] Undocumented argument [char **]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_strip_out_remaining_options_with_warning(int * argc,char ** argv);
#define strip_out_remaining_options_with_warning bp_sw_strip_out_remaining_options_with_warning


/* Function:  strip_out_boolean_argument(argc,argv,tag)
 *
 * Descrip:    This removes argument in tag from the commandline if there and
 *             returns TRUE
 *
 *             otherwise returns FALSE
 *
 *
 * Arg:        argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:        argv [UNKN ] argv from main declaration [char **]
 * Arg:         tag [READ ] -[string] argument to find [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_strip_out_boolean_argument(int * argc,char ** argv,char * tag);
#define strip_out_boolean_argument bp_sw_strip_out_boolean_argument


/* Function:  strip_out_assigned_argument(argc,argv,tag)
 *
 * Descrip:    This removes argument in tag from the commandline if there and
 *             returns the argument to it (in -tag arg - ie with a space).
 *
 *             otherwise returns NULL
 *
 *
 * Arg:        argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:        argv [UNKN ] argv from main declaration [char **]
 * Arg:         tag [READ ] -[string] argument to find [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_strip_out_assigned_argument(int * argc,char ** argv,char * tag);
#define strip_out_assigned_argument bp_sw_strip_out_assigned_argument


/* Function:  strip_out_integer_argument(argc,argv,tag,value)
 *
 * Descrip:    This removes argument in tag from the commandline if there, and
 *             looks at the argument as whether it is an int or not.
 *
 *             No tag - returns FALSE and leaves value alone
 *             Tag but no integer value - issues warning, returns FALSE
 *             tag but integer value    - sets value, returns true
 *
 *
 * Arg:         argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:         argv [UNKN ] argv from main declaration [char **]
 * Arg:          tag [READ ] -[string] argument to find [char *]
 * Arg:        value [WRITE] int pointer to write value to [int *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_strip_out_integer_argument(int * argc,char ** argv,char * tag,int * value);
#define strip_out_integer_argument bp_sw_strip_out_integer_argument


/* Function:  strip_out_float_argument(argc,argv,tag,value)
 *
 * Descrip:    This removes argument in tag from the commandline if there, and
 *             looks at the argument as whether it is a double or not.
 *
 *             No tag - returns FALSE and leaves value alone
 *             Tag but no integer value - issues warning, returns FALSE
 *             tag but integer value    - sets value, returns true
 *
 *
 * Arg:         argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:         argv [UNKN ] argv from main declaration [char **]
 * Arg:          tag [READ ] -[string] argument to find [char *]
 * Arg:        value [WRITE] double pointer to write value to [double *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_strip_out_float_argument(int * argc,char ** argv,char * tag,double * value);
#define strip_out_float_argument bp_sw_strip_out_float_argument


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
