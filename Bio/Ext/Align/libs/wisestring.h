#ifndef DYNAMITEwisestringHEADERFILE
#define DYNAMITEwisestringHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"



/**********************************************/
/* useful macros to put into fprintf lines... */
/* Makes sure you don't trash memory etc      */
/**********************************************/
#define CHECKSTRING(str) (str == NULL ? "NullString" : str)
#define CKS CHECKSTRING

/**********************************************/
/* useful standard strings for parsing        */
/* spacestr is general whitespace             */
/* breakstr is general non alpha/num          */
/* used alot in breakstring                   */
/**********************************************/
#define spacestr " \t\n\0"
#define breakstr "!\"#$%^&*()-+={}[]@';:?/.,\\|~` \n\t"

/**********************************************/
/* Not the nicest of macros. Stay away from it*/
/**********************************************/ 
#define NEXTWORD strtok(NULL,spacestr)



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  get_number_from_slashed_string(qstr,slashstr)
 *
 * Descrip:    handy: pass a string like "xxx/yyy/zzz"    
 *             and a query like yyy, will return 2        
 *             (ie, maps positions in slashed string with 
 *             a number from start). Returns -1 if none   
 *
 *
 * Arg:            qstr [UNKN ] Undocumented argument [char *]
 * Arg:        slashstr [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_get_number_from_slashed_string(char * qstr,char * slashstr);
#define get_number_from_slashed_string bp_sw_get_number_from_slashed_string


/* Function:  is_integer_string(string,val)
 *
 * Descrip:    checks that strings are ints or doubles    
 *             and then converts, storing value in val    
 *             if val == NULL, will not store (!)        
 *                                                         
 *             Does use sensible library functions        
 *             strtol...                          
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 * Arg:           val [UNKN ] Undocumented argument [int *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_is_integer_string(char * string,int * val);
#define is_integer_string bp_sw_is_integer_string


/* Function:  is_double_string(string,val)
 *
 * Descrip:     checks that strings are doubles    
 *              and then converts, storing value in val    
 *               if val == NULL, will not store (!)        
 *                                                         
 *              Does use sensible library functions        
 *              strtod
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 * Arg:           val [UNKN ] Undocumented argument [double *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_is_double_string(char * string,double * val);
#define is_double_string bp_sw_is_double_string


/* Function:  compress_space_around_punc(buffer,punc,space)
 *
 * Descrip: No Description
 *
 * Arg:        buffer [UNKN ] Undocumented argument [char *]
 * Arg:          punc [UNKN ] Undocumented argument [char *]
 * Arg:         space [UNKN ] Undocumented argument [char *]
 *
 */
void bp_sw_compress_space_around_punc(char * buffer,char * punc,char * space);
#define compress_space_around_punc bp_sw_compress_space_around_punc


/* Function:  striptoprint(line)
 *
 * Descrip:    useful strip functions to remove nasty chars
 *             does not allocate memory, simply uses       
 *             given memory, but returns the line pointer
 *             so you can use it in nested function calls                                
 *
 *
 * Arg:        line [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_striptoprint(char * line);
#define striptoprint bp_sw_striptoprint


/* Function:  stringalloc_next_quoted_string(buffer)
 *
 * Descrip:    takes str's of type <garbage> "xxxxx"   
 *             and gives back xxxxxx .             
 *             stringalloc'd piece so make sure you free it
 *
 *
 * Arg:        buffer [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_stringalloc_next_quoted_string(char * buffer);
#define stringalloc_next_quoted_string bp_sw_stringalloc_next_quoted_string


/* Function:  strwhitestartcmp(line,str,whitespace)
 *
 * Descrip:    sees if line starts with str, ignoring whitespace
 *
 *             returns 0 if they match, to look like strcmp
 *
 *
 * Arg:              line [UNKN ] Undocumented argument [char *]
 * Arg:               str [UNKN ] Undocumented argument [char *]
 * Arg:        whitespace [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_strwhitestartcmp(char * line,char * str,char * whitespace);
#define strwhitestartcmp bp_sw_strwhitestartcmp


/* Function:  strwordcmp(buf,str,space)
 *
 * Descrip:    sees if buf matches str\s in perl regex, ie
 *             a word match
 *
 *             space defined \s
 *
 *             returns 0 if they match to look like strcmp
 *
 *
 * Arg:          buf [UNKN ] Undocumented argument [char *]
 * Arg:          str [UNKN ] Undocumented argument [char *]
 * Arg:        space [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_strwordcmp(char * buf,char * str,char * space);
#define strwordcmp bp_sw_strwordcmp


/* Function:  strstartcmp(buf,str)
 *
 * Descrip:    sees if buf starts with str.
 *
 *             returns 0 if so, to mimic strcmp
 *
 *
 * Arg:        buf [UNKN ] Undocumented argument [char *]
 * Arg:        str [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_strstartcmp(char * buf,char * str);
#define strstartcmp bp_sw_strstartcmp


/* Function:  print_numbered_line(num,ofp)
 *
 * Descrip:    prints lines like _1_________
 *
 *
 * Arg:        num [UNKN ] Undocumented argument [int]
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_print_numbered_line(int num,FILE * ofp);
#define print_numbered_line bp_sw_print_numbered_line


/* Function:  print_line(ofp)
 *
 * Descrip:    prints _______________ (70 chars)
 *
 *
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 */
void bp_sw_print_line(FILE * ofp);
#define print_line bp_sw_print_line


/* Function:  chop_newline(str)
 *
 * Descrip:    removes trailing newline if present
 *
 *
 * Arg:        str [UNKN ] Undocumented argument [char *]
 *
 */
void bp_sw_chop_newline(char * str);
#define chop_newline bp_sw_chop_newline


/* Function:  good_datastring_fromend(str)
 *
 * Descrip:    Tries to find the last 'database name' 
 *             type string from a string.
 *
 *             Does not allocate memory
 *
 *
 * Arg:        str [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_good_datastring_fromend(char * str);
#define good_datastring_fromend bp_sw_good_datastring_fromend


/* Function:  estrcasecmp(one,two)
 *
 * Descrip:    returns strcmp on the captilalised
 *             one and two bufferers (doesn't touch them).
 *
 *
 * Arg:        one [UNKN ] Undocumented argument [char *]
 * Arg:        two [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_estrcasecmp(char *  one,char *  two);
#define estrcasecmp bp_sw_estrcasecmp


/* Function:  number_from_quoted_equality(s)
 *
 * Descrip:    supposedly gets a number from a
 *             string like xxx="12"
 *
 *
 * Arg:        s [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_number_from_quoted_equality(char * s);
#define number_from_quoted_equality bp_sw_number_from_quoted_equality


/* Function:  number_from_equality(string)
 *
 * Descrip:    supposedly gets a number from
 *             xxxx=12
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_number_from_equality(char * string);
#define number_from_equality bp_sw_number_from_equality


/* Function:  string_from_quoted_equality(string)
 *
 * Descrip:    gets the string from xxx="yyy". Returns
 *             yyy allocated, and messes around with string
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_string_from_quoted_equality(char * string);
#define string_from_quoted_equality bp_sw_string_from_quoted_equality


/* Function:  string_from_charred_equality(string,quote)
 *
 * Descrip:    gets the string from xxx="yyy" ,where " comes
 *             from the quote argument Returns
 *             yyy allocated, and messes around with string
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 * Arg:         quote [UNKN ] Undocumented argument [char]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_string_from_charred_equality(char * string,char quote);
#define string_from_charred_equality bp_sw_string_from_charred_equality


/* Function:  breakstring(string,parsestr)
 *
 * Descrip:    A call to /breakstring_protect(string,parsestr,"\"")
 *
 *
 * Arg:          string [UNKN ] Undocumented argument [char *]
 * Arg:        parsestr [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char **]
 *
 */
char ** bp_sw_breakstring(char * string,char * parsestr);
#define breakstring bp_sw_breakstring


/* Function:  breakstring_protect(string,parsestr,strpair)
 *
 * Descrip:    will parse out words in string using parse  
 *             as white space, like strtok, but strings    
 *             enclosed in characters from strpair are not 
 *             taken in parsed form.                       
 *             breakstring =                               
 *             breakstring_protect(string,parse,"\"");     
 *             hence will not break in double quotes       
 *                                                          
 *             unlike strtok they return char **           
 *             which is a list of char * of words          
 *             the last being NULL'd                       
 *                                                          
 *                                                          
 *             They returned an alloc'd char ** which you  
 *             are expected to free. Standard idiom is     
 *             base=brk=breakstring(buffer,spacestr)       
 *               (NB - spacestr #defin'd above )           
 *               ... do stuff using brk                     
 *               eg *brk = first word                       
 *                  *(++brk) = next word                    
 *                last word = NULL                          
 *              cleanup by ckfree(base)                     
 *
 *
 * Arg:          string [UNKN ] Undocumented argument [char *]
 * Arg:        parsestr [UNKN ] Undocumented argument [char *]
 * Arg:         strpair [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char **]
 *
 */
char ** bp_sw_breakstring_protect(char * string,char * parsestr,char * strpair);
#define breakstring_protect bp_sw_breakstring_protect


/* Function:  strip_quote_chars(string,quote)
 *
 * Descrip:    removes chars in quote
 *
 *
 * Arg:        string [UNKN ] Undocumented argument [char *]
 * Arg:         quote [UNKN ] Undocumented argument [char *]
 *
 */
void bp_sw_strip_quote_chars(char * string,char * quote);
#define strip_quote_chars bp_sw_strip_quote_chars


/* Function:  padstring(buffer,string,maxlen)
 *
 * Descrip:    copies string into buffer, and if under maxlen,
 *             adds spaces. Does *not* put in '\0'
 *
 *
 * Arg:        buffer [UNKN ] Undocumented argument [char *]
 * Arg:        string [UNKN ] Undocumented argument [char *]
 * Arg:        maxlen [UNKN ] Undocumented argument [int]
 *
 */
void bp_sw_padstring(char * buffer,char * string,int maxlen);
#define padstring bp_sw_padstring


/* Function:  capitalise(word)
 *
 * Descrip:    toupper's each char in word
 *
 *
 * Arg:        word [UNKN ] Undocumented argument [char *]
 *
 */
void bp_sw_capitalise(char * word);
#define capitalise bp_sw_capitalise


/* Function:  show_line(line,max,*ofp)
 *
 * Descrip:    This shouws line putting a new line in every max
 *             chars, not minding word boundaries
 *
 *
 * Arg:        line [UNKN ] Undocumented argument [char *]
 * Arg:         max [UNKN ] Undocumented argument [int]
 * Arg:        *ofp [UNKN ] Undocumented argument [FILE]
 *
 */
void bp_sw_show_line(char * line,int max,FILE *ofp);
#define show_line bp_sw_show_line


/* Function:  show_text(line,max,*ofp)
 *
 * Descrip:    This shouws line putting a new line in every max
 *             chars, *minding* word boundaries
 *
 *
 * Arg:        line [UNKN ] Undocumented argument [char *]
 * Arg:         max [UNKN ] Undocumented argument [int]
 * Arg:        *ofp [UNKN ] Undocumented argument [FILE]
 *
 */
void bp_sw_show_text(char * line,int max,FILE *ofp);
#define show_text bp_sw_show_text


/* Function:  second_word_alloc(str,space)
 *
 * Descrip:    returns the second word alloc'd for
 *
 *             xxx yyyy
 *
 *             returns yyyy.
 *
 *
 * Arg:          str [UNKN ] Undocumented argument [char *]
 * Arg:        space [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_second_word_alloc(char * str,char * space);
#define second_word_alloc bp_sw_second_word_alloc


/* Function:  stringallocf(str,)
 *
 * Descrip:    Don't use this
 *
 *             sprintf's then allocs
 *
 *
 * Arg:        str [UNKN ] Undocumented argument [char *]
 * Arg:            [UNKN ] Undocumented argument [.]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_stringallocf(char * str,...);
#define stringallocf bp_sw_stringallocf


/* Function:  stringalloc(c)
 *
 * Descrip:    returns the allocated copy of c.
 *             Usually called strdup in other packages
 *
 *
 * Arg:        c [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
char * bp_sw_stringalloc(char * c);
#define stringalloc bp_sw_stringalloc


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
boolean bp_sw_only_whitespace(char * str,char * space);
#define only_whitespace bp_sw_only_whitespace
boolean bp_sw_looks_like_vms(const char * str);
#define looks_like_vms bp_sw_looks_like_vms
boolean bp_sw_looks_like_unix(const char * str);
#define looks_like_unix bp_sw_looks_like_unix
char * bp_sw_strend(char * bu,char * se);
#define strend bp_sw_strend
char * bp_sw_string_before_equality(char * string);
#define string_before_equality bp_sw_string_before_equality
char * bp_sw_sub_string(char * into,char * key,char * sub);
#define sub_string bp_sw_sub_string

#ifdef _cplusplus
}
#endif

#endif
