#ifdef _cplusplus
extern "C" {
#endif
#include "wisememman.h"



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
# line 16 "wisememman.dy"
void * ckalloc(size_t bytes)
{
  register void *ret;
  extern void *calloc (size_t nelem, size_t elsize);
	
  if( (ret = calloc(bytes, sizeof(char))) == NULL) {
    warn("Out of memory, on asking for %d bytes\n",bytes);
    return NULL; /*** for the moment, could fail here ***/
  } else
    return ret;	
}

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
# line 31 "wisememman.dy"
void * ckcalloc(int len,size_t bytes)
{
	return ckalloc(len*bytes);
}

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
# line 39 "wisememman.dy"
void * ckrealloc(void *ptr, size_t bytes)
{
  register void *ret;
  extern void *realloc (void *ptr, size_t size);

  if (ptr == NULL) {	
    warn("Bad call to ckrealloc, NULL pointer\n");
    return NULL;
  }
  else if( (ret = realloc(ptr, bytes)) == NULL) {
    warn("Out of memory, trying to realloc %d bytes\n",bytes);
    return NULL;
  }
  else
    return ret;	
}

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
# line 59 "wisememman.dy"
void * ckfree(void *ptr)
{

  if (ptr == NULL)
    warn("Bad call to ckfree - NULL pointer\n");
  else {
    free(ptr);
    ptr = NULL;
  }
  return ptr;
}





# line 96 "wisememman.c"

#ifdef _cplusplus
}
#endif
