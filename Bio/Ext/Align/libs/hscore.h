#ifndef DYNAMITEhscoreHEADERFILE
#define DYNAMITEhscoreHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"
#include "histogram.h"

#define HscoreLISTLENGTH 256
#define DATAENTRYSTDPOINTS 8

#define DATASCORESTORAGE_LENGTH 1024

/* Object DataEntry
 *
 * Descrip: A lightweight structure to represent the information
 *        a db search algorithm will want to store and *nothing*
 *        more about a single entry
 *
 *
 */
struct bp_sw_DataEntry {  
    int dynamite_hard_link;  
    char * name;    /*  name of the entry */ 
    int data[DATAENTRYSTDPOINTS];   /*  space for algorithms to use  */ 
    boolean is_reversed;    /*  for sequences. handy */ 
    char * filename;    /*  useful for indexers etc. */ 
    } ;  
/* DataEntry defined */ 
#ifndef DYNAMITE_DEFINED_DataEntry
typedef struct bp_sw_DataEntry bp_sw_DataEntry;
#define DataEntry bp_sw_DataEntry
#define DYNAMITE_DEFINED_DataEntry
#endif


/* Object DataScore
 *
 * Descrip: The basic one entry vs one entry structure
 *
 *
 */
struct bp_sw_DataScore {  
    int dynamite_hard_link;  
    DataEntry * query;   
    DataEntry * target;  
    int score;   
    double evalue;   
    int is_stored;   
    } ;  
/* DataScore defined */ 
#ifndef DYNAMITE_DEFINED_DataScore
typedef struct bp_sw_DataScore bp_sw_DataScore;
#define DataScore bp_sw_DataScore
#define DYNAMITE_DEFINED_DataScore
#endif


/* Object DataScoreStorage
 *
 * Descrip: Scary internal structure to simplify storage methods
 *
 *
 */
struct bp_sw_DataScoreStorage {  
    int dynamite_hard_link;  
    DataScore score_array[DATASCORESTORAGE_LENGTH];  
    DataEntry query_array[DATASCORESTORAGE_LENGTH];  
    DataEntry target_array[DATASCORESTORAGE_LENGTH];     
    int curr_pos;    
    } ;  
/* DataScoreStorage defined */ 
#ifndef DYNAMITE_DEFINED_DataScoreStorage
typedef struct bp_sw_DataScoreStorage bp_sw_DataScoreStorage;
#define DataScoreStorage bp_sw_DataScoreStorage
#define DYNAMITE_DEFINED_DataScoreStorage
#endif


/* Object Hscore
 *
 * Descrip: Holds the information about a db search.
 *        Meant to be very lightweight
 *
 *        The histogram is carried for on-the-fly histogram storage outside
 *        of the database. The idea is that the function should_store will
 *        tell whether the datascore structure should be stored (if it is
 *        NULL, it is always stored). The score_to_his function maps the
 *        score in datascore to the float in Histogram, allowing the scoring
 *        system of the search method to be on a different basis to the 
 *        scoring system of the histogram. For most times, this is going to
 *        be Score2Bits
 *
 *        To prevent too much dependency, the 'standard' way of making a 
 *        histogram that has a bits cut off level is done using functions
 *        in the dynlibcross module (cross code), as it needs both Hscore and
 *        Probability 
 *
 *
 */
struct bp_sw_Hscore {  
    int dynamite_hard_link;  
    DataScore ** ds;     
    int len;/* len for above ds  */ 
    int maxlen; /* maxlen for above ds */ 
    DataScoreStorage ** store;   
    int st_len; /* len for above store  */ 
    int st_maxlen;  /* maxlen for above store */ 
    Histogram * his;     
    double score_level; /*  passed into should_store function */ 
    boolean (*should_store)(int given_score,double internal_score_level);    
    float (*score_to_his)(int given_score);  
    int report_level;   /*  number of sequences to report on */ 
    long total; /*  total number of scores (duplicated info in histogram)  */ 
    } ;  
/* Hscore defined */ 
#ifndef DYNAMITE_DEFINED_Hscore
typedef struct bp_sw_Hscore bp_sw_Hscore;
#define Hscore bp_sw_Hscore
#define DYNAMITE_DEFINED_Hscore
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  should_store_Hscore(hs,score)
 *
 * Descrip:    Tells whether this score should be stored
 *             or not. Also updates Histogram if needed
 *
 *
 * Arg:           hs [UNKN ] Undocumented argument [Hscore *]
 * Arg:        score [UNKN ] Undocumented argument [int]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_should_store_Hscore(Hscore * hs,int score);
