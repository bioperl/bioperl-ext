#ifndef DYNAMITEwiseerrorHEADERFILE
#define DYNAMITEwiseerrorHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif

#include "wisebase.h"



typedef int Flag;

#define MAXERROR 256
#define MAXERRORCALL 32
#define MAXMSGSTACKERROR 64

/* flags on errors */
#define ERRORUSE      1
#define ERRORTOSTDERR 2
#define ERRORTOLOG    4
#define ERRORTOCALL   8
#define LONGERROR     16 /* not used */


/* types of error */
#define FATAL    1
#define WARNING  2
#define PEDANTIC 4 /* deprecated */
#define INFO     8
#define REPORT   16

#define erroroff(type)       error_flag_off(type,ERRORUSE)
#define erroron(type)        error_flag_on (type,ERRORUSE)
#define errorcallon(type)    error_flag_on (type,ERRORTOCALL)
#define errorcalloff(type)   error_flag_off(type,ERRORTOCALL)
#define errorstderron(type)  error_flag_on (type,ERRORTOSTDERR)
#define errorstderroff(type) error_flag_off(type,ERRORTOSTDERR)
#define errorlogon(type)     error_flag_on (type,ERRORTOLOG)
#define errorlogoff(type)    error_flag_off(type,ERRORTOLOG)



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  push_errormsg_stack_call(ecall)
 *
 * Descrip:    This adds a function call for people who want
 *             to register error handling functions
 *
 *             Probably best wrapped by a separate function
 *
 *
 * Arg:        ecall [UNKN ] Undocumented argument [NullString]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_push_errormsg_stack_call( char * (*ecall)(void));
#define push_errormsg_stack_call bp_sw_push_errormsg_stack_call


/* Function:  pop_errormsg_stack(void)
 *
 * Descrip:    This removes a error message from the stack
 *
 *
 *
 */
void bp_sw_pop_errormsg_stack(void);
#define pop_errormsg_stack bp_sw_pop_errormsg_stack


/* Function:  add_log_filename(filename)
 *
 * Descrip:    Opens filename as the log file. 
 *
 *
 * Arg:        filename [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_log_filename(char * filename);
#define add_log_filename bp_sw_add_log_filename


/* Function:  error_off(type)
 *
 * Descrip:    Really for the API. Wraps some
 *             of the error concepts..
 *
 *
 * Arg:        type [UNKN ] Undocumented argument [int]
 *
 */
void bp_sw_error_off(int type);
#define error_off bp_sw_error_off


/* Function:  error_on(type)
 *
 * Descrip:    Really for the API. Wraps some
 *             of the error concepts..
 *
 *
 * Arg:        type [UNKN ] Undocumented argument [int]
 *
 */
void bp_sw_error_on(int type);
#define error_on bp_sw_error_on


/* Function:  error_flag_on(type,f)
 *
 * Descrip:    Turns on the particular type of error flag
 *             (eg, STDERR etc). 
 *
 *
 * Arg:        type [UNKN ] Undocumented argument [int]
 * Arg:           f [UNKN ] Undocumented argument [Flag]
 *
 */
void bp_sw_error_flag_on(int type,Flag f);
#define error_flag_on bp_sw_error_flag_on


/* Function:  error_flag_off(type,f)
 *
 * Descrip:    Turns off the particular type of error flag
 *             (eg, STDERR etc). 
 *
 *
 * Arg:        type [UNKN ] Undocumented argument [int]
 * Arg:           f [UNKN ] Undocumented argument [Flag]
 *
 */
void bp_sw_error_flag_off(int type,Flag f);
#define error_flag_off bp_sw_error_flag_off


/* Function:  catch_errors(catch)
 *
 * Descrip:    This is a wrapper for the error handling
 *             system. It does the following things
 *
 *              Sets function as the function to process errors
 *
 *              Switches the INFO,ERROR and FATAL flags off on STDERR
 *             and on to ERROR CALL.
 *
 *
 *
 * Arg:        catch [UNKN ] Undocumented argument [NullString]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_catch_errors(void (*catch)(char *,int));
#define catch_errors bp_sw_catch_errors


/* Function:  stop_catching_errors(void)
 *
 * Descrip:    Switches off error catching,
 *             putting flags back on to STDERR
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_stop_catching_errors(void);
#define stop_catching_errors bp_sw_stop_catching_errors


/* Function:  push_error_call()
 *
 * Descrip:    Registers this function for dealing with errors
 *
 *             Try to use catch_errors instead
 *
 *
 *
 * Arg:         [UNKN ] Undocumented argument [NullString]
 *
 */
void bp_sw_push_error_call(void (* func)(char *,int));
#define push_error_call bp_sw_push_error_call


/* Function:  pop_error_call(void)
 *
 * Descrip:    Discards current function for dealing with errors
 *
 *
 *
 */
void bp_sw_pop_error_call(void);
#define pop_error_call bp_sw_pop_error_call


/* Function:  type_to_error(type)
 *
 * Descrip:    Turns int error types to Names
 *             for display purposes.
 *
 *
 * Arg:        type [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_type_to_error(int type);
#define type_to_error bp_sw_type_to_error


/* Function:  info(msg,)
 *
 * Descrip:    Produces a 'info' error message.
 *
 *
 * Arg:        msg [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_info(char * msg, ...);
#define info bp_sw_info


/* Function:  warn(msg,)
 *
 * Descrip:    Produces a 'warn' error message.
 *
 *
 * Arg:        msg [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_warn(char * msg, ...);
#define warn bp_sw_warn


/* Function:  fatal(msg,)
 *
 * Descrip:    Produces a 'fatal' error message.
 *
 *
 * Arg:        msg [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_fatal(char * msg, ...);
#define fatal bp_sw_fatal


/* Function:  log_full_error(type,location,msg,)
 *
 * Descrip:    Deprecated
 *
 *             produces any of the error types
 *
 *
 * Arg:            type [UNKN ] Undocumented argument [int]
 * Arg:        location [UNKN ] Undocumented argument [int]
 * Arg:             msg [UNKN ] Undocumented argument [char *]
 * Arg:                 [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_log_full_error(int type,int location,char * msg, ...);
#define log_full_error bp_sw_log_full_error


/* Function:  start_reporting(msg,)
 *
 * Descrip:    Starts a % reporting run. This is the header message
 *
 *
 * Arg:        msg [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 */
void bp_sw_start_reporting(char * msg,...);
#define start_reporting bp_sw_start_reporting


/* Function:  stop_reporting(void)
 *
 * Descrip:    Stops a % reporting run. 
 *
 *
 *
 */
void bp_sw_stop_reporting(void);
#define stop_reporting bp_sw_stop_reporting


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_push_errormsg_stack(char * msg, ...);
#define push_errormsg_stack bp_sw_push_errormsg_stack
void bp_sw_show_message_stack(FILE * ofp);
#define show_message_stack bp_sw_show_message_stack
void bp_sw_add_log_file(FILE * ofp);
#define add_log_file bp_sw_add_log_file
void bp_sw_show_error(Flag flag,char * othermsg,int type);
#define show_error bp_sw_show_error

#ifdef _cplusplus
}
#endif

#endif
