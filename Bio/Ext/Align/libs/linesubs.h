#ifndef DYNAMITElinesubsHEADERFILE
#define DYNAMITElinesubsHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"


 typedef struct {
	char * key;
	char * replace;
	} KeyandReplace;



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



  /* Unplaced functions */
  /* There has been no indication of the use of these functions */
void bp_sw_scan_and_replace(KeyandReplace * kr);
#define scan_and_replace bp_sw_scan_and_replace
char * bp_sw_scan_and_replace_line(char * line);
#define scan_and_replace_line bp_sw_scan_and_replace_line
boolean bp_sw_push_scan_and_replace_pair(char * key,char * replace);
#define push_scan_and_replace_pair bp_sw_push_scan_and_replace_pair
boolean bp_sw_pop_scan_and_replace_pair(void);
#define pop_scan_and_replace_pair bp_sw_pop_scan_and_replace_pair
void bp_sw_flush_scan_and_replace(void);
#define flush_scan_and_replace bp_sw_flush_scan_and_replace
void bp_sw_read_plain_scan_and_replace(char * filename);
#define read_plain_scan_and_replace bp_sw_read_plain_scan_and_replace
void bp_sw_read_scan_and_replace_file(FILE * ifp,char * endstring);
#define read_scan_and_replace_file bp_sw_read_scan_and_replace_file


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/

#ifdef _cplusplus
}
#endif

#endif