#define should_store_Hscore bp_sw_should_store_Hscore


/* Function:  length_datascore_Hscore(obj)
 *
 * Descrip:    Returns the number of datascores in the hscore
 *             structure
 *
 *
 * Arg:        obj [READ ] Hscore object [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_length_datascore_Hscore(Hscore * obj);
#define length_datascore_Hscore bp_sw_length_datascore_Hscore


/* Function:  get_datascore_Hscore(hs,i)
 *
 * Descrip:    Returns the specific datascore held at this
 *             position.
 *
 *             This requires a considerable amount of memory
 *             duplication, so please dont process all your
 *             results by looping through this.
 *
 *
 * Arg:        hs [READ ] Hscore object [Hscore *]
 * Arg:         i [UNKN ] position to be read [int]
 *
 * Return [OWNER]  New datascore object [DataScore *]
 *
 */
DataScore * bp_sw_get_datascore_Hscore(Hscore * hs,int i);
#define get_datascore_Hscore bp_sw_get_datascore_Hscore


/* Function:  get_score_Hscore(hs,i)
 *
 * Descrip: No Description
 *
 * Arg:        hs [READ ] Hscore object [Hscore *]
 * Arg:         i [UNKN ] position to be read [int]
 *
 * Return [UNKN ]  score  [int]
 *
 */
int bp_sw_get_score_Hscore(Hscore * hs,int i);
#define get_score_Hscore bp_sw_get_score_Hscore


/* Function:  get_evalue_Hscore(hs,i)
 *
 * Descrip:    Returns the evalue of the specific datascore held at this position.
 *
 *
 *
 * Arg:        hs [READ ] Hscore object [Hscore *]
 * Arg:         i [UNKN ] position to be read [int]
 *
 * Return [UNKN ]  evalue  [double]
 *
 */
double bp_sw_get_evalue_Hscore(Hscore * hs,int i);
#define get_evalue_Hscore bp_sw_get_evalue_Hscore


/* Function:  fit_Hscore_to_EVD(hs,guess_of_outliers)
 *
 * Descrip:    If a histogram is present, tries to fit the histogram and
 *             then gives evalues to all the scores in the Hscore model
 *
 *
 * Arg:                       hs [UNKN ] Undocumented argument [Hscore *]
 * Arg:        guess_of_outliers [UNKN ] Undocumented argument [float]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_fit_Hscore_to_EVD(Hscore * hs,float guess_of_outliers);
#define fit_Hscore_to_EVD bp_sw_fit_Hscore_to_EVD


/* Function:  minimum_score_Hscore(hs)
 *
 * Descrip:    gets the minimum score from Hscore
 *
 *
 * Arg:        hs [UNKN ] Undocumented argument [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_minimum_score_Hscore(Hscore * hs);
#define minimum_score_Hscore bp_sw_minimum_score_Hscore


/* Function:  maximum_score_Hscore(hs)
 *
 * Descrip:    gets the maximum score from Hscore
 *
 *
 * Arg:        hs [UNKN ] Undocumented argument [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_maximum_score_Hscore(Hscore * hs);
#define maximum_score_Hscore bp_sw_maximum_score_Hscore


/* Function:  basic_show_Hscore(hs,ofp)
 *
 * Descrip:    The most baby-talk showing of Hscore
 *
 *
 * Arg:         hs [UNKN ] Undocumented argument [Hscore *]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_basic_show_Hscore(Hscore * hs,FILE * ofp);
#define basic_show_Hscore bp_sw_basic_show_Hscore


/* Function:  sort_Hscore_by_score(hs)
 *
 * Descrip:    As it says, sorts the high score by its score
 *
 *
 * Arg:        hs [UNKN ] Hscore to be sorted [Hscore *]
 *
 */
void bp_sw_sort_Hscore_by_score(Hscore * hs);
#define sort_Hscore_by_score bp_sw_sort_Hscore_by_score


/* Function:  free_DataScore(obj)
 *
 * Descrip:    Correctly handles destruction of a datascore
 *
 *
 * Arg:        obj [UNKN ] Undocumented argument [DataScore *]
 *
 * Return [UNKN ]  Undocumented return value [DataScore *]
 *
 */
