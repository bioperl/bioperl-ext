
#include <stdio.h>

typedef char aa;
typedef int base;
typedef double Probability;
typedef double Bits;
typedef int Score;
typedef int codon;
typedef int boolean;

#define WISE2_FATAL    1
#define WISE2_WARNING  2
#define WISE2_INFO     8
#define WISE2_REPORT   16


char * bp_sw_stringalloc(char *);
void   bp_sw_error_off(int type);
void   bp_sw_error_on(int type);

typedef struct bp_sw_AlnBlock bp_sw_AlnBlock;

typedef struct bp_sw_AlnColumn bp_sw_AlnColumn;

typedef struct bp_sw_AlnUnit bp_sw_AlnUnit;

typedef struct bp_sw_AlnSequence bp_sw_AlnSequence;

typedef struct bp_sw_AlnRangeSet bp_sw_AlnRangeSet;

typedef struct bp_sw_AlnRange bp_sw_AlnRange;

typedef struct bp_sw_cDNA bp_sw_cDNA;

typedef struct bp_sw_cDNADB bp_sw_cDNADB;

typedef struct bp_sw_CodonTable bp_sw_CodonTable;

typedef struct bp_sw_CodonMapper bp_sw_CodonMapper;

typedef struct bp_sw_ComplexSequence bp_sw_ComplexSequence;

typedef struct bp_sw_ComplexSequenceEvalSet bp_sw_ComplexSequenceEvalSet;

typedef struct bp_sw_CompMat bp_sw_CompMat;

typedef struct bp_sw_Gene bp_sw_Gene;

typedef struct bp_sw_Genomic bp_sw_Genomic;

typedef struct bp_sw_GenomicDB bp_sw_GenomicDB;

typedef struct bp_sw_GenomicRegion bp_sw_GenomicRegion;

typedef struct bp_sw_Histogram bp_sw_Histogram;

typedef struct bp_sw_Hscore bp_sw_Hscore;

typedef struct bp_sw_DataScore bp_sw_DataScore;

typedef struct bp_sw_DataEntry bp_sw_DataEntry;

typedef struct bp_sw_PackAln bp_sw_PackAln;

typedef struct bp_sw_PackAlnUnit bp_sw_PackAlnUnit;

typedef struct bp_sw_Protein bp_sw_Protein;

typedef struct bp_sw_ProteinDB bp_sw_ProteinDB;

typedef struct bp_sw_Sequence bp_sw_Sequence;

typedef struct bp_sw_SequenceDB bp_sw_SequenceDB;

typedef struct bp_sw_FileSource bp_sw_FileSource;

typedef struct bp_sw_Exon bp_sw_Exon;

typedef struct bp_sw_Transcript bp_sw_Transcript;

typedef struct bp_sw_Translation bp_sw_Translation;



/* Functions that create, manipulate or act on AlnBlock
 *
 * bp_sw_bit_ascii_AlnBlock
 * bp_sw_dump_ascii_AlnBlock
 * bp_sw_hard_link_AlnBlock
 * bp_sw_AlnBlock_alloc_std
 * bp_sw_replace_start_AlnBlock
 * bp_sw_access_start_AlnBlock
 * bp_sw_access_seq_AlnBlock
 * bp_sw_length_seq_AlnBlock
 * bp_sw_flush_AlnBlock
 * bp_sw_add_AlnBlock
 * bp_sw_replace_length_AlnBlock
 * bp_sw_access_length_AlnBlock
 * bp_sw_replace_score_AlnBlock
 * bp_sw_access_score_AlnBlock
 * bp_sw_free_AlnBlock [destructor]
 *
 */



/* Functions that create, manipulate or act on AlnColumn
 *
 * bp_sw_at_end_AlnColumn
 * bp_sw_hard_link_AlnColumn
 * bp_sw_AlnColumn_alloc_std
 * bp_sw_access_alu_AlnColumn
 * bp_sw_length_alu_AlnColumn
 * bp_sw_flush_AlnColumn
 * bp_sw_add_AlnColumn
 * bp_sw_replace_next_AlnColumn
 * bp_sw_access_next_AlnColumn
 * bp_sw_free_AlnColumn [destructor]
 *
 */



/* Functions that create, manipulate or act on AlnUnit
 *
 * bp_sw_bio_start_AlnUnit
 * bp_sw_bio_end_AlnUnit
 * bp_sw_hard_link_AlnUnit
 * bp_sw_AlnUnit_alloc
 * bp_sw_replace_start_AlnUnit
 * bp_sw_access_start_AlnUnit
 * bp_sw_replace_end_AlnUnit
 * bp_sw_access_end_AlnUnit
 * bp_sw_replace_label_AlnUnit
 * bp_sw_access_label_AlnUnit
 * bp_sw_replace_text_label_AlnUnit
 * bp_sw_access_text_label_AlnUnit
 * bp_sw_replace_next_AlnUnit
 * bp_sw_access_next_AlnUnit
 * bp_sw_replace_in_column_AlnUnit
 * bp_sw_access_in_column_AlnUnit
 * bp_sw_replace_seq_AlnUnit
 * bp_sw_access_seq_AlnUnit
 * bp_sw_free_AlnUnit [destructor]
 *
 */



/* Functions that create, manipulate or act on AlnSequence
 *
 * bp_sw_hard_link_AlnSequence
 * bp_sw_AlnSequence_alloc
 * bp_sw_replace_start_AlnSequence
 * bp_sw_access_start_AlnSequence
 * bp_sw_replace_data_type_AlnSequence
 * bp_sw_access_data_type_AlnSequence
 * bp_sw_replace_data_AlnSequence
 * bp_sw_access_data_AlnSequence
 * bp_sw_replace_bio_start_AlnSequence
 * bp_sw_access_bio_start_AlnSequence
 * bp_sw_replace_bio_end_AlnSequence
 * bp_sw_access_bio_end_AlnSequence
 * bp_sw_free_AlnSequence [destructor]
 *
 */

/* API for object AlnBlock */
/* Function:  bp_sw_bit_ascii_AlnBlock(alb,ofp)
 *
 * Descrip:    Should not be here...
 *
 *
 * Arg:        alb          AlnBlock to dump [bp_sw_AlnBlock *]
 * Arg:        ofp          File stream to dump to [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_bit_ascii_AlnBlock( bp_sw_AlnBlock * alb,FILE * ofp);

/* Function:  bp_sw_dump_ascii_AlnBlock(alb,ofp)
 *
 * Descrip:    Dumps the alignment in rereadable ascii form.
 *
 *             Not really for human consumption
 *
 *
 * Arg:        alb          AlnBlock to dump [bp_sw_AlnBlock *]
 * Arg:        ofp          File stream to dump to [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_dump_ascii_AlnBlock( bp_sw_AlnBlock * alb,FILE * ofp);

/* Function:  bp_sw_hard_link_AlnBlock(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnBlock *]
 *
 * Returns Undocumented return value [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_hard_link_AlnBlock( bp_sw_AlnBlock * obj);

/* Function:  bp_sw_AlnBlock_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnBlock_alloc_len(AlnBlockLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_AlnBlock_alloc_std();

/* Function:  bp_sw_replace_start_AlnBlock(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 * Arg:        start        New value of the variable [bp_sw_AlnColumn *]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_AlnBlock( bp_sw_AlnBlock * obj,bp_sw_AlnColumn * start);

/* Function:  bp_sw_access_start_AlnBlock(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 *
 * Returns member variable start [bp_sw_AlnColumn *]
 *
 */
bp_sw_AlnColumn * bp_sw_access_start_AlnBlock( bp_sw_AlnBlock * obj);

/* Function:  bp_sw_access_seq_AlnBlock(obj,i)
 *
 * Descrip:    Access members stored in the seq list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnBlock *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_AlnSequence *]
 *
 */
bp_sw_AlnSequence * bp_sw_access_seq_AlnBlock( bp_sw_AlnBlock * obj,int i);

/* Function:  bp_sw_length_seq_AlnBlock(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnBlock *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_seq_AlnBlock( bp_sw_AlnBlock * obj);

/* Function:  bp_sw_flush_AlnBlock(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_AlnBlock *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnBlock( bp_sw_AlnBlock * obj);

/* Function:  bp_sw_add_AlnBlock(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_AlnBlock *]
 * Arg:        add          Object to add to the list [bp_sw_AlnSequence *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnBlock( bp_sw_AlnBlock * obj,bp_sw_AlnSequence * add);

/* Function:  bp_sw_replace_length_AlnBlock(obj,length)
 *
 * Descrip:    Replace member variable length
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 * Arg:        length       New value of the variable [int]
 *
 * Returns member variable length [boolean]
 *
 */
boolean bp_sw_replace_length_AlnBlock( bp_sw_AlnBlock * obj,int length);

/* Function:  bp_sw_access_length_AlnBlock(obj)
 *
 * Descrip:    Access member variable length
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 *
 * Returns member variable length [int]
 *
 */
int bp_sw_access_length_AlnBlock( bp_sw_AlnBlock * obj);

/* Function:  bp_sw_replace_score_AlnBlock(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 * Arg:        score        New value of the variable [int]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_AlnBlock( bp_sw_AlnBlock * obj,int score);

/* Function:  bp_sw_access_score_AlnBlock(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnBlock *]
 *
 * Returns member variable score [int]
 *
 */
