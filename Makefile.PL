use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'NAME'      => 'Bio',
    'VERSION'	=> '0.08.0',
    'DIR'       => [ qw( Bio/Ext/Align Bio/SeqIO/staden )],
    'dist'      => {  COMPRESS     => 'gzip -9f',
                      SUFFIX       => '.gz', 
                      DIST_DEFAULT => 'all tardist',
                   },
    ($] ge '5.005')  ? (
     'AUTHOR'   => 'Bioperl Team (bioperl-l@bioperl.org)',
     'ABSTRACT' => 'Bioinformatics Toolkit',
    ) : (),
);
