# test framework rewritten by Jason Stajich

## Test framework for pSW and related XS stuff
## $Id$

## We start with some black magic to print on failure.
my $DEBUG = $ENV{'BIOPERLDEBUG'} || 0;
BEGIN {
    eval { require Test::More; };
    if ($@) {
        die "Tests require Test::More";
    }
    use Test::More;
    plan tests => 19;
    use_ok('Bio::Ext::Align');
    use_ok('Bio::Tools::dpAlign');
    use_ok('Bio::Seq');
    use_ok('Bio::AlignIO');
}

&Bio::Ext::Align::change_max_BaseMatrix_kbytes(20000);
$cm   = &Bio::Ext::Align::CompMat::read_Blast_file_CompMat("blosum62.bla");
isa_ok($cm,'Bio::Ext::Align::CompMat');
$seq1 = &Bio::Ext::Align::new_Sequence_from_strings("one","WLGQRNLVSSTGGNLLNVWLKDW");
isa_ok($seq1,'Bio::Ext::Align::Sequence');
$seq2 = &Bio::Ext::Align::new_Sequence_from_strings("two","WMGNRNVVNLLNVWFRDW");
isa_ok($seq2,'Bio::Ext::Align::Sequence');

$alb = &Bio::Ext::Align::Align_Sequences_ProteinSmithWaterman($seq1,$seq2,
							      $cm,-12,-2);
&Bio::Ext::Align::write_pretty_str_align($alb,$seq1->name,
					 $seq1->seq,$seq2->name,
					 $seq2->seq,15,50,STDERR) if $DEBUG;

warn( "Testing Local Alignment case...\n") if $DEBUG;

$alnout = Bio::AlignIO->new(-format => 'pfam', -fh => \*STDERR);
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

$aln = &Bio::Ext::Align::Align_Protein_Sequences("WLGQRNLVSSTGGNLLNVWLKDW","WMGNRNVVNLLNVWFRDW",0,Bio::Tools::dpAlign::DPALIGN_LOCAL_MILLER_MYERS);

$out = Bio::SimpleAlign->new();
isa_ok($aln,'Bio::Ext::Align::AlignOutput');

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
$s1 = Bio::Seq->new(-id => "one", -seq => "AATGCCATTGACGG", -alphabet => 'dna');
$s2 = Bio::Seq->new(-id => "two", -seq => "CAGCCTCGCTTAG", -alphabet => 'dna');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;

ok(1);

$s1 = Bio::Seq->new(-id => "one", -seq => "WLGQRNLVSSTGGNLLNVWLKDW", 
		   -alphabet => 'protein');
$s2 = Bio::Seq->new(-id => "two", -seq => "WMGNRNVVNLLNVWFRDW", 
		   -alphabet => 'protein');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;
ok(1);

warn( "Testing Ends-Free Alignment case...\n") if $DEBUG;

$factory = Bio::Tools::dpAlign->new('-alg' => Bio::Tools::dpAlign::DPALIGN_ENDSFREE_MILLER_MYERS);
$s1 = Bio::Seq->new(-id => "one", -seq => "AATGCCATTGACGG", -alphabet => 'dna');
$s2 = Bio::Seq->new(-id => "two", -seq => "CAGCCTCGCTTAG", -alphabet => 'dna');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;
ok(1);

$s1 = Bio::Seq->new(-id => "one", -seq => "WLGQRNLVSSTGGNLLNVWLKDW", 
		   -alphabet => 'protein');
$s2 = Bio::Seq->new(-id => "two", -seq => "NVVNLLNVWFRDWAVQPL", 
		   -alphabet => 'protein');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln) if $DEBUG;
$factory->align_and_show($s1, $s2) if $DEBUG;
ok(1);

warn( "Testing Profile Local Alignment Score case...\n") if $DEBUG;

$s1 = Bio::Seq->new(-id => "one", -seq => "WLGQRNLVSSTGGNLLNVWLKDW", 
                   -alphabet => 'protein');
$s2 = Bio::Seq->new(-id => "two", -seq => "WMGNRNVVNLLNVWFRDW", 
                   -alphabet => 'protein');
$prof = $factory->sequence_profile($s1);
warn(sprintf "Optimal Alignment Score = %d\n", $factory->pairwise_alignment_score($prof, $s2)) if $DEBUG;

is($factory->pairwise_alignment_score($prof,$s2),77);

open(my $list, '<', 'scores.lst') || die "Can't open file:$!";

my $eng = &Bio::Ext::Align::new_Histogram(-100,100,50);

while (<$list>) {
    chomp;
    $eng->add($_);
}

close $list;

is($eng->fit_EVD(10000,1),1);

my $mu = $eng->mu();
my $lambda = $eng->lambda();

TODO:{
    local $TODO = "evalues vary based on platform, needs fixing";
    warn($eng->show(\*STDERR)) if $DEBUG;
    is($eng->evalue(1073),1764904);
    is($eng->evalue(100),1764872);
    is($eng->evalue(10),1764872);
    is($eng->evalue(-10),1764872);
}

#TODO:{
#    local $TODO = "evalues vary based on platform, needs fixing";
#    warn($eng->show(\*STDERR)) if $DEBUG;
#    is($eng->evalue(1073),1);
#    is($eng->evalue(1000),1);
#    is($eng->evalue(900),1);
#    is($eng->evalue(800),1);
#    is($eng->evalue(700),1);
#    is($eng->evalue(700),1);
#    is($eng->evalue(700),1);
#    is($eng->evalue(700),1);
#    is($eng->evalue(100),1);
#    is($eng->evalue(10),1);
#    is($eng->evalue(-10),1);
#}
