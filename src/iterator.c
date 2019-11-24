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
    it->word = calloc(h,sizeof(char));
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
      return it->index_stack != -1 ;
    }else{
      return false;
    }
}

char * next (iterator * it){

  int index_stack_init ; 
  int estampille;

  while (true){



    index_stack_init = it->index_stack;
    it->index_stack --;
    estampille = it->stack[index_stack_init].index_word;
    it->word[estampille] = it->stack[index_stack_init].t->first;
    dico fils_de_racine = it->stack[index_stack_init].t->children;

  
    for(int i=NB_KEYS-1; i>=0 ; i--){
      if (fils_de_racine[i]){
        it->index_stack++;
        it->stack[it->index_stack].t=(tree) fils_de_racine[i];
        it->stack[it->index_stack].index_word = estampille+1;
      }
    }

    for (int i = estampille + 1; i < strlen(it->word); i++){
      it->word[i]=0;
    }

    if (it->stack[index_stack_init].t->end_of_word){
      printf("index = %d\n",it->index_stack);
      break;
    }
  } 
  if (it->index_stack != -1 && it->stack[it->index_stack].t->end_of_word) 
  {
    it->word[it->stack[it->index_stack].index_word] = it->stack[it->index_stack].t->first ;
  }
  return  it->word;  


}
