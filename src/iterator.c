#include "iterator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

iterator * start_iterator(dico d){
  if(d==NULL) return NULL;
  else{
    unsigned int nbnodes = nb_nodes(d);
    unsigned int h = height(d);
    iterator* it = malloc(sizeof(iterator));
    it->word = (char*)calloc(h,sizeof(char));
    it->stack = malloc(nbnodes*sizeof(*it->stack));
    it->index_stack = -1;
    for(int i=0;i<NB_KEYS;i++){
      if(d[i]!=NULL) {
        it->index_stack ++ ;
        it->stack[it->index_stack].t = d[i];
        it->stack[it->index_stack].index_word = 0;
      }
    }
    return it ;
  }
}

void destroy_iterator(iterator ** it){
    if ((*it) != NULL){
        if ((*it)->stack ){
            free((*it)->stack);
            (*it)->stack = NULL;
        }
        free((*it)->word);
        (*it)->word = NULL;
        free(*it);
        *it=NULL;
    }
}

bool has_next(iterator *it){
    if (it){
      return it->index_stack > -1 ;
    }else{
      return false;
    }
}

void empiler_fils(iterator * it ,int estampille,dico fils){
  for(int i=NB_KEYS-1; i>=0 ; i--){
    if (fils[i]){
      it->index_stack++;
      it->stack[it->index_stack].t=(tree) fils[i];
      it->stack[it->index_stack].index_word = estampille+1;
    }
  }
}

char * next (iterator * it){
  int index_stack_init ; 
  dico fils_de_racine;
  int estampille ;
  // on sort si le dico fils ou si on rencontre une fin de mot
  while (!is_empty(it->stack[it->index_stack].t->children)){
    index_stack_init = it->index_stack;
    it->index_stack --;           // depilement
    estampille = it->stack[index_stack_init].index_word;
    it->word[estampille] = it->stack[index_stack_init].t->first;  // maj mot
    fils_de_racine = it->stack[index_stack_init].t->children;
    empiler_fils(it,estampille,fils_de_racine);     //empilement des fils
    if (it->stack[it->index_stack].t->end_of_word){
      break;
    }
  }  
  // depilement du caractere de fin de mot et empilement de ses fils
  if (it->index_stack != -1 ){ 
    // reinitialiser les cases du mot dont l'indice est plus grd que l'estampille.
    for (int i = it->stack[it->index_stack].index_word; i < sizeof(it->word); i++) it->word[i]=0;
    index_stack_init = it->index_stack;
    it->index_stack --;
    estampille = it->stack[index_stack_init].index_word;
    it->word[estampille] = it->stack[index_stack_init].t->first;
    fils_de_racine = it->stack[index_stack_init].t->children;
    empiler_fils(it,estampille,fils_de_racine);
  }
  return  it->word;  
}
