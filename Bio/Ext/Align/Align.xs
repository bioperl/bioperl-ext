
#ifdef __cplusplus
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifdef __cplusplus
}
#endif

#include "sw.h"


static int
not_here(s)
char *s;
{
    croak("%s not implemented on this architecture", s);
    return -1;
}

static double
constant(name, arg)
char *name;
int arg;
{
    errno = 0;
    switch (*name) {
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}


MODULE = Bio::Ext::Align  PACKAGE = Bio::Ext::Align


double
constant(name,arg)
	char *		name
	int		arg


PROTOTYPES: ENABLE

void
error_on(type)
	int type;
	CODE:
	bp_sw_error_on(type);


void
error_off(type)
	int type;
	CODE:
	bp_sw_error_off(type);


MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnBlock

void
bit_ascii_AlnBlock(alb,ofp)
	bp_sw_AlnBlock * alb
	FILE * ofp
	CODE:
	bp_sw_bit_ascii_AlnBlock(alb,ofp);



void
dump_ascii_AlnBlock(alb,ofp)
	bp_sw_AlnBlock * alb
	FILE * ofp
	CODE:
	bp_sw_dump_ascii_AlnBlock(alb,ofp);



bp_sw_AlnBlock *
hard_link_AlnBlock(obj)
	bp_sw_AlnBlock * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnBlock(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnBlock *
AlnBlock_alloc_std()
	CODE:
	RETVAL = bp_sw_AlnBlock_alloc_std();
	OUTPUT:
	RETVAL



boolean
set_start(obj,start)
	bp_sw_AlnBlock * obj
	bp_sw_AlnColumn * start
	CODE:
	RETVAL = bp_sw_replace_start_AlnBlock(obj,bp_sw_hard_link_AlnColumn(start));
	OUTPUT:
	RETVAL



bp_sw_AlnColumn *
start(obj)
	bp_sw_AlnBlock * obj
	INIT:
bp_sw_AlnColumn * temp;
	CODE:
	temp = bp_sw_hard_link_AlnColumn(bp_sw_access_start_AlnBlock(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



bp_sw_AlnSequence *
seq(obj,i)
	bp_sw_AlnBlock * obj
	int i
	INIT:
bp_sw_AlnSequence * temp;
	CODE:
	temp = bp_sw_hard_link_AlnSequence(bp_sw_access_seq_AlnBlock(obj,i));
	RETVAL = temp;
	OUTPUT:
	RETVAL



int
length_seq(obj)
	bp_sw_AlnBlock * obj
	CODE:
	RETVAL = bp_sw_length_seq_AlnBlock(obj);
	OUTPUT:
	RETVAL



int
flush_seq(obj)
	bp_sw_AlnBlock * obj
	CODE:
	RETVAL = bp_sw_flush_AlnBlock(obj);
	OUTPUT:
	RETVAL



boolean
add_seq(obj,add)
	bp_sw_AlnBlock * obj
	bp_sw_AlnSequence * add
	CODE:
	RETVAL = bp_sw_add_AlnBlock(obj,bp_sw_hard_link_AlnSequence(add));
	OUTPUT:
	RETVAL



boolean
set_length(obj,length)
	bp_sw_AlnBlock * obj
	int length
	CODE:
	RETVAL = bp_sw_replace_length_AlnBlock(obj,length);
	OUTPUT:
	RETVAL



int
length(obj)
	bp_sw_AlnBlock * obj
	CODE:
	RETVAL = bp_sw_access_length_AlnBlock(obj);
	OUTPUT:
	RETVAL



boolean
set_score(obj,score)
	bp_sw_AlnBlock * obj
	int score
	CODE:
	RETVAL = bp_sw_replace_score_AlnBlock(obj,score);
	OUTPUT:
	RETVAL



int
score(obj)
	bp_sw_AlnBlock * obj
	CODE:
	RETVAL = bp_sw_access_score_AlnBlock(obj);
	OUTPUT:
	RETVAL




bp_sw_AlnBlock *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnBlock * out;
	out = bp_sw_AlnBlock_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnBlock * obj
	CODE:
	bp_sw_free_AlnBlock(obj);

void
each_seq(obj)
	bp_sw_AlnBlock * obj
	PPCODE:
	int i=0;
	int len;
	SV* temp;
	len = bp_sw_length_seq_AlnBlock(obj);
	for(i=0;i<len;i++){
	  temp = sv_newmortal();
	  sv_setref_pv(temp, "Bio::Ext::Align::AlnSequence", (void*) (bp_sw_hard_link_AlnSequence(bp_sw_access_seq_AlnBlock(obj,i))));
	  XPUSHs(temp);
	  }
	XSRETURN(len);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnColumn

boolean
at_end(alc)
	bp_sw_AlnColumn * alc
	CODE:
	RETVAL = bp_sw_at_end_AlnColumn(alc);
	OUTPUT:
	RETVAL



bp_sw_AlnColumn *
hard_link_AlnColumn(obj)
	bp_sw_AlnColumn * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnColumn(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnColumn *
AlnColumn_alloc_std()
	CODE:
	RETVAL = bp_sw_AlnColumn_alloc_std();
	OUTPUT:
	RETVAL



bp_sw_AlnUnit *
alu(obj,i)
	bp_sw_AlnColumn * obj
	int i
	INIT:
bp_sw_AlnUnit * temp;
	CODE:
	temp = bp_sw_hard_link_AlnUnit(bp_sw_access_alu_AlnColumn(obj,i));
	RETVAL = temp;
	OUTPUT:
	RETVAL



int
length_alu(obj)
	bp_sw_AlnColumn * obj
	CODE:
	RETVAL = bp_sw_length_alu_AlnColumn(obj);
	OUTPUT:
	RETVAL



int
flush_alu(obj)
	bp_sw_AlnColumn * obj
	CODE:
	RETVAL = bp_sw_flush_AlnColumn(obj);
	OUTPUT:
	RETVAL



boolean
add_alu(obj,add)
	bp_sw_AlnColumn * obj
	bp_sw_AlnUnit * add
	CODE:
	RETVAL = bp_sw_add_AlnColumn(obj,bp_sw_hard_link_AlnUnit(add));
	OUTPUT:
	RETVAL



boolean
set_next(obj,next)
	bp_sw_AlnColumn * obj
	bp_sw_AlnColumn * next
	CODE:
	RETVAL = bp_sw_replace_next_AlnColumn(obj,bp_sw_hard_link_AlnColumn(next));
	OUTPUT:
	RETVAL



bp_sw_AlnColumn *
next(obj)
	bp_sw_AlnColumn * obj
	INIT:
bp_sw_AlnColumn * temp;
	CODE:
	temp = bp_sw_hard_link_AlnColumn(bp_sw_access_next_AlnColumn(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_AlnColumn *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnColumn * out;
	out = bp_sw_AlnColumn_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnColumn * obj
	CODE:
	bp_sw_free_AlnColumn(obj);

void
each_alu(obj)
	bp_sw_AlnColumn * obj
	PPCODE:
	int i=0;
	int len;
	SV* temp;
	len = bp_sw_length_alu_AlnColumn(obj);
	for(i=0;i<len;i++){
	  temp = sv_newmortal();
	  sv_setref_pv(temp, "Bio::Ext::Align::AlnUnit", (void*) (bp_sw_hard_link_AlnUnit(bp_sw_access_alu_AlnColumn(obj,i))));
	  XPUSHs(temp);
	  }
	XSRETURN(len);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnUnit

int
bio_start(alu)
	bp_sw_AlnUnit * alu
	CODE:
	RETVAL = bp_sw_bio_start_AlnUnit(alu);
	OUTPUT:
	RETVAL



int
bio_end(alu)
	bp_sw_AlnUnit * alu
	CODE:
	RETVAL = bp_sw_bio_end_AlnUnit(alu);
	OUTPUT:
	RETVAL



bp_sw_AlnUnit *
hard_link_AlnUnit(obj)
	bp_sw_AlnUnit * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnUnit(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnUnit *
alloc()
	CODE:
	RETVAL = bp_sw_AlnUnit_alloc();
	OUTPUT:
	RETVAL



boolean
set_start(obj,start)
	bp_sw_AlnUnit * obj
	int start
	CODE:
	RETVAL = bp_sw_replace_start_AlnUnit(obj,start);
	OUTPUT:
	RETVAL



int
start(obj)
	bp_sw_AlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_start_AlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_end(obj,end)
	bp_sw_AlnUnit * obj
	int end
	CODE:
	RETVAL = bp_sw_replace_end_AlnUnit(obj,end);
	OUTPUT:
	RETVAL



int
end(obj)
	bp_sw_AlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_end_AlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_label(obj,label)
	bp_sw_AlnUnit * obj
	int label
	CODE:
	RETVAL = bp_sw_replace_label_AlnUnit(obj,label);
	OUTPUT:
	RETVAL



int
label(obj)
	bp_sw_AlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_label_AlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_text_label(obj,text_label)
	bp_sw_AlnUnit * obj
	char * text_label
	CODE:
	RETVAL = bp_sw_replace_text_label_AlnUnit(obj,bp_sw_stringalloc(text_label));
	OUTPUT:
	RETVAL



char *
text_label(obj)
	bp_sw_AlnUnit * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_text_label_AlnUnit(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_next(obj,next)
	bp_sw_AlnUnit * obj
	bp_sw_AlnUnit * next
	CODE:
	RETVAL = bp_sw_replace_next_AlnUnit(obj,bp_sw_hard_link_AlnUnit(next));
	OUTPUT:
	RETVAL



bp_sw_AlnUnit *
next(obj)
	bp_sw_AlnUnit * obj
	INIT:
bp_sw_AlnUnit * temp;
	CODE:
	temp = bp_sw_hard_link_AlnUnit(bp_sw_access_next_AlnUnit(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_in_column(obj,in_column)
	bp_sw_AlnUnit * obj
	boolean in_column
	CODE:
	RETVAL = bp_sw_replace_in_column_AlnUnit(obj,in_column);
	OUTPUT:
	RETVAL



boolean
in_column(obj)
	bp_sw_AlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_in_column_AlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_seq(obj,seq)
	bp_sw_AlnUnit * obj
	bp_sw_AlnSequence * seq
	CODE:
	RETVAL = bp_sw_replace_seq_AlnUnit(obj,bp_sw_hard_link_AlnSequence(seq));
	OUTPUT:
	RETVAL



bp_sw_AlnSequence *
seq(obj)
	bp_sw_AlnUnit * obj
	INIT:
bp_sw_AlnSequence * temp;
	CODE:
	temp = bp_sw_hard_link_AlnSequence(bp_sw_access_seq_AlnUnit(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_AlnUnit *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnUnit * out;
	out = bp_sw_AlnUnit_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnUnit * obj
	CODE:
	bp_sw_free_AlnUnit(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnSequence

bp_sw_AlnSequence *
hard_link_AlnSequence(obj)
	bp_sw_AlnSequence * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnSequence(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnSequence *
alloc()
	CODE:
	RETVAL = bp_sw_AlnSequence_alloc();
	OUTPUT:
	RETVAL



boolean
set_start(obj,start)
	bp_sw_AlnSequence * obj
	bp_sw_AlnUnit * start
	CODE:
	RETVAL = bp_sw_replace_start_AlnSequence(obj,bp_sw_hard_link_AlnUnit(start));
	OUTPUT:
	RETVAL



bp_sw_AlnUnit *
start(obj)
	bp_sw_AlnSequence * obj
	INIT:
bp_sw_AlnUnit * temp;
	CODE:
	temp = bp_sw_hard_link_AlnUnit(bp_sw_access_start_AlnSequence(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_data_type(obj,data_type)
	bp_sw_AlnSequence * obj
	int data_type
	CODE:
	RETVAL = bp_sw_replace_data_type_AlnSequence(obj,data_type);
	OUTPUT:
	RETVAL



int
data_type(obj)
	bp_sw_AlnSequence * obj
	CODE:
	RETVAL = bp_sw_access_data_type_AlnSequence(obj);
	OUTPUT:
	RETVAL



boolean
set_data(obj,data)
	bp_sw_AlnSequence * obj
	void * data
	CODE:
	RETVAL = bp_sw_replace_data_AlnSequence(obj,data);
	OUTPUT:
	RETVAL



void *
data(obj)
	bp_sw_AlnSequence * obj
	CODE:
	RETVAL = bp_sw_access_data_AlnSequence(obj);
	OUTPUT:
	RETVAL



boolean
set_bio_start(obj,bio_start)
	bp_sw_AlnSequence * obj
	int bio_start
	CODE:
	RETVAL = bp_sw_replace_bio_start_AlnSequence(obj,bio_start);
	OUTPUT:
	RETVAL



int
bio_start(obj)
	bp_sw_AlnSequence * obj
	CODE:
	RETVAL = bp_sw_access_bio_start_AlnSequence(obj);
	OUTPUT:
	RETVAL



boolean
set_bio_end(obj,bio_end)
	bp_sw_AlnSequence * obj
	int bio_end
	CODE:
	RETVAL = bp_sw_replace_bio_end_AlnSequence(obj,bio_end);
	OUTPUT:
	RETVAL



int
bio_end(obj)
	bp_sw_AlnSequence * obj
	CODE:
	RETVAL = bp_sw_access_bio_end_AlnSequence(obj);
	OUTPUT:
	RETVAL




bp_sw_AlnSequence *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnSequence * out;
	out = bp_sw_AlnSequence_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnSequence * obj
	CODE:
	bp_sw_free_AlnSequence(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align


MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnRangeSet

bp_sw_AlnRangeSet *
hard_link_AlnRangeSet(obj)
	bp_sw_AlnRangeSet * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnRangeSet(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnRangeSet *
AlnRangeSet_alloc_std()
	CODE:
	RETVAL = bp_sw_AlnRangeSet_alloc_std();
	OUTPUT:
	RETVAL



boolean
set_score(obj,score)
	bp_sw_AlnRangeSet * obj
	int score
	CODE:
	RETVAL = bp_sw_replace_score_AlnRangeSet(obj,score);
	OUTPUT:
	RETVAL



int
score(obj)
	bp_sw_AlnRangeSet * obj
	CODE:
	RETVAL = bp_sw_access_score_AlnRangeSet(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnRange *
alr(obj,i)
	bp_sw_AlnRangeSet * obj
	int i
	INIT:
bp_sw_AlnRange * temp;
	CODE:
	temp = bp_sw_hard_link_AlnRange(bp_sw_access_alr_AlnRangeSet(obj,i));
	RETVAL = temp;
	OUTPUT:
	RETVAL



int
length_alr(obj)
	bp_sw_AlnRangeSet * obj
	CODE:
	RETVAL = bp_sw_length_alr_AlnRangeSet(obj);
	OUTPUT:
	RETVAL



int
flush_alr(obj)
	bp_sw_AlnRangeSet * obj
	CODE:
	RETVAL = bp_sw_flush_AlnRangeSet(obj);
	OUTPUT:
	RETVAL



boolean
add_alr(obj,add)
	bp_sw_AlnRangeSet * obj
	bp_sw_AlnRange * add
	CODE:
	RETVAL = bp_sw_add_AlnRangeSet(obj,bp_sw_hard_link_AlnRange(add));
	OUTPUT:
	RETVAL




bp_sw_AlnRangeSet *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnRangeSet * out;
	out = bp_sw_AlnRangeSet_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnRangeSet * obj
	CODE:
	bp_sw_free_AlnRangeSet(obj);

void
each_alr(obj)
	bp_sw_AlnRangeSet * obj
	PPCODE:
	int i=0;
	int len;
	SV* temp;
	len = bp_sw_length_alr_AlnRangeSet(obj);
	for(i=0;i<len;i++){
	  temp = sv_newmortal();
	  sv_setref_pv(temp, "Bio::Ext::Align::AlnRange", (void*) (bp_sw_hard_link_AlnRange(bp_sw_access_alr_AlnRangeSet(obj,i))));
	  XPUSHs(temp);
	  }
	XSRETURN(len);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::AlnRange

bp_sw_AlnRange *
hard_link_AlnRange(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_hard_link_AlnRange(obj);
	OUTPUT:
	RETVAL



bp_sw_AlnRange *
alloc()
	CODE:
	RETVAL = bp_sw_AlnRange_alloc();
	OUTPUT:
	RETVAL



boolean
set_starti(obj,starti)
	bp_sw_AlnRange * obj
	int starti
	CODE:
	RETVAL = bp_sw_replace_starti_AlnRange(obj,starti);
	OUTPUT:
	RETVAL



int
starti(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_starti_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_startj(obj,startj)
	bp_sw_AlnRange * obj
	int startj
	CODE:
	RETVAL = bp_sw_replace_startj_AlnRange(obj,startj);
	OUTPUT:
	RETVAL



int
startj(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_startj_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_startstate(obj,startstate)
	bp_sw_AlnRange * obj
	int startstate
	CODE:
	RETVAL = bp_sw_replace_startstate_AlnRange(obj,startstate);
	OUTPUT:
	RETVAL



int
startstate(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_startstate_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_stopi(obj,stopi)
	bp_sw_AlnRange * obj
	int stopi
	CODE:
	RETVAL = bp_sw_replace_stopi_AlnRange(obj,stopi);
	OUTPUT:
	RETVAL



int
stopi(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_stopi_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_stopj(obj,stopj)
	bp_sw_AlnRange * obj
	int stopj
	CODE:
	RETVAL = bp_sw_replace_stopj_AlnRange(obj,stopj);
	OUTPUT:
	RETVAL



int
stopj(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_stopj_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_stopstate(obj,stopstate)
	bp_sw_AlnRange * obj
	int stopstate
	CODE:
	RETVAL = bp_sw_replace_stopstate_AlnRange(obj,stopstate);
	OUTPUT:
	RETVAL



int
stopstate(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_stopstate_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_startscore(obj,startscore)
	bp_sw_AlnRange * obj
	int startscore
	CODE:
	RETVAL = bp_sw_replace_startscore_AlnRange(obj,startscore);
	OUTPUT:
	RETVAL



int
startscore(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_startscore_AlnRange(obj);
	OUTPUT:
	RETVAL



boolean
set_stopscore(obj,stopscore)
	bp_sw_AlnRange * obj
	int stopscore
	CODE:
	RETVAL = bp_sw_replace_stopscore_AlnRange(obj,stopscore);
	OUTPUT:
	RETVAL



int
stopscore(obj)
	bp_sw_AlnRange * obj
	CODE:
	RETVAL = bp_sw_access_stopscore_AlnRange(obj);
	OUTPUT:
	RETVAL




bp_sw_AlnRange *
new(class)
	char * class
	PPCODE:
	bp_sw_AlnRange * out;
	out = bp_sw_AlnRange_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_AlnRange * obj
	CODE:
	bp_sw_free_AlnRange(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

void
change_max_BaseMatrix_kbytes(new_kilo_number)
	int new_kilo_number
	CODE:
	bp_sw_change_max_BaseMatrix_kbytes(new_kilo_number);



int
get_max_BaseMatrix_kbytes()
	CODE:
	RETVAL = bp_sw_get_max_BaseMatrix_kbytes();
	OUTPUT:
	RETVAL


MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::ComplexSequence

bp_sw_ComplexSequence *
hard_link_ComplexSequence(obj)
	bp_sw_ComplexSequence * obj
	CODE:
	RETVAL = bp_sw_hard_link_ComplexSequence(obj);
	OUTPUT:
	RETVAL



bp_sw_ComplexSequence *
alloc()
	CODE:
	RETVAL = bp_sw_ComplexSequence_alloc();
	OUTPUT:
	RETVAL



boolean
set_type(obj,type)
	bp_sw_ComplexSequence * obj
	int type
	CODE:
	RETVAL = bp_sw_replace_type_ComplexSequence(obj,type);
	OUTPUT:
	RETVAL



int
type(obj)
	bp_sw_ComplexSequence * obj
	CODE:
	RETVAL = bp_sw_access_type_ComplexSequence(obj);
	OUTPUT:
	RETVAL



boolean
set_seq(obj,seq)
	bp_sw_ComplexSequence * obj
	bp_sw_Sequence * seq
	CODE:
	RETVAL = bp_sw_replace_seq_ComplexSequence(obj,bp_sw_hard_link_Sequence(seq));
	OUTPUT:
	RETVAL



bp_sw_Sequence *
seq(obj)
	bp_sw_ComplexSequence * obj
	INIT:
bp_sw_Sequence * temp;
	CODE:
	temp = bp_sw_hard_link_Sequence(bp_sw_access_seq_ComplexSequence(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_ComplexSequence *
new(class)
	char * class
	PPCODE:
	bp_sw_ComplexSequence * out;
	out = bp_sw_ComplexSequence_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_ComplexSequence * obj
	CODE:
	bp_sw_free_ComplexSequence(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::ComplexSequenceEvalSet

bp_sw_ComplexSequenceEvalSet *
hard_link_ComplexSequenceEvalSet(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_hard_link_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL



bp_sw_ComplexSequenceEvalSet *
ComplexSequenceEvalSet_alloc_std()
	CODE:
	RETVAL = bp_sw_ComplexSequenceEvalSet_alloc_std();
	OUTPUT:
	RETVAL



boolean
set_type(obj,type)
	bp_sw_ComplexSequenceEvalSet * obj
	int type
	CODE:
	RETVAL = bp_sw_replace_type_ComplexSequenceEvalSet(obj,type);
	OUTPUT:
	RETVAL



int
type(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_access_type_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL



boolean
set_has_been_prepared(obj,has_been_prepared)
	bp_sw_ComplexSequenceEvalSet * obj
	boolean has_been_prepared
	CODE:
	RETVAL = bp_sw_replace_has_been_prepared_ComplexSequenceEvalSet(obj,has_been_prepared);
	OUTPUT:
	RETVAL



boolean
has_been_prepared(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_access_has_been_prepared_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL



boolean
set_left_window(obj,left_window)
	bp_sw_ComplexSequenceEvalSet * obj
	int left_window
	CODE:
	RETVAL = bp_sw_replace_left_window_ComplexSequenceEvalSet(obj,left_window);
	OUTPUT:
	RETVAL



int
left_window(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_access_left_window_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL



boolean
set_right_window(obj,right_window)
	bp_sw_ComplexSequenceEvalSet * obj
	int right_window
	CODE:
	RETVAL = bp_sw_replace_right_window_ComplexSequenceEvalSet(obj,right_window);
	OUTPUT:
	RETVAL



int
right_window(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_access_right_window_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL



boolean
set_left_lookback(obj,left_lookback)
	bp_sw_ComplexSequenceEvalSet * obj
	int left_lookback
	CODE:
	RETVAL = bp_sw_replace_left_lookback_ComplexSequenceEvalSet(obj,left_lookback);
	OUTPUT:
	RETVAL



int
left_lookback(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	RETVAL = bp_sw_access_left_lookback_ComplexSequenceEvalSet(obj);
	OUTPUT:
	RETVAL




bp_sw_ComplexSequenceEvalSet *
new(class)
	char * class
	PPCODE:
	bp_sw_ComplexSequenceEvalSet * out;
	out = bp_sw_ComplexSequenceEvalSet_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_ComplexSequenceEvalSet * obj
	CODE:
	bp_sw_free_ComplexSequenceEvalSet(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::CompMat

Score
fail_safe_CompMat_access(cm,aa1,aa2)
	bp_sw_CompMat * cm
	int aa1
	int aa2
	CODE:
	RETVAL = bp_sw_fail_safe_CompMat_access(cm,aa1,aa2);
	OUTPUT:
	RETVAL



boolean
write_Blast_CompMat(cm,ofp)
	bp_sw_CompMat * cm
	FILE * ofp
	CODE:
	RETVAL = bp_sw_write_Blast_CompMat(cm,ofp);
	OUTPUT:
	RETVAL



bp_sw_CompMat *
read_Blast_file_CompMat(filename)
	char * filename
	CODE:
	RETVAL = bp_sw_read_Blast_file_CompMat(filename);
	OUTPUT:
	RETVAL



bp_sw_CompMat *
read_Blast_CompMat(ifp)
	FILE * ifp
	CODE:
	RETVAL = bp_sw_read_Blast_CompMat(ifp);
	OUTPUT:
	RETVAL



bp_sw_CompMat *
hard_link_CompMat(obj)
	bp_sw_CompMat * obj
	CODE:
	RETVAL = bp_sw_hard_link_CompMat(obj);
	OUTPUT:
	RETVAL



bp_sw_CompMat *
alloc()
	CODE:
	RETVAL = bp_sw_CompMat_alloc();
	OUTPUT:
	RETVAL



boolean
set_name(obj,name)
	bp_sw_CompMat * obj
	char * name
	CODE:
	RETVAL = bp_sw_replace_name_CompMat(obj,bp_sw_stringalloc(name));
	OUTPUT:
	RETVAL



char *
name(obj)
	bp_sw_CompMat * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_name_CompMat(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_CompMat *
new(class)
	char * class
	PPCODE:
	bp_sw_CompMat * out;
	out = bp_sw_CompMat_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_CompMat * obj
	CODE:
	bp_sw_free_CompMat(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::Histogram


double
evalue(his,score)
	bp_sw_Histogram * his
	double score
	CODE:
	RETVAL = bp_sw_Evalue_from_Histogram(his,score);
	OUTPUT:
	RETVAL


void
UnfitHistogram(h)
	bp_sw_Histogram * h
	CODE:
	bp_sw_UnfitHistogram(h);



void
add(h,sc)
	bp_sw_Histogram * h
	float sc
	CODE:
	bp_sw_AddToHistogram(h,sc);



void
show(h,fp)
	bp_sw_Histogram * h
	FILE * fp
	CODE:
	bp_sw_PrintASCIIHistogram(h,fp);



void
EVDBasicFit(h)
	bp_sw_Histogram * h
	CODE:
	bp_sw_EVDBasicFit(h);



int
fit_EVD(h,censor,high_hint)
	bp_sw_Histogram * h
	int censor
	float high_hint
	CODE:
	RETVAL = bp_sw_ExtremeValueFitHistogram(h,censor,high_hint);
	OUTPUT:
	RETVAL



void
set_EVD(h,mu,lambda,lowbound,highbound,wonka,ndegrees)
	bp_sw_Histogram * h
	float mu
	float lambda
	float lowbound
	float highbound
	float wonka
	int ndegrees
	CODE:
	bp_sw_ExtremeValueSetHistogram(h,mu,lambda,lowbound,highbound,wonka,ndegrees);



int
fit_Gaussian(h,high_hint)
	bp_sw_Histogram * h
	float high_hint
	CODE:
	RETVAL = bp_sw_GaussianFitHistogram(h,high_hint);
	OUTPUT:
	RETVAL



void
set_Gaussian(h,mean,sd)
	bp_sw_Histogram * h
	float mean
	float sd
	CODE:
	bp_sw_GaussianSetHistogram(h,mean,sd);



bp_sw_Histogram *
hard_link_Histogram(obj)
	bp_sw_Histogram * obj
	CODE:
	RETVAL = bp_sw_hard_link_Histogram(obj);
	OUTPUT:
	RETVAL



bp_sw_Histogram *
alloc()
	CODE:
	RETVAL = bp_sw_Histogram_alloc();
	OUTPUT:
	RETVAL




bp_sw_Histogram *
new(class)
	char * class
	PPCODE:
	bp_sw_Histogram * out;
	out = bp_sw_Histogram_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_Histogram * obj
	CODE:
	bp_sw_free_Histogram(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

bp_sw_Histogram *
new_Histogram(min,max,lumpsize)
	int min
	int max
	int lumpsize
	CODE:
	RETVAL = bp_sw_new_Histogram(min,max,lumpsize);
	OUTPUT:
	RETVAL





MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::Hscore

int
minimum_score_Hscore(hs)
	bp_sw_Hscore * hs
	CODE:
	RETVAL = bp_sw_minimum_score_Hscore(hs);
	OUTPUT:
	RETVAL



int
maximum_score_Hscore(hs)
	bp_sw_Hscore * hs
	CODE:
	RETVAL = bp_sw_maximum_score_Hscore(hs);
	OUTPUT:
	RETVAL



void
sort_Hscore_by_score(hs)
	bp_sw_Hscore * hs
	CODE:
	bp_sw_sort_Hscore_by_score(hs);



int
length(obj)
	bp_sw_Hscore * obj
	CODE:
	RETVAL = bp_sw_length_datascore_Hscore(obj);
	OUTPUT:
	RETVAL



bp_sw_DataScore *
datascore(hs,i)
	bp_sw_Hscore * hs
	int i
	CODE:
	RETVAL = bp_sw_get_datascore_Hscore(hs,i);
	OUTPUT:
	RETVAL



int
score(hs,i)
	bp_sw_Hscore * hs
	int i
	CODE:
	RETVAL = bp_sw_get_score_Hscore(hs,i);
	OUTPUT:
	RETVAL



double
evalue(hs,i)
	bp_sw_Hscore * hs
	int i
	CODE:
	RETVAL = bp_sw_get_evalue_Hscore(hs,i);
	OUTPUT:
	RETVAL



void
show(hs,ofp)
	bp_sw_Hscore * hs
	FILE * ofp
	CODE:
	bp_sw_basic_show_Hscore(hs,ofp);



bp_sw_Hscore *
hard_link_Hscore(obj)
	bp_sw_Hscore * obj
	CODE:
	RETVAL = bp_sw_hard_link_Hscore(obj);
	OUTPUT:
	RETVAL



bp_sw_Hscore *
Hscore_alloc_std()
	CODE:
	RETVAL = bp_sw_Hscore_alloc_std();
	OUTPUT:
	RETVAL




bp_sw_Hscore *
new(class)
	char * class
	PPCODE:
	bp_sw_Hscore * out;
	out = bp_sw_Hscore_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_Hscore * obj
	CODE:
	bp_sw_free_Hscore(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::DataScore

bp_sw_DataScore *
hard_link_DataScore(obj)
	bp_sw_DataScore * obj
	CODE:
	RETVAL = bp_sw_hard_link_DataScore(obj);
	OUTPUT:
	RETVAL



bp_sw_DataScore *
alloc()
	CODE:
	RETVAL = bp_sw_DataScore_alloc();
	OUTPUT:
	RETVAL



boolean
set_query(obj,query)
	bp_sw_DataScore * obj
	bp_sw_DataEntry * query
	CODE:
	RETVAL = bp_sw_replace_query_DataScore(obj,bp_sw_hard_link_DataEntry(query));
	OUTPUT:
	RETVAL



bp_sw_DataEntry *
query(obj)
	bp_sw_DataScore * obj
	INIT:
bp_sw_DataEntry * temp;
	CODE:
	temp = bp_sw_hard_link_DataEntry(bp_sw_access_query_DataScore(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_target(obj,target)
	bp_sw_DataScore * obj
	bp_sw_DataEntry * target
	CODE:
	RETVAL = bp_sw_replace_target_DataScore(obj,bp_sw_hard_link_DataEntry(target));
	OUTPUT:
	RETVAL



bp_sw_DataEntry *
target(obj)
	bp_sw_DataScore * obj
	INIT:
bp_sw_DataEntry * temp;
	CODE:
	temp = bp_sw_hard_link_DataEntry(bp_sw_access_target_DataScore(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_score(obj,score)
	bp_sw_DataScore * obj
	int score
	CODE:
	RETVAL = bp_sw_replace_score_DataScore(obj,score);
	OUTPUT:
	RETVAL



int
score(obj)
	bp_sw_DataScore * obj
	CODE:
	RETVAL = bp_sw_access_score_DataScore(obj);
	OUTPUT:
	RETVAL



boolean
set_evalue(obj,evalue)
	bp_sw_DataScore * obj
	double evalue
	CODE:
	RETVAL = bp_sw_replace_evalue_DataScore(obj,evalue);
	OUTPUT:
	RETVAL



double
evalue(obj)
	bp_sw_DataScore * obj
	CODE:
	RETVAL = bp_sw_access_evalue_DataScore(obj);
	OUTPUT:
	RETVAL




bp_sw_DataScore *
new(class)
	char * class
	PPCODE:
	bp_sw_DataScore * out;
	out = bp_sw_DataScore_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_DataScore * obj
	CODE:
	bp_sw_free_DataScore(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::DataEntry

bp_sw_DataEntry *
hard_link_DataEntry(obj)
	bp_sw_DataEntry * obj
	CODE:
	RETVAL = bp_sw_hard_link_DataEntry(obj);
	OUTPUT:
	RETVAL



bp_sw_DataEntry *
alloc()
	CODE:
	RETVAL = bp_sw_DataEntry_alloc();
	OUTPUT:
	RETVAL



boolean
set_name(obj,name)
	bp_sw_DataEntry * obj
	char * name
	CODE:
	RETVAL = bp_sw_replace_name_DataEntry(obj,bp_sw_stringalloc(name));
	OUTPUT:
	RETVAL



char *
name(obj)
	bp_sw_DataEntry * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_name_DataEntry(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_is_reversed(obj,is_reversed)
	bp_sw_DataEntry * obj
	boolean is_reversed
	CODE:
	RETVAL = bp_sw_replace_is_reversed_DataEntry(obj,is_reversed);
	OUTPUT:
	RETVAL



boolean
is_reversed(obj)
	bp_sw_DataEntry * obj
	CODE:
	RETVAL = bp_sw_access_is_reversed_DataEntry(obj);
	OUTPUT:
	RETVAL



boolean
set_filename(obj,filename)
	bp_sw_DataEntry * obj
	char * filename
	CODE:
	RETVAL = bp_sw_replace_filename_DataEntry(obj,bp_sw_stringalloc(filename));
	OUTPUT:
	RETVAL



char *
filename(obj)
	bp_sw_DataEntry * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_filename_DataEntry(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_DataEntry *
new(class)
	char * class
	PPCODE:
	bp_sw_DataEntry * out;
	out = bp_sw_DataEntry_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_DataEntry * obj
	CODE:
	bp_sw_free_DataEntry(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::PackAln

void
show_simple_PackAln(pal,ofp)
	bp_sw_PackAln * pal
	FILE * ofp
	CODE:
	bp_sw_show_simple_PackAln(pal,ofp);



void
show_bits_and_cumlative_PackAln(pal,ofp)
	bp_sw_PackAln * pal
	FILE * ofp
	CODE:
	bp_sw_show_bits_and_cumlative_PackAln(pal,ofp);



bp_sw_PackAln *
hard_link_PackAln(obj)
	bp_sw_PackAln * obj
	CODE:
	RETVAL = bp_sw_hard_link_PackAln(obj);
	OUTPUT:
	RETVAL



bp_sw_PackAln *
PackAln_alloc_std()
	CODE:
	RETVAL = bp_sw_PackAln_alloc_std();
	OUTPUT:
	RETVAL



bp_sw_PackAlnUnit *
pau(obj,i)
	bp_sw_PackAln * obj
	int i
	INIT:
bp_sw_PackAlnUnit * temp;
	CODE:
	temp = bp_sw_hard_link_PackAlnUnit(bp_sw_access_pau_PackAln(obj,i));
	RETVAL = temp;
	OUTPUT:
	RETVAL



int
length_pau(obj)
	bp_sw_PackAln * obj
	CODE:
	RETVAL = bp_sw_length_pau_PackAln(obj);
	OUTPUT:
	RETVAL



int
flush_pau(obj)
	bp_sw_PackAln * obj
	CODE:
	RETVAL = bp_sw_flush_PackAln(obj);
	OUTPUT:
	RETVAL



boolean
add_pau(obj,add)
	bp_sw_PackAln * obj
	bp_sw_PackAlnUnit * add
	CODE:
	RETVAL = bp_sw_add_PackAln(obj,bp_sw_hard_link_PackAlnUnit(add));
	OUTPUT:
	RETVAL



boolean
set_score(obj,score)
	bp_sw_PackAln * obj
	int score
	CODE:
	RETVAL = bp_sw_replace_score_PackAln(obj,score);
	OUTPUT:
	RETVAL



int
score(obj)
	bp_sw_PackAln * obj
	CODE:
	RETVAL = bp_sw_access_score_PackAln(obj);
	OUTPUT:
	RETVAL




bp_sw_PackAln *
new(class)
	char * class
	PPCODE:
	bp_sw_PackAln * out;
	out = bp_sw_PackAln_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_PackAln * obj
	CODE:
	bp_sw_free_PackAln(obj);

void
each_pau(obj)
	bp_sw_PackAln * obj
	PPCODE:
	int i=0;
	int len;
	SV* temp;
	len = bp_sw_length_pau_PackAln(obj);
	for(i=0;i<len;i++){
	  temp = sv_newmortal();
	  sv_setref_pv(temp, "Bio::Ext::Align::PackAlnUnit", (void*) (bp_sw_hard_link_PackAlnUnit(bp_sw_access_pau_PackAln(obj,i))));
	  XPUSHs(temp);
	  }
	XSRETURN(len);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::PackAlnUnit

bp_sw_PackAlnUnit *
hard_link_PackAlnUnit(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	RETVAL = bp_sw_hard_link_PackAlnUnit(obj);
	OUTPUT:
	RETVAL



bp_sw_PackAlnUnit *
alloc()
	CODE:
	RETVAL = bp_sw_PackAlnUnit_alloc();
	OUTPUT:
	RETVAL



boolean
set_i(obj,i)
	bp_sw_PackAlnUnit * obj
	int i
	CODE:
	RETVAL = bp_sw_replace_i_PackAlnUnit(obj,i);
	OUTPUT:
	RETVAL



int
i(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_i_PackAlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_j(obj,j)
	bp_sw_PackAlnUnit * obj
	int j
	CODE:
	RETVAL = bp_sw_replace_j_PackAlnUnit(obj,j);
	OUTPUT:
	RETVAL



int
j(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_j_PackAlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_state(obj,state)
	bp_sw_PackAlnUnit * obj
	int state
	CODE:
	RETVAL = bp_sw_replace_state_PackAlnUnit(obj,state);
	OUTPUT:
	RETVAL



int
state(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_state_PackAlnUnit(obj);
	OUTPUT:
	RETVAL



boolean
set_score(obj,score)
	bp_sw_PackAlnUnit * obj
	int score
	CODE:
	RETVAL = bp_sw_replace_score_PackAlnUnit(obj,score);
	OUTPUT:
	RETVAL



int
score(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	RETVAL = bp_sw_access_score_PackAlnUnit(obj);
	OUTPUT:
	RETVAL




bp_sw_PackAlnUnit *
new(class)
	char * class
	PPCODE:
	bp_sw_PackAlnUnit * out;
	out = bp_sw_PackAlnUnit_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_PackAlnUnit * obj
	CODE:
	bp_sw_free_PackAlnUnit(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

Probability
Probability_from_average_state_occupancy(length)
	double length
	CODE:
	RETVAL = bp_sw_Probability_from_average_state_occupancy(length);
	OUTPUT:
	RETVAL



double
state_occupancy_from_Probability(p)
	double p
	CODE:
	RETVAL = bp_sw_state_occupancy_from_Probability(p);
	OUTPUT:
	RETVAL



Score
Probability2Score(p)
	Probability p
	CODE:
	RETVAL = bp_sw_Probability2Score(p);
	OUTPUT:
	RETVAL



Probability
Score2Probability(s)
	Score s
	CODE:
	RETVAL = bp_sw_Score2Probability(s);
	OUTPUT:
	RETVAL



Bits
Score2Bits(s)
	Score s
	CODE:
	RETVAL = bp_sw_Score2Bits(s);
	OUTPUT:
	RETVAL



Probability
halfbit2Probability(half_bit)
	double half_bit
	CODE:
	RETVAL = bp_sw_halfbit2Probability(half_bit);
	OUTPUT:
	RETVAL





MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::Protein

bp_sw_Protein *
Protein_from_Sequence(seq)
	bp_sw_Sequence * seq
	CODE:
	RETVAL = bp_sw_Protein_from_Sequence(bp_sw_hard_link_Sequence(seq));
	OUTPUT:
	RETVAL



bp_sw_Protein *
hard_link_Protein(obj)
	bp_sw_Protein * obj
	CODE:
	RETVAL = bp_sw_hard_link_Protein(obj);
	OUTPUT:
	RETVAL



bp_sw_Protein *
alloc()
	CODE:
	RETVAL = bp_sw_Protein_alloc();
	OUTPUT:
	RETVAL



boolean
set_baseseq(obj,baseseq)
	bp_sw_Protein * obj
	bp_sw_Sequence * baseseq
	CODE:
	RETVAL = bp_sw_replace_baseseq_Protein(obj,bp_sw_hard_link_Sequence(baseseq));
	OUTPUT:
	RETVAL



bp_sw_Sequence *
baseseq(obj)
	bp_sw_Protein * obj
	INIT:
bp_sw_Sequence * temp;
	CODE:
	temp = bp_sw_hard_link_Sequence(bp_sw_access_baseseq_Protein(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_Protein *
new(class)
	char * class
	PPCODE:
	bp_sw_Protein * out;
	out = bp_sw_Protein_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_Protein * obj
	CODE:
	bp_sw_free_Protein(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::ProteinDB

bp_sw_ProteinDB *
hard_link_ProteinDB(obj)
	bp_sw_ProteinDB * obj
	CODE:
	RETVAL = bp_sw_hard_link_ProteinDB(obj);
	OUTPUT:
	RETVAL



bp_sw_ProteinDB *
alloc()
	CODE:
	RETVAL = bp_sw_ProteinDB_alloc();
	OUTPUT:
	RETVAL



boolean
set_is_single_seq(obj,is_single_seq)
	bp_sw_ProteinDB * obj
	boolean is_single_seq
	CODE:
	RETVAL = bp_sw_replace_is_single_seq_ProteinDB(obj,is_single_seq);
	OUTPUT:
	RETVAL



boolean
is_single_seq(obj)
	bp_sw_ProteinDB * obj
	CODE:
	RETVAL = bp_sw_access_is_single_seq_ProteinDB(obj);
	OUTPUT:
	RETVAL



boolean
set_single(obj,single)
	bp_sw_ProteinDB * obj
	bp_sw_ComplexSequence * single
	CODE:
	RETVAL = bp_sw_replace_single_ProteinDB(obj,bp_sw_hard_link_ComplexSequence(single));
	OUTPUT:
	RETVAL



bp_sw_ComplexSequence *
single(obj)
	bp_sw_ProteinDB * obj
	INIT:
bp_sw_ComplexSequence * temp;
	CODE:
	temp = bp_sw_hard_link_ComplexSequence(bp_sw_access_single_ProteinDB(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_sdb(obj,sdb)
	bp_sw_ProteinDB * obj
	bp_sw_SequenceDB * sdb
	CODE:
	RETVAL = bp_sw_replace_sdb_ProteinDB(obj,bp_sw_hard_link_SequenceDB(sdb));
	OUTPUT:
	RETVAL



bp_sw_SequenceDB *
sdb(obj)
	bp_sw_ProteinDB * obj
	INIT:
bp_sw_SequenceDB * temp;
	CODE:
	temp = bp_sw_hard_link_SequenceDB(bp_sw_access_sdb_ProteinDB(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_cses(obj,cses)
	bp_sw_ProteinDB * obj
	bp_sw_ComplexSequenceEvalSet * cses
	CODE:
	RETVAL = bp_sw_replace_cses_ProteinDB(obj,bp_sw_hard_link_ComplexSequenceEvalSet(cses));
	OUTPUT:
	RETVAL



bp_sw_ComplexSequenceEvalSet *
cses(obj)
	bp_sw_ProteinDB * obj
	INIT:
bp_sw_ComplexSequenceEvalSet * temp;
	CODE:
	temp = bp_sw_hard_link_ComplexSequenceEvalSet(bp_sw_access_cses_ProteinDB(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL




bp_sw_ProteinDB *
new(class)
	char * class
	PPCODE:
	bp_sw_ProteinDB * out;
	out = bp_sw_ProteinDB_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_ProteinDB * obj
	CODE:
	bp_sw_free_ProteinDB(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

bp_sw_ProteinDB *
new_ProteinDB_from_single_seq(seq)
	bp_sw_Sequence * seq
	CODE:
	RETVAL = bp_sw_new_ProteinDB_from_single_seq(seq);
	OUTPUT:
	RETVAL



bp_sw_ProteinDB *
single_fasta_ProteinDB(filename)
	char * filename
	CODE:
	RETVAL = bp_sw_single_fasta_ProteinDB(filename);
	OUTPUT:
	RETVAL



bp_sw_ProteinDB *
new_ProteinDB(seqdb,cses)
	bp_sw_SequenceDB * seqdb
	bp_sw_ComplexSequenceEvalSet * cses
	CODE:
	RETVAL = bp_sw_new_ProteinDB(seqdb,cses);
	OUTPUT:
	RETVAL





MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

boolean
write_pretty_str_align(alb,qname,query,tname,target,name,main,ofp)
	bp_sw_AlnBlock * alb
	char * qname
	char * query
	char * tname
	char * target
	int name
	int main
	FILE * ofp
	CODE:
	RETVAL = bp_sw_write_pretty_str_align(alb,qname,query,tname,target,name,main,ofp);
	OUTPUT:
	RETVAL



boolean
write_pretty_seq_align(alb,q,t,name,main,ofp)
	bp_sw_AlnBlock * alb
	bp_sw_Sequence * q
	bp_sw_Sequence * t
	int name
	int main
	FILE * ofp
	CODE:
	RETVAL = bp_sw_write_pretty_seq_align(alb,q,t,name,main,ofp);
	OUTPUT:
	RETVAL



boolean
write_pretty_Protein_align(alb,q,t,name,main,ofp)
	bp_sw_AlnBlock * alb
	bp_sw_Protein * q
	bp_sw_Protein * t
	int name
	int main
	FILE * ofp
	CODE:
	RETVAL = bp_sw_write_pretty_Protein_align(alb,q,t,name,main,ofp);
	OUTPUT:
	RETVAL





MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::Sequence

void
uppercase(seq)
	bp_sw_Sequence * seq
	CODE:
	bp_sw_uppercase_Sequence(seq);



boolean
force_to_dna(seq,fraction)
	bp_sw_Sequence * seq
	double fraction
	CODE:
	RETVAL = bp_sw_force_to_dna_Sequence(seq,fraction,NULL);
	OUTPUT:
	RETVAL



boolean
is_reversed(seq)
	bp_sw_Sequence * seq
	CODE:
	RETVAL = bp_sw_is_reversed_Sequence(seq);
	OUTPUT:
	RETVAL

bp_sw_Sequence *
revcomp(seq)
	bp_sw_Sequence * seq
	CODE:
	RETVAL = bp_sw_reverse_complement_Sequence(seq);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
magic_trunc(seq,start,end)
	bp_sw_Sequence * seq
	int start
	int end
	CODE:
	RETVAL = bp_sw_magic_trunc_Sequence(seq,start,end);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
trunc(seq,start,end)
	bp_sw_Sequence * seq
	int start
	int end
	CODE:
	RETVAL = bp_sw_trunc_Sequence(seq,start,end);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
read_fasta_file_Sequence(filename)
	char * filename
	CODE:
	RETVAL = bp_sw_read_fasta_file_Sequence(filename);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
read_Sequence_EMBL_seq(buffer,maxlen,ifp)
	char * buffer
	int maxlen
	FILE * ifp
	CODE:
	RETVAL = bp_sw_read_Sequence_EMBL_seq(buffer,maxlen,ifp);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
read_fasta_Sequence(ifp)
	FILE * ifp
	CODE:
	RETVAL = bp_sw_read_fasta_Sequence(ifp);
	OUTPUT:
	RETVAL



void
show_debug(seq,start,end,ofp)
	bp_sw_Sequence * seq
	int start
	int end
	FILE * ofp
	CODE:
	bp_sw_show_Sequence_residue_list(seq,start,end,ofp);



void
write_fasta(seq,ofp)
	bp_sw_Sequence * seq
	FILE * ofp
	CODE:
	bp_sw_write_fasta_Sequence(seq,ofp);



void
validate(seq)
	bp_sw_Sequence * seq
	CODE:
	bp_sw_make_len_type_Sequence(seq);



bp_sw_Sequence *
hard_link_Sequence(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_hard_link_Sequence(obj);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
alloc()
	CODE:
	RETVAL = bp_sw_Sequence_alloc();
	OUTPUT:
	RETVAL



boolean
set_name(obj,name)
	bp_sw_Sequence * obj
	char * name
	CODE:
	RETVAL = bp_sw_replace_name_Sequence(obj,bp_sw_stringalloc(name));
	OUTPUT:
	RETVAL



char *
name(obj)
	bp_sw_Sequence * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_name_Sequence(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_seq(obj,seq)
	bp_sw_Sequence * obj
	char * seq
	CODE:
	RETVAL = bp_sw_replace_seq_Sequence(obj,bp_sw_stringalloc(seq));
	OUTPUT:
	RETVAL



char *
seq(obj)
	bp_sw_Sequence * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_seq_Sequence(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_len(obj,len)
	bp_sw_Sequence * obj
	int len
	CODE:
	RETVAL = bp_sw_replace_len_Sequence(obj,len);
	OUTPUT:
	RETVAL



int
len(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_access_len_Sequence(obj);
	OUTPUT:
	RETVAL



boolean
set_maxlen(obj,maxlen)
	bp_sw_Sequence * obj
	int maxlen
	CODE:
	RETVAL = bp_sw_replace_maxlen_Sequence(obj,maxlen);
	OUTPUT:
	RETVAL



int
maxlen(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_access_maxlen_Sequence(obj);
	OUTPUT:
	RETVAL



boolean
set_offset(obj,offset)
	bp_sw_Sequence * obj
	int offset
	CODE:
	RETVAL = bp_sw_replace_offset_Sequence(obj,offset);
	OUTPUT:
	RETVAL



int
offset(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_access_offset_Sequence(obj);
	OUTPUT:
	RETVAL



boolean
set_end(obj,end)
	bp_sw_Sequence * obj
	int end
	CODE:
	RETVAL = bp_sw_replace_end_Sequence(obj,end);
	OUTPUT:
	RETVAL



int
end(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_access_end_Sequence(obj);
	OUTPUT:
	RETVAL



boolean
set_type(obj,type)
	bp_sw_Sequence * obj
	int type
	CODE:
	RETVAL = bp_sw_replace_type_Sequence(obj,type);
	OUTPUT:
	RETVAL



int
type(obj)
	bp_sw_Sequence * obj
	CODE:
	RETVAL = bp_sw_access_type_Sequence(obj);
	OUTPUT:
	RETVAL




bp_sw_Sequence *
new(class)
	char * class
	PPCODE:
	bp_sw_Sequence * out;
	out = bp_sw_Sequence_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_Sequence * obj
	CODE:
	bp_sw_free_Sequence(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

char *
Sequence_type_to_string(type)
	int type
	CODE:
	RETVAL = bp_sw_Sequence_type_to_string(type);
	OUTPUT:
	RETVAL



bp_sw_Sequence *
new_Sequence_from_strings(name,seq)
	char * name
	char * seq
	CODE:
	RETVAL = bp_sw_new_Sequence_from_strings(name,seq);
	OUTPUT:
	RETVAL





MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::SequenceDB

bp_sw_SequenceDB *
single_fasta_SequenceDB(filename)
	char * filename
	CODE:
	RETVAL = bp_sw_single_fasta_SequenceDB(filename);
	OUTPUT:
	RETVAL



bp_sw_SequenceDB *
hard_link_SequenceDB(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_hard_link_SequenceDB(obj);
	OUTPUT:
	RETVAL



bp_sw_SequenceDB *
SequenceDB_alloc_std()
	CODE:
	RETVAL = bp_sw_SequenceDB_alloc_std();
	OUTPUT:
	RETVAL



boolean
set_name(obj,name)
	bp_sw_SequenceDB * obj
	char * name
	CODE:
	RETVAL = bp_sw_replace_name_SequenceDB(obj,bp_sw_stringalloc(name));
	OUTPUT:
	RETVAL



char *
name(obj)
	bp_sw_SequenceDB * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_name_SequenceDB(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



bp_sw_FileSource *
fs(obj,i)
	bp_sw_SequenceDB * obj
	int i
	INIT:
bp_sw_FileSource * temp;
	CODE:
	temp = bp_sw_hard_link_FileSource(bp_sw_access_fs_SequenceDB(obj,i));
	RETVAL = temp;
	OUTPUT:
	RETVAL



int
length_fs(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_length_fs_SequenceDB(obj);
	OUTPUT:
	RETVAL



int
flush_fs(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_flush_SequenceDB(obj);
	OUTPUT:
	RETVAL



boolean
add_fs(obj,add)
	bp_sw_SequenceDB * obj
	bp_sw_FileSource * add
	CODE:
	RETVAL = bp_sw_add_SequenceDB(obj,bp_sw_hard_link_FileSource(add));
	OUTPUT:
	RETVAL



boolean
set_current_source(obj,current_source)
	bp_sw_SequenceDB * obj
	int current_source
	CODE:
	RETVAL = bp_sw_replace_current_source_SequenceDB(obj,current_source);
	OUTPUT:
	RETVAL



int
current_source(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_access_current_source_SequenceDB(obj);
	OUTPUT:
	RETVAL



boolean
set_current_file(obj,current_file)
	bp_sw_SequenceDB * obj
	FILE * current_file
	CODE:
	RETVAL = bp_sw_replace_current_file_SequenceDB(obj,current_file);
	OUTPUT:
	RETVAL



FILE *
current_file(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_access_current_file_SequenceDB(obj);
	OUTPUT:
	RETVAL



boolean
set_sequence_no(obj,sequence_no)
	bp_sw_SequenceDB * obj
	int sequence_no
	CODE:
	RETVAL = bp_sw_replace_sequence_no_SequenceDB(obj,sequence_no);
	OUTPUT:
	RETVAL



int
sequence_no(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_access_sequence_no_SequenceDB(obj);
	OUTPUT:
	RETVAL



boolean
set_byte_position(obj,byte_position)
	bp_sw_SequenceDB * obj
	int byte_position
	CODE:
	RETVAL = bp_sw_replace_byte_position_SequenceDB(obj,byte_position);
	OUTPUT:
	RETVAL



int
byte_position(obj)
	bp_sw_SequenceDB * obj
	CODE:
	RETVAL = bp_sw_access_byte_position_SequenceDB(obj);
	OUTPUT:
	RETVAL




bp_sw_SequenceDB *
new(class)
	char * class
	PPCODE:
	bp_sw_SequenceDB * out;
	out = bp_sw_SequenceDB_alloc_std();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_SequenceDB * obj
	CODE:
	bp_sw_free_SequenceDB(obj);

void
each_fs(obj)
	bp_sw_SequenceDB * obj
	PPCODE:
	int i=0;
	int len;
	SV* temp;
	len = bp_sw_length_fs_SequenceDB(obj);
	for(i=0;i<len;i++){
	  temp = sv_newmortal();
	  sv_setref_pv(temp, "Bio::Ext::Align::FileSource", (void*) (bp_sw_hard_link_FileSource(bp_sw_access_fs_SequenceDB(obj,i))));
	  XPUSHs(temp);
	  }
	XSRETURN(len);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align::FileSource

bp_sw_FileSource *
hard_link_FileSource(obj)
	bp_sw_FileSource * obj
	CODE:
	RETVAL = bp_sw_hard_link_FileSource(obj);
	OUTPUT:
	RETVAL



bp_sw_FileSource *
alloc()
	CODE:
	RETVAL = bp_sw_FileSource_alloc();
	OUTPUT:
	RETVAL



boolean
set_filename(obj,filename)
	bp_sw_FileSource * obj
	char * filename
	CODE:
	RETVAL = bp_sw_replace_filename_FileSource(obj,bp_sw_stringalloc(filename));
	OUTPUT:
	RETVAL



char *
filename(obj)
	bp_sw_FileSource * obj
	INIT:
	char * temp;
	CODE:
	temp = bp_sw_stringalloc(bp_sw_access_filename_FileSource(obj));
	RETVAL = temp;
	OUTPUT:
	RETVAL



boolean
set_input(obj,input)
	bp_sw_FileSource * obj
	FILE * input
	CODE:
	RETVAL = bp_sw_replace_input_FileSource(obj,input);
	OUTPUT:
	RETVAL



FILE *
input(obj)
	bp_sw_FileSource * obj
	CODE:
	RETVAL = bp_sw_access_input_FileSource(obj);
	OUTPUT:
	RETVAL



boolean
set_format(obj,format)
	bp_sw_FileSource * obj
	int format
	CODE:
	RETVAL = bp_sw_replace_format_FileSource(obj,format);
	OUTPUT:
	RETVAL



int
format(obj)
	bp_sw_FileSource * obj
	CODE:
	RETVAL = bp_sw_access_format_FileSource(obj);
	OUTPUT:
	RETVAL



boolean
set_type(obj,type)
	bp_sw_FileSource * obj
	int type
	CODE:
	RETVAL = bp_sw_replace_type_FileSource(obj,type);
	OUTPUT:
	RETVAL



int
type(obj)
	bp_sw_FileSource * obj
	CODE:
	RETVAL = bp_sw_access_type_FileSource(obj);
	OUTPUT:
	RETVAL




bp_sw_FileSource *
new(class)
	char * class
	PPCODE:
	bp_sw_FileSource * out;
	out = bp_sw_FileSource_alloc();
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0),class,(void*)out);
	XSRETURN(1);

void
DESTROY(obj)
	bp_sw_FileSource * obj
	CODE:
	bp_sw_free_FileSource(obj);



MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align


MODULE = Bio::Ext::Align PACKAGE = Bio::Ext::Align

bp_sw_AlnBlock *
Align_strings_ProteinSmithWaterman(one,two,comp,gap,ext)
	char * one
	char * two
	bp_sw_CompMat * comp
	int gap
	int ext
	CODE:
	RETVAL = bp_sw_Align_strings_ProteinSmithWaterman(one,two,comp,gap,ext);
	OUTPUT:
	RETVAL



bp_sw_AlnBlock *
Align_Sequences_ProteinSmithWaterman(one,two,comp,gap,ext)
	bp_sw_Sequence * one
	bp_sw_Sequence * two
	bp_sw_CompMat * comp
	int gap
	int ext
	CODE:
	RETVAL = bp_sw_Align_Sequences_ProteinSmithWaterman(one,two,comp,gap,ext);
	OUTPUT:
	RETVAL



bp_sw_AlnBlock *
Align_Proteins_SmithWaterman(one,two,comp,gap,ext)
	bp_sw_Protein * one
	bp_sw_Protein * two
	bp_sw_CompMat * comp
	int gap
	int ext
	CODE:
	RETVAL = bp_sw_Align_Proteins_SmithWaterman(one,two,comp,gap,ext);
	OUTPUT:
	RETVAL





