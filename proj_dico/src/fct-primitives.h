#ifndef FCT_PRIMITIVES_H
#define FCT_PRIMITIVES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    char first;
    bool end_of_word;
    struct node ** children;
};

typedef struct node * tree;
typedef struct node ** dico;

#define NB_KEYS 26


unsigned get_index(char c);
char get_char(unsigned index);

/** construction / destruction */
dico create_dico();

void destroy_dico(dico * d);

/** mesures */
unsigned nb_children(tree t);
unsigned nb_nodes(dico d);
unsigned height(dico d);

/** routine d'impression : en prefixe */
void print_prefix(dico d);

/** egalite structurelle */
bool equals(dico d1, dico d2);




#endif






