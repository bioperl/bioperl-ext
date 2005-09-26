# -*-Perl-*- mode (to keep my emacs happy)

use strict;
use vars qw($DEBUG);
BEGIN {     
    eval { require Test; };
    if( $@ ) {
	use lib 't';
    }
    use Test;
    plan tests => 1;
}

ok(1);
