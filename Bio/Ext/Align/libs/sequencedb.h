#ifndef DYNAMITEsequencedbHEADERFILE
#define DYNAMITEsequencedbHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "sequence.h"
#include "database.h"
#include "hscore.h"


#define SequenceDBLISTLENGTH 128

enum SequenceDBFormat {
  SEQ_DB_UNKNOWN = 32,
  SEQ_DB_FASTA };

struct bp_sw_FileSource {  
    int dynamite_hard_link;  
    char * filename;     
    FILE * input;   /*  could be stdin!  */ 
    int format;  
    int type;    
    } ;  
/* FileSource defined */ 
#ifndef DYNAMITE_DEFINED_FileSource
typedef struct bp_sw_FileSource bp_sw_FileSource;
#define FileSource bp_sw_FileSource
#define DYNAMITE_DEFINED_FileSource
#endif


/* Object SequenceDB
 *
 * Descrip: This is the basic Sequence database
 *        wrapper - it handles all the formats
 *        and the on-the-fly indexing.
 *
 *        Generally it wont be directly used by
 *        an algorithm, which will be using something
 *        specific to the sequence type produce complex 
 *        sequence type objects
 *
 *
 */
struct bp_sw_SequenceDB {  
    int dynamite_hard_link;  
    char * name;     
    FileSource ** fs;    
    int len;/* len for above fs  */ 
    int maxlen; /* maxlen for above fs */ 
    int current_source;  
    FILE * current_file;     
    int sequence_no;     
    int byte_position;   
    } ;  
/* SequenceDB defined */ 
#ifndef DYNAMITE_DEFINED_SequenceDB
typedef struct bp_sw_SequenceDB bp_sw_SequenceDB;
#define SequenceDB bp_sw_SequenceDB
#define DYNAMITE_DEFINED_SequenceDB
#endif




    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  get_Sequence_from_SequenceDB(sdb,de)
 *
 * Descrip:    Quite a mindless function which retrieves sequences
 *             via indexes
 *
 *             Going to spend too much time in fopen if this is used
 *             too much
 *
 *
 * Arg:        sdb [UNKN ] Undocumented argument [SequenceDB *]
 * Arg:         de [UNKN ] Undocumented argument [DataEntry *]
 *
 * Return [UNKN ]  Undocumented return value [Sequence *]
 *
 */
Sequence * bp_sw_get_Sequence_from_SequenceDB(SequenceDB * sdb,DataEntry * de);
#define get_Sequence_from_SequenceDB bp_sw_get_Sequence_from_SequenceDB


/* Function:  add_SequenceDB_info_DataEntry(sdb,de)
 *
 * Descrip:    A function which places data into dataentry so we can
 *             be guarenteed to retrieve it sometime.
 *
 *             It uses 0 and 1 points in the Data array.
 *
 *
 * Arg:        sdb [UNKN ] Undocumented argument [SequenceDB *]
 * Arg:         de [UNKN ] Undocumented argument [DataEntry *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_SequenceDB_info_DataEntry(SequenceDB * sdb,DataEntry * de);
#define add_SequenceDB_info_DataEntry bp_sw_add_SequenceDB_info_DataEntry


/* Function:  close_SequenceDB(last,sdb)
 *
 * Descrip:    top level function that closes the SequenceDB
 *             after the last sequence is read.
 *
 *
 * Arg:        last [WRITE] Sequence object to be freed  [Sequence *]
 * Arg:         sdb [READ ] database to be closed [SequenceDB *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_close_SequenceDB(Sequence * last,SequenceDB * sdb);
#define close_SequenceDB bp_sw_close_SequenceDB


/* Function:  init_SequenceDB(sdb,return_status)
 *
 * Descrip:    top level function that starts a database read on
 *             SequenceDB
 *
 *
 *
 * Arg:                  sdb [READ ] sequence database [SequenceDB *]
 * Arg:        return_status [WRITE] returns the database status as found in database.h [int *]
 *
 * Return [UNKN ]  Undocumented return value [Sequence *]
 *
 */
Sequence * bp_sw_init_SequenceDB(SequenceDB * sdb,int * return_status);
#define init_SequenceDB bp_sw_init_SequenceDB


/* Function:  reload_SequenceDB(last,sdb,return_status)
 *
 * Descrip:    top level function that reloads a sequence database
 *
 *
 *
 * Arg:                 last [WRITE] previous sequence to be used: will simply be freed at the moment [Sequence *]
 * Arg:                  sdb [UNKN ] sequence database [SequenceDB *]
 * Arg:        return_status [WRITE] returns the database status as found in database.h [int *]
 *
 * Return [UNKN ]  Undocumented return value [Sequence *]
 *
 */
