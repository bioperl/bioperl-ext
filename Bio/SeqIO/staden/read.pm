# $Id$
# BioPerl module for Bio::SeqIO::staden::read.pm
#
# Cared for by Aaron Mackey <amackey@virginia.edu>
#
# Copyright Aaron Mackey
#
# You may distribute this module under the same terms as perl itself

# POD documentation - main docs before the code

=head1 NAME

Bio::SeqIO::staden::read - trace file input/output stream using the Staden IO "read" library

=head1 SYNOPSIS

Do not use this module directly.  Use it via the Bio::SeqIO class.

=head1 DESCRIPTION

This object can transform Bio::Seq objects to and from various trace
file formats.

=head1 FEEDBACK

=head2 Mailing Lists

User feedback is an integral part of the evolution of this and other
Bioperl modules. Send your comments and suggestions preferably to one
of the Bioperl mailing lists.  Your participation is much appreciated.

  bioperl-l@bioperl.org            - General discussion
  http://bioperl.org/wiki/Mailing_lists - About the mailing lists

=head2 Reporting Bugs

Report bugs to the Bioperl bug tracking system to help us keep track
the bugs and their resolution.  Bug reports can be submitted via the
web:

  http://bugzilla.bioperl.org/

=head1 AUTHORS - Aaron Mackey

Email: amackey@virginia.edu


=head1 APPENDIX

The rest of the documentation details each of the object
methods. Internal methods are usually preceded with a _

=cut

# Let the code begin...

package Bio::SeqIO::staden::read;

use strict;
use vars qw(@ISA $VERSION $HAS_INLINE);

use Bio::Root::Root;

my @ISA = qw( Bio::Root::Root );

sub BEGIN {
    eval {
	require Inline;

#       Debugging tools:
#	use Inline C => (Config =>
#			 CC => '/opt/parasoft/bin.linux2/insure',
#			 OPTIMIZE => '-g',
#			);

	use Inline (C => 'DATA',
		    VERSION => '1.51',
		    NAME => 'Bio::SeqIO::staden::read',
		    LIBS => "-L/usr/local/lib -lread -lz", # leave these as double quotes - necessary for Makefile.PL function
		    INC  => "-I/usr/local/include/io_lib", # leave these as double quotes - necessary for Makefile.PL function
		   );
    } or Bio::Root::Root::throw( -class => 'Bio::Root::SystemException',
				 -text  => "No Inline::C (or maybe io-lib?) support available",
			       );
}

$VERSION = 1.51;

my %formats = ( scf => 1,
		abi => 2,
		alf => 3,
		pln => 4,
		exp => 5,
		ctf => 6,
		ztr => 7,
		ztr1 => 8,
		ztr2 => 9,
		ztr3 => 10,
	      );

sub read_trace {

    my ($self) = shift;
    my ($fh, $format) = @_;

    unless (exists $formats{$format}) {
	$self->throw( -class => 'Bio::Root::NotImplemented',
		      -text  => "Format '$format' not supported by Staden read lib",
		      -value => $format
		    );
    }

    my @data = $self->staden_read_trace($fh, $formats{$format});

    unless (@data) {
	$self->throw( -class => 'Bio::Root::SystemException',
		      -text  => "Format could not be read - are you sure this is a \"$format\"-formatted trace file?",
		      -value => $format
		    );
    }

    return @data;
}

sub write_trace {

    my ($self) = shift;
    my ($fh, $seq, $format) = @_;

    unless (exists $formats{$format}) {
	$self->throw( -class => 'Bio::Root::NotImplemented',
		      -text  => "Format '$format' not supported by Staden read lib",
		      -value => $format
		    );
    }

    my $len = $seq->length();
    if ($len =~ m/DIFFERENT/i) {
	$self->throw( -class => 'Bio::Root::Exception',
		      -text  => "Sequence and quality lengths differ; cannot write seq",
		      -value => $len
		    );
    }

    my $ret = $self->staden_write_trace($fh,
					$formats{$format},
					$seq->seq,
					$len,
					$seq->can('qual') ? $seq->qual : [],
					$seq->display_id || '',
					$seq->desc || ''
				       );
    if ($ret == -1) {
	$self->throw( -class => 'Bio::Root::NotImplemented',
		      -text  => "Error while Writing format '$format'; either bad input or writing not supported by Staden read lib",
		      -value => $ret
		    );
    } elsif ($ret == -2) {
	$self->throw( -class => 'Bio::Root::SytemException',
		      -text  => "Out of memory error while writing seq",
		      -value => $ret
		    );
    }
    return $ret
}

