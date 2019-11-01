#include "fct-primitives.h"

/*************versions iteratives*********/


bool contains_iter(dico d, char * word, unsigned size){

}
/* size est la taille du mot word */
bool add_iter(dico d, char * word, unsigned size){

}
bool remove_iter(dico d, char * word, unsigned size){

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

}
bool remove_rec(dico d, char * word, unsigned size){
    
}