Sequence * bp_sw_reload_SequenceDB(Sequence * last,SequenceDB * sdb,int * return_status);
#define reload_SequenceDB bp_sw_reload_SequenceDB


/* Function:  SequenceDB_from_FILE_and_format(input,format)
 *
 * Descrip:    makes a SequencDB from a straight file stream.
 *
 *             This means SequenceDB will *not* close it when
 *             the SequenceDB is closed.
 *
 *
 * Arg:         input [READ ] filestream [FILE *]
 * Arg:        format [UNKN ] format as defined by /word_to_format [int]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_SequenceDB_from_FILE_and_format(FILE * input,int format);
#define SequenceDB_from_FILE_and_format bp_sw_SequenceDB_from_FILE_and_format


/* Function:  single_fasta_SequenceDB(filename)
 *
 * Descrip:    pre-packed single fasta file db
 *
 *
 *
 * Arg:        filename [UNKN ] name of fastadb [char *]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_single_fasta_SequenceDB(char * filename);
#define single_fasta_SequenceDB bp_sw_single_fasta_SequenceDB


/* Function:  read_SequenceDB_line(line,ifp)
 *
 * Descrip:    Reads a SequenceDB definition from
 *
 *             seqdb <name>
 *             <filename> <format> <type>
 *             ...
 *             endseqdb
 *
 *
 *
 * Arg:        line [UNKN ] starting line (seqdb line) [char *]
 * Arg:         ifp [UNKN ] file input [FILE *]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_read_SequenceDB_line(char * line,FILE * ifp);
#define read_SequenceDB_line bp_sw_read_SequenceDB_line


/* Function:  word_to_format(word)
 *
 * Descrip:    converts char * to format for SequenceDB FileSources
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_word_to_format(char * word);
#define word_to_format bp_sw_word_to_format


/* Function:  hard_link_FileSource(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [FileSource *]
 *
 * Return [UNKN ]  Undocumented return value [FileSource *]
 *
 */
FileSource * bp_sw_hard_link_FileSource(FileSource * obj);
#define hard_link_FileSource bp_sw_hard_link_FileSource


/* Function:  FileSource_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [FileSource *]
 *
 */
FileSource * bp_sw_FileSource_alloc(void);
#define FileSource_alloc bp_sw_FileSource_alloc


/* Function:  free_FileSource(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [FileSource *]
 *
 * Return [UNKN ]  Undocumented return value [FileSource *]
 *
 */
FileSource * bp_sw_free_FileSource(FileSource * obj);
#define free_FileSource bp_sw_free_FileSource


/* Function:  add_SequenceDB(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list [SequenceDB *]
 * Arg:        add [OWNER] Object to add to the list [FileSource *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_SequenceDB(SequenceDB * obj,FileSource * add);
#define add_SequenceDB bp_sw_add_SequenceDB


/* Function:  flush_SequenceDB(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj [UNKN ] Object which contains the list  [SequenceDB *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_flush_SequenceDB(SequenceDB * obj);
#define flush_SequenceDB bp_sw_flush_SequenceDB


/* Function:  SequenceDB_alloc_std(void)
 *
 * Descrip:    Equivalent to SequenceDB_alloc_len(SequenceDBLISTLENGTH)
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_SequenceDB_alloc_std(void);
#define SequenceDB_alloc_std bp_sw_SequenceDB_alloc_std


/* Function:  SequenceDB_alloc_len(len)
 *
 * Descrip:    Allocates len length to all lists
 *
 *
 * Arg:        len [UNKN ] Length of lists to allocate [int]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_SequenceDB_alloc_len(int len);
#define SequenceDB_alloc_len bp_sw_SequenceDB_alloc_len


/* Function:  hard_link_SequenceDB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj [UNKN ] Object to be hard linked [SequenceDB *]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_hard_link_SequenceDB(SequenceDB * obj);
#define hard_link_SequenceDB bp_sw_hard_link_SequenceDB


/* Function:  SequenceDB_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_SequenceDB_alloc(void);
#define SequenceDB_alloc bp_sw_SequenceDB_alloc


/* Function:  free_SequenceDB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj [UNKN ] Object that is free'd [SequenceDB *]
 *
 * Return [UNKN ]  Undocumented return value [SequenceDB *]
 *
 */
