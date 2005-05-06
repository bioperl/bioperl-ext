
#ifdef __cplusplus
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifdef __cplusplus
}
#endif

#include "hmm.h"

MODULE = Bio::Ext::HMM PACKAGE = Bio::Ext::HMM

void
HMM_statistical_training(class, hmm, obs, hs)
        char * class
        HMM * hmm
        SV * obs
        SV * hs
        PPCODE:
        AV * obs_av = (AV *) SvRV(obs);
        AV * hs_av = (AV *) SvRV(hs);
        int i;
        int avlen = av_len(obs_av);
        char ** obs_ar = (char **) malloc(avlen*sizeof(char *));
        char ** hs_ar = (char **) malloc(avlen*sizeof(char *));
        if (obs_ar == NULL || hs_ar == NULL)
           croak("Can't allocate memory for observation and/or state arrays!\n");
        for (i = 0; i < avlen; ++i) {
           obs_ar[i] = (char *) SvPV(*av_fetch(obs_av, i, 0), PL_na);   
           hs_ar[i] = (char *) SvPV(*av_fetch(hs_av, i, 0), PL_na);   
        }
        state_est(hmm, obs_ar, hs_ar, avlen);
        free(obs_ar);
        free(hs_ar);

double
HMM_likelihood(class, hmm, seq)
        char * class
        HMM * hmm
        char * seq
        CODE:
        RETVAL = Palpha(hmm, seq);
        OUTPUT:
        RETVAL

void
HMM_baum_welch_training(class, hmm, obs)
        char * class
        HMM * hmm
        SV * obs
        PPCODE:
        AV * obs_av = (AV *) SvRV(obs);
        int i;
        int avlen = av_len(obs_av);
        char ** obs_ar = (char **) malloc(avlen*sizeof(char *));
        if (obs_ar == NULL)
           croak("Can't allocate memory for observation arrays!\n");
        for (i = 0; i < avlen; ++i) {
           obs_ar[i] = (char *) SvPV(*av_fetch(obs_av, i, 0), PL_na);   
        }
        baum_welch(hmm, obs_ar, avlen);
        free(obs_ar);

SV *
HMM_viterbi(class, hmm, obs)
        char * class
        HMM * hmm
        char * obs
        PPCODE:
        SV * sv;
        char * hss = (char *) malloc(strlen(obs)*sizeof(char));
        if (hss == NULL)
           croak("Can't allocate memory for hidden state sequence!\n");
        viterbi(hmm, hss, obs);
        sv = newSVpv(hss, strlen(hss));
        free(hss);
        PUSHs(sv_2mortal(sv));
        

MODULE = Bio::Ext::HMM PACKAGE = Bio::Ext::HMM::HMM

HMM *
new(class, symbols, states)
        char * class
        char * symbols
        char * states
        PPCODE:
        HMM * out;
        out = HMM_new(symbols, states);
        ST(0) = sv_newmortal();
        sv_setref_pv(ST(0), class, (void *) out);
        XSRETURN(1);

double
get_init_entry(class, hmm, state)
        char * class
        HMM * hmm
        char * state
        CODE:
        RETVAL = HMM_get_init_entry(hmm, state);
        OUTPUT:
        RETVAL

void
set_init_entry(class, hmm, state, val)
        char * class
        HMM * hmm
        char * state
        double val
        CODE:
        HMM_set_init_entry(hmm, state, val);

double
get_a_entry(class, hmm, state1, state2)
        char * class
        HMM * hmm
        char * state1
        char * state2
        CODE:
        RETVAL = HMM_get_a_entry(hmm, state1, state2);
        OUTPUT:
        RETVAL

void
set_a_entry(class, hmm, state1, state2, val)
        char * class
        HMM * hmm
        char * state1
        char * state2
        double val
        CODE:
        HMM_set_a_entry(hmm, state1, state2, val);

double
get_e_entry(class, hmm, state, symbol)
        char * class
        HMM * hmm
        char * state
        char * symbol 
        CODE:
        RETVAL = HMM_get_e_entry(hmm, state, symbol);
        OUTPUT:
        RETVAL

void
set_e_entry(class, hmm, state, symbol, val)
        char * class
        HMM * hmm
        char * state
        char * symbol
        double val 
        CODE:
        HMM_set_e_entry(hmm, state, symbol, val);

void
DESTROY(obj)
        HMM * obj
        PPCODE:
        int i;
        free(obj->init);
        for (i = 0; i < obj->N; ++i)
           free(obj->a_mat[i]);
        free(obj->a_mat);
        for (i = 0; i < obj->N; ++i)
           free(obj->e_mat[i]);
        free(obj->e_mat);

