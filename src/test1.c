
#include "fct-primitives.h"

int main(int argc, char const *argv[]){
    dico d = create_dico();
    d[3]=calloc(1,sizeof(struct node));
    d[3]->first = 'h';
    d[3]->children = create_dico();
    d[3]->children[12]=calloc(1,sizeof(struct node));
    d[3]->children[12]->first='i';
    d[3]->children[12]->end_of_word=true;
    d[3]->children[12]->children=create_dico();
    d[2]=calloc(1,sizeof(struct node));
    d[2]->first = 'c';
    d[2]->children = create_dico();
    d[2]->children[5]=calloc(1,sizeof(struct node));
    d[2]->children[5]->first='h';
    d[2]->children[5]->children=create_dico();
    d[16]=calloc(1,sizeof(struct node));
    d[16]->first = 'm';
    d[16]->children = create_dico();
    d[16]->children[0]=calloc(1,sizeof(struct node));
    d[16]->children[0]->first ='o';
    d[16]->children[0]->end_of_word=true;
    d[16]->children[0]->children=create_dico(); 
    d[16]->children[0]->children[5]=calloc(1,sizeof(struct node));
    d[16]->children[0]->children[5]->first='i';
    d[16]->children[0]->children[5]->end_of_word=true;
    d[2]->children[5]->children[6]=calloc(1,sizeof(struct node));
    d[2]->children[5]->children[6]->first='a';
    d[2]->children[5]->children[6]->children=create_dico();
    d[2]->children[5]->children[6]->children[20]=calloc(1,sizeof(struct node));
    d[2]->children[5]->children[6]->children[20]->first='t';
    d[2]->children[5]->children[6]->children[20]->end_of_word=true;
    d[2]->children[5]->children[6]->children[20]->children=create_dico();


    unsigned h = height(d);
    printf("h=%u\n",h);

    print_prefix(d);
    destroy_dico(&d);

    return EXIT_SUCCESS;
}
