#ifndef DYNAMITEcomplexconsensiHEADERFILE
#define DYNAMITEcomplexconsensiHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"
#include "probability.h"

#define ComplexConsensiLISTLENGTH 64

struct bp_sw_ComplexConsensusWord {  
    int dynamite_hard_link;  
    char * pattern;  
    Score score;     
    Probability p;   
    } ;  
/* ComplexConsensusWord defined */ 
#ifndef DYNAMITE_DEFINED_ComplexConsensusWord
typedef struct bp_sw_ComplexConsensusWord bp_sw_ComplexConsensusWord;
#define ComplexConsensusWord bp_sw_ComplexConsensusWord
#define DYNAMITE_DEFINED_ComplexConsensusWord
#endif


struct bp_sw_ComplexConsensi {  
    int dynamite_hard_link;  
    ComplexConsensusWord ** ccw;     
    int len;/* len for above ccw  */ 
    int maxlen; /* maxlen for above ccw */ 
    char * name;     
    } ;  
/* ComplexConsensi defined */ 
#ifndef DYNAMITE_DEFINED_ComplexConsensi
typedef struct bp_sw_ComplexConsensi bp_sw_ComplexConsensi;
#define ComplexConsensi bp_sw_ComplexConsensi
#define DYNAMITE_DEFINED_ComplexConsensi
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  show_ComplexConsensi(cc,*ofp)
 *
 * Descrip:    shows complexconsensi in vaguely human form
 *
 *
 * Arg:          cc [UNKN ] Undocumented argument [ComplexConsensi *]
 * Arg:        *ofp [UNKN ] Undocumented argument [FILE]
 *
 */
void bp_sw_show_ComplexConsensi(ComplexConsensi * cc,FILE *ofp);
#define show_ComplexConsensi bp_sw_show_ComplexConsensi


/* Function:  word_from_ComplexConsensi(word,cc)
 *
 * Descrip:    Way of getting probabilities out of a consensus.
 *             If it is in the Consensus, then gets prob, otherwise 0.
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 * Arg:          cc [UNKN ] Undocumented argument [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [Probability]
 *
 */
Probability bp_sw_word_from_ComplexConsensi(char * word,ComplexConsensi * cc);
#define word_from_ComplexConsensi bp_sw_word_from_ComplexConsensi


/* Function:  score_from_ComplexConsensi(word,cc)
 *
 * Descrip:    Way of getting scores out of a consensus.
 *             If it is in the Consensus, then gets score, otherwise NEGI.
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 * Arg:          cc [UNKN ] Undocumented argument [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [Score]
 *
 */
Score bp_sw_score_from_ComplexConsensi(char * word,ComplexConsensi * cc);
#define score_from_ComplexConsensi bp_sw_score_from_ComplexConsensi


/* Function:  best_ComplexConsensusWord(word,cc)
 *
 * Descrip:    Finds the best (highest) match to this word
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 * Arg:          cc [UNKN ] Undocumented argument [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensusWord *]
 *
 */
ComplexConsensusWord * bp_sw_best_ComplexConsensusWord(char * word,ComplexConsensi * cc);
#define best_ComplexConsensusWord bp_sw_best_ComplexConsensusWord


/* Function:  word_matches_ComplexConsensusWord(word,ccw)
 *
 * Descrip:    Core of the matching system. Checks that word matches 
 *             ComplexConsensusWord. This says that '-' matches anything.
 *             Issues a warning if hits a '\0' in word
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 * Arg:         ccw [UNKN ] Undocumented argument [ComplexConsensusWord *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_word_matches_ComplexConsensusWord(char * word,ComplexConsensusWord * ccw);
#define word_matches_ComplexConsensusWord bp_sw_word_matches_ComplexConsensusWord


/* Function:  read_ComplexConsensi_file(filename)
 *
 * Descrip:    Reads a file containing the ComplexConsensi.
 *             Not every useful, as most times these consensi
 *             are in one file, with other things
 *
 *
 * Arg:        filename [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_read_ComplexConsensi_file(char * filename);
#define read_ComplexConsensi_file bp_sw_read_ComplexConsensi_file


/* Function:  read_ComplexConsensi(ifp)
 *
 * Descrip:    Reads on ComplexConsensi from the FILE ifp.
 *
 *
 * Arg:        ifp [UNKN ] input filestream [FILE *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_read_ComplexConsensi(FILE * ifp);
#define read_ComplexConsensi bp_sw_read_ComplexConsensi


/* Function:  hard_link_ComplexConsensusWord(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [ComplexConsensusWord *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensusWord *]
 *
 */
