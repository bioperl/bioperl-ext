#ifndef DYNAMITEalnHEADERFILE
#define DYNAMITEalnHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"
#include "probability.h" 


#define AlnColumnLISTLENGTH 32
#define AlnBlockLISTLENGTH   32
#define AlnBlockListLISTLENGTH   32

#define AlnUnitSCORENUMBER 8

#ifndef DYNAMITE_DEFINED_AlnColumn
typedef struct bp_sw_AlnColumn bp_sw_AlnColumn;
#define AlnColumn bp_sw_AlnColumn
#define DYNAMITE_DEFINED_AlnColumn
#endif

#ifndef DYNAMITE_DEFINED_AlnUnit
typedef struct bp_sw_AlnUnit bp_sw_AlnUnit;
#define AlnUnit bp_sw_AlnUnit
#define DYNAMITE_DEFINED_AlnUnit
#endif

#ifndef DYNAMITE_DEFINED_AlnSequence
typedef struct bp_sw_AlnSequence bp_sw_AlnSequence;
#define AlnSequence bp_sw_AlnSequence
#define DYNAMITE_DEFINED_AlnSequence
#endif

/* Object AlnUnit
 *
 * Descrip: This is the basic unit of the label alignment.
 *        It describes a single mark-up over one sequence:
 *        being a start, an end and a text_label.
 *
 *
 */
struct bp_sw_AlnUnit {  
    int dynamite_hard_link;  
    int start;  /*  start position in the sequence */ 
    int end;    /*  end position in the sequence */ 
    int label;  /*  not used */ 
    char * text_label;  /*  text label of this position */ 
    AlnUnit * next; /*  next AlnUnit in this sequence */ 
    int score[AlnUnitSCORENUMBER];  /*  a series of scores for this position. */ 
    boolean in_column;  /*  not used  */ 
    AlnSequence * seq;   
    } ;  
/* AlnUnit defined */ 
#ifndef DYNAMITE_DEFINED_AlnUnit
typedef struct bp_sw_AlnUnit bp_sw_AlnUnit;
#define AlnUnit bp_sw_AlnUnit
#define DYNAMITE_DEFINED_AlnUnit
#endif


/* Object AlnColumn
 *
 * Descrip: This is a coupling of AlnUnits from different sequences.
 *        Each AlnUnit is meant to represent *the equivalent* piece
 *        of biological information in some sense (ie, they are
 *        alignmed), even though quite possibly they are very 
 *        different types of information
 *
 *
 */
struct bp_sw_AlnColumn {  
    int dynamite_hard_link;  
    AlnUnit ** alu; /*  list of the AlnUnits in this column */ 
    int len;/* len for above alu  */ 
    int maxlen; /* maxlen for above alu */ 
    AlnColumn * next;   /*  the next AlnColumn in this block */ 
    } ;  
/* AlnColumn defined */ 
#ifndef DYNAMITE_DEFINED_AlnColumn
typedef struct bp_sw_AlnColumn bp_sw_AlnColumn;
#define AlnColumn bp_sw_AlnColumn
#define DYNAMITE_DEFINED_AlnColumn
#endif


/* Object AlnSequence
 *
 * Descrip: Each Sequence in an AlnBlock is represented by one of these, and
 *        in many ways this is an orthogonal way of looking at the alignment
 *        than the AlnColumns. If you look at the alignment from one 
 *        AlnSequence you will just see the individual labels on this 
 *        sequence
 *
 *
 */
struct bp_sw_AlnSequence {  
    int dynamite_hard_link;  
    AlnUnit * start;    /*  the first AlnUnit of this sequence */ 
    int data_type;  /*  not used */ 
    void * data;    /*  not used - don't use! */ 
    int bio_start;  /*  start of this sequence in its 'bio' coordinates */ 
    int bio_end;    /*  end of this sequence in its 'bio' coordinates */ 
    } ;  
