#ifndef DYNAMITEproteinswHEADERFILE
#define DYNAMITEproteinswHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "dyna.h"

struct bp_sw_ProteinSW {  
    int dynamite_hard_link;  
    BaseMatrix * basematrix;     
    int leni;    
    int lenj;    
    ComplexSequence* query;  
    ComplexSequence* target;     
    CompMat* comp;   
    int gap;     
    int ext;     
    } ;  
/* ProteinSW defined */ 
#ifndef DYNAMITE_DEFINED_ProteinSW
typedef struct bp_sw_ProteinSW bp_sw_ProteinSW;
#define ProteinSW bp_sw_ProteinSW
#define DYNAMITE_DEFINED_ProteinSW
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  search_ProteinSW(out,querydb,targetdb,comp,gap,ext)
 *
 * Descrip:    This function makes a database search of ProteinSW
 *
 *
 * Arg:             out [UNKN ] Undocumented argument [Hscore *]
 * Arg:         querydb [UNKN ] Undocumented argument [ProteinDB*]
 * Arg:        targetdb [UNKN ] Undocumented argument [ProteinDB*]
 * Arg:            comp [UNKN ] Undocumented argument [CompMat*]
 * Arg:             gap [UNKN ] Undocumented argument [int]
 * Arg:             ext [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [Search_Return_Type]
 *
 */
Search_Return_Type bp_sw_search_ProteinSW(Hscore * out,ProteinDB* querydb,ProteinDB* targetdb ,CompMat* comp,int gap,int ext);
#define search_ProteinSW bp_sw_search_ProteinSW


/* Function:  PackAln_bestmemory_ProteinSW(query,target,comp,gap,ext,dpenv)
 *
 * Descrip:    This function chooses the best memory set-up for the alignment
 *             using calls to basematrix, and then implements either a large
 *             or small memory model.
 *
 *             It is the best function to use if you just want an alignment
 *
 *             If you want a label alignment, you will need
 *             /convert_PackAln_to_AlnBlock_ProteinSW
 *
 *
 * Arg:         query [UNKN ] query data structure [ComplexSequence*]
 * Arg:        target [UNKN ] target data structure [ComplexSequence*]
 * Arg:          comp [UNKN ] Resource [CompMat*]
 * Arg:           gap [UNKN ] Resource [int]
 * Arg:           ext [UNKN ] Resource [int]
 * Arg:         dpenv [UNKN ] Undocumented argument [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_bestmemory_ProteinSW(ComplexSequence* query,ComplexSequence* target ,CompMat* comp,int gap,int ext,DPEnvelope * dpenv);
#define PackAln_bestmemory_ProteinSW bp_sw_PackAln_bestmemory_ProteinSW


/* Function:  allocate_Expl_ProteinSW(query,target,comp,gap,ext)
 *
 * Descrip:    This function allocates the ProteinSW structure
 *             and the basematrix area for explicit memory implementations
 *             It calls /allocate_ProteinSW_only
 *
 *
 * Arg:         query [UNKN ] query data structure [ComplexSequence*]
 * Arg:        target [UNKN ] target data structure [ComplexSequence*]
 * Arg:          comp [UNKN ] Resource [CompMat*]
 * Arg:           gap [UNKN ] Resource [int]
 * Arg:           ext [UNKN ] Resource [int]
 *
 * Return [UNKN ]  Undocumented return value [ProteinSW *]
 *
 */
ProteinSW * bp_sw_allocate_Expl_ProteinSW(ComplexSequence* query,ComplexSequence* target ,CompMat* comp,int gap,int ext);
#define allocate_Expl_ProteinSW bp_sw_allocate_Expl_ProteinSW


/* Function:  recalculate_PackAln_ProteinSW(pal,mat)
 *
 * Descrip:    This function recalculates the PackAln structure produced by ProteinSW
 *             For example, in linear space methods this is used to score them
 *
 *
 * Arg:        pal [UNKN ] Undocumented argument [PackAln *]
 * Arg:        mat [UNKN ] Undocumented argument [ProteinSW *]
 *
 */
void bp_sw_recalculate_PackAln_ProteinSW(PackAln * pal,ProteinSW * mat);
#define recalculate_PackAln_ProteinSW bp_sw_recalculate_PackAln_ProteinSW


/* Function:  allocate_Small_ProteinSW(query,target,comp,gap,ext)
 *
 * Descrip:    This function allocates the ProteinSW structure
 *             and the basematrix area for a small memory implementations
 *             It calls /allocate_ProteinSW_only
 *
 *
 * Arg:         query [UNKN ] query data structure [ComplexSequence*]
 * Arg:        target [UNKN ] target data structure [ComplexSequence*]
 * Arg:          comp [UNKN ] Resource [CompMat*]
 * Arg:           gap [UNKN ] Resource [int]
 * Arg:           ext [UNKN ] Resource [int]
 *
 * Return [UNKN ]  Undocumented return value [ProteinSW *]
 *
 */
ProteinSW * bp_sw_allocate_Small_ProteinSW(ComplexSequence* query,ComplexSequence* target ,CompMat* comp,int gap,int ext);
#define allocate_Small_ProteinSW bp_sw_allocate_Small_ProteinSW


/* Function:  PackAln_calculate_Small_ProteinSW(mat,dpenv)
 *
 * Descrip:    This function calculates an alignment for ProteinSW structure in linear space
 *             If you want only the start/end points
 *             use /AlnRangeSet_calculate_Small_ProteinSW 
 *
 *             The function basically
 *               finds start/end points 
 *               foreach start/end point 
 *                 calls /full_dc_ProteinSW 
 *
 *
 * Arg:          mat [UNKN ] Undocumented argument [ProteinSW *]
 * Arg:        dpenv [UNKN ] Undocumented argument [DPEnvelope *]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_calculate_Small_ProteinSW(ProteinSW * mat,DPEnvelope * dpenv);
#define PackAln_calculate_Small_ProteinSW bp_sw_PackAln_calculate_Small_ProteinSW


/* Function:  AlnRangeSet_calculate_Small_ProteinSW(mat)
 *
 * Descrip:    This function calculates an alignment for ProteinSW structure in linear space
 *             If you want the full alignment, use /PackAln_calculate_Small_ProteinSW 
 *             If you have already got the full alignment, but want the range set, use /AlnRangeSet_from_PackAln_ProteinSW
 *             If you have got the small matrix but not the alignment, use /AlnRangeSet_from_ProteinSW 
 *
 *
 * Arg:        mat [UNKN ] Undocumented argument [ProteinSW *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_calculate_Small_ProteinSW(ProteinSW * mat);
#define AlnRangeSet_calculate_Small_ProteinSW bp_sw_AlnRangeSet_calculate_Small_ProteinSW


/* Function:  AlnRangeSet_from_ProteinSW(mat)
 *
 * Descrip:    This function reads off a start/end structure
 *             for ProteinSW structure in linear space
 *             If you want the full alignment use
 *             /PackAln_calculate_Small_ProteinSW 
 *             If you have not calculated the matrix use
 *             /AlnRange_calculate_Small_ProteinSW
 *
 *
 * Arg:        mat [UNKN ] Undocumented argument [ProteinSW *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_from_ProteinSW(ProteinSW * mat);
#define AlnRangeSet_from_ProteinSW bp_sw_AlnRangeSet_from_ProteinSW


/* Function:  AlnRangeSet_from_PackAln_ProteinSW(pal)
 *
 * Descrip:    Converts a PackAln (full alignment) to start/stop range
 *             The point being that you may have the PackAln and someone wants a range
 *
 *
 * Arg:        pal [UNKN ] Undocumented argument [PackAln *]
 *
 * Return [UNKN ]  Undocumented return value [AlnRangeSet *]
 *
 */
AlnRangeSet * bp_sw_AlnRangeSet_from_PackAln_ProteinSW(PackAln * pal);
#define AlnRangeSet_from_PackAln_ProteinSW bp_sw_AlnRangeSet_from_PackAln_ProteinSW


/* Function:  convert_PackAln_to_AlnBlock_ProteinSW(pal)
 *
 * Descrip:    Converts a path alignment to a label alignment
 *             The label alignment is probably much more useful than the path
 *
 *
 * Arg:        pal [UNKN ] Undocumented argument [PackAln *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_convert_PackAln_to_AlnBlock_ProteinSW(PackAln * pal);
#define convert_PackAln_to_AlnBlock_ProteinSW bp_sw_convert_PackAln_to_AlnBlock_ProteinSW


/* Function:  PackAln_read_Expl_ProteinSW(mat)
 *
 * Descrip:    Reads off PackAln from explicit matrix structure
 *
 *
 * Arg:        mat [UNKN ] Undocumented argument [ProteinSW *]
 *
 * Return [UNKN ]  Undocumented return value [PackAln *]
 *
 */
PackAln * bp_sw_PackAln_read_Expl_ProteinSW(ProteinSW * mat);
#define PackAln_read_Expl_ProteinSW bp_sw_PackAln_read_Expl_ProteinSW


/* Function:  calculate_ProteinSW(mat)
 *
 * Descrip:    This function calculates the ProteinSW matrix when in explicit mode
 *             To allocate the matrix use /allocate_Expl_ProteinSW
 *
 *
 * Arg:        mat [UNKN ] ProteinSW which contains explicit basematrix memory [ProteinSW *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_calculate_ProteinSW(ProteinSW * mat);
#define calculate_ProteinSW bp_sw_calculate_ProteinSW


/* Function:  ProteinSW_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [ProteinSW *]
 *
 */
ProteinSW * bp_sw_ProteinSW_alloc(void);
#define ProteinSW_alloc bp_sw_ProteinSW_alloc


/* Function:  free_ProteinSW(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [ProteinSW *]
 *
 * Return [UNKN ]  Undocumented return value [ProteinSW *]
 *
 */
ProteinSW * bp_sw_free_ProteinSW(ProteinSW * obj);
#define free_ProteinSW bp_sw_free_ProteinSW


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
int bp_sw_score_only_ProteinSW(ComplexSequence* query,ComplexSequence* target ,CompMat* comp,int gap,int ext);
#define score_only_ProteinSW bp_sw_score_only_ProteinSW
ProteinSW * bp_sw_allocate_ProteinSW_only(ComplexSequence* query,ComplexSequence* target ,CompMat* comp,int gap,int ext);
#define allocate_ProteinSW_only bp_sw_allocate_ProteinSW_only
void bp_sw_init_ProteinSW(ProteinSW * mat);
#define init_ProteinSW bp_sw_init_ProteinSW
AlnRange * bp_sw_AlnRange_build_ProteinSW(ProteinSW * mat,int stopj,int stopspecstate,int * startj,int * startspecstate);
#define AlnRange_build_ProteinSW bp_sw_AlnRange_build_ProteinSW
boolean bp_sw_read_hidden_ProteinSW(ProteinSW * mat,int starti,int startj,int startstate,int stopi,int stopj,int stopstate,PackAln * out);
#define read_hidden_ProteinSW bp_sw_read_hidden_ProteinSW
int bp_sw_max_hidden_ProteinSW(ProteinSW * mat,int hiddenj,int i,int j,int state,boolean isspecial,int * reti,int * retj,int * retstate,boolean * retspecial,int * cellscore);
#define max_hidden_ProteinSW bp_sw_max_hidden_ProteinSW
boolean bp_sw_read_special_strip_ProteinSW(ProteinSW * mat,int stopi,int stopj,int stopstate,int * startj,int * startstate,PackAln * out);
#define read_special_strip_ProteinSW bp_sw_read_special_strip_ProteinSW
int bp_sw_max_special_strip_ProteinSW(ProteinSW * mat,int i,int j,int state,boolean isspecial,int * reti,int * retj,int * retstate,boolean * retspecial,int * cellscore);
#define max_special_strip_ProteinSW bp_sw_max_special_strip_ProteinSW
int bp_sw_max_matrix_to_special_ProteinSW(ProteinSW * mat,int i,int j,int state,int cscore,int * reti,int * retj,int * retstate,boolean * retspecial,int * cellscore);
#define max_matrix_to_special_ProteinSW bp_sw_max_matrix_to_special_ProteinSW
void bp_sw_calculate_hidden_ProteinSW(ProteinSW * mat,int starti,int startj,int startstate,int stopi,int stopj,int stopstate,DPEnvelope * dpenv);
#define calculate_hidden_ProteinSW bp_sw_calculate_hidden_ProteinSW
void bp_sw_init_hidden_ProteinSW(ProteinSW * mat,int starti,int startj,int stopi,int stopj);
#define init_hidden_ProteinSW bp_sw_init_hidden_ProteinSW
boolean bp_sw_full_dc_ProteinSW(ProteinSW * mat,int starti,int startj,int startstate,int stopi,int stopj,int stopstate,PackAln * out,int * donej,int totalj,DPEnvelope * dpenv);
#define full_dc_ProteinSW bp_sw_full_dc_ProteinSW
boolean bp_sw_do_dc_single_pass_ProteinSW(ProteinSW * mat,int starti,int startj,int startstate,int stopi,int stopj,int stopstate,DPEnvelope * dpenv,int perc_done);
#define do_dc_single_pass_ProteinSW bp_sw_do_dc_single_pass_ProteinSW
void bp_sw_push_dc_at_merge_ProteinSW(ProteinSW * mat,int starti,int stopi,int startj,int * stopj,DPEnvelope * dpenv);
#define push_dc_at_merge_ProteinSW bp_sw_push_dc_at_merge_ProteinSW
void bp_sw_follow_on_dc_ProteinSW(ProteinSW * mat,int starti,int stopi,int startj,int stopj,DPEnvelope * dpenv,int perc_done);
#define follow_on_dc_ProteinSW bp_sw_follow_on_dc_ProteinSW
void bp_sw_run_up_dc_ProteinSW(ProteinSW * mat,int starti,int stopi,int startj,int stopj,DPEnvelope * dpenv,int perc_done);
#define run_up_dc_ProteinSW bp_sw_run_up_dc_ProteinSW
void bp_sw_init_dc_ProteinSW(ProteinSW * mat);
#define init_dc_ProteinSW bp_sw_init_dc_ProteinSW
boolean bp_sw_dc_start_end_calculate_ProteinSW(ProteinSW * mat,DPEnvelope * dpenv);
#define dc_start_end_calculate_ProteinSW bp_sw_dc_start_end_calculate_ProteinSW
int bp_sw_start_end_find_end_ProteinSW(ProteinSW * mat,int * endj);
#define start_end_find_end_ProteinSW bp_sw_start_end_find_end_ProteinSW
void bp_sw_init_start_end_linear_ProteinSW(ProteinSW * mat);
#define init_start_end_linear_ProteinSW bp_sw_init_start_end_linear_ProteinSW
AlnConvertSet * bp_sw_AlnConvertSet_ProteinSW(void);
#define AlnConvertSet_ProteinSW bp_sw_AlnConvertSet_ProteinSW
int bp_sw_find_end_ProteinSW(ProteinSW * mat,int * ri,int * rj,int * state,boolean * isspecial);
#define find_end_ProteinSW bp_sw_find_end_ProteinSW
void bp_sw_ProteinSW_debug_show_matrix(ProteinSW * mat,int starti,int stopi,int startj,int stopj,FILE * ofp);
#define ProteinSW_debug_show_matrix bp_sw_ProteinSW_debug_show_matrix
int bp_sw_max_calc_ProteinSW(ProteinSW * mat,int i,int j,int state,boolean isspecial,int * reti,int * retj,int * retstate,boolean * retspecial,int * cellscore);
#define max_calc_ProteinSW bp_sw_max_calc_ProteinSW
int bp_sw_max_calc_special_ProteinSW(ProteinSW * mat,int i,int j,int state,boolean isspecial,int * reti,int * retj,int * retstate,boolean * retspecial,int * cellscore);
#define max_calc_special_ProteinSW bp_sw_max_calc_special_ProteinSW

#ifdef _cplusplus
}
#endif

#endif
