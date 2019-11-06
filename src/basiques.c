#include "fct-primitives.h"


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
      if(p[indice]!=NULL) p=p[indice]->children;
      else {
        p[indice]=calloc(1,sizeof(struct node));
        p[indice]->first = word[i];
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
      if(nb_nodes(temp)==size-(i+1)){
        p[indice]=NULL;
      }
      p=temp;
    }
  }
  return 1;
}


/*************versions recursives*********/

bool contains_rec(dico d, char * word, unsigned size){
    if (d!=NULL){
        if (size == 0 || *word == 0){
            return true;
        }
        else if(d[get_index(*word)] != NULL  && d[get_index(*word)]->first==*word ){
            return contains_rec(d[get_index(*word)]->children,word+1,size-1);
        }else return false;
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

/** faut s'arreter quand size ==0 pas quand *word==0
 * size doit etre exactement la taille du mot
*/
bool remove_rec(dico d, char * word, unsigned size){
    bool mot_supprime=false;
    if (d!=NULL && size>0 && d[get_index(*word)] != NULL){
        if (nb_nodes(d[get_index(*word)]->children) + 1== size ){
            dico p = d[get_index(*word)]->children;
            free(d[get_index(*word)]);
            d[get_index(*word)]=NULL;
            remove_rec(p,word+1,size-1);
            mot_supprime = true;
        }else{
            remove_rec(d[get_index(*word)]->children,word+1,size-1);
        }
       // d[get_index(*word)]->end_of_word =  ? false:true;
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
void print_dico(dico d){
  if (d!=NULL){
    
  }
}