/* AlnSequence defined */ 
#ifndef DYNAMITE_DEFINED_AlnSequence
typedef struct bp_sw_AlnSequence bp_sw_AlnSequence;
#define AlnSequence bp_sw_AlnSequence
#define DYNAMITE_DEFINED_AlnSequence
#endif


/* Object AlnBlock
 *
 * Descrip: AlnBlock is the main representation of alignments from Dynamite. Each
 *        AlnBlock represents any number of 'sequences', of any type, which share
 *        things in common. The alignment is represented by a series of /AlnColumns 
 *        (linked list) in which each AlnColumn has a series of AlnUnits, each 
 *        Unit being a start/end/text_label triple. Alternatively, one can see
 *        each sequence in isolation, and not ask what it is aligned to, but rather
 *        what labels it has on it. 
 *
 *
 */
struct bp_sw_AlnBlock {  
    int dynamite_hard_link;  
    AlnColumn * start;  /*  the first AlnColumn in the alignment */ 
    AlnSequence ** seq; /*  a list of AlnSequences in the alignment */ 
    int len;/* len for above seq  */ 
    int maxlen; /* maxlen for above seq */ 
    int length; /*  not used  */ 
    int score;  /*  not used */ 
    } ;  
/* AlnBlock defined */ 
#ifndef DYNAMITE_DEFINED_AlnBlock
typedef struct bp_sw_AlnBlock bp_sw_AlnBlock;
#define AlnBlock bp_sw_AlnBlock
#define DYNAMITE_DEFINED_AlnBlock
#endif


/* Object AlnBlockList
 *
 * Descrip: No Description
 *
 */
struct bp_sw_AlnBlockList {  
    int dynamite_hard_link;  
    AlnBlock ** alb;     
    int len;/* len for above alb  */ 
    int maxlen; /* maxlen for above alb */ 
    } ;  