DataScore * bp_sw_free_DataScore(DataScore * obj);
#define free_DataScore bp_sw_free_DataScore


/* Function:  free_DataScoreStorage(obj)
 *
 * Descrip:    Correctly handles destruction of DataScoreStorage, by
 *             freeing members in data storage
 *
 *
 * Arg:        obj [UNKN ] Undocumented argument [DataScoreStorage *]
 *
 * Return [UNKN ]  Undocumented return value [DataScoreStorage *]
 *
 */
DataScoreStorage * bp_sw_free_DataScoreStorage(DataScoreStorage * obj);
#define free_DataScoreStorage bp_sw_free_DataScoreStorage


/* Function:  new_DataScoreStorage(void)
 *
 * Descrip:    Makes a new DataScoreStorage with all the pointers connected correctly
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DataScoreStorage *]
 *
 */
DataScoreStorage * bp_sw_new_DataScoreStorage(void);
#define new_DataScoreStorage bp_sw_new_DataScoreStorage


/* Function:  hard_link_DataEntry(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [DataEntry *]
 *
 * Return [UNKN ]  Undocumented return value [DataEntry *]
 *
 */
DataEntry * bp_sw_hard_link_DataEntry(DataEntry * obj);
#define hard_link_DataEntry bp_sw_hard_link_DataEntry


/* Function:  DataEntry_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DataEntry *]
 *
 */
DataEntry * bp_sw_DataEntry_alloc(void);
#define DataEntry_alloc bp_sw_DataEntry_alloc


/* Function:  free_DataEntry(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [DataEntry *]
 *
 * Return [UNKN ]  Undocumented return value [DataEntry *]
 *
 */
DataEntry * bp_sw_free_DataEntry(DataEntry * obj);
#define free_DataEntry bp_sw_free_DataEntry


/* Function:  hard_link_DataScore(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [DataScore *]
 *
 * Return [UNKN ]  Undocumented return value [DataScore *]
 *
 */
DataScore * bp_sw_hard_link_DataScore(DataScore * obj);
#define hard_link_DataScore bp_sw_hard_link_DataScore


/* Function:  DataScore_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DataScore *]
 *
 */
DataScore * bp_sw_DataScore_alloc(void);
#define DataScore_alloc bp_sw_DataScore_alloc


/* Function:  hard_link_DataScoreStorage(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [DataScoreStorage *]
 *
 * Return [UNKN ]  Undocumented return value [DataScoreStorage *]
 *
 */
DataScoreStorage * bp_sw_hard_link_DataScoreStorage(DataScoreStorage * obj);
#define hard_link_DataScoreStorage bp_sw_hard_link_DataScoreStorage


/* Function:  DataScoreStorage_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [DataScoreStorage *]
 *
 */
DataScoreStorage * bp_sw_DataScoreStorage_alloc(void);
#define DataScoreStorage_alloc bp_sw_DataScoreStorage_alloc


/* Function:  add_Hscore(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [Hscore *]
 * Arg:        add [OWNER] Object to add to the list [DataScore *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_Hscore(Hscore * obj,DataScore * add);
#define add_Hscore bp_sw_add_Hscore


/* Function:  flush_Hscore(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_Hscore(Hscore * obj);
#define flush_Hscore bp_sw_flush_Hscore


/* Function:  add_st_Hscore(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [Hscore *]
 * Arg:        add [OWNER] Object to add to the list [DataScoreStorage *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_st_Hscore(Hscore * obj,DataScoreStorage * add);
#define add_st_Hscore bp_sw_add_st_Hscore


/* Function:  flush_st_Hscore(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_st_Hscore(Hscore * obj);
#define flush_st_Hscore bp_sw_flush_st_Hscore


/* Function:  Hscore_alloc_std(void)
 *
 * Descrip:    Equivalent to Hscore_alloc_len(HscoreLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_Hscore_alloc_std(void);
#define Hscore_alloc_std bp_sw_Hscore_alloc_std


/* Function:  Hscore_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_Hscore_alloc_len(int len);
#define Hscore_alloc_len bp_sw_Hscore_alloc_len


/* Function:  hard_link_Hscore(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_hard_link_Hscore(Hscore * obj);
#define hard_link_Hscore bp_sw_hard_link_Hscore


/* Function:  Hscore_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_Hscore_alloc(void);
#define Hscore_alloc bp_sw_Hscore_alloc


/* Function:  free_Hscore(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [Hscore *]
 *
 * Return [UNKN ]  Undocumented return value [Hscore *]
 *
 */