1;
__DATA__
__C__
#include <Read.h>

int staden_write_trace(SV *self, FILE *fh, int format,
		       char *seq, int len, SV *qual, char *id, char *desc) {
  Read *read;
  SV *val;
  AV *qualarr;
  unsigned char qval;
  int i, n;
  
  read = read_allocate(0, len);
  memcpy(read->base, seq, len + 1);

  if (NULL == (read->ident = (char *) xcalloc(strlen(id) + 1, 1))) {
    read_deallocate(read); return -2;
  }
  strcpy(read->ident, id);

  if (NULL == (read->info = (char *) xcalloc(strlen(desc) + 1, 1))) {
    read_deallocate(read); return -2;
  }
  strcpy(read->info, desc);

  read->format = format;
  read->leftCutoff = 0;
  read->rightCutoff = len + 1;
  
  qualarr = (AV *) SvRV(qual);
  n = av_len(qualarr) + 1;
  for (i = 0 ; i < n && i < len ; i++) {
    val = *(av_fetch(qualarr, i, 0));
    qval = (unsigned char) SvIV(val);

    switch (read->base[i]) {
    case 'A' :
    case 'a' :
      read->prob_A[i] = qval;
      break;
    case 'C' :
    case 'c' :
      read->prob_C[i] = qval;
      break;
    case 'G' :
    case 'g' :
      read->prob_G[i] = qval;
      break;
    case 'T' :
    case 't' :
      read->prob_T[i] = qval;
      break;
    case 'N' :
    case 'n' :
    case '-' :
      read->prob_A[i] = read->prob_C[i] =
	read->prob_G[i] = read->prob_T[i] = qval / 4;
      break;
    default :
      read->prob_A[i] = read->prob_C[i] =
	read->prob_G[i] = read->prob_T[i] = 0;
      break;
    }
}

  i = fwrite_reading(fh, read, format);

  read_deallocate(read);
  return i;
}

void staden_read_trace(SV *self, FILE *fh, int format) {
  Inline_Stack_Vars;
  Read *read;
  SV *seq = NULL, *qual = NULL;
  char *bases, *pA, *pC, *pG, *pT, base, conf;
  int b, e;

  read = fread_reading(fh, (char *) NULL, format);

  if (read == NULLRead) {
      Inline_Stack_Reset; Inline_Stack_Push(&PL_sv_undef); Inline_Stack_Done;
      Inline_Stack_Return(1);
  }

  b = read->leftCutoff;
  if (b <= 0) b = 0;
  e = read->rightCutoff - 1;
  if (e < 0 || e > read->NBases) e = read->NBases;

  for (bases = &read->base[b],
	 pA = &read->prob_A[b], pC = &read->prob_C[b],
	 pG = &read->prob_G[b], pT = &read->prob_T[b]
	 ; b < e ;
       b++, bases++, pA++, pC++, pG++, pT++
       ) {

    base = *bases;
    if (base == '-') base = 'N';
    if (seq) {
      sv_catpvf(seq, "%c", base);
    } else {
      seq = newSVpvf("%c", base);
    }

    switch (base) {
    case 'A' :
    case 'a' :
      conf = *pA;
      break;
    case 'T' :
    case 't' :
      conf = *pT;
      break;
   case 'C' :
    case 'c' :
      conf = *pC;
      break;
    case 'G' :
    case 'g' :
      conf = *pG;
      break;
    case 'n' :
    case 'N' :
    case '-' :
      conf = (*pA + *pC + *pG + *pT) / 4;
      break;
    default :
      conf = 2; /* from the staden source code - 2 is the default confidence value */
      break;
    }
	
    if(qual) {
      sv_catpvf(qual, " %d", conf);
    } else {
      qual = newSVpvf("%d", conf);
    }
  }

  Inline_Stack_Reset;
  Inline_Stack_Push(sv_2mortal(seq));
  Inline_Stack_Push(sv_2mortal(newSVpvf("%s", read->ident)));
  Inline_Stack_Push(sv_2mortal(newSVpvf("%s", read->info)));
  Inline_Stack_Push(sv_2mortal(qual));
  Inline_Stack_Done;

  read_deallocate(read);
  Inline_Stack_Return(4);
}