/* AlnBlockList defined */ 
#ifndef DYNAMITE_DEFINED_AlnBlockList
typedef struct bp_sw_AlnBlockList bp_sw_AlnBlockList;
#define AlnBlockList bp_sw_AlnBlockList
#define DYNAMITE_DEFINED_AlnBlockList
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  at_end_AlnColumn(alc)
 *
 * Descrip:    This tells you whether the AlnColumn is at the
 *             end without passing NULL's around
 *
 *
 *
 * Arg:        alc [READ ] AlnColumn [AlnColumn *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_at_end_AlnColumn(AlnColumn * alc);
#define at_end_AlnColumn bp_sw_at_end_AlnColumn


/* Function:  bio_start_AlnUnit(alu)
 *
 * Descrip:    Tells the bio-coordinate of the
 *             start point of this alnunit
 *
 *
 * Arg:        alu [UNKN ] Undocumented argument [AlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_bio_start_AlnUnit(AlnUnit * alu);
#define bio_start_AlnUnit bp_sw_bio_start_AlnUnit


/* Function:  bio_end_AlnUnit(alu)
 *
 * Descrip:    Tells the bio-coordinate of the
 *             end point of this alnunit
 *
 *
 * Arg:        alu [UNKN ] Undocumented argument [AlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_bio_end_AlnUnit(AlnUnit * alu);
#define bio_end_AlnUnit bp_sw_bio_end_AlnUnit


/* Function:  swallow_AlnColumn_multiple(master,eaten,comp_func)
 *
 * Descrip:    This function will 'swallow' any number of AlnColumns as long
 *             as the comparison function of the labels match (the basic
 *             comp function would be something like strcmp(a,b) == 0 ? TRUE : FALSE)
 *             The columns are 'swallowed' into master and come from eaten. (these
 *             columns could be in the same linked list, though it only makes sense
 *             if the master is before the eaten).
 *
 *             It returns the first column that it could not swallow.
 *
 *             you use this to collapse regions of the label alignment.
 *
 *
 * Arg:           master [UNKN ] column which will eat other columns [AlnColumn *]
 * Arg:            eaten [UNKN ] column which will be consumed [AlnColumn *]
 * Arg:        comp_func [FUNCP] comparison function for label set [boolean (*comp_func]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_swallow_AlnColumn_multiple(AlnColumn * master,AlnColumn * eaten,boolean (*comp_func)(char *,char *));
#define swallow_AlnColumn_multiple bp_sw_swallow_AlnColumn_multiple


/* Function:  swallow_AlnColumn_number(master,eaten,num,comp_func)
 *
 * Descrip:    Basicaly the same as /swallow_AlnColumn_mulitple but there is a maximum number
 *             of columns it will swallow
 *
 *
 * Arg:           master [UNKN ] column which will eat other columns [AlnColumn *]
 * Arg:            eaten [UNKN ] column which will be consumed [AlnColumn *]
 * Arg:              num [UNKN ] max number of columns to eat [int]
 * Arg:        comp_func [FUNCP] comparison function for label set [boolean (*comp_func]
 *
 * Return [UNKN ]  number of columns eaten [int]
 *
 */
int bp_sw_swallow_AlnColumn_number(AlnColumn * master,AlnColumn * eaten,int num,boolean (*comp_func)(char *,char *));
#define swallow_AlnColumn_number bp_sw_swallow_AlnColumn_number


/* Function:  swallow_AlnColumn(master,eaten,comp_func)
 *
 * Descrip:    This is the function that actually does the 'swallowing'. It will
 *             try to swallow eaten into master. If comp_func does not give us an
 *             ok (actually using /can_swallow_AlnColumn it returns FALSE. Otherwise
 *             it moves on the end of AlnColumn in master to eaten and adds the 
 *             score of eaten to master.
 *
 *
 * Arg:           master [UNKN ] column which will eat  [AlnColumn *]
 * Arg:            eaten [UNKN ] column which will dissappear into master if eatable [AlnColumn *]
 * Arg:        comp_func [FUNCP] comparison function for labels [boolean (*comp_func]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_swallow_AlnColumn(AlnColumn * master,AlnColumn * eaten,boolean (*comp_func)(char *,char *));
#define swallow_AlnColumn bp_sw_swallow_AlnColumn


/* Function:  replace_and_free_AlnColumn_with_one(start,end,insert)
 *
 * Descrip:    Linked list manipulation function
 *
 *             Puts insert between start and end, and free's from start->next
 *             onwards. *Beware* if start is linked to end before calling this
 *             function thsi wil free end and everything chained to it. Think
 *             before you call this!
 *
 *
 * Arg:         start [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:           end [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:        insert [UNKN ] Undocumented argument [AlnColumn *]
 *
 */
void bp_sw_replace_and_free_AlnColumn_with_one(AlnColumn * start,AlnColumn * end,AlnColumn * insert);
#define replace_and_free_AlnColumn_with_one bp_sw_replace_and_free_AlnColumn_with_one


/* Function:  replace_AlnColumn_with_one(start,end,insert)
 *
 * Descrip:    Linked list manipulation function
 *
 *             places insert between start and end. If start/end are not
 *             continuous then it will loop out the start/end region
 *
 *
 * Arg:         start [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:           end [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:        insert [UNKN ] Undocumented argument [AlnColumn *]
 *
 */
void bp_sw_replace_AlnColumn_with_one(AlnColumn * start,AlnColumn * end,AlnColumn * insert);
#define replace_AlnColumn_with_one bp_sw_replace_AlnColumn_with_one


/* Function:  insert_AlnColumn(start,insert)
 *
 * Descrip:    Linked list manipulation function
 *
 *             places insert just after start: links insert
 *             up to what start was linked to
 *
 *
 * Arg:         start [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:        insert [UNKN ] Undocumented argument [AlnColumn *]
 *
 */
void bp_sw_insert_AlnColumn(AlnColumn * start,AlnColumn * insert);
#define insert_AlnColumn bp_sw_insert_AlnColumn


/* Function:  go_back_n_AlnColumn(alb,start,n)
 *
 * Descrip:    Linked list movement function
 *
 *             A nasty function to reverse up a singly linked list by going to
 *             the start and coming back until you are in the current position. yuk.
 *
 *
 * Arg:          alb [UNKN ] Undocumented argument [AlnBlock *]
 * Arg:        start [UNKN ] Undocumented argument [AlnColumn *]
 * Arg:            n [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_go_back_n_AlnColumn(AlnBlock * alb,AlnColumn * start,int n);
#define go_back_n_AlnColumn bp_sw_go_back_n_AlnColumn


/* Function:  dump_ascii_AlnBlock(alb,ofp)
 *
 * Descrip:    Dumps the alignment in rereadable ascii form.
 *
 *             Not really for human consumption
 *
 *
 * Arg:        alb [UNKN ] AlnBlock to dump [AlnBlock *]
 * Arg:        ofp [UNKN ] File stream to dump to [FILE *]
 *
 */
void bp_sw_dump_ascii_AlnBlock(AlnBlock * alb,FILE * ofp);
#define dump_ascii_AlnBlock bp_sw_dump_ascii_AlnBlock


/* Function:  bit_ascii_AlnBlock(alb,ofp)
 *
 * Descrip:    Should not be here...
 *
 *
 * Arg:        alb [UNKN ] AlnBlock to dump [AlnBlock *]
 * Arg:        ofp [UNKN ] File stream to dump to [FILE *]
 *
 */
void bp_sw_bit_ascii_AlnBlock(AlnBlock * alb,FILE * ofp);
#define bit_ascii_AlnBlock bp_sw_bit_ascii_AlnBlock


/* Function:  read_ascii_dump_AlnBlock(ifp)
 *
 * Descrip:    Reads an ascii dumped alignment
 *
 *
 * Arg:        ifp [UNKN ] File stream to read from [FILE *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_read_ascii_dump_AlnBlock(FILE * ifp);
#define read_ascii_dump_AlnBlock bp_sw_read_ascii_dump_AlnBlock


/* Function:  show_flat_AlnBlock(alb,ofp)
 *
 * Descrip:    Shows the AlnBlock in vaguely human
 *             readable form
 *
 *
 * Arg:        alb [UNKN ] AlnBlock to show [AlnBlock *]
 * Arg:        ofp [UNKN ] output [FILE *]
 *
 */
void bp_sw_show_flat_AlnBlock(AlnBlock * alb,FILE * ofp);
#define show_flat_AlnBlock bp_sw_show_flat_AlnBlock


/* Function:  get_second_end_AlnColumn(alb)
 *
 * Descrip:    Not sure if this is used!
 *
 *
 * Arg:        alb [UNKN ] Undocumented argument [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_get_second_end_AlnColumn(AlnBlock * alb);
#define get_second_end_AlnColumn bp_sw_get_second_end_AlnColumn


/* Function:  get_end_AlnColumn(alb)
 *
 * Descrip:    To get to the last AlnColumn. If this was
 *             a doubly linked list, life would be much easier
 *
 *
 * Arg:        alb [UNKN ] Undocumented argument [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_get_end_AlnColumn(AlnBlock * alb);
#define get_end_AlnColumn bp_sw_get_end_AlnColumn


/* Function:  link_AlnUnits_AlnBlock(alb)
 *
 * Descrip:    Links up all AlnUnits to their parent
 *             sequences
 *
 *
 * Arg:        alb [UNKN ] Undocumented argument [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_link_AlnUnits_AlnBlock(AlnBlock * alb);
#define link_AlnUnits_AlnBlock bp_sw_link_AlnUnits_AlnBlock


/* Function:  new_pairwise_AlnColumn(void)
 *
 * Descrip:    Function as a constructor for the special
 *             case of a pairwise alignment. Makes an
 *             AlnColumn and puts in two AlnUnits all ready
 *             to be linked in.
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_new_pairwise_AlnColumn(void);
#define new_pairwise_AlnColumn bp_sw_new_pairwise_AlnColumn


/* Function:  free_AlnColumn(obj)
 *
 * Descrip:    Specilased deconstructor needed because
 *             of linked list nature of the data structure
 *
 *
 * Arg:        obj [UNKN ] Undocumented argument [AlnColumn *]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_free_AlnColumn(AlnColumn * obj);
#define free_AlnColumn bp_sw_free_AlnColumn


/* Function:  free_AlnUnit(obj)
 *
 * Descrip:    Specilased deconstructor needed because
 *             of linked list nature of the data structure
 *
 *
 * Arg:        obj [UNKN ] Undocumented argument [AlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [AlnUnit *]
 *
 */
AlnUnit * bp_sw_free_AlnUnit(AlnUnit * obj);
#define free_AlnUnit bp_sw_free_AlnUnit


/* Function:  hard_link_AlnUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [AlnUnit *]
 *
 */
AlnUnit * bp_sw_hard_link_AlnUnit(AlnUnit * obj);
#define hard_link_AlnUnit bp_sw_hard_link_AlnUnit


/* Function:  AlnUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnUnit *]
 *
 */
AlnUnit * bp_sw_AlnUnit_alloc(void);
#define AlnUnit_alloc bp_sw_AlnUnit_alloc


/* Function:  add_AlnColumn(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [AlnColumn *]
 * Arg:        add [OWNER] Object to add to the list [AlnUnit *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnColumn(AlnColumn * obj,AlnUnit * add);
#define add_AlnColumn bp_sw_add_AlnColumn


/* Function:  flush_AlnColumn(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [AlnColumn *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnColumn(AlnColumn * obj);
#define flush_AlnColumn bp_sw_flush_AlnColumn


/* Function:  AlnColumn_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnColumn_alloc_len(AlnColumnLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_AlnColumn_alloc_std(void);
#define AlnColumn_alloc_std bp_sw_AlnColumn_alloc_std


/* Function:  AlnColumn_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_AlnColumn_alloc_len(int len);
#define AlnColumn_alloc_len bp_sw_AlnColumn_alloc_len


/* Function:  hard_link_AlnColumn(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnColumn *]
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_hard_link_AlnColumn(AlnColumn * obj);
#define hard_link_AlnColumn bp_sw_hard_link_AlnColumn


/* Function:  AlnColumn_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnColumn *]
 *
 */
AlnColumn * bp_sw_AlnColumn_alloc(void);
#define AlnColumn_alloc bp_sw_AlnColumn_alloc


/* Function:  hard_link_AlnSequence(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnSequence *]
 *
 * Return [UNKN ]  Undocumented return value [AlnSequence *]
 *
 */
AlnSequence * bp_sw_hard_link_AlnSequence(AlnSequence * obj);
#define hard_link_AlnSequence bp_sw_hard_link_AlnSequence


/* Function:  AlnSequence_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnSequence *]
 *
 */
AlnSequence * bp_sw_AlnSequence_alloc(void);
#define AlnSequence_alloc bp_sw_AlnSequence_alloc


/* Function:  free_AlnSequence(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnSequence *]
 *
 * Return [UNKN ]  Undocumented return value [AlnSequence *]
 *
 */
AlnSequence * bp_sw_free_AlnSequence(AlnSequence * obj);
#define free_AlnSequence bp_sw_free_AlnSequence


/* Function:  add_AlnBlock(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [AlnBlock *]
 * Arg:        add [OWNER] Object to add to the list [AlnSequence *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnBlock(AlnBlock * obj,AlnSequence * add);
#define add_AlnBlock bp_sw_add_AlnBlock


/* Function:  flush_AlnBlock(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnBlock(AlnBlock * obj);
#define flush_AlnBlock bp_sw_flush_AlnBlock


/* Function:  AlnBlock_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnBlock_alloc_len(AlnBlockLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_AlnBlock_alloc_std(void);
#define AlnBlock_alloc_std bp_sw_AlnBlock_alloc_std


/* Function:  AlnBlock_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_AlnBlock_alloc_len(int len);
#define AlnBlock_alloc_len bp_sw_AlnBlock_alloc_len


/* Function:  hard_link_AlnBlock(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_hard_link_AlnBlock(AlnBlock * obj);
#define hard_link_AlnBlock bp_sw_hard_link_AlnBlock


/* Function:  AlnBlock_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_AlnBlock_alloc(void);
#define AlnBlock_alloc bp_sw_AlnBlock_alloc


/* Function:  free_AlnBlock(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
AlnBlock * bp_sw_free_AlnBlock(AlnBlock * obj);
#define free_AlnBlock bp_sw_free_AlnBlock


/* Function:  add_AlnBlockList(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [AlnBlockList *]
 * Arg:        add [OWNER] Object to add to the list [AlnBlock *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnBlockList(AlnBlockList * obj,AlnBlock * add);
#define add_AlnBlockList bp_sw_add_AlnBlockList


/* Function:  flush_AlnBlockList(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [AlnBlockList *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnBlockList(AlnBlockList * obj);
#define flush_AlnBlockList bp_sw_flush_AlnBlockList


/* Function:  AlnBlockList_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnBlockList_alloc_len(AlnBlockListLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnBlockList *]
 *
 */
AlnBlockList * bp_sw_AlnBlockList_alloc_std(void);
#define AlnBlockList_alloc_std bp_sw_AlnBlockList_alloc_std


/* Function:  AlnBlockList_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlockList *]
 *
 */
AlnBlockList * bp_sw_AlnBlockList_alloc_len(int len);
#define AlnBlockList_alloc_len bp_sw_AlnBlockList_alloc_len


/* Function:  hard_link_AlnBlockList(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [AlnBlockList *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlockList *]
 *
 */
AlnBlockList * bp_sw_hard_link_AlnBlockList(AlnBlockList * obj);
#define hard_link_AlnBlockList bp_sw_hard_link_AlnBlockList


/* Function:  AlnBlockList_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [AlnBlockList *]
 *
 */
AlnBlockList * bp_sw_AlnBlockList_alloc(void);
#define AlnBlockList_alloc bp_sw_AlnBlockList_alloc


/* Function:  free_AlnBlockList(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [AlnBlockList *]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlockList *]
 *
 */
AlnBlockList * bp_sw_free_AlnBlockList(AlnBlockList * obj);
#define free_AlnBlockList bp_sw_free_AlnBlockList


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
int bp_sw_length_seq_AlnBlock(AlnBlock * obj);
#define length_seq_AlnBlock bp_sw_length_seq_AlnBlock
AlnUnit * bp_sw_access_alu_AlnColumn(AlnColumn * obj,int i);
#define access_alu_AlnColumn bp_sw_access_alu_AlnColumn
int bp_sw_length_alu_AlnColumn(AlnColumn * obj);
#define length_alu_AlnColumn bp_sw_length_alu_AlnColumn
int bp_sw_access_start_AlnUnit(AlnUnit * obj);
#define access_start_AlnUnit bp_sw_access_start_AlnUnit
int bp_sw_access_bio_end_AlnSequence(AlnSequence * obj);
#define access_bio_end_AlnSequence bp_sw_access_bio_end_AlnSequence
boolean bp_sw_replace_end_AlnUnit(AlnUnit * obj,int end);
#define replace_end_AlnUnit bp_sw_replace_end_AlnUnit
boolean bp_sw_replace_label_AlnUnit(AlnUnit * obj,int label);
#define replace_label_AlnUnit bp_sw_replace_label_AlnUnit
int bp_sw_access_label_AlnUnit(AlnUnit * obj);
#define access_label_AlnUnit bp_sw_access_label_AlnUnit
boolean bp_sw_replace_start_AlnBlock(AlnBlock * obj,AlnColumn * start);
#define replace_start_AlnBlock bp_sw_replace_start_AlnBlock
boolean bp_sw_replace_text_label_AlnUnit(AlnUnit * obj,char * text_label);
#define replace_text_label_AlnUnit bp_sw_replace_text_label_AlnUnit
AlnColumn * bp_sw_access_start_AlnBlock(AlnBlock * obj);
#define access_start_AlnBlock bp_sw_access_start_AlnBlock
char * bp_sw_access_text_label_AlnUnit(AlnUnit * obj);
#define access_text_label_AlnUnit bp_sw_access_text_label_AlnUnit
boolean bp_sw_replace_length_AlnBlock(AlnBlock * obj,int length);
#define replace_length_AlnBlock bp_sw_replace_length_AlnBlock
boolean bp_sw_replace_bio_start_AlnSequence(AlnSequence * obj,int bio_start);
#define replace_bio_start_AlnSequence bp_sw_replace_bio_start_AlnSequence
boolean bp_sw_replace_next_AlnUnit(AlnUnit * obj,AlnUnit * next);
#define replace_next_AlnUnit bp_sw_replace_next_AlnUnit
boolean bp_sw_replace_score_AlnBlock(AlnBlock * obj,int score);
#define replace_score_AlnBlock bp_sw_replace_score_AlnBlock
AlnUnit * bp_sw_access_next_AlnUnit(AlnUnit * obj);
#define access_next_AlnUnit bp_sw_access_next_AlnUnit
boolean bp_sw_replace_next_AlnColumn(AlnColumn * obj,AlnColumn * next);
#define replace_next_AlnColumn bp_sw_replace_next_AlnColumn
void * bp_sw_access_data_AlnSequence(AlnSequence * obj);
#define access_data_AlnSequence bp_sw_access_data_AlnSequence
boolean bp_sw_replace_in_column_AlnUnit(AlnUnit * obj,boolean in_column);
#define replace_in_column_AlnUnit bp_sw_replace_in_column_AlnUnit
boolean bp_sw_replace_start_AlnUnit(AlnUnit * obj,int start);
#define replace_start_AlnUnit bp_sw_replace_start_AlnUnit
boolean bp_sw_access_in_column_AlnUnit(AlnUnit * obj);
#define access_in_column_AlnUnit bp_sw_access_in_column_AlnUnit
boolean bp_sw_replace_bio_end_AlnSequence(AlnSequence * obj,int bio_end);
#define replace_bio_end_AlnSequence bp_sw_replace_bio_end_AlnSequence
boolean bp_sw_replace_seq_AlnUnit(AlnUnit * obj,AlnSequence * seq);
#define replace_seq_AlnUnit bp_sw_replace_seq_AlnUnit
AlnSequence * bp_sw_access_seq_AlnBlock(AlnBlock * obj,int i);
#define access_seq_AlnBlock bp_sw_access_seq_AlnBlock
AlnSequence * bp_sw_access_seq_AlnUnit(AlnUnit * obj);
#define access_seq_AlnUnit bp_sw_access_seq_AlnUnit
int bp_sw_access_score_AlnBlock(AlnBlock * obj);
#define access_score_AlnBlock bp_sw_access_score_AlnBlock
boolean bp_sw_replace_start_AlnSequence(AlnSequence * obj,AlnUnit * start);
#define replace_start_AlnSequence bp_sw_replace_start_AlnSequence
int bp_sw_access_end_AlnUnit(AlnUnit * obj);
#define access_end_AlnUnit bp_sw_access_end_AlnUnit
AlnUnit * bp_sw_access_start_AlnSequence(AlnSequence * obj);
#define access_start_AlnSequence bp_sw_access_start_AlnSequence
int bp_sw_access_length_AlnBlock(AlnBlock * obj);
#define access_length_AlnBlock bp_sw_access_length_AlnBlock
boolean bp_sw_replace_data_type_AlnSequence(AlnSequence * obj,int data_type);
#define replace_data_type_AlnSequence bp_sw_replace_data_type_AlnSequence
int bp_sw_access_bio_start_AlnSequence(AlnSequence * obj);
#define access_bio_start_AlnSequence bp_sw_access_bio_start_AlnSequence
int bp_sw_access_data_type_AlnSequence(AlnSequence * obj);
#define access_data_type_AlnSequence bp_sw_access_data_type_AlnSequence
AlnColumn * bp_sw_access_next_AlnColumn(AlnColumn * obj);
#define access_next_AlnColumn bp_sw_access_next_AlnColumn
boolean bp_sw_replace_data_AlnSequence(AlnSequence * obj,void * data);
#define replace_data_AlnSequence bp_sw_replace_data_AlnSequence
boolean bp_sw_can_swallow_AlnColumn(AlnColumn * master,AlnColumn * eaten,boolean (*comp_func)(char *,char *));
#define can_swallow_AlnColumn bp_sw_can_swallow_AlnColumn
boolean bp_sw_identical_labels_in_AlnColumn(AlnColumn * one,AlnColumn * two,boolean (*comp_func)(char *,char *));
#define identical_labels_in_AlnColumn bp_sw_identical_labels_in_AlnColumn
boolean bp_sw_identical_labels_in_AlnUnits(AlnUnit * one,AlnUnit * two,boolean (*comp_func)(char *,char *));
#define identical_labels_in_AlnUnits bp_sw_identical_labels_in_AlnUnits
AlnColumn * bp_sw_read_dumped_ascii_AlnColumn_line(char * line);
#define read_dumped_ascii_AlnColumn_line bp_sw_read_dumped_ascii_AlnColumn_line
void bp_sw_show_flat_AlnColumn(AlnColumn * alc,FILE * ofp);
#define show_flat_AlnColumn bp_sw_show_flat_AlnColumn
void bp_sw_show_flat_AlnUnit(AlnUnit * alu,FILE * ofp);
#define show_flat_AlnUnit bp_sw_show_flat_AlnUnit
AlnUnit * bp_sw_read_flat_AlnUnit_line(char * line,int * ret_pos);
#define read_flat_AlnUnit_line bp_sw_read_flat_AlnUnit_line
void bp_sw_swap_AlnColumn(AlnUnit ** list,int i,int j) ;
#define swap_AlnColumn bp_sw_swap_AlnColumn
void bp_sw_qsort_AlnColumn(AlnUnit ** list,int left,int right,int (*comp)(AlnUnit * ,AlnUnit * ));
#define qsort_AlnColumn bp_sw_qsort_AlnColumn
void bp_sw_sort_AlnColumn(AlnColumn * obj,int (*comp)(AlnUnit *, AlnUnit *));
#define sort_AlnColumn bp_sw_sort_AlnColumn
boolean bp_sw_expand_AlnColumn(AlnColumn * obj,int len);
#define expand_AlnColumn bp_sw_expand_AlnColumn
void bp_sw_swap_AlnBlock(AlnSequence ** list,int i,int j) ;
#define swap_AlnBlock bp_sw_swap_AlnBlock
void bp_sw_qsort_AlnBlock(AlnSequence ** list,int left,int right,int (*comp)(AlnSequence * ,AlnSequence * ));
#define qsort_AlnBlock bp_sw_qsort_AlnBlock
void bp_sw_sort_AlnBlock(AlnBlock * obj,int (*comp)(AlnSequence *, AlnSequence *));
#define sort_AlnBlock bp_sw_sort_AlnBlock
boolean bp_sw_expand_AlnBlock(AlnBlock * obj,int len);
#define expand_AlnBlock bp_sw_expand_AlnBlock
void bp_sw_swap_AlnBlockList(AlnBlock ** list,int i,int j) ;
#define swap_AlnBlockList bp_sw_swap_AlnBlockList
void bp_sw_qsort_AlnBlockList(AlnBlock ** list,int left,int right,int (*comp)(AlnBlock * ,AlnBlock * ));
#define qsort_AlnBlockList bp_sw_qsort_AlnBlockList
void bp_sw_sort_AlnBlockList(AlnBlockList * obj,int (*comp)(AlnBlock *, AlnBlock *));
#define sort_AlnBlockList bp_sw_sort_AlnBlockList
boolean bp_sw_expand_AlnBlockList(AlnBlockList * obj,int len);
#define expand_AlnBlockList bp_sw_expand_AlnBlockList

#ifdef _cplusplus
}
#endif

#endif