SequenceDB * bp_sw_free_SequenceDB(SequenceDB * obj);
#define free_SequenceDB bp_sw_free_SequenceDB


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
FileSource * bp_sw_access_fs_SequenceDB(SequenceDB * obj,int i);
#define access_fs_SequenceDB bp_sw_access_fs_SequenceDB
int bp_sw_access_current_source_SequenceDB(SequenceDB * obj);
#define access_current_source_SequenceDB bp_sw_access_current_source_SequenceDB
boolean bp_sw_replace_current_source_SequenceDB(SequenceDB * obj,int current_source);
#define replace_current_source_SequenceDB bp_sw_replace_current_source_SequenceDB
boolean bp_sw_replace_current_file_SequenceDB(SequenceDB * obj,FILE * current_file);
#define replace_current_file_SequenceDB bp_sw_replace_current_file_SequenceDB
boolean bp_sw_replace_sequence_no_SequenceDB(SequenceDB * obj,int sequence_no);
#define replace_sequence_no_SequenceDB bp_sw_replace_sequence_no_SequenceDB
int bp_sw_access_sequence_no_SequenceDB(SequenceDB * obj);
#define access_sequence_no_SequenceDB bp_sw_access_sequence_no_SequenceDB
boolean bp_sw_replace_name_SequenceDB(SequenceDB * obj,char * name);
#define replace_name_SequenceDB bp_sw_replace_name_SequenceDB
int bp_sw_access_format_FileSource(FileSource * obj);
#define access_format_FileSource bp_sw_access_format_FileSource
boolean bp_sw_replace_byte_position_SequenceDB(SequenceDB * obj,int byte_position);
#define replace_byte_position_SequenceDB bp_sw_replace_byte_position_SequenceDB
int bp_sw_length_fs_SequenceDB(SequenceDB * obj);
#define length_fs_SequenceDB bp_sw_length_fs_SequenceDB
boolean bp_sw_replace_format_FileSource(FileSource * obj,int format);
#define replace_format_FileSource bp_sw_replace_format_FileSource
int bp_sw_access_byte_position_SequenceDB(SequenceDB * obj);
#define access_byte_position_SequenceDB bp_sw_access_byte_position_SequenceDB
FILE * bp_sw_access_current_file_SequenceDB(SequenceDB * obj);
#define access_current_file_SequenceDB bp_sw_access_current_file_SequenceDB
boolean bp_sw_replace_filename_FileSource(FileSource * obj,char * filename);
#define replace_filename_FileSource bp_sw_replace_filename_FileSource
char * bp_sw_access_name_SequenceDB(SequenceDB * obj);
#define access_name_SequenceDB bp_sw_access_name_SequenceDB
char * bp_sw_access_filename_FileSource(FileSource * obj);
#define access_filename_FileSource bp_sw_access_filename_FileSource
boolean bp_sw_replace_type_FileSource(FileSource * obj,int type);
#define replace_type_FileSource bp_sw_replace_type_FileSource
boolean bp_sw_replace_input_FileSource(FileSource * obj,FILE * input);
#define replace_input_FileSource bp_sw_replace_input_FileSource
int bp_sw_access_type_FileSource(FileSource * obj);
#define access_type_FileSource bp_sw_access_type_FileSource
FILE * bp_sw_access_input_FileSource(FileSource * obj);
#define access_input_FileSource bp_sw_access_input_FileSource
Sequence * bp_sw_get_next_SequenceDB(SequenceDB * sdb);
#define get_next_SequenceDB bp_sw_get_next_SequenceDB
boolean bp_sw_SequenceDB_at_end(SequenceDB * sdb);
#define SequenceDB_at_end bp_sw_SequenceDB_at_end
boolean bp_sw_load_next_fs_SequenceDB(SequenceDB * sdb);
#define load_next_fs_SequenceDB bp_sw_load_next_fs_SequenceDB
boolean bp_sw_close_last_fs_SequenceDB(SequenceDB * sdb);
#define close_last_fs_SequenceDB bp_sw_close_last_fs_SequenceDB
FileSource * bp_sw_FileSource_from_FILE_and_format(FILE * input,int format);
#define FileSource_from_FILE_and_format bp_sw_FileSource_from_FILE_and_format
FileSource * bp_sw_FileSource_from_line(char * line);
#define FileSource_from_line bp_sw_FileSource_from_line
void bp_sw_swap_SequenceDB(FileSource ** list,int i,int j) ;
#define swap_SequenceDB bp_sw_swap_SequenceDB
void bp_sw_qsort_SequenceDB(FileSource ** list,int left,int right,int (*comp)(FileSource * ,FileSource * ));
#define qsort_SequenceDB bp_sw_qsort_SequenceDB
void bp_sw_sort_SequenceDB(SequenceDB * obj,int (*comp)(FileSource *, FileSource *));
#define sort_SequenceDB bp_sw_sort_SequenceDB
boolean bp_sw_expand_SequenceDB(SequenceDB * obj,int len);
#define expand_SequenceDB bp_sw_expand_SequenceDB

#ifdef _cplusplus
}
#endif

#endif
