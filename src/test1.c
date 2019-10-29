
#include "fct-primitives.h"

int main(int argc, char const *argv[]){
    dico d = create_dico();
    d[2]=calloc(1,sizeof(struct node));
    d[2]->first = 'c';
    d[2]->children = create_dico();
    d[2]->children[5]=calloc(1,sizeof(struct node));
    d[2]->children[5]->first='r';
    d[2]->children[5]->children=create_dico();
    d[16]=calloc(1,sizeof(struct node));
    d[16]->first = 'm';
    d[16]->children = create_dico();
    d[16]->children[0]=calloc(1,sizeof(struct node));
    d[16]->children[0]->first ='t';
    d[16]->children[0]->children=create_dico(); 
    d[2]->children[5]->children[6]=calloc(1,sizeof(struct node));
    d[2]->children[5]->children[6]->first='s';
    d[2]->children[5]->children[6]->children=create_dico();
    unsigned h = height(d);
    printf("h=%u\n",h);
    destroy_dico(&d);

    return EXIT_SUCCESS;
}
