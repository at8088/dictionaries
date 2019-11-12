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
    
    print_prefix(d);

    int it = contains_iter(d,"chien",5);
    printf("test contains iter de \"chien\"  = %d\n",it);
    int rec = contains_rec(d,"bateau",6);
    printf("test contains rec de \"bateau\"  = %d\n",rec);


    puts("on supprime chien et bateau");
    remove_iter(d,"chien",5);
    remove_rec(d,"bateau",6);

    print_prefix(d);
    destroy_dico(&d);

    return 0;
    
}