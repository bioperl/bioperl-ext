#ifndef DYNAMITEalnrangeHEADERFILE
#define DYNAMITEalnrangeHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "dyna.h"

#define AlnRangeSetLISTLENGTH 64
struct bp_sw_AlnRange {  
    int dynamite_hard_link;  
    int starti;  
    int startj;  
    int startstate;  
    int stopi;   
    int stopj;   
    int stopstate;   
    int startscore;  
    int stopscore;   
    } ;  
/* AlnRange defined */ 
#ifndef DYNAMITE_DEFINED_AlnRange
typedef struct bp_sw_AlnRange bp_sw_AlnRange;
#define AlnRange bp_sw_AlnRange
#define DYNAMITE_DEFINED_AlnRange
#endif


struct bp_sw_AlnRangeSet {  
    int dynamite_hard_link;  
    int score;  /*  over complete alignment */ 
    AlnRange ** alr;     
    int len;/* len for above alr  */ 
    int maxlen; /* maxlen for above alr */ 
    } ;  
/* AlnRangeSet defined */ 
#ifndef DYNAMITE_DEFINED_AlnRangeSet
typedef struct bp_sw_AlnRangeSet bp_sw_AlnRangeSet;
#define AlnRangeSet bp_sw_AlnRangeSet
#define DYNAMITE_DEFINED_AlnRangeSet
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  show_AlnRangeSet(ars,ofp)
 *
 * Descrip:    shows AlnRangeSet in vaguely human form
 *
 *
 * Arg:        ars [UNKN ] Undocumented argument [AlnRangeSet *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_AlnRangeSet(AlnRangeSet * ars,FILE * ofp);
#define show_AlnRangeSet bp_sw_show_AlnRangeSet


/* Function:  show_AlnRange(alr,ofp)
 *
 * Descrip:    shows AlnRange in vaguely human form
 *
 *
 * Arg:        alr [UNKN ] Undocumented argument [AlnRange *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_AlnRange(AlnRange * alr,FILE * ofp);
#define show_AlnRange bp_sw_show_AlnRange


/* Function:  sort_AlnRangeSet_by_start(ars)
 *
 * Descrip:    Sorts an AlnRangeSet by start of each AlnRange
 *
 *
 * Arg:        ars [UNKN ] Undocumented argument [AlnRangeSet *]
 *
 */
void bp_sw_sort_AlnRangeSet_by_start(AlnRangeSet * ars);
#define sort_AlnRangeSet_by_start bp_sw_sort_AlnRangeSet_by_start


/* Function:  hard_link_AlnRange(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnRange *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRange *]
 *
 */
AlnRange * bp_sw_hard_link_AlnRange(AlnRange * obj);
#define hard_link_AlnRange bp_sw_hard_link_AlnRange


/* Function:  AlnRange_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnRange *]
 *
 */
AlnRange * bp_sw_AlnRange_alloc(void);
#define AlnRange_alloc bp_sw_AlnRange_alloc


/* Function:  free_AlnRange(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnRange *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRange *]
 *
 */
AlnRange * bp_sw_free_AlnRange(AlnRange * obj);
#define free_AlnRange bp_sw_free_AlnRange


/* Function:  add_AlnRangeSet(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [AlnRangeSet *]
 * Arg:        add [OWNER] Object to add to the list [AlnRange *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnRangeSet(AlnRangeSet * obj,AlnRange * add);
#define add_AlnRangeSet bp_sw_add_AlnRangeSet


/* Function:  flush_AlnRangeSet(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [AlnRangeSet *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnRangeSet(AlnRangeSet * obj);
#define flush_AlnRangeSet bp_sw_flush_AlnRangeSet


/* Function:  AlnRangeSet_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnRangeSet_alloc_len(AlnRangeSetLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_alloc_std(void);
#define AlnRangeSet_alloc_std bp_sw_AlnRangeSet_alloc_std


/* Function:  AlnRangeSet_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_alloc_len(int len);
#define AlnRangeSet_alloc_len bp_sw_AlnRangeSet_alloc_len


/* Function:  hard_link_AlnRangeSet(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnRangeSet *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_hard_link_AlnRangeSet(AlnRangeSet * obj);
#define hard_link_AlnRangeSet bp_sw_hard_link_AlnRangeSet


/* Function:  AlnRangeSet_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_alloc(void);
#define AlnRangeSet_alloc bp_sw_AlnRangeSet_alloc


/* Function:  free_AlnRangeSet(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnRangeSet *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_free_AlnRangeSet(AlnRangeSet * obj);
#define free_AlnRangeSet bp_sw_free_AlnRangeSet


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_replace_score_AlnRangeSet(AlnRangeSet * obj,int score);
#define replace_score_AlnRangeSet bp_sw_replace_score_AlnRangeSet
int bp_sw_access_startj_AlnRange(AlnRange * obj);
#define access_startj_AlnRange bp_sw_access_startj_AlnRange
boolean bp_sw_replace_startstate_AlnRange(AlnRange * obj,int startstate);
#define replace_startstate_AlnRange bp_sw_replace_startstate_AlnRange
int bp_sw_access_startstate_AlnRange(AlnRange * obj);
#define access_startstate_AlnRange bp_sw_access_startstate_AlnRange
boolean bp_sw_replace_stopscore_AlnRange(AlnRange * obj,int stopscore);
#define replace_stopscore_AlnRange bp_sw_replace_stopscore_AlnRange
boolean bp_sw_replace_stopi_AlnRange(AlnRange * obj,int stopi);
#define replace_stopi_AlnRange bp_sw_replace_stopi_AlnRange
AlnRange * bp_sw_access_alr_AlnRangeSet(AlnRangeSet * obj,int i);
#define access_alr_AlnRangeSet bp_sw_access_alr_AlnRangeSet
int bp_sw_access_stopi_AlnRange(AlnRange * obj);
#define access_stopi_AlnRange bp_sw_access_stopi_AlnRange
boolean bp_sw_replace_starti_AlnRange(AlnRange * obj,int starti);
#define replace_starti_AlnRange bp_sw_replace_starti_AlnRange
boolean bp_sw_replace_stopj_AlnRange(AlnRange * obj,int stopj);
#define replace_stopj_AlnRange bp_sw_replace_stopj_AlnRange
boolean bp_sw_replace_startj_AlnRange(AlnRange * obj,int startj);
#define replace_startj_AlnRange bp_sw_replace_startj_AlnRange
int bp_sw_access_stopj_AlnRange(AlnRange * obj);
#define access_stopj_AlnRange bp_sw_access_stopj_AlnRange
int bp_sw_access_score_AlnRangeSet(AlnRangeSet * obj);
#define access_score_AlnRangeSet bp_sw_access_score_AlnRangeSet
boolean bp_sw_replace_stopstate_AlnRange(AlnRange * obj,int stopstate);
#define replace_stopstate_AlnRange bp_sw_replace_stopstate_AlnRange
int bp_sw_access_starti_AlnRange(AlnRange * obj);
#define access_starti_AlnRange bp_sw_access_starti_AlnRange
int bp_sw_access_stopstate_AlnRange(AlnRange * obj);
#define access_stopstate_AlnRange bp_sw_access_stopstate_AlnRange
int bp_sw_length_alr_AlnRangeSet(AlnRangeSet * obj);
#define length_alr_AlnRangeSet bp_sw_length_alr_AlnRangeSet
boolean bp_sw_replace_startscore_AlnRange(AlnRange * obj,int startscore);
#define replace_startscore_AlnRange bp_sw_replace_startscore_AlnRange
int bp_sw_access_stopscore_AlnRange(AlnRange * obj);
#define access_stopscore_AlnRange bp_sw_access_stopscore_AlnRange
int bp_sw_access_startscore_AlnRange(AlnRange * obj);
#define access_startscore_AlnRange bp_sw_access_startscore_AlnRange
int bp_sw_compare_AlnRange_start(AlnRange * one,AlnRange * two);
#define compare_AlnRange_start bp_sw_compare_AlnRange_start
void bp_sw_swap_AlnRangeSet(AlnRange ** list,int i,int j) ;
#define swap_AlnRangeSet bp_sw_swap_AlnRangeSet
void bp_sw_qsort_AlnRangeSet(AlnRange ** list,int left,int right,int (*comp)(AlnRange * ,AlnRange * ));
#define qsort_AlnRangeSet bp_sw_qsort_AlnRangeSet
void bp_sw_sort_AlnRangeSet(AlnRangeSet * obj,int (*comp)(AlnRange *, AlnRange *));
#define sort_AlnRangeSet bp_sw_sort_AlnRangeSet
boolean bp_sw_expand_AlnRangeSet(AlnRangeSet * obj,int len);
#define expand_AlnRangeSet bp_sw_expand_AlnRangeSet

#ifdef _cplusplus
}
#endif

#endif
