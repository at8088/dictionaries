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
    it->word = malloc(h*sizeof(char));
    it->stack = malloc(nbnodes*sizeof(*it->stack));
    it->index_stack = 0;
    for(int i=0;i<NB_KEYS;i++){
      if(d[i]!=NULL) {
        it->stack[it->index_stack].t = d[i];
        it->stack[it->index_stack].index_word = 0;
        it->index_stack ++ ;
      }
    }
    return it ;
  }


void destroy_iterator(iterator ** it){
    if (*it != NULL){
        if (*it->stack ){
            free(*it->stack);
            *it->stack == NULL;
        }
        free(*it->word);
        *it->word = NULL;
        free(*it);
        *it=NULL;
    }
}

bool has_next(iterator *it){
    return it->index_stack >= 0 ;
}
