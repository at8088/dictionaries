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


bool contains_iter(dico d, char * word, unsigned size);
/* size est la taille du mot word */
bool add_iter(dico d, char * word, unsigned size);
bool remove_iter(dico d, char * word, unsigned size);

bool contains_rec(dico d, char * word, unsigned size);
bool add_rec(dico d, char * word, unsigned size);
bool remove_rec(dico d, char * word, unsigned size);

unsigned nb_words(dico d);
void print_dico(dico d);

#endif






