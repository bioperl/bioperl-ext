#ifndef DYNAMITEalnconvertHEADERFILE
#define DYNAMITEalnconvertHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "dyna.h"

#define AlnConvertSetLISTLENGTH 64

struct bp_sw_AlnConvertUnit {  
    int dynamite_hard_link;  
    int state1;  
    int state2;  
    int offi;    
    int offj;    
    char * label1;   
    char * label2;   
    boolean can_collapse;    
    boolean is_from_special;     
    } ;  
/* AlnConvertUnit defined */ 
#ifndef DYNAMITE_DEFINED_AlnConvertUnit
typedef struct bp_sw_AlnConvertUnit bp_sw_AlnConvertUnit;
#define AlnConvertUnit bp_sw_AlnConvertUnit
#define DYNAMITE_DEFINED_AlnConvertUnit
#endif


struct bp_sw_AlnConvertSet {  
    int dynamite_hard_link;  
    AlnConvertUnit ** acu;   
    int len;/* len for above acu  */ 
    int maxlen; /* maxlen for above acu */ 
    } ;  
/* AlnConvertSet defined */ 
#ifndef DYNAMITE_DEFINED_AlnConvertSet
typedef struct bp_sw_AlnConvertSet bp_sw_AlnConvertSet;
#define AlnConvertSet bp_sw_AlnConvertSet
#define DYNAMITE_DEFINED_AlnConvertSet
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  add_collapse_label_AlnConvertSet(acs,label1,label2)
 *
 * Descrip:    Not a sensible function. Makes the convert with label1 and label2
 *             a collapsable label
 *
 *
 * Arg:           acs [UNKN ] Undocumented argument [AlnConvertSet *]
 * Arg:        label1 [UNKN ] Undocumented argument [char *]
 * Arg:        label2 [UNKN ] Undocumented argument [char *]
 *
 */
void bp_sw_add_collapse_label_AlnConvertSet(AlnConvertSet * acs,char * label1,char * label2);
#define add_collapse_label_AlnConvertSet bp_sw_add_collapse_label_AlnConvertSet


/* Function:  AlnBlock_from_PackAln(acs,*pal)
 *
 * Descrip:    Takes a AlnConvertSet (acs) and a PackAln (pal) 
 *             and blindly converts it to AlnBlock. This is really
 *             an internal for a dynamite produced dy function
 *
 *
 * Arg:         acs [UNKN ] Undocumented argument [AlnConvertSet *]
 * Arg:        *pal [UNKN ] Undocumented argument [PackAln]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock  *]
 *
 */
AlnBlock  * bp_sw_AlnBlock_from_PackAln(AlnConvertSet * acs,PackAln *pal);
#define AlnBlock_from_PackAln bp_sw_AlnBlock_from_PackAln


/* Function:  hard_link_AlnConvertUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnConvertUnit *]
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertUnit *]
 *
 */
AlnConvertUnit * bp_sw_hard_link_AlnConvertUnit(AlnConvertUnit * obj);
#define hard_link_AlnConvertUnit bp_sw_hard_link_AlnConvertUnit


/* Function:  AlnConvertUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertUnit *]
 *
 */
AlnConvertUnit * bp_sw_AlnConvertUnit_alloc(void);
#define AlnConvertUnit_alloc bp_sw_AlnConvertUnit_alloc


/* Function:  free_AlnConvertUnit(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnConvertUnit *]
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertUnit *]
 *
 */
AlnConvertUnit * bp_sw_free_AlnConvertUnit(AlnConvertUnit * obj);
#define free_AlnConvertUnit bp_sw_free_AlnConvertUnit


/* Function:  add_AlnConvertSet(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [AlnConvertSet *]
 * Arg:        add [OWNER] Object to add to the list [AlnConvertUnit *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnConvertSet(AlnConvertSet * obj,AlnConvertUnit * add);
#define add_AlnConvertSet bp_sw_add_AlnConvertSet


/* Function:  flush_AlnConvertSet(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [AlnConvertSet *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnConvertSet(AlnConvertSet * obj);
#define flush_AlnConvertSet bp_sw_flush_AlnConvertSet


/* Function:  AlnConvertSet_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnConvertSet_alloc_len(AlnConvertSetLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertSet *]
 *
 */
AlnConvertSet * bp_sw_AlnConvertSet_alloc_std(void);
#define AlnConvertSet_alloc_std bp_sw_AlnConvertSet_alloc_std


/* Function:  AlnConvertSet_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertSet *]
 *
 */
AlnConvertSet * bp_sw_AlnConvertSet_alloc_len(int len);
#define AlnConvertSet_alloc_len bp_sw_AlnConvertSet_alloc_len


/* Function:  hard_link_AlnConvertSet(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnConvertSet *]
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertSet *]
 *
 */
AlnConvertSet * bp_sw_hard_link_AlnConvertSet(AlnConvertSet * obj);
#define hard_link_AlnConvertSet bp_sw_hard_link_AlnConvertSet


/* Function:  AlnConvertSet_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertSet *]
 *
 */
AlnConvertSet * bp_sw_AlnConvertSet_alloc(void);
#define AlnConvertSet_alloc bp_sw_AlnConvertSet_alloc


/* Function:  free_AlnConvertSet(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnConvertSet *]
 *
 * Return [UNKN ]  Undocumented return value [AlnConvertSet *]
 *
 */
AlnConvertSet * bp_sw_free_AlnConvertSet(AlnConvertSet * obj);
#define free_AlnConvertSet bp_sw_free_AlnConvertSet


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
AlnColumn * bp_sw_AlnColumn_from_Pal_Convert(AlnConvertSet * acs,PackAlnUnit * before,PackAlnUnit * after,AlnColumn * prev,boolean * was_collapsed);
#define AlnColumn_from_Pal_Convert bp_sw_AlnColumn_from_Pal_Convert
AlnConvertUnit * bp_sw_AlnConvertUnit_from_state_and_offset(AlnConvertSet * acs,int state1,int state2,int offi,int offj);
#define AlnConvertUnit_from_state_and_offset bp_sw_AlnConvertUnit_from_state_and_offset
void bp_sw_swap_AlnConvertSet(AlnConvertUnit ** list,int i,int j) ;
#define swap_AlnConvertSet bp_sw_swap_AlnConvertSet
void bp_sw_qsort_AlnConvertSet(AlnConvertUnit ** list,int left,int right,int (*comp)(AlnConvertUnit * ,AlnConvertUnit * ));
#define qsort_AlnConvertSet bp_sw_qsort_AlnConvertSet
void bp_sw_sort_AlnConvertSet(AlnConvertSet * obj,int (*comp)(AlnConvertUnit *, AlnConvertUnit *));
#define sort_AlnConvertSet bp_sw_sort_AlnConvertSet
boolean bp_sw_expand_AlnConvertSet(AlnConvertSet * obj,int len);
#define expand_AlnConvertSet bp_sw_expand_AlnConvertSet

#ifdef _cplusplus
}
#endif

#endif
