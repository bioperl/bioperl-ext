#ifndef DYNAMITEpackalnHEADERFILE
#define DYNAMITEpackalnHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif

#include "wisebase.h"
#include "probability.h"


#define PackAlnLISTLENGTH 64

/* Object PackAlnUnit
 *
 * Descrip: Internal object for /PackAln:
 *        A single position of an alignment
 *        as the (i,j,state) triple
 *
 *
 */
struct bp_sw_PackAlnUnit {  
    int dynamite_hard_link;  
    int i;  /*  position in query  */ 
    int j;  /*  position in target */ 
    int state;  /*  state in FSM */ 
    int score;  /*  score of the transition that reached this state */ 
    } ;  
/* PackAlnUnit defined */ 
#ifndef DYNAMITE_DEFINED_PackAlnUnit
typedef struct bp_sw_PackAlnUnit bp_sw_PackAlnUnit;
#define PackAlnUnit bp_sw_PackAlnUnit
#define DYNAMITE_DEFINED_PackAlnUnit
#endif


/* Object PackAln
 *
 * Descrip: This is the lowest-level of representation
 *        of a DP alignment, being the list of 
 *        (i,j,state) triples taken through the
 *        DP matrix. The score for the transition to
 *        this point is held as well.
 *
 *        This object is very low level and often a
 *        much better choice for representation is
 *        in /AlnBlock objects 
 *
 *
 */
struct bp_sw_PackAln {  
    int dynamite_hard_link;  
    PackAlnUnit ** pau; /*  list of PackAlnUnits from start to end */ 
    int len;/* len for above pau  */ 
    int maxlen; /* maxlen for above pau */ 
    int score;  /*  score over the entire alignment */ 
    } ;  
