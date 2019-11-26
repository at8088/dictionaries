#include "fct-primitives.h"
#define TAILLE_MAX_MOT 30

extern bool is_empty(dico d);
/*************versions iteratives*********/
extern bool is_empty(dico d);

bool contains_iter(dico d, char * word, unsigned size){
  if(d==NULL) return 0;
  if(strlen(word)!=size) return 0;
  dico p =d;
  bool test=1;
  for(int i=0;i<size;i++){
    int indice=get_index(word[i]);
    if(p[indice]==NULL) {
      return 0;
    }
    else if(p[indice]->first!=word[i]) {
       return 0;
    }
    else if(i==size-1 && p[indice]->end_of_word == 0) return 0;

    else {
      p=p[indice]->children ;
    }
  }
  return test;
}

bool add_iter(dico d, char * word, unsigned size){
  if(strlen(word)!=size) return 0;
  if(!contains_iter(d,word,size)){
    if(d==NULL) d=create_dico();
    dico p=d;
    for(int i=0;i<size;i++){
      int indice=get_index(word[i]);
      if(p[indice]!=NULL) {
        if (i==size-1)  p[indice]->end_of_word =1;
        else p=p[indice]->children;
      }
      else {
        p[indice]=calloc(1,sizeof(struct node));
        p[indice]->first = word[i];
        p[indice]->end_of_word =0;
        if (i==size-1)  p[indice]->end_of_word =1;
        p[indice]->children = create_dico();
        p=p[indice]->children;
      }
    }
    return 1;
  }
  else return 0;
}

bool remove_iter(dico d, char * word, unsigned size){
  if(d==NULL) return 0;
  if(strlen(word)!=size) return 0;
  if(!contains_iter(d,word,size)) return 0;
  else {
    dico p=d;
    for(int i=0;i<size;i++){

      int indice=get_index(word[i]);
      dico temp=p[indice]->children;
      if((nb_words(temp)+(p[indice]->end_of_word==1))==1)
      {
        free(p[indice]);
        p[indice]=NULL;
      }
      if(i==size-1&&p[indice]) p[indice]->end_of_word=0;
      p=temp;
    }
    
  }
  return 1;
}


/*************versions recursives*********/

bool contains_rec(dico d, char * word, unsigned size){
    if (d!=NULL){
        if (size == 0 ){
            return true;
        }
        else if(d[get_index(*word)] != NULL  && d[get_index(*word)]->first==*word ){
            return contains_rec(d[get_index(*word)]->children,word+1,size-1);
        }else return false;
    }else{
      return false;
    }
}
bool add_rec(dico d, char * word, unsigned size){
    bool mot_ajoute=false;
    if (d!=NULL && *word != 0){
        if(d[get_index(*word)] == NULL){
            d[get_index(*word)]=calloc(1,sizeof(struct node));
            if (d[get_index(*word)]==NULL){
                fprintf(stderr,"Echec d'allocation memoire pour le mot %s\n",word);
            }
            d[get_index(*word)]->first=*word;
            d[get_index(*word)]->children=create_dico();
            if(*(word+1)==0) d[get_index(*word)]->end_of_word=true;
            mot_ajoute = true ;

        }
        add_rec(d[get_index(*word)]->children,word+1,size-1);
    }
    return mot_ajoute;
    
}


bool remove_rec(dico d, char * word, unsigned size){
  if (strlen(word) != size)
  {
    return false;
  }
  
  bool mot_supprime=false;
  if (d!=NULL  && size >0 ){
    if(d[get_index(*word)]!= NULL){
      if ((nb_words(d[get_index(*word)]->children) +(int) d[get_index(*word)]->end_of_word )== 1 ){
          dico p = d[get_index(*word)]->children;
          free(d[get_index(*word)]);
          d[get_index(*word)]=NULL;
          remove_rec(p,word+1,size-1);
          destroy_dico(&p);
          mot_supprime = true;
      }else{
          if (d[get_index(word[size-1])]!=NULL) d[get_index(word[size-1])]->end_of_word=false;
          remove_rec(d[get_index(*word)]->children,word+1,size-1);
      }
    }
  }
  return mot_supprime;
    
}


unsigned nb_words(dico d){
  if(d!=NULL){
    int nbr_mot=0;
    for(int i = 0 ; i<NB_KEYS ; i++){
      if(d[i]!=NULL){
        if(d[i]->end_of_word){
          nbr_mot+=1;
        }
        nbr_mot+=+nb_words(d[i]->children);
      }  
    }
    return nbr_mot;
  }else{
    return 0;
  }
}


char  str[TAILLE_MAX_MOT]; 
int indice = 0;


void print_dico(dico d){
  if (!is_empty(d)){
    for(int i=0; i<NB_KEYS ; i++){
      if (d[i]!=NULL){
        for(int j=indice; j<TAILLE_MAX_MOT; j++){
            str[j]=0;
        }
        str[indice]=d[i]->first;
        indice++;
        if (d[i]->end_of_word){
          printf("%s,",str);
        }
        print_dico(d[i]->children);
        indice--;
      }
    }
  }
}