Hscore * bp_sw_free_Hscore(Hscore * obj);
#define free_Hscore bp_sw_free_Hscore


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_replace_target_DataScore(DataScore * obj,DataEntry * target);
#define replace_target_DataScore bp_sw_replace_target_DataScore
DataEntry * bp_sw_access_target_DataScore(DataScore * obj);
#define access_target_DataScore bp_sw_access_target_DataScore
boolean bp_sw_replace_score_DataScore(DataScore * obj,int score);
#define replace_score_DataScore bp_sw_replace_score_DataScore
boolean bp_sw_access_is_reversed_DataEntry(DataEntry * obj);
#define access_is_reversed_DataEntry bp_sw_access_is_reversed_DataEntry
int bp_sw_access_score_DataScore(DataScore * obj);
#define access_score_DataScore bp_sw_access_score_DataScore
char * bp_sw_access_filename_DataEntry(DataEntry * obj);
#define access_filename_DataEntry bp_sw_access_filename_DataEntry
boolean bp_sw_replace_evalue_DataScore(DataScore * obj,double evalue);
#define replace_evalue_DataScore bp_sw_replace_evalue_DataScore
DataEntry * bp_sw_access_query_DataScore(DataScore * obj);
#define access_query_DataScore bp_sw_access_query_DataScore
double bp_sw_access_evalue_DataScore(DataScore * obj);
#define access_evalue_DataScore bp_sw_access_evalue_DataScore
boolean bp_sw_replace_query_DataScore(DataScore * obj,DataEntry * query);
#define replace_query_DataScore bp_sw_replace_query_DataScore
boolean bp_sw_replace_is_reversed_DataEntry(DataEntry * obj,boolean is_reversed);
#define replace_is_reversed_DataEntry bp_sw_replace_is_reversed_DataEntry
boolean bp_sw_replace_name_DataEntry(DataEntry * obj,char * name);
#define replace_name_DataEntry bp_sw_replace_name_DataEntry
boolean bp_sw_replace_filename_DataEntry(DataEntry * obj,char * filename);
#define replace_filename_DataEntry bp_sw_replace_filename_DataEntry
char * bp_sw_access_name_DataEntry(DataEntry * obj);
#define access_name_DataEntry bp_sw_access_name_DataEntry
void bp_sw_copy_DataEntry(DataEntry * from,DataEntry * to);
#define copy_DataEntry bp_sw_copy_DataEntry
int bp_sw_compare_DataScore_by_score(DataScore * one,DataScore * two);
#define compare_DataScore_by_score bp_sw_compare_DataScore_by_score
DataScore * bp_sw_new_DataScore(void);
#define new_DataScore bp_sw_new_DataScore
DataScore * bp_sw_new_DataScore_from_storage(Hscore * hs);
#define new_DataScore_from_storage bp_sw_new_DataScore_from_storage
void bp_sw_swap_Hscore(DataScore ** list,int i,int j) ;
#define swap_Hscore bp_sw_swap_Hscore
void bp_sw_qsort_Hscore(DataScore ** list,int left,int right,int (*comp)(DataScore * ,DataScore * ));
#define qsort_Hscore bp_sw_qsort_Hscore
void bp_sw_sort_Hscore(Hscore * obj,int (*comp)(DataScore *, DataScore *));
#define sort_Hscore bp_sw_sort_Hscore
boolean bp_sw_expand_Hscore(Hscore * obj,int len);
#define expand_Hscore bp_sw_expand_Hscore
void bp_sw_swap_st_Hscore(DataScoreStorage ** list,int i,int j) ;
#define swap_st_Hscore bp_sw_swap_st_Hscore
void bp_sw_qsort_st_Hscore(DataScoreStorage ** list,int left,int right,int (*comp)(DataScoreStorage * ,DataScoreStorage * ));
#define qsort_st_Hscore bp_sw_qsort_st_Hscore
void bp_sw_sort_st_Hscore(Hscore * obj,int (*comp)(DataScoreStorage *, DataScoreStorage *));
#define sort_st_Hscore bp_sw_sort_st_Hscore
boolean bp_sw_expand_st_Hscore(Hscore * obj,int len);
#define expand_st_Hscore bp_sw_expand_st_Hscore

#ifdef _cplusplus
}
#endif

#endif
