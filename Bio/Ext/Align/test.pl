# test framework rewritten by Jason Stajich

## Test framework for pSW XS stuff
## $Id$

## We start with some black magic to print on failure.
my $DEBUG = $ENV{'BIOPERLDEBUG'} || 0;
BEGIN {
    eval { require Test; };
    use Test;
    plan tests => 9;
}

use Bio::Ext::Align;
use Bio::Tools::dpAlign;
use Bio::Seq;
use Bio::AlignIO;

$loaded = 1;
ok(1); # modules loaded

&Bio::Ext::Align::change_max_BaseMatrix_kbytes(20000);
$cm   = &Bio::Ext::Align::CompMat::read_Blast_file_CompMat("blosum62.bla");
ok($cm);
$seq1 = &Bio::Ext::Align::new_Sequence_from_strings("one","WLGQRNLVSSTGGNLLNVWLKDW");
ok($seq1);
$seq2 = &Bio::Ext::Align::new_Sequence_from_strings("two","WMGNRNVVNLLNVWFRDW");
ok($seq2);

$alb = &Bio::Ext::Align::Align_Sequences_ProteinSmithWaterman($seq1,$seq2,
							      $cm,-12,-2);
&Bio::Ext::Align::write_pretty_str_align($alb,$seq1->name,
					 $seq1->seq,$seq2->name,
					 $seq2->seq,15,50,STDERR) if $DEBUG;


warn( "Testing Local Alignment case...\n") if $DEBUg;

$alnout = new Bio::AlignIO(-format => 'pfam', -fh => \*STDERR);
$aln = &Bio::Ext::Align::Align_DNA_Sequences("AATGCCATTGACGG",
					     "CAGCCTCGCTTAG",3,-1,3,1,
		      Bio::Tools::dpAlign::DPALIGN_LOCAL_MILLER_MYERS);

$out = Bio::SimpleAlign->new();

$out->add_seq(Bio::LocatableSeq->new(-seq   => $aln->aln1,
				     -start => $aln->start1,
				     -end   => $aln->end1,
				     -id    => "one"));

$out->add_seq(Bio::LocatableSeq->new(-seq   => $aln->aln2,
				     -start => $aln->start2,
				     -end   => $aln->end2,
				     -id    => "two"));
$alnout->write_aln($out) if $DEBUG;

$aln = &Bio::Ext::Align::Align_Protein_Sequences("WLGQRNLVSSTGGNLLNVWLKDW","WMGNRNVVNLLNVWFRDW",0,
						 Bio::Tools::dpAlign::DPALIGN_LOCAL_MILLER_MYERS);
$out = Bio::SimpleAlign->new();
ok($aln);

$out->add_seq(Bio::LocatableSeq->new(-seq   => $aln->aln1,
				     -start => $aln->start1,
				     -end   => $aln->end1,
				     -id    => "one"));

$out->add_seq(Bio::LocatableSeq->new(-seq   => $aln->aln2,
				     -start => $aln->start2,
				     -end   => $aln->end2,
				     -id    => "two"));
$alnout->write_aln($out) if $DEBUG;
ok(1);

warn( "Testing Global Alignment case...\n") if $DEBUG;

$factory = new Bio::Tools::dpAlign('-alg' => Bio::Tools::dpAlign::DPALIGN_GLOBAL_MILLER_MYERS);
$s1 = new Bio::Seq(-id => "one", -seq => "AATGCCATTGACGG", -alphabet => 'dna');
$s2 = new Bio::Seq(-id => "two", -seq => "CAGCCTCGCTTAG", -alphabet => 'dna');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;

ok(1);

$s1 = new Bio::Seq(-id => "one", -seq => "WLGQRNLVSSTGGNLLNVWLKDW", 
		   -alphabet => 'protein');
$s2 = new Bio::Seq(-id => "two", -seq => "WMGNRNVVNLLNVWFRDW", 
		   -alphabet => 'protein');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;
ok(1);

$prof = $factory->sequence_profile($s1);
warn( "Optimal Alignment Score = %d\n", $factory->pairwise_alignment_score($prof, $s2)) if $DEBUG;

ok($factory->pairwise_alignment_score($prof,$s2),77);