int bp_sw_access_score_AlnBlock( bp_sw_AlnBlock * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnBlock(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_AlnBlock *]
 *
 * Returns Undocumented return value [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_free_AlnBlock( bp_sw_AlnBlock * obj);

/* API for object AlnColumn */
/* Function:  bp_sw_at_end_AlnColumn(alc)
 *
 * Descrip:    This tells you whether the AlnColumn is at the
 *             end without passing NULL's around
 *
 *
 *
 * Arg:        alc          AlnColumn [bp_sw_AlnColumn *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_at_end_AlnColumn( bp_sw_AlnColumn * alc);

/* Function:  bp_sw_hard_link_AlnColumn(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnColumn *]
 *
 * Returns Undocumented return value [bp_sw_AlnColumn *]
 *
 */
bp_sw_AlnColumn * bp_sw_hard_link_AlnColumn( bp_sw_AlnColumn * obj);

/* Function:  bp_sw_AlnColumn_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnColumn_alloc_len(AlnColumnLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnColumn *]
 *
 */
bp_sw_AlnColumn * bp_sw_AlnColumn_alloc_std();

/* Function:  bp_sw_access_alu_AlnColumn(obj,i)
 *
 * Descrip:    Access members stored in the alu list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnColumn *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_access_alu_AlnColumn( bp_sw_AlnColumn * obj,int i);

/* Function:  bp_sw_length_alu_AlnColumn(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnColumn *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_alu_AlnColumn( bp_sw_AlnColumn * obj);

/* Function:  bp_sw_flush_AlnColumn(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_AlnColumn *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnColumn( bp_sw_AlnColumn * obj);

/* Function:  bp_sw_add_AlnColumn(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_AlnColumn *]
 * Arg:        add          Object to add to the list [bp_sw_AlnUnit *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnColumn( bp_sw_AlnColumn * obj,bp_sw_AlnUnit * add);

/* Function:  bp_sw_replace_next_AlnColumn(obj,next)
 *
 * Descrip:    Replace member variable next
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnColumn *]
 * Arg:        next         New value of the variable [bp_sw_AlnColumn *]
 *
 * Returns member variable next [boolean]
 *
 */
boolean bp_sw_replace_next_AlnColumn( bp_sw_AlnColumn * obj,bp_sw_AlnColumn * next);

/* Function:  bp_sw_access_next_AlnColumn(obj)
 *
 * Descrip:    Access member variable next
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnColumn *]
 *
 * Returns member variable next [bp_sw_AlnColumn *]
 *
 */
bp_sw_AlnColumn * bp_sw_access_next_AlnColumn( bp_sw_AlnColumn * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnColumn(obj)
 *
 * Descrip:    Specilased deconstructor needed because
 *             of linked list nature of the data structure
 *
 *
 * Arg:        obj          Undocumented argument [bp_sw_AlnColumn *]
 *
 * Returns Undocumented return value [bp_sw_AlnColumn *]
 *
 */
bp_sw_AlnColumn * bp_sw_free_AlnColumn( bp_sw_AlnColumn * obj);

/* API for object AlnUnit */
/* Function:  bp_sw_bio_start_AlnUnit(alu)
 *
 * Descrip:    Tells the bio-coordinate of the
 *             start point of this alnunit
 *
 *
 * Arg:        alu          Undocumented argument [bp_sw_AlnUnit *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_bio_start_AlnUnit( bp_sw_AlnUnit * alu);

/* Function:  bp_sw_bio_end_AlnUnit(alu)
 *
 * Descrip:    Tells the bio-coordinate of the
 *             end point of this alnunit
 *
 *
 * Arg:        alu          Undocumented argument [bp_sw_AlnUnit *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_bio_end_AlnUnit( bp_sw_AlnUnit * alu);

/* Function:  bp_sw_hard_link_AlnUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnUnit *]
 *
 * Returns Undocumented return value [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_hard_link_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_AlnUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_AlnUnit_alloc();

/* Function:  bp_sw_replace_start_AlnUnit(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        start        New value of the variable [int]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_AlnUnit( bp_sw_AlnUnit * obj,int start);

/* Function:  bp_sw_access_start_AlnUnit(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable start [int]
 *
 */
int bp_sw_access_start_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_end_AlnUnit(obj,end)
 *
 * Descrip:    Replace member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        end          New value of the variable [int]
 *
 * Returns member variable end [boolean]
 *
 */
boolean bp_sw_replace_end_AlnUnit( bp_sw_AlnUnit * obj,int end);

/* Function:  bp_sw_access_end_AlnUnit(obj)
 *
 * Descrip:    Access member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable end [int]
 *
 */
int bp_sw_access_end_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_label_AlnUnit(obj,label)
 *
 * Descrip:    Replace member variable label
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        label        New value of the variable [int]
 *
 * Returns member variable label [boolean]
 *
 */
boolean bp_sw_replace_label_AlnUnit( bp_sw_AlnUnit * obj,int label);

/* Function:  bp_sw_access_label_AlnUnit(obj)
 *
 * Descrip:    Access member variable label
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable label [int]
 *
 */
int bp_sw_access_label_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_text_label_AlnUnit(obj,text_label)
 *
 * Descrip:    Replace member variable text_label
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        text_label   New value of the variable [char *]
 *
 * Returns member variable text_label [boolean]
 *
 */
boolean bp_sw_replace_text_label_AlnUnit( bp_sw_AlnUnit * obj,char * text_label);

/* Function:  bp_sw_access_text_label_AlnUnit(obj)
 *
 * Descrip:    Access member variable text_label
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable text_label [char *]
 *
 */
char * bp_sw_access_text_label_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_next_AlnUnit(obj,next)
 *
 * Descrip:    Replace member variable next
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        next         New value of the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable next [boolean]
 *
 */
boolean bp_sw_replace_next_AlnUnit( bp_sw_AlnUnit * obj,bp_sw_AlnUnit * next);

/* Function:  bp_sw_access_next_AlnUnit(obj)
 *
 * Descrip:    Access member variable next
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable next [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_access_next_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_in_column_AlnUnit(obj,in_column)
 *
 * Descrip:    Replace member variable in_column
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        in_column    New value of the variable [boolean]
 *
 * Returns member variable in_column [boolean]
 *
 */
boolean bp_sw_replace_in_column_AlnUnit( bp_sw_AlnUnit * obj,boolean in_column);

/* Function:  bp_sw_access_in_column_AlnUnit(obj)
 *
 * Descrip:    Access member variable in_column
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable in_column [boolean]
 *
 */
boolean bp_sw_access_in_column_AlnUnit( bp_sw_AlnUnit * obj);

/* Function:  bp_sw_replace_seq_AlnUnit(obj,seq)
 *
 * Descrip:    Replace member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 * Arg:        seq          New value of the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable seq [boolean]
 *
 */
boolean bp_sw_replace_seq_AlnUnit( bp_sw_AlnUnit * obj,bp_sw_AlnSequence * seq);

/* Function:  bp_sw_access_seq_AlnUnit(obj)
 *
 * Descrip:    Access member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable seq [bp_sw_AlnSequence *]
 *
 */
bp_sw_AlnSequence * bp_sw_access_seq_AlnUnit( bp_sw_AlnUnit * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnUnit(obj)
 *
 * Descrip:    Specilased deconstructor needed because
 *             of linked list nature of the data structure
 *
 *
 * Arg:        obj          Undocumented argument [bp_sw_AlnUnit *]
 *
 * Returns Undocumented return value [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_free_AlnUnit( bp_sw_AlnUnit * obj);

/* API for object AlnSequence */
/* Function:  bp_sw_hard_link_AlnSequence(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnSequence *]
 *
 * Returns Undocumented return value [bp_sw_AlnSequence *]
 *
 */
bp_sw_AlnSequence * bp_sw_hard_link_AlnSequence( bp_sw_AlnSequence * obj);

/* Function:  bp_sw_AlnSequence_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnSequence *]
 *
 */
bp_sw_AlnSequence * bp_sw_AlnSequence_alloc();

/* Function:  bp_sw_replace_start_AlnSequence(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 * Arg:        start        New value of the variable [bp_sw_AlnUnit *]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_AlnSequence( bp_sw_AlnSequence * obj,bp_sw_AlnUnit * start);

/* Function:  bp_sw_access_start_AlnSequence(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable start [bp_sw_AlnUnit *]
 *
 */
bp_sw_AlnUnit * bp_sw_access_start_AlnSequence( bp_sw_AlnSequence * obj);

/* Function:  bp_sw_replace_data_type_AlnSequence(obj,data_type)
 *
 * Descrip:    Replace member variable data_type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 * Arg:        data_type    New value of the variable [int]
 *
 * Returns member variable data_type [boolean]
 *
 */
boolean bp_sw_replace_data_type_AlnSequence( bp_sw_AlnSequence * obj,int data_type);

/* Function:  bp_sw_access_data_type_AlnSequence(obj)
 *
 * Descrip:    Access member variable data_type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable data_type [int]
 *
 */
int bp_sw_access_data_type_AlnSequence( bp_sw_AlnSequence * obj);

/* Function:  bp_sw_replace_data_AlnSequence(obj,data)
 *
 * Descrip:    Replace member variable data
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 * Arg:        data         New value of the variable [void *]
 *
 * Returns member variable data [boolean]
 *
 */
boolean bp_sw_replace_data_AlnSequence( bp_sw_AlnSequence * obj,void * data);

/* Function:  bp_sw_access_data_AlnSequence(obj)
 *
 * Descrip:    Access member variable data
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable data [void *]
 *
 */
void * bp_sw_access_data_AlnSequence( bp_sw_AlnSequence * obj);

/* Function:  bp_sw_replace_bio_start_AlnSequence(obj,bio_start)
 *
 * Descrip:    Replace member variable bio_start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 * Arg:        bio_start    New value of the variable [int]
 *
 * Returns member variable bio_start [boolean]
 *
 */
boolean bp_sw_replace_bio_start_AlnSequence( bp_sw_AlnSequence * obj,int bio_start);

/* Function:  bp_sw_access_bio_start_AlnSequence(obj)
 *
 * Descrip:    Access member variable bio_start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable bio_start [int]
 *
 */
int bp_sw_access_bio_start_AlnSequence( bp_sw_AlnSequence * obj);

/* Function:  bp_sw_replace_bio_end_AlnSequence(obj,bio_end)
 *
 * Descrip:    Replace member variable bio_end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 * Arg:        bio_end      New value of the variable [int]
 *
 * Returns member variable bio_end [boolean]
 *
 */
boolean bp_sw_replace_bio_end_AlnSequence( bp_sw_AlnSequence * obj,int bio_end);

/* Function:  bp_sw_access_bio_end_AlnSequence(obj)
 *
 * Descrip:    Access member variable bio_end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnSequence *]
 *
 * Returns member variable bio_end [int]
 *
 */
int bp_sw_access_bio_end_AlnSequence( bp_sw_AlnSequence * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnSequence(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_AlnSequence *]
 *
 * Returns Undocumented return value [bp_sw_AlnSequence *]
 *
 */
bp_sw_AlnSequence * bp_sw_free_AlnSequence( bp_sw_AlnSequence * obj);



/* Functions that create, manipulate or act on AlnRangeSet
 *
 * bp_sw_hard_link_AlnRangeSet
 * bp_sw_AlnRangeSet_alloc_std
 * bp_sw_replace_score_AlnRangeSet
 * bp_sw_access_score_AlnRangeSet
 * bp_sw_access_alr_AlnRangeSet
 * bp_sw_length_alr_AlnRangeSet
 * bp_sw_flush_AlnRangeSet
 * bp_sw_add_AlnRangeSet
 * bp_sw_free_AlnRangeSet [destructor]
 *
 */



/* Functions that create, manipulate or act on AlnRange
 *
 * bp_sw_hard_link_AlnRange
 * bp_sw_AlnRange_alloc
 * bp_sw_replace_starti_AlnRange
 * bp_sw_access_starti_AlnRange
 * bp_sw_replace_startj_AlnRange
 * bp_sw_access_startj_AlnRange
 * bp_sw_replace_startstate_AlnRange
 * bp_sw_access_startstate_AlnRange
 * bp_sw_replace_stopi_AlnRange
 * bp_sw_access_stopi_AlnRange
 * bp_sw_replace_stopj_AlnRange
 * bp_sw_access_stopj_AlnRange
 * bp_sw_replace_stopstate_AlnRange
 * bp_sw_access_stopstate_AlnRange
 * bp_sw_replace_startscore_AlnRange
 * bp_sw_access_startscore_AlnRange
 * bp_sw_replace_stopscore_AlnRange
 * bp_sw_access_stopscore_AlnRange
 * bp_sw_free_AlnRange [destructor]
 *
 */

/* API for object AlnRangeSet */
/* Function:  bp_sw_hard_link_AlnRangeSet(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnRangeSet *]
 *
 * Returns Undocumented return value [bp_sw_AlnRangeSet *]
 *
 */
bp_sw_AlnRangeSet * bp_sw_hard_link_AlnRangeSet( bp_sw_AlnRangeSet * obj);

/* Function:  bp_sw_AlnRangeSet_alloc_std(void)
 *
 * Descrip:    Equivalent to AlnRangeSet_alloc_len(AlnRangeSetLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnRangeSet *]
 *
 */
bp_sw_AlnRangeSet * bp_sw_AlnRangeSet_alloc_std();

/* Function:  bp_sw_replace_score_AlnRangeSet(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRangeSet *]
 * Arg:        score        New value of the variable [int]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_AlnRangeSet( bp_sw_AlnRangeSet * obj,int score);

/* Function:  bp_sw_access_score_AlnRangeSet(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRangeSet *]
 *
 * Returns member variable score [int]
 *
 */
int bp_sw_access_score_AlnRangeSet( bp_sw_AlnRangeSet * obj);

/* Function:  bp_sw_access_alr_AlnRangeSet(obj,i)
 *
 * Descrip:    Access members stored in the alr list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnRangeSet *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_AlnRange *]
 *
 */
bp_sw_AlnRange * bp_sw_access_alr_AlnRangeSet( bp_sw_AlnRangeSet * obj,int i);

/* Function:  bp_sw_length_alr_AlnRangeSet(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_AlnRangeSet *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_alr_AlnRangeSet( bp_sw_AlnRangeSet * obj);

/* Function:  bp_sw_flush_AlnRangeSet(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_AlnRangeSet *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_AlnRangeSet( bp_sw_AlnRangeSet * obj);

/* Function:  bp_sw_add_AlnRangeSet(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_AlnRangeSet *]
 * Arg:        add          Object to add to the list [bp_sw_AlnRange *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_AlnRangeSet( bp_sw_AlnRangeSet * obj,bp_sw_AlnRange * add);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnRangeSet(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_AlnRangeSet *]
 *
 * Returns Undocumented return value [bp_sw_AlnRangeSet *]
 *
 */
bp_sw_AlnRangeSet * bp_sw_free_AlnRangeSet( bp_sw_AlnRangeSet * obj);

/* API for object AlnRange */
/* Function:  bp_sw_hard_link_AlnRange(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_AlnRange *]
 *
 * Returns Undocumented return value [bp_sw_AlnRange *]
 *
 */
bp_sw_AlnRange * bp_sw_hard_link_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_AlnRange_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_AlnRange *]
 *
 */
bp_sw_AlnRange * bp_sw_AlnRange_alloc();

/* Function:  bp_sw_replace_starti_AlnRange(obj,starti)
 *
 * Descrip:    Replace member variable starti
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        starti       New value of the variable [int]
 *
 * Returns member variable starti [boolean]
 *
 */
boolean bp_sw_replace_starti_AlnRange( bp_sw_AlnRange * obj,int starti);

/* Function:  bp_sw_access_starti_AlnRange(obj)
 *
 * Descrip:    Access member variable starti
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable starti [int]
 *
 */
int bp_sw_access_starti_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_startj_AlnRange(obj,startj)
 *
 * Descrip:    Replace member variable startj
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        startj       New value of the variable [int]
 *
 * Returns member variable startj [boolean]
 *
 */
boolean bp_sw_replace_startj_AlnRange( bp_sw_AlnRange * obj,int startj);

/* Function:  bp_sw_access_startj_AlnRange(obj)
 *
 * Descrip:    Access member variable startj
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable startj [int]
 *
 */
int bp_sw_access_startj_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_startstate_AlnRange(obj,startstate)
 *
 * Descrip:    Replace member variable startstate
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        startstate   New value of the variable [int]
 *
 * Returns member variable startstate [boolean]
 *
 */
boolean bp_sw_replace_startstate_AlnRange( bp_sw_AlnRange * obj,int startstate);

/* Function:  bp_sw_access_startstate_AlnRange(obj)
 *
 * Descrip:    Access member variable startstate
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable startstate [int]
 *
 */
int bp_sw_access_startstate_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_stopi_AlnRange(obj,stopi)
 *
 * Descrip:    Replace member variable stopi
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        stopi        New value of the variable [int]
 *
 * Returns member variable stopi [boolean]
 *
 */
boolean bp_sw_replace_stopi_AlnRange( bp_sw_AlnRange * obj,int stopi);

/* Function:  bp_sw_access_stopi_AlnRange(obj)
 *
 * Descrip:    Access member variable stopi
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable stopi [int]
 *
 */
int bp_sw_access_stopi_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_stopj_AlnRange(obj,stopj)
 *
 * Descrip:    Replace member variable stopj
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        stopj        New value of the variable [int]
 *
 * Returns member variable stopj [boolean]
 *
 */
boolean bp_sw_replace_stopj_AlnRange( bp_sw_AlnRange * obj,int stopj);

/* Function:  bp_sw_access_stopj_AlnRange(obj)
 *
 * Descrip:    Access member variable stopj
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable stopj [int]
 *
 */
int bp_sw_access_stopj_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_stopstate_AlnRange(obj,stopstate)
 *
 * Descrip:    Replace member variable stopstate
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        stopstate    New value of the variable [int]
 *
 * Returns member variable stopstate [boolean]
 *
 */
boolean bp_sw_replace_stopstate_AlnRange( bp_sw_AlnRange * obj,int stopstate);

/* Function:  bp_sw_access_stopstate_AlnRange(obj)
 *
 * Descrip:    Access member variable stopstate
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable stopstate [int]
 *
 */
int bp_sw_access_stopstate_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_startscore_AlnRange(obj,startscore)
 *
 * Descrip:    Replace member variable startscore
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        startscore   New value of the variable [int]
 *
 * Returns member variable startscore [boolean]
 *
 */
boolean bp_sw_replace_startscore_AlnRange( bp_sw_AlnRange * obj,int startscore);

/* Function:  bp_sw_access_startscore_AlnRange(obj)
 *
 * Descrip:    Access member variable startscore
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable startscore [int]
 *
 */
int bp_sw_access_startscore_AlnRange( bp_sw_AlnRange * obj);

/* Function:  bp_sw_replace_stopscore_AlnRange(obj,stopscore)
 *
 * Descrip:    Replace member variable stopscore
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 * Arg:        stopscore    New value of the variable [int]
 *
 * Returns member variable stopscore [boolean]
 *
 */
boolean bp_sw_replace_stopscore_AlnRange( bp_sw_AlnRange * obj,int stopscore);

/* Function:  bp_sw_access_stopscore_AlnRange(obj)
 *
 * Descrip:    Access member variable stopscore
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_AlnRange *]
 *
 * Returns member variable stopscore [int]
 *
 */
int bp_sw_access_stopscore_AlnRange( bp_sw_AlnRange * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_AlnRange(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_AlnRange *]
 *
 * Returns Undocumented return value [bp_sw_AlnRange *]
 *
 */
bp_sw_AlnRange * bp_sw_free_AlnRange( bp_sw_AlnRange * obj);



/* Helper functions in the module
 *
 * bp_sw_change_max_BaseMatrix_kbytes
 * bp_sw_get_max_BaseMatrix_kbytes
 *



/* These functions are not associated with an object */
/* Function:  bp_sw_change_max_BaseMatrix_kbytes(new_kilo_number)
 *
 * Descrip:    This is to change, at run-time the maximum level of bytes basematrix *thinks*
 *             it can use. This number is *not* used for any actual calls to basematrix
 *             allocation: it is only used with /get_max_BaseMatrix_kbytes
 *
 *
 * Arg:        new_kilo_number max kilobytes allowed [int]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_change_max_BaseMatrix_kbytes( int new_kilo_number);

/* Function:  bp_sw_get_max_BaseMatrix_kbytes(void)
 *
 * Descrip:    returns the max. number of kilobytes suggested as a limited
 *             to BaseMatrix. 
 *
 *
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_get_max_BaseMatrix_kbytes();



/* Functions that create, manipulate or act on cDNA
 *
 * bp_sw_truncate_cDNA
 * bp_sw_read_fasta_file_cDNA
 * bp_sw_cDNA_name
 * bp_sw_cDNA_length
 * bp_sw_cDNA_seqchar
 * bp_sw_cDNA_from_Sequence
 * bp_sw_hard_link_cDNA
 * bp_sw_cDNA_alloc
 * bp_sw_replace_baseseq_cDNA
 * bp_sw_access_baseseq_cDNA
 * bp_sw_free_cDNA [destructor]
 *
 */

/* API for object cDNA */
/* Function:  bp_sw_truncate_cDNA(cdna,start,stop)
 *
 * Descrip:    Truncates a cDNA sequence. Basically uses
 *             the /magic_trunc_Sequence function (of course!)
 *
 *             It does not alter cdna, rather it returns a new
 *             sequence with that truncation
 *
 *
 * Arg:        cdna         cDNA that is truncated [bp_sw_cDNA *]
 * Arg:        start        Undocumented argument [int]
 * Arg:        stop         Undocumented argument [int]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_truncate_cDNA( bp_sw_cDNA * cdna,int start,int stop);

/* Function:  bp_sw_read_fasta_file_cDNA(filename)
 *
 * Descrip:    Reads a fasta file assumming that it is cDNA. 
 *             Will complain if it is not, and return NULL.
 *
 *
 * Arg:        filename     filename to be opened and read [char *]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_read_fasta_file_cDNA( char * filename);

/* Function:  bp_sw_cDNA_name(cdna)
 *
 * Descrip:    Returns the name of the cDNA
 *
 *
 * Arg:        cdna         Undocumented argument [bp_sw_cDNA *]
 *
 * Returns Undocumented return value [char *]
 *
 */
char * bp_sw_cDNA_name( bp_sw_cDNA * cdna);

/* Function:  bp_sw_cDNA_length(cdna)
 *
 * Descrip:    Returns the length of the cDNA
 *
 *
 * Arg:        cdna         Undocumented argument [bp_sw_cDNA *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_cDNA_length( bp_sw_cDNA * cdna);

/* Function:  bp_sw_cDNA_seqchar(cdna,pos)
 *
 * Descrip:    Returns sequence character at this position.
 *
 *
 * Arg:        cdna         cDNA [bp_sw_cDNA *]
 * Arg:        pos          position in cDNA to get char [int]
 *
 * Returns Undocumented return value [char]
 *
 */
char bp_sw_cDNA_seqchar( bp_sw_cDNA * cdna,int pos);

/* Function:  bp_sw_cDNA_from_Sequence(seq)
 *
 * Descrip:    makes a new cDNA from a Sequence. It 
 *             owns the Sequence memory, ie will attempt a /free_Sequence
 *             on the structure when /free_cDNA is called
 *
 *             If you want to give this cDNA this Sequence and
 *             forget about it, then just hand it this sequence and set
 *             seq to NULL (no need to free it). If you intend to use 
 *             the sequence object elsewhere outside of the cDNA datastructure
 *             then use cDNA_from_Sequence(/hard_link_Sequence(seq))
 *
 *
 *
 * Arg:        seq          Sequence to make cDNA from [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_cDNA_from_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_hard_link_cDNA(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_cDNA *]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_hard_link_cDNA( bp_sw_cDNA * obj);

/* Function:  bp_sw_cDNA_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_cDNA_alloc();

/* Function:  bp_sw_replace_baseseq_cDNA(obj,baseseq)
 *
 * Descrip:    Replace member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNA *]
 * Arg:        baseseq      New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable baseseq [boolean]
 *
 */
boolean bp_sw_replace_baseseq_cDNA( bp_sw_cDNA * obj,bp_sw_Sequence * baseseq);

/* Function:  bp_sw_access_baseseq_cDNA(obj)
 *
 * Descrip:    Access member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNA *]
 *
 * Returns member variable baseseq [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_baseseq_cDNA( bp_sw_cDNA * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_cDNA(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_cDNA *]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_free_cDNA( bp_sw_cDNA * obj);



/* Functions that create, manipulate or act on cDNADB
 *
 * bp_sw_get_cDNA_from_cDNADB
 * bp_sw_hard_link_cDNADB
 * bp_sw_cDNADB_alloc
 * bp_sw_replace_is_single_seq_cDNADB
 * bp_sw_access_is_single_seq_cDNADB
 * bp_sw_replace_done_forward_cDNADB
 * bp_sw_access_done_forward_cDNADB
 * bp_sw_replace_forw_cDNADB
 * bp_sw_access_forw_cDNADB
 * bp_sw_replace_rev_cDNADB
 * bp_sw_access_rev_cDNADB
 * bp_sw_replace_sdb_cDNADB
 * bp_sw_access_sdb_cDNADB
 * bp_sw_replace_current_cDNADB
 * bp_sw_access_current_cDNADB
 * bp_sw_replace_cses_cDNADB
 * bp_sw_access_cses_cDNADB
 * bp_sw_free_cDNADB [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_new_cDNADB_from_single_seq
 * bp_sw_new_cDNADB
 *

/* API for object cDNADB */
/* Function:  bp_sw_get_cDNA_from_cDNADB(cdnadb,de)
 *
 * Descrip:    Gets cDNA sequence out from
 *             the cDNADB using the information stored in
 *             dataentry
 *
 *
 * Arg:        cdnadb       cDNA database [bp_sw_cDNADB *]
 * Arg:        de           DataEntry information  [bp_sw_DataEntry *]
 *
 * Returns Undocumented return value [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_get_cDNA_from_cDNADB( bp_sw_cDNADB * cdnadb,bp_sw_DataEntry * de);

/* Function:  bp_sw_hard_link_cDNADB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_cDNADB *]
 *
 * Returns Undocumented return value [bp_sw_cDNADB *]
 *
 */
bp_sw_cDNADB * bp_sw_hard_link_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_cDNADB_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_cDNADB *]
 *
 */
bp_sw_cDNADB * bp_sw_cDNADB_alloc();

/* Function:  bp_sw_replace_is_single_seq_cDNADB(obj,is_single_seq)
 *
 * Descrip:    Replace member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        is_single_seq New value of the variable [boolean]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_replace_is_single_seq_cDNADB( bp_sw_cDNADB * obj,boolean is_single_seq);

/* Function:  bp_sw_access_is_single_seq_cDNADB(obj)
 *
 * Descrip:    Access member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_access_is_single_seq_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_done_forward_cDNADB(obj,done_forward)
 *
 * Descrip:    Replace member variable done_forward
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        done_forward New value of the variable [boolean]
 *
 * Returns member variable done_forward [boolean]
 *
 */
boolean bp_sw_replace_done_forward_cDNADB( bp_sw_cDNADB * obj,boolean done_forward);

/* Function:  bp_sw_access_done_forward_cDNADB(obj)
 *
 * Descrip:    Access member variable done_forward
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable done_forward [boolean]
 *
 */
boolean bp_sw_access_done_forward_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_forw_cDNADB(obj,forw)
 *
 * Descrip:    Replace member variable forw
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        forw         New value of the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable forw [boolean]
 *
 */
boolean bp_sw_replace_forw_cDNADB( bp_sw_cDNADB * obj,bp_sw_ComplexSequence * forw);

/* Function:  bp_sw_access_forw_cDNADB(obj)
 *
 * Descrip:    Access member variable forw
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable forw [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_access_forw_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_rev_cDNADB(obj,rev)
 *
 * Descrip:    Replace member variable rev
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        rev          New value of the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable rev [boolean]
 *
 */
boolean bp_sw_replace_rev_cDNADB( bp_sw_cDNADB * obj,bp_sw_ComplexSequence * rev);

/* Function:  bp_sw_access_rev_cDNADB(obj)
 *
 * Descrip:    Access member variable rev
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable rev [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_access_rev_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_sdb_cDNADB(obj,sdb)
 *
 * Descrip:    Replace member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        sdb          New value of the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable sdb [boolean]
 *
 */
boolean bp_sw_replace_sdb_cDNADB( bp_sw_cDNADB * obj,bp_sw_SequenceDB * sdb);

/* Function:  bp_sw_access_sdb_cDNADB(obj)
 *
 * Descrip:    Access member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable sdb [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_access_sdb_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_current_cDNADB(obj,current)
 *
 * Descrip:    Replace member variable current
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        current      New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable current [boolean]
 *
 */
boolean bp_sw_replace_current_cDNADB( bp_sw_cDNADB * obj,bp_sw_Sequence * current);

/* Function:  bp_sw_access_current_cDNADB(obj)
 *
 * Descrip:    Access member variable current
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable current [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_current_cDNADB( bp_sw_cDNADB * obj);

/* Function:  bp_sw_replace_cses_cDNADB(obj,cses)
 *
 * Descrip:    Replace member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 * Arg:        cses         New value of the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable cses [boolean]
 *
 */
boolean bp_sw_replace_cses_cDNADB( bp_sw_cDNADB * obj,bp_sw_ComplexSequenceEvalSet * cses);

/* Function:  bp_sw_access_cses_cDNADB(obj)
 *
 * Descrip:    Access member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_cDNADB *]
 *
 * Returns member variable cses [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_access_cses_cDNADB( bp_sw_cDNADB * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_cDNADB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_cDNADB *]
 *
 * Returns Undocumented return value [bp_sw_cDNADB *]
 *
 */
bp_sw_cDNADB * bp_sw_free_cDNADB( bp_sw_cDNADB * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_new_cDNADB_from_single_seq(seq)
 *
 * Descrip:    To make a new cDNA database
 *             from a single cDNA Sequence with a eval system
 *
 *
 * Arg:        seq          sequence which as placed into cDNADB structure. [bp_sw_cDNA *]
 *
 * Returns Undocumented return value [bp_sw_cDNADB *]
 *
 */
bp_sw_cDNADB * bp_sw_new_cDNADB_from_single_seq( bp_sw_cDNA * seq);

/* Function:  bp_sw_new_cDNADB(seqdb)
 *
 * Descrip:    To make a new cDNA database
 *
 *
 * Arg:        seqdb        sequence database [bp_sw_SequenceDB *]
 *
 * Returns Undocumented return value [bp_sw_cDNADB *]
 *
 */
bp_sw_cDNADB * bp_sw_new_cDNADB( bp_sw_SequenceDB * seqdb);



/* Functions that create, manipulate or act on CodonTable
 *
 * bp_sw_read_CodonTable_file
 * bp_sw_read_CodonTable
 * bp_sw_aminoacid_from_seq
 * bp_sw_aminoacid_from_codon
 * bp_sw_is_stop_codon
 * bp_sw_is_valid_aminoacid
 * bp_sw_hard_link_CodonTable
 * bp_sw_CodonTable_alloc
 * bp_sw_replace_name_CodonTable
 * bp_sw_access_name_CodonTable
 * bp_sw_free_CodonTable [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_is_non_ambiguous_codon_seq
 * bp_sw_codon_from_base4_codon
 * bp_sw_base4_codon_from_codon
 * bp_sw_has_random_bases
 * bp_sw_permute_possible_random_bases
 * bp_sw_base_from_codon
 * bp_sw_codon_from_seq
 * bp_sw_base4_codon_from_seq
 * bp_sw_char_from_base
 * bp_sw_base_from_char
 * bp_sw_char_complement_base
 * bp_sw_complement_base
 *

/* API for object CodonTable */
/* Function:  bp_sw_read_CodonTable_file(file)
 *
 * Descrip:    Opens filename, reads it as if a Ewan style
 *             codon table and closes.
 *
 *
 * Arg:        file         filename to open [char *]
 *
 * Returns A codon-table, NULL if error [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_read_CodonTable_file( char * file);

/* Function:  bp_sw_read_CodonTable(ifp)
 *
 * Descrip:    reads a codon table from a filestream in Ewan
 *             format.
 *
 *             As Ewan format is really bad and has no start/stop
 *             this will effectively read to the end of the file.
 *             Ooops.
 *
 *
 * Arg:        ifp          file input [FILE *]
 *
 * Returns Undocumented return value [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_read_CodonTable( FILE * ifp);

/* Function:  bp_sw_aminoacid_from_seq(ct,seq)
 *
 * Descrip:    Returns the amino acid for this position in the DNA sequence
 *             Takes the pointer +1 and +2 points.
 *
 *             No error checks implemented. Probably a mistake ;)
 *
 *
 * Arg:        ct           codon table [bp_sw_CodonTable *]
 * Arg:        seq          pointer to DNA chars [char *]
 *
 * Returns an amino acid char (A-Z) [aa]
 *
 */
aa bp_sw_aminoacid_from_seq( bp_sw_CodonTable * ct,char * seq);

/* Function:  bp_sw_aminoacid_from_codon(ct,c)
 *
 * Descrip:    returns amino acid for this codon number (NB codon numbers 0-125)
 *
 *
 * Arg:        ct           codon table [bp_sw_CodonTable *]
 * Arg:        c            codon number [codon]
 *
 * Returns aminoacid that is this codon (X for ambiguous, * for stop) [aa]
 *
 */
aa bp_sw_aminoacid_from_codon( bp_sw_CodonTable * ct,codon c);

/* Function:  bp_sw_is_stop_codon(c,ct)
 *
 * Descrip:    tells you whether this codon number is really a stop
 *             in this translation table
 *
 *
 * Arg:        c            codon number [codon]
 * Arg:        ct           codon table [bp_sw_CodonTable *]
 *
 * Returns TRUE if is stop, FALSE otherwise [boolean]
 *
 */
boolean bp_sw_is_stop_codon( codon c,bp_sw_CodonTable * ct);

/* Function:  bp_sw_is_valid_aminoacid(ct,c)
 *
 * Descrip:    Tells you if this letter (c) is recognised as a valid amino acid
 *             in this codon table
 *
 *
 * Arg:        ct           Codon Table [bp_sw_CodonTable *]
 * Arg:        c            aminoacid [char]
 *
 * Returns TRUE if valid, FALSE if not. [boolean]
 *
 */
boolean bp_sw_is_valid_aminoacid( bp_sw_CodonTable * ct,char c);

/* Function:  bp_sw_hard_link_CodonTable(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_CodonTable *]
 *
 * Returns Undocumented return value [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_hard_link_CodonTable( bp_sw_CodonTable * obj);

/* Function:  bp_sw_CodonTable_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_CodonTable_alloc();

/* Function:  bp_sw_replace_name_CodonTable(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CodonTable *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_CodonTable( bp_sw_CodonTable * obj,char * name);

/* Function:  bp_sw_access_name_CodonTable(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CodonTable *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_CodonTable( bp_sw_CodonTable * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_CodonTable(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_CodonTable *]
 *
 * Returns Undocumented return value [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_free_CodonTable( bp_sw_CodonTable * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_is_non_ambiguous_codon_seq(seq)
 *
 * Descrip:    Tells you if this codon is a real codon
 *
 *
 * Arg:        seq          pointer to DNA sequence [char *]
 *
 * Returns TRUE if real codon, FALSE if contains N's [boolean]
 *
 */
boolean bp_sw_is_non_ambiguous_codon_seq( char * seq);

/* Function:  bp_sw_codon_from_base4_codon(c)
 *
 * Descrip:    maps a 0-63 codon to a 0-123 codon. Suprisingly useful.
 *
 *
 * Arg:        c            Undocumented argument [int]
 *
 * Returns Undocumented return value [codon]
 *
 */
codon bp_sw_codon_from_base4_codon( int c);

/* Function:  bp_sw_base4_codon_from_codon(c)
 *
 * Descrip:    maps a 0-125 codon to a 0-63 codon.
 *
 *             If ambiguous then returns 64 having issued a warning.
 *
 *
 * Arg:        c            codon 0-125 [codon]
 *
 * Returns base 4 codon (0-63) [int]
 *
 */
int bp_sw_base4_codon_from_codon( codon c);

/* Function:  bp_sw_has_random_bases(c)
 *
 * Descrip:    Tests to see if this codon number has any N's in it
 *
 *
 * Arg:        c            codon number 0-124 [codon]
 *
 * Returns TRUE if has N's , FALSE otherwise [boolean]
 *
 */
boolean bp_sw_has_random_bases( codon c);

/* Function:  bp_sw_permute_possible_random_bases(c,one,two,three)
 *
 * Descrip:    Bizarely useful function for calculating ambiguity scores.
 *
 *             This takes the codon c, and for each possible base, 
 *             if it is N, replaces it with one, two or three.
 *
 *             If the base is not N, it remains the same
 *
 *
 * Arg:        c            codon number [codon]
 * Arg:        one          base to replace first position if N [base]
 * Arg:        two          base to replace second position if N [base]
 * Arg:        three        base to replace third position if N [base]
 *
 * Returns codon number  [codon]
 *
 */
codon bp_sw_permute_possible_random_bases( codon c,base one,base two,base three);

/* Function:  bp_sw_base_from_codon(c,pos)
 *
 * Descrip:    Probably not the best function to use for this, but 
 *             useful. Takes a codon and with pos being 1,2,3 gives
 *             you the firt,second of third base
 *
 *
 * Arg:        c            Undocumented argument [codon]
 * Arg:        pos          Undocumented argument [int]
 *
 * Returns Undocumented return value [base]
 *
 */
base bp_sw_base_from_codon( codon c,int pos);

/* Function:  bp_sw_codon_from_seq(seq)
 *
 * Descrip:    takes an ASCII coded pointer to a 3 base pair
 *             sequence (it could be the part of a sequence: it only
 *             assummes that the seq points with 3 chars at pos 0,1,2 
 *             in C coordinates from seq. No NULL is required). It 
 *             ives back the codon as made from standard mapping, ie,
 *             25*base_1+5*base_2 + base3 being a number from 0-124 inc.
 *
 *
 * Arg:        seq          pointer to sequence of at least 3 chrs long. [char *]
 *
 * Returns Undocumented return value [codon]
 *
 */
codon bp_sw_codon_from_seq( char * seq);

/* Function:  bp_sw_base4_codon_from_seq(seq)
 *
 * Descrip:    Sometimes it is more useful to work in base64, ie, 
 *             non N. this functions does the same thing as 
 *             /codon_from_seq but produces a seq being
 *             16*base1 + 4 *base2 + base3
 *
 *
 * Arg:        seq          pointer to sequence of at least 3 chrs long [char *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_base4_codon_from_seq( char * seq);

/* Function:  bp_sw_char_from_base(b)
 *
 * Descrip:    maps a base number (-04 inc) to A,T,G,C,N
 *
 *
 * Arg:        b            Undocumented argument [base]
 *
 * Returns Undocumented return value [char]
 *
 */
char bp_sw_char_from_base( base b);

/* Function:  bp_sw_base_from_char(c)
 *
 * Descrip:    maps a char (atcgn) to number, 
 *             case insensitive, returns BASE_N
 *             if not atcgn
 *
 *
 * Arg:        c            Undocumented argument [char]
 *
 * Returns Undocumented return value [base]
 *
 */
base bp_sw_base_from_char( char c);

/* Function:  bp_sw_char_complement_base(c)
 *
 * Descrip:    the char equivalent of /complement_base.
 *             this gives the complement in char of a base
 *             in char. Does not check for non ATGCN
 *
 *
 * Arg:        c            Undocumented argument [char]
 *
 * Returns Undocumented return value [char]
 *
 */
char bp_sw_char_complement_base( char c);

/* Function:  bp_sw_complement_base(b)
 *
 * Descrip:    gives back the complement as a number
 *             ofthe base (given as a number)
 *
 *
 * Arg:        b            Undocumented argument [base]
 *
 * Returns Undocumented return value [base]
 *
 */
base bp_sw_complement_base( base b);



/* Functions that create, manipulate or act on CodonMapper
 *
 * bp_sw_sprinkle_errors_over_CodonMapper
 * bp_sw_hard_link_CodonMapper
 * bp_sw_CodonMapper_alloc
 * bp_sw_replace_ct_CodonMapper
 * bp_sw_access_ct_CodonMapper
 * bp_sw_free_CodonMapper [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_flat_CodonMapper
 *

/* API for object CodonMapper */
/* Function:  bp_sw_sprinkle_errors_over_CodonMapper(cm,error)
 *
 * Descrip:    Takes a codon mapper and assummes that the majority of errors
 *             are due to a single base change in the codon at probability error.
 *             Therefore, for each codon it adds error * prob(codon) * 0.25 to each 
 *             other codon one base away, taking away therefore the result.
 *
 *
 *
 * Arg:        cm           CodonMapper to be sprinkled [bp_sw_CodonMapper *]
 * Arg:        error        substitution error rate [double]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_sprinkle_errors_over_CodonMapper( bp_sw_CodonMapper * cm,double error);

/* Function:  bp_sw_hard_link_CodonMapper(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_CodonMapper *]
 *
 * Returns Undocumented return value [bp_sw_CodonMapper *]
 *
 */
bp_sw_CodonMapper * bp_sw_hard_link_CodonMapper( bp_sw_CodonMapper * obj);

/* Function:  bp_sw_CodonMapper_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_CodonMapper *]
 *
 */
bp_sw_CodonMapper * bp_sw_CodonMapper_alloc();

/* Function:  bp_sw_replace_ct_CodonMapper(obj,ct)
 *
 * Descrip:    Replace member variable ct
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CodonMapper *]
 * Arg:        ct           New value of the variable [bp_sw_CodonTable *]
 *
 * Returns member variable ct [boolean]
 *
 */
boolean bp_sw_replace_ct_CodonMapper( bp_sw_CodonMapper * obj,bp_sw_CodonTable * ct);

/* Function:  bp_sw_access_ct_CodonMapper(obj)
 *
 * Descrip:    Access member variable ct
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CodonMapper *]
 *
 * Returns member variable ct [bp_sw_CodonTable *]
 *
 */
bp_sw_CodonTable * bp_sw_access_ct_CodonMapper( bp_sw_CodonMapper * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_CodonMapper(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_CodonMapper *]
 *
 * Returns Undocumented return value [bp_sw_CodonMapper *]
 *
 */
bp_sw_CodonMapper * bp_sw_free_CodonMapper( bp_sw_CodonMapper * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_flat_CodonMapper(ct)
 *
 * Descrip:    Makes a CodonMapper with no codon bias
 *             or error possiblities from codon table
 *
 *
 *
 * Arg:        ct           Codon Table giving codon->aa info [bp_sw_CodonTable *]
 *
 * Returns Undocumented return value [bp_sw_CodonMapper *]
 *
 */
bp_sw_CodonMapper * bp_sw_flat_CodonMapper( bp_sw_CodonTable * ct);



/* Functions that create, manipulate or act on ComplexSequence
 *
 * bp_sw_hard_link_ComplexSequence
 * bp_sw_ComplexSequence_alloc
 * bp_sw_replace_type_ComplexSequence
 * bp_sw_access_type_ComplexSequence
 * bp_sw_replace_seq_ComplexSequence
 * bp_sw_access_seq_ComplexSequence
 * bp_sw_free_ComplexSequence [destructor]
 *
 */



/* Functions that create, manipulate or act on ComplexSequenceEvalSet
 *
 * bp_sw_hard_link_ComplexSequenceEvalSet
 * bp_sw_ComplexSequenceEvalSet_alloc_std
 * bp_sw_replace_type_ComplexSequenceEvalSet
 * bp_sw_access_type_ComplexSequenceEvalSet
 * bp_sw_replace_has_been_prepared_ComplexSequenceEvalSet
 * bp_sw_access_has_been_prepared_ComplexSequenceEvalSet
 * bp_sw_replace_left_window_ComplexSequenceEvalSet
 * bp_sw_access_left_window_ComplexSequenceEvalSet
 * bp_sw_replace_right_window_ComplexSequenceEvalSet
 * bp_sw_access_right_window_ComplexSequenceEvalSet
 * bp_sw_replace_left_lookback_ComplexSequenceEvalSet
 * bp_sw_access_left_lookback_ComplexSequenceEvalSet
 * bp_sw_free_ComplexSequenceEvalSet [destructor]
 *
 */

/* API for object ComplexSequence */
/* Function:  bp_sw_hard_link_ComplexSequence(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_ComplexSequence *]
 *
 * Returns Undocumented return value [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_hard_link_ComplexSequence( bp_sw_ComplexSequence * obj);

/* Function:  bp_sw_ComplexSequence_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_ComplexSequence_alloc();

/* Function:  bp_sw_replace_type_ComplexSequence(obj,type)
 *
 * Descrip:    Replace member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequence *]
 * Arg:        type         New value of the variable [int]
 *
 * Returns member variable type [boolean]
 *
 */
boolean bp_sw_replace_type_ComplexSequence( bp_sw_ComplexSequence * obj,int type);

/* Function:  bp_sw_access_type_ComplexSequence(obj)
 *
 * Descrip:    Access member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable type [int]
 *
 */
int bp_sw_access_type_ComplexSequence( bp_sw_ComplexSequence * obj);

/* Function:  bp_sw_replace_seq_ComplexSequence(obj,seq)
 *
 * Descrip:    Replace member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequence *]
 * Arg:        seq          New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable seq [boolean]
 *
 */
boolean bp_sw_replace_seq_ComplexSequence( bp_sw_ComplexSequence * obj,bp_sw_Sequence * seq);

/* Function:  bp_sw_access_seq_ComplexSequence(obj)
 *
 * Descrip:    Access member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable seq [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_seq_ComplexSequence( bp_sw_ComplexSequence * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_ComplexSequence(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_ComplexSequence *]
 *
 * Returns Undocumented return value [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_free_ComplexSequence( bp_sw_ComplexSequence * obj);

/* API for object ComplexSequenceEvalSet */
/* Function:  bp_sw_hard_link_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns Undocumented return value [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_hard_link_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* Function:  bp_sw_ComplexSequenceEvalSet_alloc_std(void)
 *
 * Descrip:    Equivalent to ComplexSequenceEvalSet_alloc_len(ComplexSequenceEvalSetLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_ComplexSequenceEvalSet_alloc_std();

/* Function:  bp_sw_replace_type_ComplexSequenceEvalSet(obj,type)
 *
 * Descrip:    Replace member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 * Arg:        type         New value of the variable [int]
 *
 * Returns member variable type [boolean]
 *
 */
boolean bp_sw_replace_type_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj,int type);

/* Function:  bp_sw_access_type_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Access member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable type [int]
 *
 */
int bp_sw_access_type_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* Function:  bp_sw_replace_has_been_prepared_ComplexSequenceEvalSet(obj,has_been_prepared)
 *
 * Descrip:    Replace member variable has_been_prepared
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 * Arg:        has_been_prepared New value of the variable [boolean]
 *
 * Returns member variable has_been_prepared [boolean]
 *
 */
boolean bp_sw_replace_has_been_prepared_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj,boolean has_been_prepared);

/* Function:  bp_sw_access_has_been_prepared_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Access member variable has_been_prepared
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable has_been_prepared [boolean]
 *
 */
boolean bp_sw_access_has_been_prepared_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* Function:  bp_sw_replace_left_window_ComplexSequenceEvalSet(obj,left_window)
 *
 * Descrip:    Replace member variable left_window
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 * Arg:        left_window  New value of the variable [int]
 *
 * Returns member variable left_window [boolean]
 *
 */
boolean bp_sw_replace_left_window_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj,int left_window);

/* Function:  bp_sw_access_left_window_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Access member variable left_window
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable left_window [int]
 *
 */
int bp_sw_access_left_window_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* Function:  bp_sw_replace_right_window_ComplexSequenceEvalSet(obj,right_window)
 *
 * Descrip:    Replace member variable right_window
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 * Arg:        right_window New value of the variable [int]
 *
 * Returns member variable right_window [boolean]
 *
 */
boolean bp_sw_replace_right_window_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj,int right_window);

/* Function:  bp_sw_access_right_window_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Access member variable right_window
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable right_window [int]
 *
 */
int bp_sw_access_right_window_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* Function:  bp_sw_replace_left_lookback_ComplexSequenceEvalSet(obj,left_lookback)
 *
 * Descrip:    Replace member variable left_lookback
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 * Arg:        left_lookback New value of the variable [int]
 *
 * Returns member variable left_lookback [boolean]
 *
 */
boolean bp_sw_replace_left_lookback_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj,int left_lookback);

/* Function:  bp_sw_access_left_lookback_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Access member variable left_lookback
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable left_lookback [int]
 *
 */
int bp_sw_access_left_lookback_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_ComplexSequenceEvalSet(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns Undocumented return value [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_free_ComplexSequenceEvalSet( bp_sw_ComplexSequenceEvalSet * obj);



/* Functions that create, manipulate or act on CompMat
 *
 * bp_sw_fail_safe_CompMat_access
 * bp_sw_write_Blast_CompMat
 * bp_sw_read_Blast_file_CompMat
 * bp_sw_read_Blast_CompMat
 * bp_sw_hard_link_CompMat
 * bp_sw_CompMat_alloc
 * bp_sw_replace_name_CompMat
 * bp_sw_access_name_CompMat
 * bp_sw_free_CompMat [destructor]
 *
 */

/* API for object CompMat */
/* Function:  bp_sw_fail_safe_CompMat_access(cm,aa1,aa2)
 *
 * Descrip:    gives the fail form of the macro CompMat_AAMATCH which 
 *             checks that aa1 and a2 are sensible and that cm is not NULL.
 *
 *
 * Arg:        cm           compmat object [bp_sw_CompMat *]
 * Arg:        aa1          first amino acid [int]
 * Arg:        aa2          second amino acid [int]
 *
 * Returns Undocumented return value [Score]
 *
 */
Score bp_sw_fail_safe_CompMat_access( bp_sw_CompMat * cm,int aa1,int aa2);

/* Function:  bp_sw_write_Blast_CompMat(cm,ofp)
 *
 * Descrip:    writes a protien CompMat with a standard
 *             alphabet.
 *
 *
 * Arg:        cm           CompMat object [bp_sw_CompMat *]
 * Arg:        ofp          file to output [FILE *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_write_Blast_CompMat( bp_sw_CompMat * cm,FILE * ofp);

/* Function:  bp_sw_read_Blast_file_CompMat(filename)
 *
 * Descrip:    Opens file, reads matrix, closes file.
 *             calls /read_Blast_CompMat for the actual format
 *             reading. Uses /openfile to open the file,
 *             so will open from config files.
 *
 *
 * Arg:        filename     Undocumented argument [char *]
 *
 * Returns Undocumented return value [bp_sw_CompMat *]
 *
 */
bp_sw_CompMat * bp_sw_read_Blast_file_CompMat( char * filename);

/* Function:  bp_sw_read_Blast_CompMat(ifp)
 *
 * Descrip:    reads a BLAST format matrix and
 *             allocates a new ComMat structure.
 *
 *
 * Arg:        ifp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [bp_sw_CompMat *]
 *
 */
bp_sw_CompMat * bp_sw_read_Blast_CompMat( FILE * ifp);

/* Function:  bp_sw_hard_link_CompMat(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_CompMat *]
 *
 * Returns Undocumented return value [bp_sw_CompMat *]
 *
 */
bp_sw_CompMat * bp_sw_hard_link_CompMat( bp_sw_CompMat * obj);

/* Function:  bp_sw_CompMat_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_CompMat *]
 *
 */
bp_sw_CompMat * bp_sw_CompMat_alloc();

/* Function:  bp_sw_replace_name_CompMat(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CompMat *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_CompMat( bp_sw_CompMat * obj,char * name);

/* Function:  bp_sw_access_name_CompMat(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_CompMat *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_CompMat( bp_sw_CompMat * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_CompMat(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_CompMat *]
 *
 * Returns Undocumented return value [bp_sw_CompMat *]
 *
 */
bp_sw_CompMat * bp_sw_free_CompMat( bp_sw_CompMat * obj);



/* Functions that create, manipulate or act on Gene
 *
 * bp_sw_get_Genomic_from_Gene
 * bp_sw_show_pretty_Gene
 * bp_sw_hard_link_Gene
 * bp_sw_Gene_alloc_std
 * bp_sw_replace_start_Gene
 * bp_sw_access_start_Gene
 * bp_sw_replace_end_Gene
 * bp_sw_access_end_Gene
 * bp_sw_replace_parent_Gene
 * bp_sw_access_parent_Gene
 * bp_sw_replace_genomic_Gene
 * bp_sw_access_genomic_Gene
 * bp_sw_access_transcript_Gene
 * bp_sw_length_transcript_Gene
 * bp_sw_flush_Gene
 * bp_sw_add_Gene
 * bp_sw_replace_name_Gene
 * bp_sw_access_name_Gene
 * bp_sw_replace_bits_Gene
 * bp_sw_access_bits_Gene
 * bp_sw_replace_seqname_Gene
 * bp_sw_access_seqname_Gene
 * bp_sw_free_Gene [destructor]
 *
 */

/* API for object Gene */
/* Function:  bp_sw_get_Genomic_from_Gene(gene)
 *
 * Descrip:    Gives back a Genomic sequence type
 *             from a gene.
 *
 *
 * Arg:        gene         gene to get Genomic from [bp_sw_Gene *]
 *
 * Returns Genomic DNA data structure [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_get_Genomic_from_Gene( bp_sw_Gene * gene);

/* Function:  bp_sw_show_pretty_Gene(ge,ofp)
 *
 * Descrip:    Shows a gene in the biologically accepted form
 *
 *
 * Arg:        ge           Undocumented argument [bp_sw_Gene *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_pretty_Gene( bp_sw_Gene * ge,FILE * ofp);

/* Function:  bp_sw_hard_link_Gene(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Gene *]
 *
 * Returns Undocumented return value [bp_sw_Gene *]
 *
 */
bp_sw_Gene * bp_sw_hard_link_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_Gene_alloc_std(void)
 *
 * Descrip:    Equivalent to Gene_alloc_len(GeneLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Gene *]
 *
 */
bp_sw_Gene * bp_sw_Gene_alloc_std();

/* Function:  bp_sw_replace_start_Gene(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        start        New value of the variable [int]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_Gene( bp_sw_Gene * obj,int start);

/* Function:  bp_sw_access_start_Gene(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable start [int]
 *
 */
int bp_sw_access_start_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_replace_end_Gene(obj,end)
 *
 * Descrip:    Replace member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        end          New value of the variable [int]
 *
 * Returns member variable end [boolean]
 *
 */
boolean bp_sw_replace_end_Gene( bp_sw_Gene * obj,int end);

/* Function:  bp_sw_access_end_Gene(obj)
 *
 * Descrip:    Access member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable end [int]
 *
 */
int bp_sw_access_end_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_replace_parent_Gene(obj,parent)
 *
 * Descrip:    Replace member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        parent       New value of the variable [bp_sw_GenomicRegion *]
 *
 * Returns member variable parent [boolean]
 *
 */
boolean bp_sw_replace_parent_Gene( bp_sw_Gene * obj,bp_sw_GenomicRegion * parent);

/* Function:  bp_sw_access_parent_Gene(obj)
 *
 * Descrip:    Access member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable parent [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_access_parent_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_replace_genomic_Gene(obj,genomic)
 *
 * Descrip:    Replace member variable genomic
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        genomic      New value of the variable [bp_sw_Genomic *]
 *
 * Returns member variable genomic [boolean]
 *
 */
boolean bp_sw_replace_genomic_Gene( bp_sw_Gene * obj,bp_sw_Genomic * genomic);

/* Function:  bp_sw_access_genomic_Gene(obj)
 *
 * Descrip:    Access member variable genomic
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable genomic [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_access_genomic_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_access_transcript_Gene(obj,i)
 *
 * Descrip:    Access members stored in the transcript list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Gene *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_Transcript *]
 *
 */
bp_sw_Transcript * bp_sw_access_transcript_Gene( bp_sw_Gene * obj,int i);

/* Function:  bp_sw_length_transcript_Gene(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Gene *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_transcript_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_flush_Gene(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_Gene *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_add_Gene(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_Gene *]
 * Arg:        add          Object to add to the list [bp_sw_Transcript *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_Gene( bp_sw_Gene * obj,bp_sw_Transcript * add);

/* Function:  bp_sw_replace_name_Gene(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_Gene( bp_sw_Gene * obj,char * name);

/* Function:  bp_sw_access_name_Gene(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_replace_bits_Gene(obj,bits)
 *
 * Descrip:    Replace member variable bits
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        bits         New value of the variable [double]
 *
 * Returns member variable bits [boolean]
 *
 */
boolean bp_sw_replace_bits_Gene( bp_sw_Gene * obj,double bits);

/* Function:  bp_sw_access_bits_Gene(obj)
 *
 * Descrip:    Access member variable bits
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable bits [double]
 *
 */
double bp_sw_access_bits_Gene( bp_sw_Gene * obj);

/* Function:  bp_sw_replace_seqname_Gene(obj,seqname)
 *
 * Descrip:    Replace member variable seqname
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 * Arg:        seqname      New value of the variable [char *]
 *
 * Returns member variable seqname [boolean]
 *
 */
boolean bp_sw_replace_seqname_Gene( bp_sw_Gene * obj,char * seqname);

/* Function:  bp_sw_access_seqname_Gene(obj)
 *
 * Descrip:    Access member variable seqname
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Gene *]
 *
 * Returns member variable seqname [char *]
 *
 */
char * bp_sw_access_seqname_Gene( bp_sw_Gene * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Gene(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Gene *]
 *
 * Returns Undocumented return value [bp_sw_Gene *]
 *
 */
bp_sw_Gene * bp_sw_free_Gene( bp_sw_Gene * obj);



/* Functions that create, manipulate or act on Genomic
 *
 * bp_sw_truncate_Genomic
 * bp_sw_read_fasta_file_Genomic
 * bp_sw_Genomic_name
 * bp_sw_Genomic_length
 * bp_sw_Genomic_seqchar
 * bp_sw_Genomic_from_Sequence
 * bp_sw_hard_link_Genomic
 * bp_sw_Genomic_alloc
 * bp_sw_replace_baseseq_Genomic
 * bp_sw_access_baseseq_Genomic
 * bp_sw_free_Genomic [destructor]
 *
 */

/* API for object Genomic */
/* Function:  bp_sw_truncate_Genomic(gen,start,stop)
 *
 * Descrip:    Truncates a Genomic sequence. Basically uses
 *             the /magic_trunc_Sequence function (of course!)
 *
 *             It does not alter gen, rather it returns a new
 *             sequence with that truncation
 *
 *
 * Arg:        gen          Genomic that is truncated [bp_sw_Genomic *]
 * Arg:        start        Undocumented argument [int]
 * Arg:        stop         Undocumented argument [int]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_truncate_Genomic( bp_sw_Genomic * gen,int start,int stop);

/* Function:  bp_sw_read_fasta_file_Genomic(filename)
 *
 * Descrip:    Reads a fasta file assumming that it is Genomic. 
 *             Will complain if it is not, and return NULL.
 *
 *
 * Arg:        filename     filename to be opened and read [char *]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_read_fasta_file_Genomic( char * filename);

/* Function:  bp_sw_Genomic_name(gen)
 *
 * Descrip:    Returns the name of the Genomic
 *
 *
 * Arg:        gen          Undocumented argument [bp_sw_Genomic *]
 *
 * Returns Undocumented return value [char *]
 *
 */
char * bp_sw_Genomic_name( bp_sw_Genomic * gen);

/* Function:  bp_sw_Genomic_length(gen)
 *
 * Descrip:    Returns the length of the Genomic
 *
 *
 * Arg:        gen          Undocumented argument [bp_sw_Genomic *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_Genomic_length( bp_sw_Genomic * gen);

/* Function:  bp_sw_Genomic_seqchar(gen,pos)
 *
 * Descrip:    Returns sequence character at this position.
 *
 *
 * Arg:        gen          Genomic [bp_sw_Genomic *]
 * Arg:        pos          position in Genomic to get char [int]
 *
 * Returns Undocumented return value [char]
 *
 */
char bp_sw_Genomic_seqchar( bp_sw_Genomic * gen,int pos);

/* Function:  bp_sw_Genomic_from_Sequence(seq)
 *
 * Descrip:    makes a new genomic from a Sequence. It 
 *             owns the Sequence memory, ie will attempt a /free_Sequence
 *             on the structure when /free_Genomic is called
 *
 *             If you want to give this genomic this Sequence and
 *             forget about it, then just hand it this sequence and set
 *             seq to NULL (no need to free it). If you intend to use 
 *             the sequence object elsewhere outside of the Genomic datastructure
 *             then use Genomic_from_Sequence(/hard_link_Sequence(seq))
 *
 *             This is part of a strict typing system, and therefore
 *             is going to convert all non ATGCNs to Ns. You will lose
 *             information here.
 *
 *
 * Arg:        seq          Sequence to make genomic from [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_Genomic_from_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_hard_link_Genomic(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Genomic *]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_hard_link_Genomic( bp_sw_Genomic * obj);

/* Function:  bp_sw_Genomic_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_Genomic_alloc();

/* Function:  bp_sw_replace_baseseq_Genomic(obj,baseseq)
 *
 * Descrip:    Replace member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Genomic *]
 * Arg:        baseseq      New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable baseseq [boolean]
 *
 */
boolean bp_sw_replace_baseseq_Genomic( bp_sw_Genomic * obj,bp_sw_Sequence * baseseq);

/* Function:  bp_sw_access_baseseq_Genomic(obj)
 *
 * Descrip:    Access member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Genomic *]
 *
 * Returns member variable baseseq [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_baseseq_Genomic( bp_sw_Genomic * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Genomic(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Genomic *]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_free_Genomic( bp_sw_Genomic * obj);



/* Functions that create, manipulate or act on GenomicDB
 *
 * bp_sw_get_Genomic_from_GenomicDB
 * bp_sw_hard_link_GenomicDB
 * bp_sw_GenomicDB_alloc
 * bp_sw_replace_is_single_seq_GenomicDB
 * bp_sw_access_is_single_seq_GenomicDB
 * bp_sw_replace_done_forward_GenomicDB
 * bp_sw_access_done_forward_GenomicDB
 * bp_sw_replace_forw_GenomicDB
 * bp_sw_access_forw_GenomicDB
 * bp_sw_replace_rev_GenomicDB
 * bp_sw_access_rev_GenomicDB
 * bp_sw_replace_sdb_GenomicDB
 * bp_sw_access_sdb_GenomicDB
 * bp_sw_replace_current_GenomicDB
 * bp_sw_access_current_GenomicDB
 * bp_sw_replace_cses_GenomicDB
 * bp_sw_access_cses_GenomicDB
 * bp_sw_free_GenomicDB [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_new_GenomicDB_from_single_seq
 * bp_sw_new_GenomicDB
 *

/* API for object GenomicDB */
/* Function:  bp_sw_get_Genomic_from_GenomicDB(gendb,de)
 *
 * Descrip:    Gets Genomic sequence out from
 *             the GenomicDB using the information stored in
 *             dataentry
 *
 *
 * Arg:        gendb        Undocumented argument [bp_sw_GenomicDB *]
 * Arg:        de           Undocumented argument [bp_sw_DataEntry *]
 *
 * Returns Undocumented return value [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_get_Genomic_from_GenomicDB( bp_sw_GenomicDB * gendb,bp_sw_DataEntry * de);

/* Function:  bp_sw_hard_link_GenomicDB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_GenomicDB *]
 *
 * Returns Undocumented return value [bp_sw_GenomicDB *]
 *
 */
bp_sw_GenomicDB * bp_sw_hard_link_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_GenomicDB_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_GenomicDB *]
 *
 */
bp_sw_GenomicDB * bp_sw_GenomicDB_alloc();

/* Function:  bp_sw_replace_is_single_seq_GenomicDB(obj,is_single_seq)
 *
 * Descrip:    Replace member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        is_single_seq New value of the variable [boolean]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_replace_is_single_seq_GenomicDB( bp_sw_GenomicDB * obj,boolean is_single_seq);

/* Function:  bp_sw_access_is_single_seq_GenomicDB(obj)
 *
 * Descrip:    Access member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_access_is_single_seq_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_done_forward_GenomicDB(obj,done_forward)
 *
 * Descrip:    Replace member variable done_forward
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        done_forward New value of the variable [boolean]
 *
 * Returns member variable done_forward [boolean]
 *
 */
boolean bp_sw_replace_done_forward_GenomicDB( bp_sw_GenomicDB * obj,boolean done_forward);

/* Function:  bp_sw_access_done_forward_GenomicDB(obj)
 *
 * Descrip:    Access member variable done_forward
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable done_forward [boolean]
 *
 */
boolean bp_sw_access_done_forward_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_forw_GenomicDB(obj,forw)
 *
 * Descrip:    Replace member variable forw
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        forw         New value of the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable forw [boolean]
 *
 */
boolean bp_sw_replace_forw_GenomicDB( bp_sw_GenomicDB * obj,bp_sw_ComplexSequence * forw);

/* Function:  bp_sw_access_forw_GenomicDB(obj)
 *
 * Descrip:    Access member variable forw
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable forw [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_access_forw_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_rev_GenomicDB(obj,rev)
 *
 * Descrip:    Replace member variable rev
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        rev          New value of the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable rev [boolean]
 *
 */
boolean bp_sw_replace_rev_GenomicDB( bp_sw_GenomicDB * obj,bp_sw_ComplexSequence * rev);

/* Function:  bp_sw_access_rev_GenomicDB(obj)
 *
 * Descrip:    Access member variable rev
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable rev [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_access_rev_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_sdb_GenomicDB(obj,sdb)
 *
 * Descrip:    Replace member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        sdb          New value of the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable sdb [boolean]
 *
 */
boolean bp_sw_replace_sdb_GenomicDB( bp_sw_GenomicDB * obj,bp_sw_SequenceDB * sdb);

/* Function:  bp_sw_access_sdb_GenomicDB(obj)
 *
 * Descrip:    Access member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable sdb [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_access_sdb_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_current_GenomicDB(obj,current)
 *
 * Descrip:    Replace member variable current
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        current      New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable current [boolean]
 *
 */
boolean bp_sw_replace_current_GenomicDB( bp_sw_GenomicDB * obj,bp_sw_Sequence * current);

/* Function:  bp_sw_access_current_GenomicDB(obj)
 *
 * Descrip:    Access member variable current
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable current [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_current_GenomicDB( bp_sw_GenomicDB * obj);

/* Function:  bp_sw_replace_cses_GenomicDB(obj,cses)
 *
 * Descrip:    Replace member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 * Arg:        cses         New value of the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable cses [boolean]
 *
 */
boolean bp_sw_replace_cses_GenomicDB( bp_sw_GenomicDB * obj,bp_sw_ComplexSequenceEvalSet * cses);

/* Function:  bp_sw_access_cses_GenomicDB(obj)
 *
 * Descrip:    Access member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicDB *]
 *
 * Returns member variable cses [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_access_cses_GenomicDB( bp_sw_GenomicDB * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_GenomicDB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_GenomicDB *]
 *
 * Returns Undocumented return value [bp_sw_GenomicDB *]
 *
 */
bp_sw_GenomicDB * bp_sw_free_GenomicDB( bp_sw_GenomicDB * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_new_GenomicDB_from_single_seq(seq,cses)
 *
 * Descrip:    To make a new genomic database
 *             from a single Genomic Sequence with a eval system
 *
 *
 * Arg:        seq          sequence which as placed into GenomicDB structure. [bp_sw_Genomic *]
 * Arg:        cses         Undocumented argument [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns Undocumented return value [bp_sw_GenomicDB *]
 *
 */
bp_sw_GenomicDB * bp_sw_new_GenomicDB_from_single_seq( bp_sw_Genomic * seq,bp_sw_ComplexSequenceEvalSet * cses);

/* Function:  bp_sw_new_GenomicDB(seqdb,cses)
 *
 * Descrip:    To make a new genomic database
 *
 *
 * Arg:        seqdb        sequence database [bp_sw_SequenceDB *]
 * Arg:        cses         protein evaluation set [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns Undocumented return value [bp_sw_GenomicDB *]
 *
 */
bp_sw_GenomicDB * bp_sw_new_GenomicDB( bp_sw_SequenceDB * seqdb,bp_sw_ComplexSequenceEvalSet * cses);



/* Functions that create, manipulate or act on GenomicRegion
 *
 * bp_sw_new_GenomicRegion
 * bp_sw_read_EMBL_GenomicRegion_file
 * bp_sw_read_EMBL_GenomicRegion
 * bp_sw_add_Gene_to_GenomicRegion
 * bp_sw_show_ace_GenomicRegion
 * bp_sw_show_pretty_GenomicRegion
 * bp_sw_hard_link_GenomicRegion
 * bp_sw_GenomicRegion_alloc_std
 * bp_sw_access_gene_GenomicRegion
 * bp_sw_length_gene_GenomicRegion
 * bp_sw_flush_GenomicRegion
 * bp_sw_add_GenomicRegion
 * bp_sw_replace_genomic_GenomicRegion
 * bp_sw_access_genomic_GenomicRegion
 * bp_sw_free_GenomicRegion [destructor]
 *
 */

/* API for object GenomicRegion */
/* Function:  bp_sw_new_GenomicRegion(gen)
 *
 * Descrip:    makes a genomicregion from a genomic sequence
 *
 *
 * Arg:        gen          Undocumented argument [bp_sw_Genomic *]
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_new_GenomicRegion( bp_sw_Genomic * gen);

/* Function:  bp_sw_read_EMBL_GenomicRegion_file(filename)
 *
 * Descrip:    Reads in both EMBL sequence and features 
 *
 *
 * Arg:        filename     Undocumented argument [char *]
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_read_EMBL_GenomicRegion_file( char * filename);

/* Function:  bp_sw_read_EMBL_GenomicRegion(ifp)
 *
 * Descrip:    Reads in both EMBL sequence and features 
 *
 *
 * Arg:        ifp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_read_EMBL_GenomicRegion( FILE * ifp);

/* Function:  bp_sw_add_Gene_to_GenomicRegion(gr,gene)
 *
 * Descrip:    adds a Gene to this GenomicRegion, making
 *             sure that it parent/son relationship is ok
 *
 *
 * Arg:        gr           GenomicRegion to be added to [bp_sw_GenomicRegion *]
 * Arg:        gene         Gene to be added [bp_sw_Gene *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_Gene_to_GenomicRegion( bp_sw_GenomicRegion * gr,bp_sw_Gene * gene);

/* Function:  bp_sw_show_ace_GenomicRegion(gr,seq_name,ofp)
 *
 * Descrip:    shows ACeDB subsequence source.
 *
 *             Assummes
 *               a only one transcript per gene
 *               b only cds exons are used
 *
 *
 * Arg:        gr           Undocumented argument [bp_sw_GenomicRegion *]
 * Arg:        seq_name     Undocumented argument [char *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_ace_GenomicRegion( bp_sw_GenomicRegion * gr,char * seq_name,FILE * ofp);

/* Function:  bp_sw_show_pretty_GenomicRegion(gr,ofp)
 *
 * Descrip: No Description
 *
 * Arg:        gr           Undocumented argument [bp_sw_GenomicRegion *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_pretty_GenomicRegion( bp_sw_GenomicRegion * gr,FILE * ofp);

/* Function:  bp_sw_hard_link_GenomicRegion(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_GenomicRegion *]
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_hard_link_GenomicRegion( bp_sw_GenomicRegion * obj);

/* Function:  bp_sw_GenomicRegion_alloc_std(void)
 *
 * Descrip:    Equivalent to GenomicRegion_alloc_len(GenomicRegionLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_GenomicRegion_alloc_std();

/* Function:  bp_sw_access_gene_GenomicRegion(obj,i)
 *
 * Descrip:    Access members stored in the gene list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_GenomicRegion *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_Gene *]
 *
 */
bp_sw_Gene * bp_sw_access_gene_GenomicRegion( bp_sw_GenomicRegion * obj,int i);

/* Function:  bp_sw_length_gene_GenomicRegion(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_GenomicRegion *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_gene_GenomicRegion( bp_sw_GenomicRegion * obj);

/* Function:  bp_sw_flush_GenomicRegion(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_GenomicRegion *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_GenomicRegion( bp_sw_GenomicRegion * obj);

/* Function:  bp_sw_add_GenomicRegion(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_GenomicRegion *]
 * Arg:        add          Object to add to the list [bp_sw_Gene *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_GenomicRegion( bp_sw_GenomicRegion * obj,bp_sw_Gene * add);

/* Function:  bp_sw_replace_genomic_GenomicRegion(obj,genomic)
 *
 * Descrip:    Replace member variable genomic
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicRegion *]
 * Arg:        genomic      New value of the variable [bp_sw_Genomic *]
 *
 * Returns member variable genomic [boolean]
 *
 */
boolean bp_sw_replace_genomic_GenomicRegion( bp_sw_GenomicRegion * obj,bp_sw_Genomic * genomic);

/* Function:  bp_sw_access_genomic_GenomicRegion(obj)
 *
 * Descrip:    Access member variable genomic
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_GenomicRegion *]
 *
 * Returns member variable genomic [bp_sw_Genomic *]
 *
 */
bp_sw_Genomic * bp_sw_access_genomic_GenomicRegion( bp_sw_GenomicRegion * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_GenomicRegion(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_GenomicRegion *]
 *
 * Returns Undocumented return value [bp_sw_GenomicRegion *]
 *
 */
bp_sw_GenomicRegion * bp_sw_free_GenomicRegion( bp_sw_GenomicRegion * obj);



/* Functions that create, manipulate or act on Histogram
 *
 * bp_sw_UnfitHistogram
 * bp_sw_AddToHistogram
 * bp_sw_PrintASCIIHistogram
 * bp_sw_EVDBasicFit
 * bp_sw_ExtremeValueFitHistogram
 * bp_sw_ExtremeValueSetHistogram
 * bp_sw_GaussianFitHistogram
 * bp_sw_GaussianSetHistogram
 * bp_sw_hard_link_Histogram
 * bp_sw_Histogram_alloc
 * bp_sw_free_Histogram [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_new_Histogram
 *

/* API for object Histogram */
/* Function:  bp_sw_UnfitHistogram(h)
 *
 * Descrip: No Description
 *
 * Arg:        h            Undocumented argument [bp_sw_Histogram *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_UnfitHistogram( bp_sw_Histogram * h);

/* Function:  bp_sw_AddToHistogram(h,sc)
 *
 * Descrip: No Description
 *
 * Arg:        h            Undocumented argument [bp_sw_Histogram *]
 * Arg:        sc           Undocumented argument [float]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_AddToHistogram( bp_sw_Histogram * h,float sc);

/* Function:  bp_sw_PrintASCIIHistogram(h,fp)
 *
 * Descrip: No Description
 *
 * Arg:        h            histogram to print [bp_sw_Histogram *]
 * Arg:        fp           open file to print to (stdout works) [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_PrintASCIIHistogram( bp_sw_Histogram * h,FILE * fp);

/* Function:  bp_sw_EVDBasicFit(h)
 *
 * Descrip: No Description
 *
 * Arg:        h            histogram to fit [bp_sw_Histogram *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_EVDBasicFit( bp_sw_Histogram * h);

/* Function:  bp_sw_ExtremeValueFitHistogram(h,censor,high_hint)
 *
 * Descrip: No Description
 *
 * Arg:        h            histogram to fit [bp_sw_Histogram *]
 * Arg:        censor       TRUE to censor data left of the peak [int]
 * Arg:        high_hint    score cutoff; above this are `real' hits that aren't fit [float]
 *
 * Returns if fit is judged to be valid else 0 if fit is invalid (too few seqs.) [int]
 *
 */
int bp_sw_ExtremeValueFitHistogram( bp_sw_Histogram * h,int censor,float high_hint);

/* Function:  bp_sw_ExtremeValueSetHistogram(h,mu,lambda,lowbound,highbound,wonka,ndegrees)
 *
 * Descrip: No Description
 *
 * Arg:        h            the histogram to set [bp_sw_Histogram *]
 * Arg:        mu           mu location parameter                 [float]
 * Arg:        lambda       lambda scale parameter [float]
 * Arg:        lowbound     low bound of the histogram that was fit [float]
 * Arg:        highbound    high bound of histogram that was fit [float]
 * Arg:        wonka        fudge factor; fraction of hits estimated to be "EVD-like" [float]
 * Arg:        ndegrees     extra degrees of freedom to subtract in X^2 test: [int]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_ExtremeValueSetHistogram( bp_sw_Histogram * h,float mu,float lambda,float lowbound,float highbound,float wonka,int ndegrees);

/* Function:  bp_sw_GaussianFitHistogram(h,high_hint)
 *
 * Descrip: No Description
 *
 * Arg:        h            histogram to fit [bp_sw_Histogram *]
 * Arg:        high_hint    score cutoff; above this are `real' hits that aren't fit [float]
 *
 * Returns if fit is judged to be valid else 0 if fit is invalid (too few seqs.)            [int]
 *
 */
int bp_sw_GaussianFitHistogram( bp_sw_Histogram * h,float high_hint);

/* Function:  bp_sw_GaussianSetHistogram(h,mean,sd)
 *
 * Descrip: No Description
 *
 * Arg:        h            Undocumented argument [bp_sw_Histogram *]
 * Arg:        mean         Undocumented argument [float]
 * Arg:        sd           Undocumented argument [float]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_GaussianSetHistogram( bp_sw_Histogram * h,float mean,float sd);

/* Function:  bp_sw_hard_link_Histogram(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Histogram *]
 *
 * Returns Undocumented return value [bp_sw_Histogram *]
 *
 */
bp_sw_Histogram * bp_sw_hard_link_Histogram( bp_sw_Histogram * obj);

/* Function:  bp_sw_Histogram_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Histogram *]
 *
 */
bp_sw_Histogram * bp_sw_Histogram_alloc();

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Histogram(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Histogram *]
 *
 * Returns Undocumented return value [bp_sw_Histogram *]
 *
 */
bp_sw_Histogram * bp_sw_free_Histogram( bp_sw_Histogram * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_new_Histogram(min,max,lumpsize)
 *
 * Descrip: No Description
 *
 * Arg:        min          minimum score (integer) [int]
 * Arg:        max          maximum score (integer) [int]
 * Arg:        lumpsize     when reallocating histogram, the reallocation amount [int]
 *
 * Returns Undocumented return value [bp_sw_Histogram *]
 *
 */
bp_sw_Histogram * bp_sw_new_Histogram( int min,int max,int lumpsize);



/* Functions that create, manipulate or act on Hscore
 *
 * bp_sw_minimum_score_Hscore
 * bp_sw_maximum_score_Hscore
 * bp_sw_sort_Hscore_by_score
 * bp_sw_length_datascore_Hscore
 * bp_sw_get_datascore_Hscore
 * bp_sw_get_score_Hscore
 * bp_sw_get_evalue_Hscore
 * bp_sw_basic_show_Hscore
 * bp_sw_hard_link_Hscore
 * bp_sw_Hscore_alloc_std
 * bp_sw_free_Hscore [destructor]
 *
 */



/* Functions that create, manipulate or act on DataScore
 *
 * bp_sw_hard_link_DataScore
 * bp_sw_DataScore_alloc
 * bp_sw_replace_query_DataScore
 * bp_sw_access_query_DataScore
 * bp_sw_replace_target_DataScore
 * bp_sw_access_target_DataScore
 * bp_sw_replace_score_DataScore
 * bp_sw_access_score_DataScore
 * bp_sw_replace_evalue_DataScore
 * bp_sw_access_evalue_DataScore
 * bp_sw_free_DataScore [destructor]
 *
 */



/* Functions that create, manipulate or act on DataEntry
 *
 * bp_sw_hard_link_DataEntry
 * bp_sw_DataEntry_alloc
 * bp_sw_replace_name_DataEntry
 * bp_sw_access_name_DataEntry
 * bp_sw_replace_is_reversed_DataEntry
 * bp_sw_access_is_reversed_DataEntry
 * bp_sw_replace_filename_DataEntry
 * bp_sw_access_filename_DataEntry
 * bp_sw_free_DataEntry [destructor]
 *
 */

/* API for object Hscore */
/* Function:  bp_sw_minimum_score_Hscore(hs)
 *
 * Descrip:    gets the minimum score from Hscore
 *
 *
 * Arg:        hs           Undocumented argument [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_minimum_score_Hscore( bp_sw_Hscore * hs);

/* Function:  bp_sw_maximum_score_Hscore(hs)
 *
 * Descrip:    gets the maximum score from Hscore
 *
 *
 * Arg:        hs           Undocumented argument [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_maximum_score_Hscore( bp_sw_Hscore * hs);

/* Function:  bp_sw_sort_Hscore_by_score(hs)
 *
 * Descrip:    As it says, sorts the high score by its score
 *
 *
 * Arg:        hs           Hscore to be sorted [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_sort_Hscore_by_score( bp_sw_Hscore * hs);

/* Function:  bp_sw_length_datascore_Hscore(obj)
 *
 * Descrip:    Returns the number of datascores in the hscore
 *             structure
 *
 *
 * Arg:        obj          Hscore object [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_length_datascore_Hscore( bp_sw_Hscore * obj);

/* Function:  bp_sw_get_datascore_Hscore(hs,i)
 *
 * Descrip:    Returns the specific datascore held at this
 *             position.
 *
 *             This requires a considerable amount of memory
 *             duplication, so please dont process all your
 *             results by looping through this.
 *
 *
 * Arg:        hs           Hscore object [bp_sw_Hscore *]
 * Arg:        i            position to be read [int]
 *
 * Returns New datascore object [bp_sw_DataScore *]
 *
 */
bp_sw_DataScore * bp_sw_get_datascore_Hscore( bp_sw_Hscore * hs,int i);

/* Function:  bp_sw_get_score_Hscore(hs,i)
 *
 * Descrip: No Description
 *
 * Arg:        hs           Hscore object [bp_sw_Hscore *]
 * Arg:        i            position to be read [int]
 *
 * Returns score  [int]
 *
 */
int bp_sw_get_score_Hscore( bp_sw_Hscore * hs,int i);

/* Function:  bp_sw_get_evalue_Hscore(hs,i)
 *
 * Descrip:    Returns the evalue of the specific datascore held at this position.
 *
 *
 *
 * Arg:        hs           Hscore object [bp_sw_Hscore *]
 * Arg:        i            position to be read [int]
 *
 * Returns evalue  [double]
 *
 */
double bp_sw_get_evalue_Hscore( bp_sw_Hscore * hs,int i);

/* Function:  bp_sw_basic_show_Hscore(hs,ofp)
 *
 * Descrip:    The most baby-talk showing of Hscore
 *
 *
 * Arg:        hs           Undocumented argument [bp_sw_Hscore *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_basic_show_Hscore( bp_sw_Hscore * hs,FILE * ofp);

/* Function:  bp_sw_hard_link_Hscore(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [bp_sw_Hscore *]
 *
 */
bp_sw_Hscore * bp_sw_hard_link_Hscore( bp_sw_Hscore * obj);

/* Function:  bp_sw_Hscore_alloc_std(void)
 *
 * Descrip:    Equivalent to Hscore_alloc_len(HscoreLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Hscore *]
 *
 */
bp_sw_Hscore * bp_sw_Hscore_alloc_std();

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Hscore(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Hscore *]
 *
 * Returns Undocumented return value [bp_sw_Hscore *]
 *
 */
bp_sw_Hscore * bp_sw_free_Hscore( bp_sw_Hscore * obj);

/* API for object DataScore */
/* Function:  bp_sw_hard_link_DataScore(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_DataScore *]
 *
 * Returns Undocumented return value [bp_sw_DataScore *]
 *
 */
bp_sw_DataScore * bp_sw_hard_link_DataScore( bp_sw_DataScore * obj);

/* Function:  bp_sw_DataScore_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_DataScore *]
 *
 */
bp_sw_DataScore * bp_sw_DataScore_alloc();

/* Function:  bp_sw_replace_query_DataScore(obj,query)
 *
 * Descrip:    Replace member variable query
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 * Arg:        query        New value of the variable [bp_sw_DataEntry *]
 *
 * Returns member variable query [boolean]
 *
 */
boolean bp_sw_replace_query_DataScore( bp_sw_DataScore * obj,bp_sw_DataEntry * query);

/* Function:  bp_sw_access_query_DataScore(obj)
 *
 * Descrip:    Access member variable query
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 *
 * Returns member variable query [bp_sw_DataEntry *]
 *
 */
bp_sw_DataEntry * bp_sw_access_query_DataScore( bp_sw_DataScore * obj);

/* Function:  bp_sw_replace_target_DataScore(obj,target)
 *
 * Descrip:    Replace member variable target
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 * Arg:        target       New value of the variable [bp_sw_DataEntry *]
 *
 * Returns member variable target [boolean]
 *
 */
boolean bp_sw_replace_target_DataScore( bp_sw_DataScore * obj,bp_sw_DataEntry * target);

/* Function:  bp_sw_access_target_DataScore(obj)
 *
 * Descrip:    Access member variable target
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 *
 * Returns member variable target [bp_sw_DataEntry *]
 *
 */
bp_sw_DataEntry * bp_sw_access_target_DataScore( bp_sw_DataScore * obj);

/* Function:  bp_sw_replace_score_DataScore(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 * Arg:        score        New value of the variable [int]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_DataScore( bp_sw_DataScore * obj,int score);

/* Function:  bp_sw_access_score_DataScore(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 *
 * Returns member variable score [int]
 *
 */
int bp_sw_access_score_DataScore( bp_sw_DataScore * obj);

/* Function:  bp_sw_replace_evalue_DataScore(obj,evalue)
 *
 * Descrip:    Replace member variable evalue
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 * Arg:        evalue       New value of the variable [double]
 *
 * Returns member variable evalue [boolean]
 *
 */
boolean bp_sw_replace_evalue_DataScore( bp_sw_DataScore * obj,double evalue);

/* Function:  bp_sw_access_evalue_DataScore(obj)
 *
 * Descrip:    Access member variable evalue
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataScore *]
 *
 * Returns member variable evalue [double]
 *
 */
double bp_sw_access_evalue_DataScore( bp_sw_DataScore * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_DataScore(obj)
 *
 * Descrip:    Correctly handles destruction of a datascore
 *
 *
 * Arg:        obj          Undocumented argument [bp_sw_DataScore *]
 *
 * Returns Undocumented return value [bp_sw_DataScore *]
 *
 */
bp_sw_DataScore * bp_sw_free_DataScore( bp_sw_DataScore * obj);

/* API for object DataEntry */
/* Function:  bp_sw_hard_link_DataEntry(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_DataEntry *]
 *
 * Returns Undocumented return value [bp_sw_DataEntry *]
 *
 */
bp_sw_DataEntry * bp_sw_hard_link_DataEntry( bp_sw_DataEntry * obj);

/* Function:  bp_sw_DataEntry_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_DataEntry *]
 *
 */
bp_sw_DataEntry * bp_sw_DataEntry_alloc();

/* Function:  bp_sw_replace_name_DataEntry(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_DataEntry( bp_sw_DataEntry * obj,char * name);

/* Function:  bp_sw_access_name_DataEntry(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_DataEntry( bp_sw_DataEntry * obj);

/* Function:  bp_sw_replace_is_reversed_DataEntry(obj,is_reversed)
 *
 * Descrip:    Replace member variable is_reversed
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 * Arg:        is_reversed  New value of the variable [boolean]
 *
 * Returns member variable is_reversed [boolean]
 *
 */
boolean bp_sw_replace_is_reversed_DataEntry( bp_sw_DataEntry * obj,boolean is_reversed);

/* Function:  bp_sw_access_is_reversed_DataEntry(obj)
 *
 * Descrip:    Access member variable is_reversed
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 *
 * Returns member variable is_reversed [boolean]
 *
 */
boolean bp_sw_access_is_reversed_DataEntry( bp_sw_DataEntry * obj);

/* Function:  bp_sw_replace_filename_DataEntry(obj,filename)
 *
 * Descrip:    Replace member variable filename
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 * Arg:        filename     New value of the variable [char *]
 *
 * Returns member variable filename [boolean]
 *
 */
boolean bp_sw_replace_filename_DataEntry( bp_sw_DataEntry * obj,char * filename);

/* Function:  bp_sw_access_filename_DataEntry(obj)
 *
 * Descrip:    Access member variable filename
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_DataEntry *]
 *
 * Returns member variable filename [char *]
 *
 */
char * bp_sw_access_filename_DataEntry( bp_sw_DataEntry * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_DataEntry(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_DataEntry *]
 *
 * Returns Undocumented return value [bp_sw_DataEntry *]
 *
 */
bp_sw_DataEntry * bp_sw_free_DataEntry( bp_sw_DataEntry * obj);



/* Functions that create, manipulate or act on PackAln
 *
 * bp_sw_show_simple_PackAln
 * bp_sw_show_bits_and_cumlative_PackAln
 * bp_sw_hard_link_PackAln
 * bp_sw_PackAln_alloc_std
 * bp_sw_access_pau_PackAln
 * bp_sw_length_pau_PackAln
 * bp_sw_flush_PackAln
 * bp_sw_add_PackAln
 * bp_sw_replace_score_PackAln
 * bp_sw_access_score_PackAln
 * bp_sw_free_PackAln [destructor]
 *
 */



/* Functions that create, manipulate or act on PackAlnUnit
 *
 * bp_sw_hard_link_PackAlnUnit
 * bp_sw_PackAlnUnit_alloc
 * bp_sw_replace_i_PackAlnUnit
 * bp_sw_access_i_PackAlnUnit
 * bp_sw_replace_j_PackAlnUnit
 * bp_sw_access_j_PackAlnUnit
 * bp_sw_replace_state_PackAlnUnit
 * bp_sw_access_state_PackAlnUnit
 * bp_sw_replace_score_PackAlnUnit
 * bp_sw_access_score_PackAlnUnit
 * bp_sw_free_PackAlnUnit [destructor]
 *
 */

/* API for object PackAln */
/* Function:  bp_sw_show_simple_PackAln(pal,ofp)
 *
 * Descrip:    shows packaln with a pretty verbose debugging 
 *             format
 *
 *
 * Arg:        pal          Undocumented argument [bp_sw_PackAln *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_simple_PackAln( bp_sw_PackAln * pal,FILE * ofp);

/* Function:  bp_sw_show_bits_and_cumlative_PackAln(pal,ofp)
 *
 * Descrip:    Shows packaln as: 
 *
 *             i,j,state,score,bits,cumlative-score,cumlative-bits
 *
 *             cumlative score and cumlative bits are useful sometimes
 *
 *
 * Arg:        pal          Undocumented argument [bp_sw_PackAln *]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_bits_and_cumlative_PackAln( bp_sw_PackAln * pal,FILE * ofp);

/* Function:  bp_sw_hard_link_PackAln(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_PackAln *]
 *
 * Returns Undocumented return value [bp_sw_PackAln *]
 *
 */
bp_sw_PackAln * bp_sw_hard_link_PackAln( bp_sw_PackAln * obj);

/* Function:  bp_sw_PackAln_alloc_std(void)
 *
 * Descrip:    Equivalent to PackAln_alloc_len(PackAlnLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_PackAln *]
 *
 */
bp_sw_PackAln * bp_sw_PackAln_alloc_std();

/* Function:  bp_sw_access_pau_PackAln(obj,i)
 *
 * Descrip:    Access members stored in the pau list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_PackAln *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_PackAlnUnit *]
 *
 */
bp_sw_PackAlnUnit * bp_sw_access_pau_PackAln( bp_sw_PackAln * obj,int i);

/* Function:  bp_sw_length_pau_PackAln(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_PackAln *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_pau_PackAln( bp_sw_PackAln * obj);

/* Function:  bp_sw_flush_PackAln(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_PackAln *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_PackAln( bp_sw_PackAln * obj);

/* Function:  bp_sw_add_PackAln(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_PackAln *]
 * Arg:        add          Object to add to the list [bp_sw_PackAlnUnit *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_PackAln( bp_sw_PackAln * obj,bp_sw_PackAlnUnit * add);

/* Function:  bp_sw_replace_score_PackAln(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAln *]
 * Arg:        score        New value of the variable [int]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_PackAln( bp_sw_PackAln * obj,int score);

/* Function:  bp_sw_access_score_PackAln(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAln *]
 *
 * Returns member variable score [int]
 *
 */
int bp_sw_access_score_PackAln( bp_sw_PackAln * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_PackAln(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_PackAln *]
 *
 * Returns Undocumented return value [bp_sw_PackAln *]
 *
 */
bp_sw_PackAln * bp_sw_free_PackAln( bp_sw_PackAln * obj);

/* API for object PackAlnUnit */
/* Function:  bp_sw_hard_link_PackAlnUnit(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_PackAlnUnit *]
 *
 * Returns Undocumented return value [bp_sw_PackAlnUnit *]
 *
 */
bp_sw_PackAlnUnit * bp_sw_hard_link_PackAlnUnit( bp_sw_PackAlnUnit * obj);

/* Function:  bp_sw_PackAlnUnit_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_PackAlnUnit *]
 *
 */
bp_sw_PackAlnUnit * bp_sw_PackAlnUnit_alloc();

/* Function:  bp_sw_replace_i_PackAlnUnit(obj,i)
 *
 * Descrip:    Replace member variable i
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 * Arg:        i            New value of the variable [int]
 *
 * Returns member variable i [boolean]
 *
 */
boolean bp_sw_replace_i_PackAlnUnit( bp_sw_PackAlnUnit * obj,int i);

/* Function:  bp_sw_access_i_PackAlnUnit(obj)
 *
 * Descrip:    Access member variable i
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 *
 * Returns member variable i [int]
 *
 */
int bp_sw_access_i_PackAlnUnit( bp_sw_PackAlnUnit * obj);

/* Function:  bp_sw_replace_j_PackAlnUnit(obj,j)
 *
 * Descrip:    Replace member variable j
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 * Arg:        j            New value of the variable [int]
 *
 * Returns member variable j [boolean]
 *
 */
boolean bp_sw_replace_j_PackAlnUnit( bp_sw_PackAlnUnit * obj,int j);

/* Function:  bp_sw_access_j_PackAlnUnit(obj)
 *
 * Descrip:    Access member variable j
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 *
 * Returns member variable j [int]
 *
 */
int bp_sw_access_j_PackAlnUnit( bp_sw_PackAlnUnit * obj);

/* Function:  bp_sw_replace_state_PackAlnUnit(obj,state)
 *
 * Descrip:    Replace member variable state
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 * Arg:        state        New value of the variable [int]
 *
 * Returns member variable state [boolean]
 *
 */
boolean bp_sw_replace_state_PackAlnUnit( bp_sw_PackAlnUnit * obj,int state);

/* Function:  bp_sw_access_state_PackAlnUnit(obj)
 *
 * Descrip:    Access member variable state
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 *
 * Returns member variable state [int]
 *
 */
int bp_sw_access_state_PackAlnUnit( bp_sw_PackAlnUnit * obj);

/* Function:  bp_sw_replace_score_PackAlnUnit(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 * Arg:        score        New value of the variable [int]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_PackAlnUnit( bp_sw_PackAlnUnit * obj,int score);

/* Function:  bp_sw_access_score_PackAlnUnit(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_PackAlnUnit *]
 *
 * Returns member variable score [int]
 *
 */
int bp_sw_access_score_PackAlnUnit( bp_sw_PackAlnUnit * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_PackAlnUnit(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_PackAlnUnit *]
 *
 * Returns Undocumented return value [bp_sw_PackAlnUnit *]
 *
 */
bp_sw_PackAlnUnit * bp_sw_free_PackAlnUnit( bp_sw_PackAlnUnit * obj);



/* Helper functions in the module
 *
 * bp_sw_Probability_from_average_state_occupancy
 * bp_sw_state_occupancy_from_Probability
 * bp_sw_Probability2Score
 * bp_sw_Score2Probability
 * bp_sw_Score2Bits
 * bp_sw_halfbit2Probability
 *



/* These functions are not associated with an object */
/* Function:  bp_sw_Probability_from_average_state_occupancy(length)
 *
 * Descrip:    for single state (exponetial decays) takes an average length
 *             and converts that to a probability that will produce that
 *             length (on average) for the state. NB... this *assumes* that
 *             you want a single state exp decay.
 *
 *
 * Arg:        length       average length of state [double]
 *
 * Returns Undocumented return value [Probability]
 *
 */
Probability bp_sw_Probability_from_average_state_occupancy( double length);

/* Function:  bp_sw_state_occupancy_from_Probability(p)
 *
 * Descrip:    If you have a single state then this will tak
 *             the probability for the state->state transition and
 *             give you back the average length in the state
 *
 *
 * Arg:        p            probability of staying in the state [double]
 *
 * Returns Undocumented return value [double]
 *
 */
double bp_sw_state_occupancy_from_Probability( double p);

/* Function:  bp_sw_Probability2Score(p)
 *
 * Descrip:    maps probabilities to scores. Deals
 *             sensibly with 0's.
 *
 *
 * Arg:        p            Undocumented argument [Probability]
 *
 * Returns Undocumented return value [Score]
 *
 */
Score bp_sw_Probability2Score( Probability p);

/* Function:  bp_sw_Score2Probability(s)
 *
 * Descrip:    maps scores to probabilities
 *
 *
 * Arg:        s            Undocumented argument [Score]
 *
 * Returns Undocumented return value [Probability]
 *
 */
Probability bp_sw_Score2Probability( Score s);

/* Function:  bp_sw_Score2Bits(s)
 *
 * Descrip:    maps scores to bits
 *
 *
 * Arg:        s            Undocumented argument [Score]
 *
 * Returns Undocumented return value [Bits]
 *
 */
Bits bp_sw_Score2Bits( Score s);

/* Function:  bp_sw_halfbit2Probability(half_bit)
 *
 * Descrip:    maps halfbits (log2(prob*2) to
 *             probabilities
 *
 *
 * Arg:        half_bit     Undocumented argument [double]
 *
 * Returns Undocumented return value [Probability]
 *
 */
Probability bp_sw_halfbit2Probability( double half_bit);



/* Functions that create, manipulate or act on Protein
 *
 * bp_sw_Protein_from_Sequence
 * bp_sw_hard_link_Protein
 * bp_sw_Protein_alloc
 * bp_sw_replace_baseseq_Protein
 * bp_sw_access_baseseq_Protein
 * bp_sw_free_Protein [destructor]
 *
 */

/* API for object Protein */
/* Function:  bp_sw_Protein_from_Sequence(seq)
 *
 * Descrip:    makes a new protein from a Sequence. It 
 *             owns the Sequence memory, ie will attempt a /free_Sequence
 *             on the structure when /free_Protein is called
 *
 *             If you want to give this protein this Sequence and
 *             forget about it, then just hand it this sequence and set
 *             seq to NULL (no need to free it). If you intend to use 
 *             the sequecne object elsewhere outside of the Protein datastructure
 *             then use Protein_from_Sequence(/hard_link_Sequence(seq))
 *
 *
 *
 * Arg:        seq          Sequence to make protein from [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_Protein_from_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_hard_link_Protein(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Protein *]
 *
 * Returns Undocumented return value [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_hard_link_Protein( bp_sw_Protein * obj);

/* Function:  bp_sw_Protein_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_Protein_alloc();

/* Function:  bp_sw_replace_baseseq_Protein(obj,baseseq)
 *
 * Descrip:    Replace member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Protein *]
 * Arg:        baseseq      New value of the variable [bp_sw_Sequence *]
 *
 * Returns member variable baseseq [boolean]
 *
 */
boolean bp_sw_replace_baseseq_Protein( bp_sw_Protein * obj,bp_sw_Sequence * baseseq);

/* Function:  bp_sw_access_baseseq_Protein(obj)
 *
 * Descrip:    Access member variable baseseq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Protein *]
 *
 * Returns member variable baseseq [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_access_baseseq_Protein( bp_sw_Protein * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Protein(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Protein *]
 *
 * Returns Undocumented return value [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_free_Protein( bp_sw_Protein * obj);



/* Functions that create, manipulate or act on ProteinDB
 *
 * bp_sw_hard_link_ProteinDB
 * bp_sw_ProteinDB_alloc
 * bp_sw_replace_is_single_seq_ProteinDB
 * bp_sw_access_is_single_seq_ProteinDB
 * bp_sw_replace_single_ProteinDB
 * bp_sw_access_single_ProteinDB
 * bp_sw_replace_sdb_ProteinDB
 * bp_sw_access_sdb_ProteinDB
 * bp_sw_replace_cses_ProteinDB
 * bp_sw_access_cses_ProteinDB
 * bp_sw_free_ProteinDB [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_new_ProteinDB_from_single_seq
 * bp_sw_single_fasta_ProteinDB
 * bp_sw_new_ProteinDB
 *

/* API for object ProteinDB */
/* Function:  bp_sw_hard_link_ProteinDB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_ProteinDB *]
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_hard_link_ProteinDB( bp_sw_ProteinDB * obj);

/* Function:  bp_sw_ProteinDB_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_ProteinDB_alloc();

/* Function:  bp_sw_replace_is_single_seq_ProteinDB(obj,is_single_seq)
 *
 * Descrip:    Replace member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 * Arg:        is_single_seq New value of the variable [boolean]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_replace_is_single_seq_ProteinDB( bp_sw_ProteinDB * obj,boolean is_single_seq);

/* Function:  bp_sw_access_is_single_seq_ProteinDB(obj)
 *
 * Descrip:    Access member variable is_single_seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 *
 * Returns member variable is_single_seq [boolean]
 *
 */
boolean bp_sw_access_is_single_seq_ProteinDB( bp_sw_ProteinDB * obj);

/* Function:  bp_sw_replace_single_ProteinDB(obj,single)
 *
 * Descrip:    Replace member variable single
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 * Arg:        single       New value of the variable [bp_sw_ComplexSequence *]
 *
 * Returns member variable single [boolean]
 *
 */
boolean bp_sw_replace_single_ProteinDB( bp_sw_ProteinDB * obj,bp_sw_ComplexSequence * single);

/* Function:  bp_sw_access_single_ProteinDB(obj)
 *
 * Descrip:    Access member variable single
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 *
 * Returns member variable single [bp_sw_ComplexSequence *]
 *
 */
bp_sw_ComplexSequence * bp_sw_access_single_ProteinDB( bp_sw_ProteinDB * obj);

/* Function:  bp_sw_replace_sdb_ProteinDB(obj,sdb)
 *
 * Descrip:    Replace member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 * Arg:        sdb          New value of the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable sdb [boolean]
 *
 */
boolean bp_sw_replace_sdb_ProteinDB( bp_sw_ProteinDB * obj,bp_sw_SequenceDB * sdb);

/* Function:  bp_sw_access_sdb_ProteinDB(obj)
 *
 * Descrip:    Access member variable sdb
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 *
 * Returns member variable sdb [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_access_sdb_ProteinDB( bp_sw_ProteinDB * obj);

/* Function:  bp_sw_replace_cses_ProteinDB(obj,cses)
 *
 * Descrip:    Replace member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 * Arg:        cses         New value of the variable [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns member variable cses [boolean]
 *
 */
boolean bp_sw_replace_cses_ProteinDB( bp_sw_ProteinDB * obj,bp_sw_ComplexSequenceEvalSet * cses);

/* Function:  bp_sw_access_cses_ProteinDB(obj)
 *
 * Descrip:    Access member variable cses
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_ProteinDB *]
 *
 * Returns member variable cses [bp_sw_ComplexSequenceEvalSet *]
 *
 */
bp_sw_ComplexSequenceEvalSet * bp_sw_access_cses_ProteinDB( bp_sw_ProteinDB * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_ProteinDB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_ProteinDB *]
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_free_ProteinDB( bp_sw_ProteinDB * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_new_ProteinDB_from_single_seq(seq)
 *
 * Descrip:    To make a new protein database
 *             from a single Sequence with default amino acid mapping
 *
 *
 * Arg:        seq          sequence which as placed into ProteinDB structure. [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_new_ProteinDB_from_single_seq( bp_sw_Sequence * seq);

/* Function:  bp_sw_single_fasta_ProteinDB(filename)
 *
 * Descrip:    pre-packed single fasta protein database
 *
 *
 *
 * Arg:        filename     name of fasta file [char *]
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_single_fasta_ProteinDB( char * filename);

/* Function:  bp_sw_new_ProteinDB(seqdb,cses)
 *
 * Descrip:    To make a new protein database
 *
 *
 * Arg:        seqdb        sequence database [bp_sw_SequenceDB *]
 * Arg:        cses         protein evaluation set [bp_sw_ComplexSequenceEvalSet *]
 *
 * Returns Undocumented return value [bp_sw_ProteinDB *]
 *
 */
bp_sw_ProteinDB * bp_sw_new_ProteinDB( bp_sw_SequenceDB * seqdb,bp_sw_ComplexSequenceEvalSet * cses);



/* Helper functions in the module
 *
 * bp_sw_write_pretty_str_align
 * bp_sw_write_pretty_seq_align
 * bp_sw_write_pretty_Protein_align
 *



/* These functions are not associated with an object */
/* Function:  bp_sw_write_pretty_str_align(alb,qname,query,tname,target,name,main,ofp)
 *
 * Descrip:    This gives an interface into the alignment
 *             display using strings and files.
 *
 *
 * Arg:        alb          alignment structure [bp_sw_AlnBlock *]
 * Arg:        qname        name of first sequence [char *]
 * Arg:        query        first sequence [char *]
 * Arg:        tname        name of second sequence [char *]
 * Arg:        target       second sequence [char *]
 * Arg:        name         length of the name block [int]
 * Arg:        main         length of the main block [int]
 * Arg:        ofp          output file [FILE *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_write_pretty_str_align( bp_sw_AlnBlock * alb,char * qname,char * query,char * tname,char * target,int name,int main,FILE * ofp);

/* Function:  bp_sw_write_pretty_seq_align(alb,q,t,name,main,ofp)
 *
 * Descrip:    This gives an interface into the alignment
 *             display using sequences and files. A more
 *             generic function is write_pretty_str_align
 *
 *
 * Arg:        alb          alignment structure [bp_sw_AlnBlock *]
 * Arg:        q            first sequence [bp_sw_Sequence *]
 * Arg:        t            second sequence  [bp_sw_Sequence *]
 * Arg:        name         length of the name block [int]
 * Arg:        main         length of the main block [int]
 * Arg:        ofp          output file [FILE *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_write_pretty_seq_align( bp_sw_AlnBlock * alb,bp_sw_Sequence * q,bp_sw_Sequence * t,int name,int main,FILE * ofp);

/* Function:  bp_sw_write_pretty_Protein_align(alb,q,t,name,main,ofp)
 *
 * Descrip:    This gives an interface into the
 *             alignment display using Protein
 *             objects
 *
 *
 * Arg:        alb          alignment structure [bp_sw_AlnBlock *]
 * Arg:        q            first sequence [bp_sw_Protein *]
 * Arg:        t            second sequence  [bp_sw_Protein *]
 * Arg:        name         length of the name block [int]
 * Arg:        main         length of the main block [int]
 * Arg:        ofp          output file [FILE *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_write_pretty_Protein_align( bp_sw_AlnBlock * alb,bp_sw_Protein * q,bp_sw_Protein * t,int name,int main,FILE * ofp);



/* Functions that create, manipulate or act on Sequence
 *
 * bp_sw_uppercase_Sequence
 * bp_sw_force_to_dna_Sequence
 * bp_sw_is_reversed_Sequence
 * bp_sw_translate_Sequence
 * bp_sw_reverse_complement_Sequence
 * bp_sw_magic_trunc_Sequence
 * bp_sw_trunc_Sequence
 * bp_sw_read_fasta_file_Sequence
 * bp_sw_read_Sequence_EMBL_seq
 * bp_sw_read_fasta_Sequence
 * bp_sw_show_Sequence_residue_list
 * bp_sw_write_fasta_Sequence
 * bp_sw_make_len_type_Sequence
 * bp_sw_hard_link_Sequence
 * bp_sw_Sequence_alloc
 * bp_sw_replace_name_Sequence
 * bp_sw_access_name_Sequence
 * bp_sw_replace_seq_Sequence
 * bp_sw_access_seq_Sequence
 * bp_sw_replace_len_Sequence
 * bp_sw_access_len_Sequence
 * bp_sw_replace_maxlen_Sequence
 * bp_sw_access_maxlen_Sequence
 * bp_sw_replace_offset_Sequence
 * bp_sw_access_offset_Sequence
 * bp_sw_replace_end_Sequence
 * bp_sw_access_end_Sequence
 * bp_sw_replace_type_Sequence
 * bp_sw_access_type_Sequence
 * bp_sw_free_Sequence [destructor]
 *
 */



/* Helper functions in the module
 *
 * bp_sw_Sequence_type_to_string
 * bp_sw_new_Sequence_from_strings
 *

/* API for object Sequence */
/* Function:  bp_sw_uppercase_Sequence(seq)
 *
 * Descrip:    makes all the sequence uppercase
 *
 *
 * Arg:        seq          Sequence to be uppercas'd [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_uppercase_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_force_to_dna_Sequence(seq,fraction,number_of_conver)
 *
 * Descrip:    This 
 *              a) sees how many non ATGCN characters there are in Seq
 *              b) If the level is below fraction
 *                 a) flips non ATGC chars to N
 *                 b) writes number of conversions to number_of_conver
 *                 c) returns TRUE
 *              c) else returns FALSE
 *
 *             fraction of 0.0 means completely intolerant of errors
 *             fraction of 1.0 means completely tolerant of errors
 *
 *
 *
 * Arg:        seq          sequence object read and converted  [bp_sw_Sequence *]
 * Arg:        fraction     number 0..1 for tolerance of conversion [double]
 * Arg:        number_of_conver number of conversions actually made [int *]
 *
 * Returns TRUE for conversion to DNA, FALSE if not [boolean]
 *
 */
boolean bp_sw_force_to_dna_Sequence( bp_sw_Sequence * seq,double fraction,int * number_of_conver);

/* Function:  bp_sw_is_reversed_Sequence(seq)
 *
 * Descrip:    Currently the sequence object stores 
 *             reversed sequences as start > end.
 *
 *             This tests that and returns true if it is
 *
 *
 * Arg:        seq          sequence to test [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_is_reversed_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_translate_Sequence(dna,ct)
 *
 * Descrip:    This translates a DNA sequence to a protein.
 *             It assummes that it starts at first residue
 *             (use trunc_Sequence to chop a sequence up).
 *
 *
 * Arg:        dna          DNA sequence to be translated [bp_sw_Sequence *]
 * Arg:        ct           Codon table to do codon->aa mapping [bp_sw_CodonTable *]
 *
 * Returns new protein sequence [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_translate_Sequence( bp_sw_Sequence * dna,bp_sw_CodonTable * ct);

/* Function:  bp_sw_reverse_complement_Sequence(seq)
 *
 * Descrip:    This both complements and reverses a sequence,
 *             - a common wish!
 *
 *             The start/end are correct with respect to the start/end
 *             of the sequence (ie start = end, end = start).
 *
 *
 * Arg:        seq          Sequence to that is used to reverse (makes a new Sequence) [bp_sw_Sequence *]
 *
 * Returns new Sequence which is reversed [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_reverse_complement_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_magic_trunc_Sequence(seq,start,end)
 *
 * Descrip:    Clever function for dna sequences.
 *
 *             When start < end, truncates normally
 *
 *             when start > end, truncates end,start and then
 *             reverse complements.
 *
 *             ie. If you have a coordinate system where reverse 
 *             sequences are labelled in reverse start/end way,
 *             then this routine produces the correct sequence.
 *
 *
 * Arg:        seq          sequence that is the source to be truncated [bp_sw_Sequence *]
 * Arg:        start        start point [int]
 * Arg:        end          end point [int]
 *
 * Returns new Sequence which is truncated/reversed [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_magic_trunc_Sequence( bp_sw_Sequence * seq,int start,int end);

/* Function:  bp_sw_trunc_Sequence(seq,start,end)
 *
 * Descrip:    truncates a sequence. It produces a new memory structure
 *             which is filled from sequence start to end.
 *
 *             Please notice
 *               
 *               Truncation is in C coordinates. That is
 *             the first residue is 0 and end is the number of the
 *             residue after the cut-point. In otherwords to 
 *             2 - 3 would be a single residue truncation. So - if
 *             you want to work in more usual, 'inclusive' molecular
 *             biology numbers, which start at 1, then you need to say
 *
 *               trunc_Sequence(seq,start-1,end);
 *
 *             (NB, should be (end - 1 + 1) = end for the last coordinate).
 *
 *               Truncation occurs against the *absolute* coordinate
 *             system of the Sequence, not the offset/end pair inside.
 *             So, this is a very bad error
 *              
 *               ** wrong code, and also leaks memory **
 *
 *               tru = trunc_Sequence(trunc_Sequence(seq,50,80),55,75); 
 *
 *             This the most portable way of doing this
 *
 *               temp = trunc_Sequence(seq,50,80);
 *
 *               tru  = trunc_Sequence(temp,55-temp->offset,75-temp->offset);
 *
 *               free_Sequence(temp);
 *
 *
 *
 * Arg:        seq          object holding the sequence to be truncated [bp_sw_Sequence *]
 * Arg:        start        start point of truncation [int]
 * Arg:        end          end point of truncation [int]
 *
 * Returns newly allocated sequence structure [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_trunc_Sequence( bp_sw_Sequence * seq,int start,int end);

/* Function:  bp_sw_read_fasta_file_Sequence(filename)
 *
 * Descrip:    Just a call
 *               a) open filename
 *               b) read sequence with /read_fasta_Sequence
 *               c) close file.
 *
 *
 * Arg:        filename     filename to open  [char *]
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_read_fasta_file_Sequence( char * filename);

/* Function:  bp_sw_read_Sequence_EMBL_seq(buffer,maxlen,ifp)
 *
 * Descrip:    reads the sequence part of an EMBL file.
 *
 *             This function can either take a file which 
 *             starts
 *
 *
 *
 * Arg:        buffer       buffer containing the first line. [char *]
 * Arg:        maxlen       length of buffer [int]
 * Arg:        ifp          input file to read from [FILE *]
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_read_Sequence_EMBL_seq( char * buffer,int maxlen,FILE * ifp);

/* Function:  bp_sw_read_fasta_Sequence(ifp)
 *
 * Descrip:    reads the fasta file: format is
 *
 *             >name
 *             sequence
 *
 *             allocates a structure and puts in the
 *             sequence. Calls /make_len_type_Sequence to
 *             check type and length.
 *
 *             It leaves the '>' on the next fasta sequence
 *             for multiple sequence reading
 *
 *
 * Arg:        ifp          input file to read from [FILE *]
 *
 * Returns new Sequence structure  [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_read_fasta_Sequence( FILE * ifp);

/* Function:  bp_sw_show_Sequence_residue_list(seq,start,end,ofp)
 *
 * Descrip:    shows a region of a sequence as
 *                124  A
 *                125  T
 *
 *             etc from start to end. The numbers
 *             are in C coordinates (ie, 0 is the first
 *             letter).
 *
 *             useful for debugging
 *
 *
 * Arg:        seq          Sequence to show [bp_sw_Sequence *]
 * Arg:        start        start of list [int]
 * Arg:        end          end of list [int]
 * Arg:        ofp          Undocumented argument [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_show_Sequence_residue_list( bp_sw_Sequence * seq,int start,int end,FILE * ofp);

/* Function:  bp_sw_write_fasta_Sequence(seq,ofp)
 *
 * Descrip:    writes a fasta file of the form
 *             >name
 *             Sequence
 *
 *
 * Arg:        seq          sequence to be written [bp_sw_Sequence *]
 * Arg:        ofp          file to write to [FILE *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_write_fasta_Sequence( bp_sw_Sequence * seq,FILE * ofp);

/* Function:  bp_sw_make_len_type_Sequence(seq)
 *
 * Descrip:    makes seq->len and seq->end match the seq->seq
 *             length number. 
 *
 *             It also checks the type of the sequence with
 *             /best_guess_type
 *
 *
 * Arg:        seq          Sequence object [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [void]
 *
 */
void bp_sw_make_len_type_Sequence( bp_sw_Sequence * seq);

/* Function:  bp_sw_hard_link_Sequence(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_hard_link_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_Sequence_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_Sequence_alloc();

/* Function:  bp_sw_replace_name_Sequence(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_Sequence( bp_sw_Sequence * obj,char * name);

/* Function:  bp_sw_access_name_Sequence(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_seq_Sequence(obj,seq)
 *
 * Descrip:    Replace member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        seq          New value of the variable [char *]
 *
 * Returns member variable seq [boolean]
 *
 */
boolean bp_sw_replace_seq_Sequence( bp_sw_Sequence * obj,char * seq);

/* Function:  bp_sw_access_seq_Sequence(obj)
 *
 * Descrip:    Access member variable seq
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable seq [char *]
 *
 */
char * bp_sw_access_seq_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_len_Sequence(obj,len)
 *
 * Descrip:    Replace member variable len
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        len          New value of the variable [int]
 *
 * Returns member variable len [boolean]
 *
 */
boolean bp_sw_replace_len_Sequence( bp_sw_Sequence * obj,int len);

/* Function:  bp_sw_access_len_Sequence(obj)
 *
 * Descrip:    Access member variable len
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable len [int]
 *
 */
int bp_sw_access_len_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_maxlen_Sequence(obj,maxlen)
 *
 * Descrip:    Replace member variable maxlen
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        maxlen       New value of the variable [int]
 *
 * Returns member variable maxlen [boolean]
 *
 */
boolean bp_sw_replace_maxlen_Sequence( bp_sw_Sequence * obj,int maxlen);

/* Function:  bp_sw_access_maxlen_Sequence(obj)
 *
 * Descrip:    Access member variable maxlen
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable maxlen [int]
 *
 */
int bp_sw_access_maxlen_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_offset_Sequence(obj,offset)
 *
 * Descrip:    Replace member variable offset
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        offset       New value of the variable [int]
 *
 * Returns member variable offset [boolean]
 *
 */
boolean bp_sw_replace_offset_Sequence( bp_sw_Sequence * obj,int offset);

/* Function:  bp_sw_access_offset_Sequence(obj)
 *
 * Descrip:    Access member variable offset
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable offset [int]
 *
 */
int bp_sw_access_offset_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_end_Sequence(obj,end)
 *
 * Descrip:    Replace member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        end          New value of the variable [int]
 *
 * Returns member variable end [boolean]
 *
 */
boolean bp_sw_replace_end_Sequence( bp_sw_Sequence * obj,int end);

/* Function:  bp_sw_access_end_Sequence(obj)
 *
 * Descrip:    Access member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable end [int]
 *
 */
int bp_sw_access_end_Sequence( bp_sw_Sequence * obj);

/* Function:  bp_sw_replace_type_Sequence(obj,type)
 *
 * Descrip:    Replace member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 * Arg:        type         New value of the variable [int]
 *
 * Returns member variable type [boolean]
 *
 */
boolean bp_sw_replace_type_Sequence( bp_sw_Sequence * obj,int type);

/* Function:  bp_sw_access_type_Sequence(obj)
 *
 * Descrip:    Access member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Sequence *]
 *
 * Returns member variable type [int]
 *
 */
int bp_sw_access_type_Sequence( bp_sw_Sequence * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Sequence(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Sequence *]
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_free_Sequence( bp_sw_Sequence * obj);



/* These functions are not associated with an object */
/* Function:  bp_sw_Sequence_type_to_string(type)
 *
 * Descrip:    Converts sequence type (SEQUENCE_*) to a string
 *
 *
 * Arg:        type         type eg SEQUENCE_PROTEIN [int]
 *
 * Returns Undocumented return value [char *]
 *
 */
char * bp_sw_Sequence_type_to_string( int type);

/* Function:  bp_sw_new_Sequence_from_strings(name,seq)
 *
 * Descrip:    Makes a new sequence from strings given. 
 *             Separate memory will be allocated for them
 *             and them copied into it.
 *
 *             They can be NULL, in which case 
 *             o  a dummy name SequenceName will be assigned
 *             o  No sequence placed and length of zero.
 *
 *             Though this is dangerous later on. 
 *
 *             The sequence type is calculated automatically using
 *             /best_guess_type. If you want a DNA sequence but are
 *             unsure of the content of, for example, IUPAC codes,
 *             please use /force_to_dna_Sequence before using the
 *             sequence. Most of the rest of dynamite relies on a
 *             five letter A,T,G,C,N alphabet, but this function
 *             will allow any sequence type to be stored, so please
 *             check if you want to save yourself alot of grief.
 *
 *             In perl and other interfaces, this is a much safer
 *             constructor than the raw "new" type
 *
 *
 * Arg:        name         name of sequence, memory is allocated for it. [char *]
 * Arg:        seq          char * of sequence, memory is allocated for it. [char *]
 *
 * Returns Undocumented return value [bp_sw_Sequence *]
 *
 */
bp_sw_Sequence * bp_sw_new_Sequence_from_strings( char * name,char * seq);



/* Functions that create, manipulate or act on SequenceDB
 *
 * bp_sw_single_fasta_SequenceDB
 * bp_sw_hard_link_SequenceDB
 * bp_sw_SequenceDB_alloc_std
 * bp_sw_replace_name_SequenceDB
 * bp_sw_access_name_SequenceDB
 * bp_sw_access_fs_SequenceDB
 * bp_sw_length_fs_SequenceDB
 * bp_sw_flush_SequenceDB
 * bp_sw_add_SequenceDB
 * bp_sw_replace_current_source_SequenceDB
 * bp_sw_access_current_source_SequenceDB
 * bp_sw_replace_current_file_SequenceDB
 * bp_sw_access_current_file_SequenceDB
 * bp_sw_replace_sequence_no_SequenceDB
 * bp_sw_access_sequence_no_SequenceDB
 * bp_sw_replace_byte_position_SequenceDB
 * bp_sw_access_byte_position_SequenceDB
 * bp_sw_free_SequenceDB [destructor]
 *
 */



/* Functions that create, manipulate or act on FileSource
 *
 * bp_sw_hard_link_FileSource
 * bp_sw_FileSource_alloc
 * bp_sw_replace_filename_FileSource
 * bp_sw_access_filename_FileSource
 * bp_sw_replace_input_FileSource
 * bp_sw_access_input_FileSource
 * bp_sw_replace_format_FileSource
 * bp_sw_access_format_FileSource
 * bp_sw_replace_type_FileSource
 * bp_sw_access_type_FileSource
 * bp_sw_free_FileSource [destructor]
 *
 */

/* API for object SequenceDB */
/* Function:  bp_sw_single_fasta_SequenceDB(filename)
 *
 * Descrip:    pre-packed single fasta file db
 *
 *
 *
 * Arg:        filename     name of fastadb [char *]
 *
 * Returns Undocumented return value [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_single_fasta_SequenceDB( char * filename);

/* Function:  bp_sw_hard_link_SequenceDB(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_SequenceDB *]
 *
 * Returns Undocumented return value [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_hard_link_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_SequenceDB_alloc_std(void)
 *
 * Descrip:    Equivalent to SequenceDB_alloc_len(SequenceDBLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_SequenceDB_alloc_std();

/* Function:  bp_sw_replace_name_SequenceDB(obj,name)
 *
 * Descrip:    Replace member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 * Arg:        name         New value of the variable [char *]
 *
 * Returns member variable name [boolean]
 *
 */
boolean bp_sw_replace_name_SequenceDB( bp_sw_SequenceDB * obj,char * name);

/* Function:  bp_sw_access_name_SequenceDB(obj)
 *
 * Descrip:    Access member variable name
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable name [char *]
 *
 */
char * bp_sw_access_name_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_access_fs_SequenceDB(obj,i)
 *
 * Descrip:    Access members stored in the fs list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_SequenceDB *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_FileSource *]
 *
 */
bp_sw_FileSource * bp_sw_access_fs_SequenceDB( bp_sw_SequenceDB * obj,int i);

/* Function:  bp_sw_length_fs_SequenceDB(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_SequenceDB *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_fs_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_flush_SequenceDB(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_SequenceDB *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_add_SequenceDB(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_SequenceDB *]
 * Arg:        add          Object to add to the list [bp_sw_FileSource *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_SequenceDB( bp_sw_SequenceDB * obj,bp_sw_FileSource * add);

/* Function:  bp_sw_replace_current_source_SequenceDB(obj,current_source)
 *
 * Descrip:    Replace member variable current_source
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 * Arg:        current_source New value of the variable [int]
 *
 * Returns member variable current_source [boolean]
 *
 */
boolean bp_sw_replace_current_source_SequenceDB( bp_sw_SequenceDB * obj,int current_source);

/* Function:  bp_sw_access_current_source_SequenceDB(obj)
 *
 * Descrip:    Access member variable current_source
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable current_source [int]
 *
 */
int bp_sw_access_current_source_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_replace_current_file_SequenceDB(obj,current_file)
 *
 * Descrip:    Replace member variable current_file
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 * Arg:        current_file New value of the variable [FILE *]
 *
 * Returns member variable current_file [boolean]
 *
 */
boolean bp_sw_replace_current_file_SequenceDB( bp_sw_SequenceDB * obj,FILE * current_file);

/* Function:  bp_sw_access_current_file_SequenceDB(obj)
 *
 * Descrip:    Access member variable current_file
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable current_file [FILE *]
 *
 */
FILE * bp_sw_access_current_file_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_replace_sequence_no_SequenceDB(obj,sequence_no)
 *
 * Descrip:    Replace member variable sequence_no
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 * Arg:        sequence_no  New value of the variable [int]
 *
 * Returns member variable sequence_no [boolean]
 *
 */
boolean bp_sw_replace_sequence_no_SequenceDB( bp_sw_SequenceDB * obj,int sequence_no);

/* Function:  bp_sw_access_sequence_no_SequenceDB(obj)
 *
 * Descrip:    Access member variable sequence_no
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable sequence_no [int]
 *
 */
int bp_sw_access_sequence_no_SequenceDB( bp_sw_SequenceDB * obj);

/* Function:  bp_sw_replace_byte_position_SequenceDB(obj,byte_position)
 *
 * Descrip:    Replace member variable byte_position
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 * Arg:        byte_position New value of the variable [int]
 *
 * Returns member variable byte_position [boolean]
 *
 */
boolean bp_sw_replace_byte_position_SequenceDB( bp_sw_SequenceDB * obj,int byte_position);

/* Function:  bp_sw_access_byte_position_SequenceDB(obj)
 *
 * Descrip:    Access member variable byte_position
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_SequenceDB *]
 *
 * Returns member variable byte_position [int]
 *
 */
int bp_sw_access_byte_position_SequenceDB( bp_sw_SequenceDB * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_SequenceDB(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_SequenceDB *]
 *
 * Returns Undocumented return value [bp_sw_SequenceDB *]
 *
 */
bp_sw_SequenceDB * bp_sw_free_SequenceDB( bp_sw_SequenceDB * obj);

/* API for object FileSource */
/* Function:  bp_sw_hard_link_FileSource(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_FileSource *]
 *
 * Returns Undocumented return value [bp_sw_FileSource *]
 *
 */
bp_sw_FileSource * bp_sw_hard_link_FileSource( bp_sw_FileSource * obj);

/* Function:  bp_sw_FileSource_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_FileSource *]
 *
 */
bp_sw_FileSource * bp_sw_FileSource_alloc();

/* Function:  bp_sw_replace_filename_FileSource(obj,filename)
 *
 * Descrip:    Replace member variable filename
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 * Arg:        filename     New value of the variable [char *]
 *
 * Returns member variable filename [boolean]
 *
 */
boolean bp_sw_replace_filename_FileSource( bp_sw_FileSource * obj,char * filename);

/* Function:  bp_sw_access_filename_FileSource(obj)
 *
 * Descrip:    Access member variable filename
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 *
 * Returns member variable filename [char *]
 *
 */
char * bp_sw_access_filename_FileSource( bp_sw_FileSource * obj);

/* Function:  bp_sw_replace_input_FileSource(obj,input)
 *
 * Descrip:    Replace member variable input
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 * Arg:        input        New value of the variable [FILE *]
 *
 * Returns member variable input [boolean]
 *
 */
boolean bp_sw_replace_input_FileSource( bp_sw_FileSource * obj,FILE * input);

/* Function:  bp_sw_access_input_FileSource(obj)
 *
 * Descrip:    Access member variable input
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 *
 * Returns member variable input [FILE *]
 *
 */
FILE * bp_sw_access_input_FileSource( bp_sw_FileSource * obj);

/* Function:  bp_sw_replace_format_FileSource(obj,format)
 *
 * Descrip:    Replace member variable format
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 * Arg:        format       New value of the variable [int]
 *
 * Returns member variable format [boolean]
 *
 */
boolean bp_sw_replace_format_FileSource( bp_sw_FileSource * obj,int format);

/* Function:  bp_sw_access_format_FileSource(obj)
 *
 * Descrip:    Access member variable format
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 *
 * Returns member variable format [int]
 *
 */
int bp_sw_access_format_FileSource( bp_sw_FileSource * obj);

/* Function:  bp_sw_replace_type_FileSource(obj,type)
 *
 * Descrip:    Replace member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 * Arg:        type         New value of the variable [int]
 *
 * Returns member variable type [boolean]
 *
 */
boolean bp_sw_replace_type_FileSource( bp_sw_FileSource * obj,int type);

/* Function:  bp_sw_access_type_FileSource(obj)
 *
 * Descrip:    Access member variable type
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_FileSource *]
 *
 * Returns member variable type [int]
 *
 */
int bp_sw_access_type_FileSource( bp_sw_FileSource * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_FileSource(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_FileSource *]
 *
 * Returns Undocumented return value [bp_sw_FileSource *]
 *
 */
bp_sw_FileSource * bp_sw_free_FileSource( bp_sw_FileSource * obj);



/* Helper functions in the module
 *
 * bp_sw_Align_strings_ProteinSmithWaterman
 * bp_sw_Align_Sequences_ProteinSmithWaterman
 * bp_sw_Align_Proteins_SmithWaterman
 *



/* These functions are not associated with an object */
/* Function:  bp_sw_Align_strings_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most *stupidly* abstracted view of two sequences
 *             getting aligned, being two strings.
 *
 *             It would be much better if you used Sequence objects or Protein
 *             objects to carry the proteins.
 *
 *
 * Arg:        one          string of the first sequence [char *]
 * Arg:        two          string of the second sequence [char *]
 * Arg:        comp         Comparison Matrix [bp_sw_CompMat *]
 * Arg:        gap          gap penalty [int]
 * Arg:        ext          extension penalty [int]
 *
 * Returns Undocumented return value [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_Align_strings_ProteinSmithWaterman( char * one,char * two,bp_sw_CompMat * comp,int gap,int ext);

/* Function:  bp_sw_Align_Sequences_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This function is a mid-level abstraction of
 *             comparing two sequences, which could be
 *             generic types (eg DNA!). This is tested
 *             for and warnings are given but the alignment
 *             is still calculated. To prevent this test
 *             warning either make sure the Sequence types
 *             are set to PROTEIN or, better still, use the
 *             high level abstraction Align_Proteins_SmithWaterman
 *
 *             Otherwise this performs a standard smith waterman
 *             protein alignment...
 *
 *             To display the alignment use  write_pretty_seq_align
 *
 *
 * Arg:        one          First sequence to compare [bp_sw_Sequence *]
 * Arg:        two          Second sequecne to compare [bp_sw_Sequence *]
 * Arg:        comp         Comparison matrix to use [bp_sw_CompMat *]
 * Arg:        gap          gap penalty. Must be negative or 0 [int]
 * Arg:        ext          ext penalty. Must be negative or 0 [int]
 *
 * Returns new AlnBlock structure representing the alignment [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_Align_Sequences_ProteinSmithWaterman( bp_sw_Sequence * one,bp_sw_Sequence * two,bp_sw_CompMat * comp,int gap,int ext);

/* Function:  bp_sw_Align_Proteins_SmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most correct way of aligning two Proteins,
 *             using Protein objects, which can be assummed to be
 *             proteins with no objections
 *
 *             To display the alignment use write_pretty_Protein_align
 *
 *
 *
 * Arg:        one          Protein to align [bp_sw_Protein *]
 * Arg:        two          Protein to align [bp_sw_Protein *]
 * Arg:        comp         Comparison Matrix [bp_sw_CompMat *]
 * Arg:        gap          gap penalty [int]
 * Arg:        ext          extension penalty [int]
 *
 * Returns Undocumented return value [bp_sw_AlnBlock *]
 *
 */
bp_sw_AlnBlock * bp_sw_Align_Proteins_SmithWaterman( bp_sw_Protein * one,bp_sw_Protein * two,bp_sw_CompMat * comp,int gap,int ext);



/* Functions that create, manipulate or act on Exon
 *
 * bp_sw_hard_link_Exon
 * bp_sw_Exon_alloc
 * bp_sw_replace_start_Exon
 * bp_sw_access_start_Exon
 * bp_sw_replace_end_Exon
 * bp_sw_access_end_Exon
 * bp_sw_replace_used_Exon
 * bp_sw_access_used_Exon
 * bp_sw_replace_score_Exon
 * bp_sw_access_score_Exon
 * bp_sw_free_Exon [destructor]
 *
 */



/* Functions that create, manipulate or act on Transcript
 *
 * bp_sw_get_cDNA_from_Transcript
 * bp_sw_hard_link_Transcript
 * bp_sw_Transcript_alloc_std
 * bp_sw_access_exon_Transcript
 * bp_sw_length_exon_Transcript
 * bp_sw_flush_ex_Transcript
 * bp_sw_add_ex_Transcript
 * bp_sw_replace_parent_Transcript
 * bp_sw_access_parent_Transcript
 * bp_sw_access_translation_Transcript
 * bp_sw_length_translation_Transcript
 * bp_sw_flush_Transcript
 * bp_sw_add_Transcript
 * bp_sw_replace_cDNA_Transcript
 * bp_sw_access_cDNA_Transcript
 * bp_sw_free_Transcript [destructor]
 *
 */

/* API for object Exon */
/* Function:  bp_sw_hard_link_Exon(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Exon *]
 *
 * Returns Undocumented return value [bp_sw_Exon *]
 *
 */
bp_sw_Exon * bp_sw_hard_link_Exon( bp_sw_Exon * obj);

/* Function:  bp_sw_Exon_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Exon *]
 *
 */
bp_sw_Exon * bp_sw_Exon_alloc();

/* Function:  bp_sw_replace_start_Exon(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 * Arg:        start        New value of the variable [int]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_Exon( bp_sw_Exon * obj,int start);

/* Function:  bp_sw_access_start_Exon(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 *
 * Returns member variable start [int]
 *
 */
int bp_sw_access_start_Exon( bp_sw_Exon * obj);

/* Function:  bp_sw_replace_end_Exon(obj,end)
 *
 * Descrip:    Replace member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 * Arg:        end          New value of the variable [int]
 *
 * Returns member variable end [boolean]
 *
 */
boolean bp_sw_replace_end_Exon( bp_sw_Exon * obj,int end);

/* Function:  bp_sw_access_end_Exon(obj)
 *
 * Descrip:    Access member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 *
 * Returns member variable end [int]
 *
 */
int bp_sw_access_end_Exon( bp_sw_Exon * obj);

/* Function:  bp_sw_replace_used_Exon(obj,used)
 *
 * Descrip:    Replace member variable used
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 * Arg:        used         New value of the variable [boolean]
 *
 * Returns member variable used [boolean]
 *
 */
boolean bp_sw_replace_used_Exon( bp_sw_Exon * obj,boolean used);

/* Function:  bp_sw_access_used_Exon(obj)
 *
 * Descrip:    Access member variable used
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 *
 * Returns member variable used [boolean]
 *
 */
boolean bp_sw_access_used_Exon( bp_sw_Exon * obj);

/* Function:  bp_sw_replace_score_Exon(obj,score)
 *
 * Descrip:    Replace member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 * Arg:        score        New value of the variable [double]
 *
 * Returns member variable score [boolean]
 *
 */
boolean bp_sw_replace_score_Exon( bp_sw_Exon * obj,double score);

/* Function:  bp_sw_access_score_Exon(obj)
 *
 * Descrip:    Access member variable score
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Exon *]
 *
 * Returns member variable score [double]
 *
 */
double bp_sw_access_score_Exon( bp_sw_Exon * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Exon(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Exon *]
 *
 * Returns Undocumented return value [bp_sw_Exon *]
 *
 */
bp_sw_Exon * bp_sw_free_Exon( bp_sw_Exon * obj);

/* API for object Transcript */
/* Function:  bp_sw_get_cDNA_from_Transcript(trs)
 *
 * Descrip:    gets the cDNA associated with this transcript,
 *             if necessary, building it from the exon information
 *             provided.
 *
 *             returns a soft-linked object. If you want to ensure
 *             that this cDNA object remains in memory use
 *             /hard_link_cDNA on the object.
 *
 *
 * Arg:        trs          transcript to get cDNA from [bp_sw_Transcript *]
 *
 * Returns cDNA of the transcript [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_get_cDNA_from_Transcript( bp_sw_Transcript * trs);

/* Function:  bp_sw_hard_link_Transcript(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Transcript *]
 *
 * Returns Undocumented return value [bp_sw_Transcript *]
 *
 */
bp_sw_Transcript * bp_sw_hard_link_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_Transcript_alloc_std(void)
 *
 * Descrip:    Equivalent to Transcript_alloc_len(TranscriptLISTLENGTH)
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Transcript *]
 *
 */
bp_sw_Transcript * bp_sw_Transcript_alloc_std();

/* Function:  bp_sw_access_exon_Transcript(obj,i)
 *
 * Descrip:    Access members stored in the exon list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Transcript *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_Exon *]
 *
 */
bp_sw_Exon * bp_sw_access_exon_Transcript( bp_sw_Transcript * obj,int i);

/* Function:  bp_sw_length_exon_Transcript(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Transcript *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_exon_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_flush_ex_Transcript(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_Transcript *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_ex_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_add_ex_Transcript(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_Transcript *]
 * Arg:        add          Object to add to the list [bp_sw_Exon *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_ex_Transcript( bp_sw_Transcript * obj,bp_sw_Exon * add);

/* Function:  bp_sw_replace_parent_Transcript(obj,parent)
 *
 * Descrip:    Replace member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Transcript *]
 * Arg:        parent       New value of the variable [bp_sw_Gene *]
 *
 * Returns member variable parent [boolean]
 *
 */
boolean bp_sw_replace_parent_Transcript( bp_sw_Transcript * obj,bp_sw_Gene * parent);

/* Function:  bp_sw_access_parent_Transcript(obj)
 *
 * Descrip:    Access member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Transcript *]
 *
 * Returns member variable parent [bp_sw_Gene *]
 *
 */
bp_sw_Gene * bp_sw_access_parent_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_access_translation_Transcript(obj,i)
 *
 * Descrip:    Access members stored in the translation list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Transcript *]
 * Arg:        i            Position in the list [int]
 *
 * Returns Element of the list [bp_sw_Translation *]
 *
 */
bp_sw_Translation * bp_sw_access_translation_Transcript( bp_sw_Transcript * obj,int i);

/* Function:  bp_sw_length_translation_Transcript(obj)
 *
 * Descrip:    discover the length of the list
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the list [bp_sw_Transcript *]
 *
 * Returns length of the list [int]
 *
 */
int bp_sw_length_translation_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_flush_Transcript(obj)
 *
 * Descrip:    Frees the list elements, sets length to 0
 *             If you want to save some elements, use hard_link_xxx
 *             to protect them from being actually destroyed in the free
 *
 *
 * Arg:        obj          Object which contains the list  [bp_sw_Transcript *]
 *
 * Returns Undocumented return value [int]
 *
 */
int bp_sw_flush_Transcript( bp_sw_Transcript * obj);

/* Function:  bp_sw_add_Transcript(obj,add)
 *
 * Descrip:    Adds another object to the list. It will expand the list if necessary
 *
 *
 * Arg:        obj          Object which contains the list [bp_sw_Transcript *]
 * Arg:        add          Object to add to the list [bp_sw_Translation *]
 *
 * Returns Undocumented return value [boolean]
 *
 */
boolean bp_sw_add_Transcript( bp_sw_Transcript * obj,bp_sw_Translation * add);

/* Function:  bp_sw_replace_cDNA_Transcript(obj,cDNA)
 *
 * Descrip:    Replace member variable cDNA
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Transcript *]
 * Arg:        cDNA         New value of the variable [bp_sw_cDNA *]
 *
 * Returns member variable cDNA [boolean]
 *
 */
boolean bp_sw_replace_cDNA_Transcript( bp_sw_Transcript * obj,bp_sw_cDNA * cDNA);

/* Function:  bp_sw_access_cDNA_Transcript(obj)
 *
 * Descrip:    Access member variable cDNA
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Transcript *]
 *
 * Returns member variable cDNA [bp_sw_cDNA *]
 *
 */
bp_sw_cDNA * bp_sw_access_cDNA_Transcript( bp_sw_Transcript * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Transcript(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Transcript *]
 *
 * Returns Undocumented return value [bp_sw_Transcript *]
 *
 */
bp_sw_Transcript * bp_sw_free_Transcript( bp_sw_Transcript * obj);



/* Functions that create, manipulate or act on Translation
 *
 * bp_sw_get_Protein_from_Translation
 * bp_sw_hard_link_Translation
 * bp_sw_Translation_alloc
 * bp_sw_replace_start_Translation
 * bp_sw_access_start_Translation
 * bp_sw_replace_end_Translation
 * bp_sw_access_end_Translation
 * bp_sw_replace_parent_Translation
 * bp_sw_access_parent_Translation
 * bp_sw_replace_protein_Translation
 * bp_sw_access_protein_Translation
 * bp_sw_free_Translation [destructor]
 *
 */

/* API for object Translation */
/* Function:  bp_sw_get_Protein_from_Translation(ts,ct)
 *
 * Descrip:    Gets the protein
 *
 *
 * Arg:        ts           translation [bp_sw_Translation *]
 * Arg:        ct           codon table to use [bp_sw_CodonTable *]
 *
 * Returns Protein sequence [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_get_Protein_from_Translation( bp_sw_Translation * ts,bp_sw_CodonTable * ct);

/* Function:  bp_sw_hard_link_Translation(obj)
 *
 * Descrip:    Bumps up the reference count of the object
 *             Meaning that multiple pointers can 'own' it
 *
 *
 * Arg:        obj          Object to be hard linked [bp_sw_Translation *]
 *
 * Returns Undocumented return value [bp_sw_Translation *]
 *
 */
bp_sw_Translation * bp_sw_hard_link_Translation( bp_sw_Translation * obj);

/* Function:  bp_sw_Translation_alloc(void)
 *
 * Descrip:    Allocates structure: assigns defaults if given 
 *
 *
 *
 * Returns Undocumented return value [bp_sw_Translation *]
 *
 */
bp_sw_Translation * bp_sw_Translation_alloc();

/* Function:  bp_sw_replace_start_Translation(obj,start)
 *
 * Descrip:    Replace member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 * Arg:        start        New value of the variable [int]
 *
 * Returns member variable start [boolean]
 *
 */
boolean bp_sw_replace_start_Translation( bp_sw_Translation * obj,int start);

/* Function:  bp_sw_access_start_Translation(obj)
 *
 * Descrip:    Access member variable start
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 *
 * Returns member variable start [int]
 *
 */
int bp_sw_access_start_Translation( bp_sw_Translation * obj);

/* Function:  bp_sw_replace_end_Translation(obj,end)
 *
 * Descrip:    Replace member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 * Arg:        end          New value of the variable [int]
 *
 * Returns member variable end [boolean]
 *
 */
boolean bp_sw_replace_end_Translation( bp_sw_Translation * obj,int end);

/* Function:  bp_sw_access_end_Translation(obj)
 *
 * Descrip:    Access member variable end
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 *
 * Returns member variable end [int]
 *
 */
int bp_sw_access_end_Translation( bp_sw_Translation * obj);

/* Function:  bp_sw_replace_parent_Translation(obj,parent)
 *
 * Descrip:    Replace member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 * Arg:        parent       New value of the variable [bp_sw_Transcript *]
 *
 * Returns member variable parent [boolean]
 *
 */
boolean bp_sw_replace_parent_Translation( bp_sw_Translation * obj,bp_sw_Transcript * parent);

/* Function:  bp_sw_access_parent_Translation(obj)
 *
 * Descrip:    Access member variable parent
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 *
 * Returns member variable parent [bp_sw_Transcript *]
 *
 */
bp_sw_Transcript * bp_sw_access_parent_Translation( bp_sw_Translation * obj);

/* Function:  bp_sw_replace_protein_Translation(obj,protein)
 *
 * Descrip:    Replace member variable protein
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 * Arg:        protein      New value of the variable [bp_sw_Protein *]
 *
 * Returns member variable protein [boolean]
 *
 */
boolean bp_sw_replace_protein_Translation( bp_sw_Translation * obj,bp_sw_Protein * protein);

/* Function:  bp_sw_access_protein_Translation(obj)
 *
 * Descrip:    Access member variable protein
 *             For use principly by API functions
 *
 *
 * Arg:        obj          Object holding the variable [bp_sw_Translation *]
 *
 * Returns member variable protein [bp_sw_Protein *]
 *
 */
bp_sw_Protein * bp_sw_access_protein_Translation( bp_sw_Translation * obj);

/* This is the destructor function, ie, call this to free object*/
/* Function:  bp_sw_free_Translation(obj)
 *
 * Descrip:    Free Function: removes the memory held by obj
 *             Will chain up to owned members and clear all lists
 *
 *
 * Arg:        obj          Object that is free'd [bp_sw_Translation *]
 *
 * Returns Undocumented return value [bp_sw_Translation *]
 *
 */
bp_sw_Translation * bp_sw_free_Translation( bp_sw_Translation * obj);

