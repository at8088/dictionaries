
#include "fct-primitives.h"

int main(int argc, char const *argv[]){
    dico d = create_dico();
    d[3]=calloc(1,sizeof(struct node));
    d[3]->first = 'a';
    d[3]->children = create_dico();
    d[3]->children[12]=calloc(1,sizeof(struct node));
    d[3]->children[12]->first='i';
    d[3]->children[12]->end_of_word=false;
    d[3]->children[12]->children=create_dico();
    d[3]->children[16]=calloc(1,sizeof(struct node));
    d[3]->children[16]->first='r';
    d[3]->children[16]->end_of_word=true;
    d[3]->children[16]->children=create_dico();


    d[get_index('c')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->first = 'c';
    d[get_index('c')]->children = create_dico();
    d[get_index('c')]->children[get_index('h')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->first='h';
    d[get_index('c')]->children[get_index('h')]->children=create_dico();
    d[get_index('c')]->children[get_index('h')]->children[0]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->children[0]->first='a';
    d[get_index('c')]->children[get_index('h')]->children[0]->children=create_dico();
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]=calloc(1,sizeof(struct node));
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->first='t';
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->end_of_word=true;
    d[get_index('c')]->children[get_index('h')]->children[0]->children[get_index('t')]->children=create_dico();

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

    printf("Le nombre de fils de l'arbre ayant pour racine 'm' de \"moi\" est %d",nb_children(d[16]));
    
    printf("Le nombre de noeuds est : %d\n",nb_nodes(d));

    printf("La hauteur du dictionnaire est : %d",height(d));

    print_prefix(d);
    destroy_dico(&d);

    puts("\n==============================");
    puts("Tests sur un dico vide");
    dico d1 = create_dico();
    printf("Le nombre de fils d'un de ses arbres  est %d",nb_children(d1[1]));
    
    printf("Le nombre de noeuds est : %d\n",nb_nodes(d1));

    printf("La hauteur du dictionnaire est : %d\n",height(d1));

    destroy_dico(&d1);

    return EXIT_SUCCESS;
}
