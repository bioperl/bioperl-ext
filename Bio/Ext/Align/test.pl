#!/usr/local/bin/perl

## Test framework for pSW XS stuff
## $Id$

## We start with some black magic to print on failure.
BEGIN { $| = 1; print "1..2\n"; }
END {print "not ok 1\n" unless $loaded;}

use Bio::Ext::Align;
use Bio::Tools::dpAlign;
use Bio::Seq;
use Bio::AlignIO;

$loaded = 1;
print "ok 1\n";    # 1st test passes.

print "\n2..2\nTesting bp_sw with a protein alignment...\n\n";

&Bio::Ext::Align::change_max_BaseMatrix_kbytes(20000);
$cm   = &Bio::Ext::Align::CompMat::read_Blast_file_CompMat("blosum62.bla");
$seq1 = &Bio::Ext::Align::new_Sequence_from_strings("one","WLGQRNLVSSTGGNLLNVWLKDW");
$seq2 = &Bio::Ext::Align::new_Sequence_from_strings("two","WMGNRNVVNLLNVWFRDW");

$alb = &Bio::Ext::Align::Align_Sequences_ProteinSmithWaterman($seq1,$seq2,$cm,-12,-2);
&Bio::Ext::Align::write_pretty_str_align($alb,$seq1->name,$seq1->seq,$seq2->name,$seq2->seq,15,50,STDERR);

## End of black magic.
##
## Insert additional test code below but remember to change
## the print "1..x\n" in the BEGIN block to reflect the
## total number of tests that will be run. 

# Testing dpAlign code

printf "Testing Local Alignment case...\n";

$alnout = new Bio::AlignIO(-format => 'pfam', -fh => \*STDOUT);
$aln = &Bio::Ext::Align::Align_DNA_Sequences("AATGCCATTGACGG","CAGCCTCGCTTAG",3,-1,3,1,Bio::Tools::dpAlign::DPALIGN_LOCAL_MILLER_MYERS);
$out = Bio::SimpleAlign->new();

$out->add_seq(Bio::LocatableSeq->new(-seq => $aln->aln1,
                                         -start => $aln->start1,
                                         -end => $aln->end1,
                                         -id => "one"));

$out->add_seq(Bio::LocatableSeq->new(-seq => $aln->aln2,
                                         -start => $aln->start2,
                                         -end => $aln->end2,
                                         -id => "two"));
$alnout->write_aln($out);

print "ok 3\n"; # Assume 3rd test worked

$aln = &Bio::Ext::Align::Align_Protein_Sequences("WLGQRNLVSSTGGNLLNVWLKDW","WMGNRNVVNLLNVWFRDW","blosum62", Bio::Tools::dpAlign::DPALIGN_LOCAL_MILLER_MYERS);
$out = Bio::SimpleAlign->new();

$out->add_seq(Bio::LocatableSeq->new(-seq => $aln->aln1,
                                         -start => $aln->start1,
                                         -end => $aln->end1,
                                         -id => "one"));

$out->add_seq(Bio::LocatableSeq->new(-seq => $aln->aln2,
                                         -start => $aln->start2,
                                         -end => $aln->end2,
                                         -id => "two"));
$alnout->write_aln($out);

print "ok 4\n"; # Assume 4th test worked


printf "Testing Global Alignment case...\n";

$factory = new Bio::Tools::dpAlign('-alg' => Bio::Tools::dpAlign::DPALIGN_GLOBAL_MILLER_MYERS);
$s1 = new Bio::Seq(-id => "one", -seq => "AATGCCATTGACGG", -alphabet => 'dna');
$s2 = new Bio::Seq(-id => "two", -seq => "CAGCCTCGCTTAG", -alphabet => 'dna');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln);
$factory->align_and_show($s1, $s2);

print "ok 5\n"; # Assume 5th test worked

$s1 = new Bio::Seq(-id => "one", -seq => "WLGQRNLVSSTGGNLLNVWLKDW", -alphabet => 'protein');
$s2 = new Bio::Seq(-id => "two", -seq => "WMGNRNVVNLLNVWFRDW", -alphabet => 'protein');
$aln = $factory->pairwise_alignment($s1, $s2);
$alnout->write_aln($aln);
$factory->align_and_show($s1, $s2);

printf "ok 6\n"; # Assume 6th test worked

$prof = $factory->sequence_profile($s1);
printf "Optimal Alignment Score = %d\n", $factory->pairwise_alignment_score($prof, $s2);
print "ok 7\n"; # Assume 7th test worked.
