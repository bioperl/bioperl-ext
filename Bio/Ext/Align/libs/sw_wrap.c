#ifdef _cplusplus
extern "C" {
#endif
#include "sw_wrap.h"

/* Function:  Align_strings_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most *stupidly* abstracted view of two sequences
 *             getting aligned, being two strings.
 *
 *             It would be much better if you used Sequence objects or Protein
 *             objects to carry the proteins.
 *
 *
 * Arg:         one [UNKN ] string of the first sequence [char *]
 * Arg:         two [UNKN ] string of the second sequence [char *]
 * Arg:        comp [UNKN ] Comparison Matrix [CompMat *]
 * Arg:         gap [UNKN ] gap penalty [int]
 * Arg:         ext [UNKN ] extension penalty [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
# line 31 "sw_wrap.dy"
AlnBlock * Align_strings_ProteinSmithWaterman(char * one,char * two,CompMat * comp,int gap,int ext)
{
  Sequence * one_s;
  Sequence * two_s;
  AlnBlock * out;

  /* error check the strings? */

  one_s = new_Sequence_from_strings(NULL,one);
  if( one_s == NULL ) {
    warn("Cannot make new sequence...\n");
    return NULL;
  }

  two_s = new_Sequence_from_strings(NULL,two);
  if( two_s == NULL ) {
    warn("Cannot make new sequence...\n");
    return NULL;
  }

  out = Align_Sequences_ProteinSmithWaterman(one_s,two_s,comp,gap,ext);

  free_Sequence(one_s);
  free_Sequence(two_s);

  return out;
}
  

/* Function:  Align_Sequences_ProteinSmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This function is a mid-level abstraction of
 *             comparing two sequences, which could be
 *             generic types (eg DNA!). This is tested
 *             for and warnings are given but the alignment
 *             is still calculated. To prevent this test
 *             warning either make sure the Sequence types
 *             are set to PROTEIN or, better still, use the
 *             high level abstraction Align_Proteins_SmithWaterman
 *
 *             Otherwise this performs a standard smith waterman
 *             protein alignment...
 *
 *             To display the alignment use  write_pretty_seq_align
 *
 *
 * Arg:         one [READ ] First sequence to compare [Sequence *]
 * Arg:         two [READ ] Second sequecne to compare [Sequence *]
 * Arg:        comp [READ ] Comparison matrix to use [CompMat *]
 * Arg:         gap [UNKN ] gap penalty. Must be negative or 0 [int]
 * Arg:         ext [UNKN ] ext penalty. Must be negative or 0 [int]
 *
 * Return [OWNER]  new AlnBlock structure representing the alignment [AlnBlock *]
 *
 */
# line 82 "sw_wrap.dy"
AlnBlock * Align_Sequences_ProteinSmithWaterman(Sequence * one,Sequence * two,CompMat * comp,int gap,int ext)
{
  AlnBlock * out = NULL;
  ComplexSequenceEvalSet * evalfunc = NULL;
  ComplexSequence * query_cs = NULL;
  ComplexSequence * target_cs = NULL;
  PackAln * pal = NULL;

  if( one == NULL || two == NULL || comp == NULL ) {
    warn("Passed in NULL objects into Align_Sequences_ProteinSmithWaterman!");
    return NULL;
  }

  if( one->type != SEQUENCE_PROTEIN ) {
    warn("Sequence %s is not typed as protein... ignoring!\n",one->name);
  }

  if( two->type != SEQUENCE_PROTEIN ) {
    warn("Sequence %s is not typed as protein... ignoring!\n",two->name);
  }


  if( gap > 0 || ext > 0 ) {
    warn("Gap penalties %d,%d only make sense if they are negative",gap,ext);
    return NULL;
  }

  evalfunc = default_aminoacid_ComplexSequenceEvalSet();
  
  query_cs = new_ComplexSequence(one,evalfunc);
  if( query_cs == NULL )
    goto cleanup;
  target_cs = new_ComplexSequence(two,evalfunc);
  if( target_cs == NULL )
    goto cleanup;

  pal = PackAln_bestmemory_ProteinSW(query_cs,target_cs,comp,gap,ext,NULL);
  if( pal == NULL ) 
    goto cleanup;

  out = convert_PackAln_to_AlnBlock_ProteinSW(pal);
  
  goto cleanup;

  cleanup :

    if( query_cs != NULL )
      free_ComplexSequence(query_cs);

  if( target_cs != NULL )
    free_ComplexSequence(target_cs);

  if( pal != NULL )
    free_PackAln(pal);

  if( evalfunc != NULL )
    free_ComplexSequenceEvalSet(evalfunc);

  return out;

}


/* Function:  Align_Proteins_SmithWaterman(one,two,comp,gap,ext)
 *
 * Descrip:    This is the most correct way of aligning two Proteins,
 *             using Protein objects, which can be assummed to be
 *             proteins with no objections
 *
 *             To display the alignment use write_pretty_Protein_align
 *
 *
 *
 * Arg:         one [UNKN ] Protein to align [Protein *]
 * Arg:         two [UNKN ] Protein to align [Protein *]
 * Arg:        comp [UNKN ] Comparison Matrix [CompMat *]
 * Arg:         gap [UNKN ] gap penalty [int]
 * Arg:         ext [UNKN ] extension penalty [int]
 *
 * Return [UNKN ]  Undocumented return value [AlnBlock *]
 *
 */
# line 159 "sw_wrap.dy"
AlnBlock * Align_Proteins_SmithWaterman(Protein * one,Protein * two,CompMat * comp,int gap,int ext)
{
  if( one == NULL || two == NULL || comp == NULL ) {
    warn("Passed in NULL objects into Align_Proteins_SmithWaterman!");
    return NULL;
  }
    
  
  return Align_Sequences_ProteinSmithWaterman(one->baseseq,two->baseseq,comp,gap,ext);
}





# line 172 "sw_wrap.c"

#ifdef _cplusplus
}
#endif
