use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'	=> 'Bio::Ext::Align',
    'VERSION'	=> '0.1',
    'LIBS'	=> ['-lm'],   # e.g., '-lm' 
    'DEFINE'	=> '-DPOSIX -DNOERROR',     # e.g., '-DHAVE_SOMETHING' 
    'INC'	=> '-I./libs',     # e.g., '-I/usr/include/other'
    'MYEXTLIB'  => 'libs/libsw$(LIB_EXT)',
    'clean'     => { 'FILES' => 'libs/*.o libs/*.a' }
);

sub MY::postamble{
'
$(MYEXTLIB): 
	DEFINE=\'$(DEFINE)\'; CC=\'$(PERLMAINCC)\'; export DEFINE INC CC; \
	cd libs && $(MAKE) CC=$(CC) libsw$(LIB_EXT) -e

';
}
