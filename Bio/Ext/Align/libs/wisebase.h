
#ifndef TOPBASEHEADER
#define TOPBASEHEADER


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>


#ifdef SUNS
#include <unistd.h>
#ifndef UNIX
#define UNIX /* if users put -DSUN but not -DUNIX */
#endif
#endif /* ifdef SUN */


/**** OK some system wide defines now - used all over the place ****/

#define MAXLINE 512 /* generalised maximum input line */
#define MAXBINARYDUMP 1024 /*** ok could be tricky here... ****/

#ifndef BOOLEANDEFINED

typedef int boolean;
#define TRUE 1
#define FALSE 0

#define BOOLEANDEFINED
#endif


/**** include the rest of the base files ****/

#include "wisestring.h"
#include "wisefile.h"
#include "wiseconfig.h"
#include "wisetime.h"
#include "wiserandom.h"
#include "wisememman.h"  /* memory manager - ckalloc/ckfree etc */
#include "wiseerror.h"
#include "wiseoverlay.h"
#include "commandline.h"


#endif /* TOP_BASE.H loaded */
