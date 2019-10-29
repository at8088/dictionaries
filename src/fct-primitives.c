#include "fct-primitives.h"


unsigned get_index(char c) { return c - 'a'; }
char get_char(unsigned index) { return index + 'a'; }

unsigned max(unsigned *t){
    unsigned max = t[0];
    for (int i = 0; i < NB_KEYS; i++){
        if(t[i]>max){
            max=t[i];
        }
    }
    return max;
}
/** cette fonction alloue la memoire pour un dico ie un tableau de tree 
 * et le renvoie. 
*/
dico create_dico(){
    dico d = calloc(NB_KEYS , sizeof(tree));
    if (d == NULL){
        fprintf(stderr,"Echec d'allocation de memoire");
    }
    for (int i = 0; i < NB_KEYS; i++)
    {
        d[i]=NULL;
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

bool is_empty(dico d){
    if (d==NULL){
        return true;
    }else{
        for (int i = 0; i < NB_KEYS; i++)
        {
            if(d[i]!=NULL){
                return false;
            }
        }
        return true;
        
    }
    
}



/** mesures */
unsigned nb_children(tree t){

}
unsigned nb_nodes(dico d){

}
unsigned height(dico d){
    if (is_empty(d)){
        return 0;
    }else{
        unsigned* heights = calloc(NB_KEYS,sizeof(unsigned));
        for (int i = 0; i < NB_KEYS; i++){
            if (d[i]!=NULL){
                heights[i]=1+height(d[i]->children);
            }
        }
        unsigned h = max(heights);
        free(heights);
        return h;
    }
}
int nbr_decalage = 0;

/** routine d'impression : en prefixe */
void print_prefix(dico d){
    if(!is_empty(d)){
        char *s=calloc(nbr_decalage,sizeof(char));
        memset(s,'+',nbr_decalage);
        printf("%s",s);
        free(s);
        
        for (int i = 0; i < NB_KEYS; i++){
            if(d[i]!=NULL){
                int mem_nbr_decalage=nbr_decalage;
                printf("%c",d[i]->first);
                if(d[i]->end_of_word){
                    printf("*");
                }
                puts("");
                nbr_decalage++;
                print_prefix(d[i]->children);
                nbr_decalage=mem_nbr_decalage;
            }
        }
        
    }
}

/** egalite structurelle */
bool equals(dico d1, dico d2){

}