#include "fct-primitives.h"

int main(void){
    dico d = create_dico();
    
    char s[10]="chien";
    add_rec(d,s,10);
    add_rec(d,"chateau",7);
    add_rec(d,"hello",15);
    add_iter(d,"hi",2);
    add_iter(d,"battre",6);
    add_iter(d,"bateau",6);
    add_iter(d,"moteur",6);
    add_iter(d,"arbre",5);
    add_iter(d,"mardi",5);
    add_iter(d,"xylophone",9);
    
    puts("Affichage avec print dico");
    puts("");
    print_dico(d);
    puts("\n");
    puts("Affichage avec print prefix");
    puts("");
    print_prefix(d);
    puts("");

    destroy_dico(&d);
    
    return 0;
}
