
#include "fct-primitives.h"

int main(int argc, char const *argv[]){
    dico d = create_dico();
    /* d[3]=calloc(1,sizeof(struct node));
    d[3]->first = 'h';
    d[3]->children = create_dico();
    d[3]->children[12]=calloc(1,sizeof(struct node));
    d[3]->children[12]->first='i';
    d[3]->children[12]->end_of_word=true;
    d[3]->children[12]->children=create_dico();
    d[3]->children[16]=calloc(1,sizeof(struct node));
    d[3]->children[16]->first='o';
    d[3]->children[16]->end_of_word=true;
    d[3]->children[16]->children=create_dico();


    d[get_index('c')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->first = 'c';
    d[get_index('c')]->children = create_dico();
    d[get_index('c')]->children[get_index('h')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->first='h';
    d[get_index('c')]->children[get_index('h')]->children=create_dico();
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
    d[get_index('c')]->children[get_index('h')]->children[0]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->children[0]->first='a';
    d[get_index('c')]->children[get_index('h')]->children[0]->children=create_dico();
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->first='t';
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->end_of_word=true;
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->children=create_dico();

 */
    
    char s[10]="chien";
    add_rec(d,s,10);
    add_rec(d,"chat",7);
    add_rec(d,"hello",15);
    add_rec(d,"hi",10);
    add_rec(d,"mart",10);
    add_rec(d,"martin",15);
    // remove_iter(d,"mart",6);
    print_prefix(d);
    unsigned h = nb_words(d);
    printf("\nh=%u\n",h);
    destroy_dico(&d);

    return EXIT_SUCCESS;
}
