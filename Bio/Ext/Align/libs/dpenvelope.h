#ifndef DYNAMITEdpenvelopeHEADERFILE
#define DYNAMITEdpenvelopeHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"

typedef enum dpenvelope_type {
  DPENV_RECT = 0,
  DPENV_DIAG
} dpenv_type;

#define DPEnvelopeLISTLENGTH 32
struct bp_sw_DPUnit {  
    int dynamite_hard_link;  
    int type;    
    int starti;  
    int startj;  
    int height; /*  for diagonal units */ 
    int length; /*  for diagonal units */ 
    } ;  
/* DPUnit defined */ 
#ifndef DYNAMITE_DEFINED_DPUnit
typedef struct bp_sw_DPUnit bp_sw_DPUnit;
#define DPUnit bp_sw_DPUnit
#define DYNAMITE_DEFINED_DPUnit
#endif


struct bp_sw_DPEnvelope {  
    int dynamite_hard_link;  
    DPUnit ** dpu;   
    int len;/* len for above dpu  */ 
    int maxlen; /* maxlen for above dpu */ 
    } ;  
/* DPEnvelope defined */ 
#ifndef DYNAMITE_DEFINED_DPEnvelope
typedef struct bp_sw_DPEnvelope bp_sw_DPEnvelope;
#define DPEnvelope bp_sw_DPEnvelope
#define DYNAMITE_DEFINED_DPEnvelope
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  show_DPEnvelope(dpe,ofp)
 *
 * Descrip:    shows structure. useful for debugging
 *
 *
 * Arg:        dpe [UNKN ] Undocumented argument [DPEnvelope *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_DPEnvelope(DPEnvelope * dpe,FILE * ofp);
#define show_DPEnvelope bp_sw_show_DPEnvelope


/* Function:  is_in_DPEnvelope(dpe,i,j)
 *
 * Descrip:    Tests whether this i,j position is allowed in the
 *             DPEnvelope
 *
 *
 * Arg:        dpe [UNKN ] Undocumented argument [DPEnvelope *]
 * Arg:          i [UNKN ] Undocumented argument [int]
 * Arg:          j [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_is_in_DPEnvelope(DPEnvelope * dpe,int i,int j);
#define is_in_DPEnvelope bp_sw_is_in_DPEnvelope


/* Function:  prepare_DPEnvelope(dpe)
 *
 * Descrip:    Should run this before using the DPEnvelope
 *
 *
 * Arg:        dpe [UNKN ] Undocumented argument [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_prepare_DPEnvelope(DPEnvelope * dpe);
#define prepare_DPEnvelope bp_sw_prepare_DPEnvelope


/* Function:  sort_DPEnvelope_by_startj(dpe)
 *
 * Descrip:    Sorts by startj
 *
 *
 * Arg:        dpe [UNKN ] Undocumented argument [DPEnvelope *]
 *
 */
void bp_sw_sort_DPEnvelope_by_startj(DPEnvelope * dpe);
#define sort_DPEnvelope_by_startj bp_sw_sort_DPEnvelope_by_startj


/* Function:  hard_link_DPUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [DPUnit *]
 *
 * Return [UNKN ]  Undocumented return value [DPUnit *]
 *
 */
DPUnit * bp_sw_hard_link_DPUnit(DPUnit * obj);
#define hard_link_DPUnit bp_sw_hard_link_DPUnit


/* Function:  DPUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DPUnit *]
 *
 */
DPUnit * bp_sw_DPUnit_alloc(void);
#define DPUnit_alloc bp_sw_DPUnit_alloc


/* Function:  free_DPUnit(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [DPUnit *]
 *
 * Return [UNKN ]  Undocumented return value [DPUnit *]
 *
 */
DPUnit * bp_sw_free_DPUnit(DPUnit * obj);
#define free_DPUnit bp_sw_free_DPUnit


/* Function:  add_DPEnvelope(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [DPEnvelope *]
 * Arg:        add [OWNER] Object to add to the list [DPUnit *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_DPEnvelope(DPEnvelope * obj,DPUnit * add);
#define add_DPEnvelope bp_sw_add_DPEnvelope


/* Function:  flush_DPEnvelope(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_DPEnvelope(DPEnvelope * obj);
#define flush_DPEnvelope bp_sw_flush_DPEnvelope


/* Function:  DPEnvelope_alloc_std(void)
 *
 * Descrip:    Equivalent to DPEnvelope_alloc_len(DPEnvelopeLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DPEnvelope *]
 *
 */
DPEnvelope * bp_sw_DPEnvelope_alloc_std(void);
#define DPEnvelope_alloc_std bp_sw_DPEnvelope_alloc_std


/* Function:  DPEnvelope_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [DPEnvelope *]
 *
 */
DPEnvelope * bp_sw_DPEnvelope_alloc_len(int len);
#define DPEnvelope_alloc_len bp_sw_DPEnvelope_alloc_len


/* Function:  hard_link_DPEnvelope(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [DPEnvelope *]
 *
 */
DPEnvelope * bp_sw_hard_link_DPEnvelope(DPEnvelope * obj);
#define hard_link_DPEnvelope bp_sw_hard_link_DPEnvelope


/* Function:  DPEnvelope_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DPEnvelope *]
 *
 */
DPEnvelope * bp_sw_DPEnvelope_alloc(void);
#define DPEnvelope_alloc bp_sw_DPEnvelope_alloc


/* Function:  free_DPEnvelope(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [DPEnvelope *]
 *
 */
DPEnvelope * bp_sw_free_DPEnvelope(DPEnvelope * obj);
#define free_DPEnvelope bp_sw_free_DPEnvelope


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
int bp_sw_compare_DPUnit_startj(DPUnit * one,DPUnit * two);
#define compare_DPUnit_startj bp_sw_compare_DPUnit_startj
void bp_sw_swap_DPEnvelope(DPUnit ** list,int i,int j) ;
#define swap_DPEnvelope bp_sw_swap_DPEnvelope
void bp_sw_qsort_DPEnvelope(DPUnit ** list,int left,int right,int (*comp)(DPUnit * ,DPUnit * ));
#define qsort_DPEnvelope bp_sw_qsort_DPEnvelope
void bp_sw_sort_DPEnvelope(DPEnvelope * obj,int (*comp)(DPUnit *, DPUnit *));
#define sort_DPEnvelope bp_sw_sort_DPEnvelope
boolean bp_sw_expand_DPEnvelope(DPEnvelope * obj,int len);
#define expand_DPEnvelope bp_sw_expand_DPEnvelope

#ifdef _cplusplus
}
#endif

#endif
