## Summary

This is the BioPerl Extensions (BioPerl-Ext) distribution, a collection of
Bioperl C-compiled extensions.

These currently include:

* `Bio::Ext::Align` (Ewan Birney <birney@sanger.ac.uk> and Yee Man Chan <ymc@paxil.stanford.edu>)
* `Bio::SeqIO::staden::read` (Aaron Mackey <amackey@virginia.edu>)

## Overall notes

This collection of modules is fairly old and no longer actively maintained.

## Installing

Depending on your choise of extensions, you might need
`Inline::MakeMaker` and `Inline::C `to create the makefile. Use for
example the cpan program to install `Inline::MakeMaker` and answer yes
when prompted to install `Inline::C`.

To install all of the extension packages, you can use the top-level
`Makefile.PL` (present in the same directory you're reading this README
from) (Make sure you read the various notes below about each package
before doing this!):

```
perl Makefile.PL
make
make test
make install (may need root permissions)
```

To install only the individual extensions you wish to have, change
directories into each and use the `Makefile.PL` found there; for
example:

```
cd Bio/Ext/Align
perl Makefile.PL
make
make test (should print out alignment on STDERR)
make install (probably need root permissions).
```

## Notes for Bio::Ext::Align

Although these extensions can be called by themselves, they really
need the main bioperl distribution to drive them. The modules which do
this are

* `Bio::Tools::pSW` - makes Smith-Waterman alignments for DNA
* `Bio::Tools::dpAlign` - makes Smith-Waterman alignments for proteins
* `Bio::SearchDist` - deals with EVD fitting of extreme value distributions

For more information on how to use these modules, read their own
documentation (`perldoc Bio::Tools::pSW`)

## Notes for Bio::SeqIO::staden::read

This extension needs the rest of the main bioperl distribution to
function properly.  It is only useful as a helper module for the `SeqIO`
system to read sequence trace files handled by the Staden package's
`io_lib` "read" library.  You should have this library installed prior
to installing `Bio::SeqIO::staden::read`, it's currently available at:

https://sourceforge.net/project/showfiles.php?group_id=100316

Currently, the `Bio::SeqIO::staden::read` extension only works with `io_lib`
v. 1.8.11 or 1.8.12; v. 1.9 and higher have several prototype changes in the
`read` library which have broken compatibility in those versions for now.
It is possible these changes may be addressed in the future.

Many users have noted that the `io_lib` install process often forgets
to install the `os.h` file along with the rest of the include files;
you may have to do this manually.  If so, you may also have to
install the `config.h` file for `os.h` to find all the information it
needs.  Finally, you may also need to edit `os.h` to
`#include <config.h>` instead of `#include "config.h"` if you continue to get
undefined symbol errors during compilation.  On some OSes you may in fact
have to do the OPPOSITE, meaning change `<config.h>` to `"config.h"`.

The bioperl-ext make process will prompt you for the LIB and INCLUDE
locations (usually `/usr/local/lib` and `/usr/local/include/io_lib`,
respectively) of the `io_lib` `libread` library and `Read.h` header files,
after trying to automatically find them.  You may also specify these
via the environment variables `IOLIB_LIB` and `IOLIB_INC`, or via
identically named options to `perl Makefile.PL`:

```
perl Makefile.PL IOLIB_LIB=/opt/lib IOLIB_INC=/opt/include/io_lib
```

Ignore any warnings about these options being unknown to MakeMaker.

A failed compilation is most likely due to an incomplete `io_lib`
installation; make sure that all the required `io_lib` `.h` files are in
place (see above regarding `os.h` and `config.h`).

Additional problems may occur that have been associated with the VERSION
number that Inline::C uses.  Normally, this pops up as an Inline error:

```
------------------------------------------------------------------------
The extension 'Bio::SeqIO::staden::read' is not properly installed in path:
 '/usr/lib/perl5/site_perl/5.8.0'

If this is a CPAN/distributed module, you may need to reinstall it on your
system.

To allow Inline to compile the module in a temporary cache, simply remove the
Inline config option 'VERSION=' from the Bio::SeqIO::staden::read module.
------------------------------------------------------------------------
```
 
To get around this, either quote out or remove the indicated line from your
local Bio/SeqIO/staden/read.pm file after installation:

```perl
use Inline (C => 'DATA',
           VERSION => '1.51', # <--- this line
           NAME => 'Bio::SeqIO::staden::read',
           LIBS => "-L/usr/local/lib -lread -lz", # leave these as double quotes - necessary for Makefile.PL function
           INC  => "-I/usr/local/include/io_lib", # leave these as double quotes - necessary for Makefile.PL function
          );
```

