#ifdef _cplusplus
extern "C" {
#endif
#include "commandline.h"


/* Function:  strip_out_remaining_options_with_warning(argc,argv)
 *
 * Descrip:    This removes all remaining options, issuing warnings
 *             through warn
 *
 *
 * Arg:        argc [UNKN ] Undocumented argument [int *]
 * Arg:        argv [UNKN ] Undocumented argument [char **]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
# line 33 "commandline.dy"
boolean strip_out_remaining_options_with_warning(int * argc,char ** argv)
{
  register int i;
  boolean ret = FALSE;


  for(i=0;i<*argc;i++) {
    if( argv[i][0] != '-' )
      continue;

    /*** ignore bare '-' - could be arguments ***/

    if( argv[i][1] == '\0')
      continue;

    warn("You have an unrecognised argument, %s, removing",argv[i]);
    
    memmove(argv+i,argv+i+1,sizeof(char *)*(*argc - i -1));
    *argc -= 1;
    ret = TRUE;
    }

  return ret;
}

/* Function:  strip_out_boolean_argument(argc,argv,tag)
 *
 * Descrip:    This removes argument in tag from the commandline if there and
 *             returns TRUE
 *
 *             otherwise returns FALSE
 *
 *
 * Arg:        argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:        argv [UNKN ] argv from main declaration [char **]
 * Arg:         tag [READ ] -[string] argument to find [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
# line 68 "commandline.dy"
boolean strip_out_boolean_argument(int * argc,char ** argv,char * tag)
{
  register int i;

  for(i=0;i<*argc;i++) {
    if( argv[i][0] != '-' )
      continue;
    
    /** ignore '-' by themselves **/

    if( argv[i][1] == '\0')
      continue;

    /** try to strcmp with tag **/

    if( strcmp(tag,argv[i]+1) == 0 ) {
      memmove(argv+i,argv+i+1,sizeof(char *)*(*argc - i -1));

      *argc -= 1;
      
      /* return */

      return TRUE;
    }
  }

  return FALSE;
}

/* Function:  strip_out_assigned_argument(argc,argv,tag)
 *
 * Descrip:    This removes argument in tag from the commandline if there and
 *             returns the argument to it (in -tag arg - ie with a space).
 *
 *             otherwise returns NULL
 *
 *
 * Arg:        argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:        argv [UNKN ] argv from main declaration [char **]
 * Arg:         tag [READ ] -[string] argument to find [char *]
 *
 * Return [UNKN ]  Undocumented return value [char *]
 *
 */
# line 107 "commandline.dy"
char * strip_out_assigned_argument(int * argc,char ** argv,char * tag)
{
  register int i;
  register char * ret;


  for(i=0;i<*argc;i++) {
    if( argv[i][0] != '-' )
      continue;
    
    /** ignore '-' by themselves **/

    if( argv[i][1] == '\0')
      continue;

    /** try to strcmp with tag **/

    if( strcmp(tag,argv[i]+1) == 0 ) {
      /* pick up next argument: if it has a '-' treat that as the argument. */
      
      if( i+1 >= *argc ) {
	warn("In processing command line [%s], tag [%s] expects an argument",argv[0],tag);
	return NULL; /* give 'em nothing */
      }


      /* assign return value */

      ret = argv[i+1];

      /* ok, now remove both tag and argument from the line */

      memmove(argv+i,argv+i+2,sizeof(char *)*(*argc - i -2));

      *argc -= 2;
      
      /* return */

      return ret;
    }
  }

  return NULL;
}


/* Function:  strip_out_integer_argument(argc,argv,tag,value)
 *
 * Descrip:    This removes argument in tag from the commandline if there, and
 *             looks at the argument as whether it is an int or not.
 *
 *             No tag - returns FALSE and leaves value alone
 *             Tag but no integer value - issues warning, returns FALSE
 *             tag but integer value    - sets value, returns true
 *
 *
 * Arg:         argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:         argv [UNKN ] argv from main declaration [char **]
 * Arg:          tag [READ ] -[string] argument to find [char *]
 * Arg:        value [WRITE] int pointer to write value to [int *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
# line 166 "commandline.dy"
boolean strip_out_integer_argument(int * argc,char ** argv,char * tag,int * value)
{
  char * arg;

  if( (arg = strip_out_assigned_argument(argc,argv,tag)) == NULL )
    return FALSE;

  if( is_integer_string(arg,value) == FALSE ) {
    warn("Argument [%s] to [%s] is not an integer. Not changing the value [%d]",arg,tag,value);
    return FALSE;
  }

  return TRUE;
}

/* Function:  strip_out_float_argument(argc,argv,tag,value)
 *
 * Descrip:    This removes argument in tag from the commandline if there, and
 *             looks at the argument as whether it is a double or not.
 *
 *             No tag - returns FALSE and leaves value alone
 *             Tag but no integer value - issues warning, returns FALSE
 *             tag but integer value    - sets value, returns true
 *
 *
 * Arg:         argc [UNKN ] argc from main declaration (call as &argc) [int *]
 * Arg:         argv [UNKN ] argv from main declaration [char **]
 * Arg:          tag [READ ] -[string] argument to find [char *]
 * Arg:        value [WRITE] double pointer to write value to [double *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
# line 194 "commandline.dy"
boolean strip_out_float_argument(int * argc,char ** argv,char * tag,double * value)
{
  char * arg;

  if( (arg = strip_out_assigned_argument(argc,argv,tag)) == NULL )
    return FALSE;

  if( is_double_string(arg,value) == FALSE ) {
    warn("Argument [%s] to [%s] is not a double. Not changing the value [%f]",arg,tag,value);
    return FALSE;
  }

  return TRUE;
}
      
  

# line 211 "commandline.c"

#ifdef _cplusplus
}
#endif
