#ifndef DYNAMITEasciibtcanvasHEADERFILE
#define DYNAMITEasciibtcanvasHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "btcanvas.h"


struct bp_sw_Ascii_btc_Data {  
    int dynamite_hard_link;  
    FILE * ofp; /*  file to write to */ 
    int current_x;  /*  position in main line  */ 
    int paint_x;    /*  painting cursor on the line */ 
    int res_left;   /*  amount reserved on left */ 
    int main;   /*  main block amount */ 
    int res_right;  /*  amount reserved on right */ 
    char ** scratch;    /*  scratch pad lines  */ 
    int depth_scratch;  /*  depth of scratch pad for memory */ 
    boolean in_use;  
    btPasteArea * bpa;  /*  this is what we recycle.. */ 
    } ;  
/* Ascii_btc_Data defined */ 
#ifndef DYNAMITE_DEFINED_Ascii_btc_Data
typedef struct bp_sw_Ascii_btc_Data bp_sw_Ascii_btc_Data;
#define Ascii_btc_Data bp_sw_Ascii_btc_Data
#define DYNAMITE_DEFINED_Ascii_btc_Data
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  new_Ascii_btCanvas(ofp,left,main,right,height)
 *
 * Descrip:    The only function specifically for Ascii bt Canvases.
 *
 *             Use this to make a new btCanvas. Then use functions like
 *             /get_paste_area_btCanvas to actually use it. Everything
 *             else is handled by data structures and pointer-to-functions
 *             which are hidden to you (and be thankful for that!)
 *
 *             The standard /free_btCanvas will free the hidden data structures
 *             as well
 *
 *
 * Arg:           ofp [UNKN ] FILE stream to write the ascii to [FILE *]
 * Arg:          left [UNKN ] amount of text to reserve on the left [int]
 * Arg:          main [UNKN ] Undocumented argument [int]
 * Arg:         right [UNKN ] amount of text to reserve on the right [int]
 * Arg:        height [UNKN ] height of block [int]
 *
 * Return [UNKN ]  Undocumented return value [btCanvas *]
 *
 */
btCanvas * bp_sw_new_Ascii_btCanvas(FILE * ofp,int left,int main,int right,int height);
#define new_Ascii_btCanvas bp_sw_new_Ascii_btCanvas


/* Function:  hard_link_Ascii_btc_Data(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [Ascii_btc_Data *]
 *
 * Return [UNKN ]  Undocumented return value [Ascii_btc_Data *]
 *
 */
Ascii_btc_Data * bp_sw_hard_link_Ascii_btc_Data(Ascii_btc_Data * obj);
#define hard_link_Ascii_btc_Data bp_sw_hard_link_Ascii_btc_Data


/* Function:  Ascii_btc_Data_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [Ascii_btc_Data *]
 *
 */
Ascii_btc_Data * bp_sw_Ascii_btc_Data_alloc(void);
#define Ascii_btc_Data_alloc bp_sw_Ascii_btc_Data_alloc


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
btPasteArea * bp_sw_next_Ascii_btpa(btCanvas * btc,int length);
#define next_Ascii_btpa bp_sw_next_Ascii_btpa
boolean bp_sw_paste_char_bt_Ascii(btPasteArea * bpa,int x,int y,char c,int format);
#define paste_char_bt_Ascii bp_sw_paste_char_bt_Ascii
boolean bp_sw_can_get_bt_Ascii(btCanvas * btc,int length);
#define can_get_bt_Ascii bp_sw_can_get_bt_Ascii
btPasteArea * bp_sw_get_ascii_left_btPasteArea(btCanvas * btc);
#define get_ascii_left_btPasteArea bp_sw_get_ascii_left_btPasteArea
btPasteArea * bp_sw_get_ascii_right_btPasteArea(btCanvas * btc);
#define get_ascii_right_btPasteArea bp_sw_get_ascii_right_btPasteArea
boolean bp_sw_ascii_next_line_btPasteArea(btCanvas * btc);
#define ascii_next_line_btPasteArea bp_sw_ascii_next_line_btPasteArea
btPasteArea * bp_sw_free_Ascii_btpa(btPasteArea * obj);
#define free_Ascii_btpa bp_sw_free_Ascii_btpa
Ascii_btc_Data * bp_sw_new_Ascii_btc_Data(FILE * ofp,int left,int main,int right,int height);
#define new_Ascii_btc_Data bp_sw_new_Ascii_btc_Data
btCanvas * bp_sw_free_Ascii_btc(btCanvas * btc);
#define free_Ascii_btc bp_sw_free_Ascii_btc
Ascii_btc_Data * bp_sw_free_Ascii_btc_Data(Ascii_btc_Data * obj);
#define free_Ascii_btc_Data bp_sw_free_Ascii_btc_Data

#ifdef _cplusplus
}
#endif

#endif
