#ifndef DYNAMITEwisememmanHEADERFILE
#define DYNAMITEwisememmanHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  ckalloc(bytes)
 *
 * Descrip:    Tries to alloc bytes of memory. Posts
 *             to warn if it fails
 *
 *
 * Arg:        bytes [UNKN ] Undocumented argument [size_t]
 *
 * Return [UNKN ]  Undocumented return value [void *]
 *
 */
void * bp_sw_ckalloc(size_t bytes);
#define ckalloc bp_sw_ckalloc


/* Function:  ckcalloc(len,bytes)
 *
 * Descrip:    calloc equivalent
 *
 *
 * Arg:          len [UNKN ] Undocumented argument [int]
 * Arg:        bytes [UNKN ] Undocumented argument [size_t]
 *
 * Return [UNKN ]  Undocumented return value [void *]
 *
 */
void * bp_sw_ckcalloc(int len,size_t bytes);
#define ckcalloc bp_sw_ckcalloc


/* Function:  ckrealloc(*ptr,bytes)
 *
 * Descrip:    realloc equivalent
 *
 *
 * Arg:         *ptr [UNKN ] Undocumented argument [void]
 * Arg:        bytes [UNKN ] Undocumented argument [size_t]
 *
 * Return [UNKN ]  Undocumented return value [void *]
 *
 */
void * bp_sw_ckrealloc(void *ptr, size_t bytes);
#define ckrealloc bp_sw_ckrealloc


/* Function:  ckfree(*ptr)
 *
 * Descrip:    free equivalent
 *
 *
 * Arg:        *ptr [UNKN ] Undocumented argument [void]
 *
 * Return [UNKN ]  Undocumented return value [void *]
 *
 */
void * bp_sw_ckfree(void *ptr);
#define ckfree bp_sw_ckfree


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