/* PackAln defined */ 
#ifndef DYNAMITE_DEFINED_PackAln
typedef struct bp_sw_PackAln bp_sw_PackAln;
#define PackAln bp_sw_PackAln
#define DYNAMITE_DEFINED_PackAln
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  show_bits_and_cumlative_PackAln(pal,ofp)
 *
 * Descrip:    Shows packaln as: 
 *
 *             i,j,state,score,bits,cumlative-score,cumlative-bits
 *
 *             cumlative score and cumlative bits are useful sometimes
 *
 *
 * Arg:        pal [UNKN ] Undocumented argument [PackAln *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_bits_and_cumlative_PackAln(PackAln * pal,FILE * ofp);
#define show_bits_and_cumlative_PackAln bp_sw_show_bits_and_cumlative_PackAln


/* Function:  show_simple_PackAln(pal,ofp)
 *
 * Descrip:    shows packaln with a pretty verbose debugging 
 *             format
 *
 *
 * Arg:        pal [UNKN ] Undocumented argument [PackAln *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_simple_PackAln(PackAln * pal,FILE * ofp);
#define show_simple_PackAln bp_sw_show_simple_PackAln


/* Function:  show_text_PackAln(state_to_char,pal,ofp)
 *
 * Descrip:    shows packaln with a pretty verbose debugging 
 *             format, but with a conversion function from state number to
 *             a string
 *
 *
 * Arg:        state_to_char [UNKN ] Undocumented argument [NullString]
 * Arg:                  pal [UNKN ] Undocumented argument [PackAln *]
 * Arg:                  ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_show_text_PackAln(PackAln * pal,char * (*state_to_char)(int),FILE * ofp);
#define show_text_PackAln bp_sw_show_text_PackAln


/* Function:  invert_PackAln(pal)
 *
 * Descrip:    inverts the packaln so that the last unit is the first
 *             etc. Because most alignments are read backwards this
 *             is useful
 *
 *
 * Arg:        pal [UNKN ] PackAln to be inverted  [PackAln *]
 *
 */
void bp_sw_invert_PackAln(PackAln * pal) ;
#define invert_PackAln bp_sw_invert_PackAln


/* Function:  hard_link_PackAlnUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [PackAlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [PackAlnUnit *]
 *
 */
PackAlnUnit * bp_sw_hard_link_PackAlnUnit(PackAlnUnit * obj);
#define hard_link_PackAlnUnit bp_sw_hard_link_PackAlnUnit


/* Function:  PackAlnUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [PackAlnUnit *]
 *
 */
PackAlnUnit * bp_sw_PackAlnUnit_alloc(void);
#define PackAlnUnit_alloc bp_sw_PackAlnUnit_alloc


/* Function:  free_PackAlnUnit(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [PackAlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [PackAlnUnit *]
 *
 */
PackAlnUnit * bp_sw_free_PackAlnUnit(PackAlnUnit * obj);
#define free_PackAlnUnit bp_sw_free_PackAlnUnit


/* Function:  add_PackAln(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [PackAln *]
 * Arg:        add [OWNER] Object to add to the list [PackAlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_PackAln(PackAln * obj,PackAlnUnit * add);
#define add_PackAln bp_sw_add_PackAln


/* Function:  flush_PackAln(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [PackAln *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_PackAln(PackAln * obj);
#define flush_PackAln bp_sw_flush_PackAln


/* Function:  PackAln_alloc_std(void)
 *
 * Descrip:    Equivalent to PackAln_alloc_len(PackAlnLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_alloc_std(void);
#define PackAln_alloc_std bp_sw_PackAln_alloc_std


/* Function:  PackAln_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_alloc_len(int len);
#define PackAln_alloc_len bp_sw_PackAln_alloc_len


/* Function:  hard_link_PackAln(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [PackAln *]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_hard_link_PackAln(PackAln * obj);
#define hard_link_PackAln bp_sw_hard_link_PackAln


/* Function:  PackAln_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_alloc(void);
#define PackAln_alloc bp_sw_PackAln_alloc


/* Function:  free_PackAln(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [PackAln *]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_free_PackAln(PackAln * obj);
#define free_PackAln bp_sw_free_PackAln


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
PackAlnUnit * bp_sw_access_pau_PackAln(PackAln * obj,int i);
#define access_pau_PackAln bp_sw_access_pau_PackAln
int bp_sw_access_score_PackAln(PackAln * obj);
#define access_score_PackAln bp_sw_access_score_PackAln
void bp_sw_show_simple_PackAlnUnit(PackAlnUnit * pau,FILE * ofp);
#define show_simple_PackAlnUnit bp_sw_show_simple_PackAlnUnit
boolean bp_sw_replace_i_PackAlnUnit(PackAlnUnit * obj,int i);
#define replace_i_PackAlnUnit bp_sw_replace_i_PackAlnUnit
int bp_sw_access_i_PackAlnUnit(PackAlnUnit * obj);
#define access_i_PackAlnUnit bp_sw_access_i_PackAlnUnit
boolean bp_sw_replace_score_PackAlnUnit(PackAlnUnit * obj,int score);
#define replace_score_PackAlnUnit bp_sw_replace_score_PackAlnUnit
boolean bp_sw_replace_j_PackAlnUnit(PackAlnUnit * obj,int j);
#define replace_j_PackAlnUnit bp_sw_replace_j_PackAlnUnit
boolean bp_sw_replace_score_PackAln(PackAln * obj,int score);
#define replace_score_PackAln bp_sw_replace_score_PackAln
int bp_sw_access_j_PackAlnUnit(PackAlnUnit * obj);
#define access_j_PackAlnUnit bp_sw_access_j_PackAlnUnit
int bp_sw_length_pau_PackAln(PackAln * obj);
#define length_pau_PackAln bp_sw_length_pau_PackAln
boolean bp_sw_replace_state_PackAlnUnit(PackAlnUnit * obj,int state);
#define replace_state_PackAlnUnit bp_sw_replace_state_PackAlnUnit
int bp_sw_access_score_PackAlnUnit(PackAlnUnit * obj);
#define access_score_PackAlnUnit bp_sw_access_score_PackAlnUnit
int bp_sw_access_state_PackAlnUnit(PackAlnUnit * obj);
#define access_state_PackAlnUnit bp_sw_access_state_PackAlnUnit
void bp_sw_show_text_PackAlnUnit(PackAlnUnit * pau,char * (*state_to_char)(int),FILE * ofp);
#define show_text_PackAlnUnit bp_sw_show_text_PackAlnUnit
void bp_sw_swap_PackAln(PackAlnUnit ** list,int i,int j) ;
#define swap_PackAln bp_sw_swap_PackAln
void bp_sw_qsort_PackAln(PackAlnUnit ** list,int left,int right,int (*comp)(PackAlnUnit * ,PackAlnUnit * ));
#define qsort_PackAln bp_sw_qsort_PackAln
void bp_sw_sort_PackAln(PackAln * obj,int (*comp)(PackAlnUnit *, PackAlnUnit *));
#define sort_PackAln bp_sw_sort_PackAln
boolean bp_sw_expand_PackAln(PackAln * obj,int len);
#define expand_PackAln bp_sw_expand_PackAln

#ifdef _cplusplus
}
#endif

#endif
