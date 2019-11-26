#include "fct-primitives.h"
#define NB_KEYS 26

struct iterator_info {
    tree t;
    int index_word;
};

struct _iterator {
    char * word;
    struct iterator_info * stack;
    int index_stack;
};

typedef struct _iterator iterator;


iterator * start_iterator(dico d);
void destroy_iterator(iterator ** it);
bool has_next(iterator * it);
char * next (iterator * it);

