


OBJS =	aln.o\
	alnconvert.o\
	alnrange.o\
	asciibtcanvas.o\
	basematrix.o\
	btcanvas.o\
	commandline.o\
	complexconsensi.o\
	complexevalset.o\
	complexsequence.o\
	compmat.o\
	codon.o\
	dna.o\
	dnamatrix.o\
	dpenvelope.o\
	dynlibcross.o\
	histogram.o\
	hscore.o\
	linesubs.o\
	packaln.o\
	probability.o\
	protein.o\
	proteindb.o\
	proteinsw.o\
	seqaligndisplay.o\
	sequence.o\
	sequencedb.o\
	sw_wrap.o\
	wiseerror.o\
	wisefile.o\
	wisememman.o\
	wiseoverlay.o\
	wiserandom.o\
	wisestring.o\
	wisetime.o\
	dpalign.o\
	linspc.o

libsw.a : $(OBJS)
	ar ru libsw.a $(OBJS)

wisefile.o : wisefile.c
	$(CC) $(CFLAGS) -DNOERROR wisefile.c

#
# For NetBSD or Sun (solaris) installs, add -fPIC to the CFLAGS lines
#

CFLAGS = -c -O
CC     = cc
