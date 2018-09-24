# -*-Perl-*- Test Harness script for Bioperl
# $Id$

use strict;

BEGIN { 
    use lib '.';
    use Bio::Root::Test;
    
    test_begin(-tests => 3,
			   -requires_module => 'Bio::SeqIO::staden::read');
	
	use_ok('Bio::SeqIO::ztr');
}

my $verbose = test_debug();

my $io = Bio::SeqIO->new(-format => 'ztr',
			 -verbose => $verbose,
			 -file => test_input_file('readtest.ztr'));
ok(my $seq = $io->next_seq);
is($seq->seq, "GATGATTCCGGCTTCGGACGACTCTAGAGGATCCCCATTTTTATAGTTTTTATCTTGTAATAGATGTTTAGATTTTTCGTTGTAATTATTTTCTTTATTGTTGAAATTAGTATCTCTGGGTAATTTATCATATTCTCTGGAAAATGATTTACTATCACTAGATACTTCATAAGATTTATAATCTTTATTATGAAAATCATCTCTATTTTTCAAATTATTATTATATCTATCAAAGTTTCTGTCTTCATTATATCTATTAGCATATCTATCTTTATCTTTATCCCTATCACTATATCTATCATATGGTTCATCTTGTTCAACCGATCAGACTCGATTCGCCATCGCCTCTAACGGATGGCCGCTCCCCCTCTCATACCTCGCTCCCCTCGACATCCCCCGTCTCGCCACCCTATCCGCCCCCTTCATCACCCCCCCTTATCCACACCCTCACCCCCCGCATCGCGCACCCACGACCACCCGAAGAACCGCCCTTACTCCCAAGTACGCCCCGACCTCCATCACCCTATGCGGTACCACTCCCACCACACCCAGTCCTACTTTCGCCCGCACATCGGCCCCGCTTCAGACAGCTCCCAACTACGCAACCCACGCTTGTTCTTGTTCACACTCGAATACTCGAATCTCTCATTACTCCGCGGACTCCGCCGCACCTGTGCACCATTAACTGTGTAGCGCCTGAACCGGCACCTCTGATTACCACTTCCTCCACCAGCACAGTCCTATTACCGCATGTCGCTCTGCTAAGACAGTGCAAGACTCTGCGGTCGCTCTGACCCGCATCCGCCAGGGCACCTCTCACCCTCGCTGGCCACCCCGCCCCCCTCTCCCTGCCCCTTCATTCCCCCAAACCGCTTTCAACGGGACACACCCCTCCGCGGCGGACCACAACTCGCCGTCGGCCACCACTCACACCTTCCCTCCTCCTTCCCCCACATCACGCCAACCCCGTGGGACGGCTCTCCCGCGGCTACGACGCGCAACCCCCCCTCGCCGCTTCCCCCCCAACTTCCCACGGGCTCCCCTCCGCCCCTTACCCGCGAGGAGCTTCACCCGCGAACCACCTCCCCCCTTTCCCAACAGCACCG");
