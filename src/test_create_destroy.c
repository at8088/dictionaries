
#include "fct-primitives.h"

int main(int argc, char const *argv[]){
    dico d = create_dico();
    d[2]=calloc(1,sizeof(struct node));
    d[2]->first = 'c';
    d[2]->children = create_dico();
    destroy_dico(&d);
    return EXIT_SUCCESS;
}
