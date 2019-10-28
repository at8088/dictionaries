#include "fct-primitives.h"


unsigned get_index(char c) { return c - 'a'; }
char get_char(unsigned index) { return index + 'a'; }

/** cette fonction alloue la memoire pour un dico ie un tableau de tree 
 * et le renvoie. 
*/
dico create_dico(){
    dico d = calloc(NB_KEYS , sizeof(tree));
    if (d == NULL){
        fprintf(stderr,"Echec d'allocation de memoire");
    }
    return d;
}


void destroy_dico(dico * d){
    if( *d != NULL){
        dico p = NULL;
        for (int i = 0; i < NB_KEYS; i++){
            if((*d)[i] != NULL){
                p = (*d)[i]->children;
                free((*d)[i]);
                (*d)[i]=NULL;
                destroy_dico(&p);
            }
        }
        free(*d);
        *d = NULL;
    }
}



/** mesures */
unsigned nb_children(tree t){

}
unsigned nb_nodes(dico d){

}
unsigned height(dico d){

}

/** routine d'impression : en prefixe */
void print_prefix(dico d){

}

/** egalite structurelle */
bool equals(dico d1, dico d2){

}