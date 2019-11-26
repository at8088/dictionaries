#include "iterator.h"

int main(int argc, char*argv[]){
    dico d = create_dico();    
    add_rec(d,"ours",10);
    add_rec(d,"ourson",7);
    add_rec(d,"oursonne",10);
    add_rec(d,"clair",5);
    add_rec(d,"claire",7);
    add_iter(d,"classe",6);
    add_iter(d,"classer",7);
    add_iter(d,"bar",3);
    add_iter(d,"barometre",9);
    add_iter(d,"foo",3);
    add_iter(d,"foudre",6);

    puts("Affichage avec print dico.\n");
    print_dico(d);
    puts("\n");

    puts("Affichage avec l'iterateur.\n");
    iterator * dit = start_iterator(d);
    while (has_next(dit)){
     printf("-%s\n", next(dit));
  
    }

    dico d1 = create_dico();
    iterator* dit1 = start_iterator(d1);
    while (has_next(dit1)){
     printf("-%s\n", next(dit1));
    }
    puts("Affichage avec l'iterateur d'un dico vide.\n");
    destroy_iterator(&dit1);
    destroy_iterator(&dit);
    destroy_dico(&d1);
    destroy_dico(&d);

    return EXIT_SUCCESS ;
}