ComplexConsensusWord * bp_sw_hard_link_ComplexConsensusWord(ComplexConsensusWord * obj);
#define hard_link_ComplexConsensusWord bp_sw_hard_link_ComplexConsensusWord


/* Function:  ComplexConsensusWord_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensusWord *]
 *
 */
ComplexConsensusWord * bp_sw_ComplexConsensusWord_alloc(void);
#define ComplexConsensusWord_alloc bp_sw_ComplexConsensusWord_alloc


/* Function:  free_ComplexConsensusWord(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [ComplexConsensusWord *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensusWord *]
 *
 */
ComplexConsensusWord * bp_sw_free_ComplexConsensusWord(ComplexConsensusWord * obj);
#define free_ComplexConsensusWord bp_sw_free_ComplexConsensusWord


/* Function:  add_ComplexConsensi(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [ComplexConsensi *]
 * Arg:        add [OWNER] Object to add to the list [ComplexConsensusWord *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_ComplexConsensi(ComplexConsensi * obj,ComplexConsensusWord * add);
#define add_ComplexConsensi bp_sw_add_ComplexConsensi


/* Function:  flush_ComplexConsensi(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_ComplexConsensi(ComplexConsensi * obj);
#define flush_ComplexConsensi bp_sw_flush_ComplexConsensi


/* Function:  ComplexConsensi_alloc_std(void)
 *
 * Descrip:    Equivalent to ComplexConsensi_alloc_len(ComplexConsensiLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_ComplexConsensi_alloc_std(void);
#define ComplexConsensi_alloc_std bp_sw_ComplexConsensi_alloc_std


/* Function:  ComplexConsensi_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_ComplexConsensi_alloc_len(int len);
#define ComplexConsensi_alloc_len bp_sw_ComplexConsensi_alloc_len


/* Function:  hard_link_ComplexConsensi(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_hard_link_ComplexConsensi(ComplexConsensi * obj);
#define hard_link_ComplexConsensi bp_sw_hard_link_ComplexConsensi


/* Function:  ComplexConsensi_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_ComplexConsensi_alloc(void);
#define ComplexConsensi_alloc bp_sw_ComplexConsensi_alloc


/* Function:  free_ComplexConsensi(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [ComplexConsensi *]
 *
 * Return [UNKN ]  Undocumented return value [ComplexConsensi *]
 *
 */
ComplexConsensi * bp_sw_free_ComplexConsensi(ComplexConsensi * obj);
#define free_ComplexConsensi bp_sw_free_ComplexConsensi


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
void bp_sw_show_ComplexConsensusWord(ComplexConsensusWord * ccw,FILE * ofp);
#define show_ComplexConsensusWord bp_sw_show_ComplexConsensusWord
boolean bp_sw_strcmp_with_dashes(char * word,char * pattern);
#define strcmp_with_dashes bp_sw_strcmp_with_dashes
ComplexConsensusWord * bp_sw_read_ComplexConsensusWord_line(char * line);
#define read_ComplexConsensusWord_line bp_sw_read_ComplexConsensusWord_line
void bp_sw_swap_ComplexConsensi(ComplexConsensusWord ** list,int i,int j) ;
#define swap_ComplexConsensi bp_sw_swap_ComplexConsensi
void bp_sw_qsort_ComplexConsensi(ComplexConsensusWord ** list,int left,int right,int (*comp)(ComplexConsensusWord * ,ComplexConsensusWord * ));
#define qsort_ComplexConsensi bp_sw_qsort_ComplexConsensi
void bp_sw_sort_ComplexConsensi(ComplexConsensi * obj,int (*comp)(ComplexConsensusWord *, ComplexConsensusWord *));
#define sort_ComplexConsensi bp_sw_sort_ComplexConsensi
boolean bp_sw_expand_ComplexConsensi(ComplexConsensi * obj,int len);
#define expand_ComplexConsensi bp_sw_expand_ComplexConsensi

#ifdef _cplusplus
}
#endif

#endif
