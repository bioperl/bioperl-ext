#ifndef DYNAMITEwisefileHEADERFILE
#define DYNAMITEwisefileHEADERFILE
#ifdef _cplusplus
extern "C" {
#endif
#include "wisebase.h"

#define MAXPATHLEN  1024

#ifdef FILE_DEBUG
#define fclose myfclose
#endif

#ifdef NOERROR
#define ERRORSTR "No error available"
#else
#define ERRORSTR strerror(errno)
#endif



    /***************************************************/
    /* Callable functions                              */
    /* These are the functions you are expected to use */
    /***************************************************/



/* Function:  set_config_dir(path,*path)
 *
 * Descrip:    Programmatically set systemconfigdir to override
 *             any value set (or not) by env.var. WISECONFIGDIR.
 *
 *             Added by arve.
 *
 *
 * Arg:         path [UNKN ] path that WISECONFIGDIR is set to [NullString]
 * Arg:        *path [UNKN ] Undocumented argument [char]
 *
 */
void bp_sw_set_config_dir(char *path) ;
#define set_config_dir bp_sw_set_config_dir


/* Function:  myfclose(ofp)
 *
 * Descrip:    reports the fclose type etc
 *
 *
 * Arg:        ofp [UNKN ] Undocumented argument [FILE *]
 *
 * Return [UNKN ]  Undocumented return value [int]
 *
 */
int bp_sw_myfclose(FILE * ofp);
#define myfclose bp_sw_myfclose


/* Function:  remove_file(filename)
 *
 * Descrip:    silly function to provide a boolean wrapper
 *             around remove. 
 *
 *
 * Arg:        filename [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_remove_file(char * filename);
#define remove_file bp_sw_remove_file


/* Function:  move_file(from,to)
 *
 * Descrip:    silly function to provide a boolean wrapper
 *             around rename 
 *
 *
 * Arg:        from [UNKN ] Undocumented argument [char *]
 * Arg:          to [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_move_file(char * from,char * to);
#define move_file bp_sw_move_file


/* Function:  touchfile(filename)
 *
 * Descrip:    sees if filename exists
 *
 *
 * Arg:        filename [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  Undocumented return value [boolean]
 *
 */
boolean bp_sw_touchfile(char * filename);
#define touchfile bp_sw_touchfile


/* Function:  openfile(filename,passedprot)
 *
 * Descrip:    Every file open goes through this.
 *
 *             It opens for reading in the following order 
 *                .
 *                WISEPERSONALDIR
 *                WISECONFIGDIR
 *
 *             For writing it opens in .
 *
 *             Filenames with ~'s are expanded to HOME/filename
 *
 *
 * Arg:          filename [UNKN ] filename to open for read/writing [const char *]
 * Arg:        passedprot [UNKN ] string representing standard fopen attributes [const char *]
 *
 * Return [UNKN ]  open'd filehandle, NULL on error [FILE *]
 *
 */
FILE * bp_sw_openfile(const char * filename,const char * passedprot);
#define openfile bp_sw_openfile


/* Function:  envopenfile(envname,filename,name,env)
 *
 * Descrip:    This function basically mirrors the function in file.c
 *             in HMMer2. You call it as
 *
 *               fp = Envfile(filename,envname);
 *
 *               where envname looks like "BLASTDB" etc.
 *
 *
 *
 * Arg:         envname [READ ] enviroment variable to read from [NullString]
 * Arg:        filename [UNKN ] Undocumented argument [char *]
 * Arg:            name [READ ] filename to open [NullString]
 * Arg:             env [UNKN ] Undocumented argument [char *]
 *
 * Return [UNKN ]  a valid file pointer or NULL [FILE *]
 *
 */
FILE * bp_sw_envopenfile(char * filename,char * env);
#define envopenfile bp_sw_envopenfile


  /* Unplaced functions */
  /* There has been no indication of the use of these functions */


    /***************************************************/
    /* Internal functions                              */
    /* you are not expected to have to call these      */
    /***************************************************/
void bp_sw_try_to_load(void);
#define try_to_load bp_sw_try_to_load
boolean bp_sw_append_file_to_path(char * buffer,int len,const char * file,char * path);
#define append_file_to_path bp_sw_append_file_to_path

#ifdef _cplusplus
}
#endif

#endif
