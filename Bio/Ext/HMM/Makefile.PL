use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
   'NAME'      => 'Bio::Ext::HMM',
   'VERSION'   => '0.1', 
   'LIBS'      => ['-lm'],   # e.g., '-lm'
   'DEFINE'    => '',     # e.g., '-DHAVE_SOMETHING'
   'INC'       => '',     # e.g., '-I/usr/include/other'
   'OBJECT'    => 'HMM.o hmmlib.o',
   'clean'     => { 'FILES' => '*.o' }
);

