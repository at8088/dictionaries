#include "fct-primitives.h"

int main(void){
    dico d = create_dico();
    
    char s[10]="chien";
    add_rec(d,s,10);
    add_rec(d,"chateau",7);
    add_rec(d,"flemme",15);

    puts("Test ajout recursif des mots \"chien \", \"chateau \" et \"flemme\". ");    
    print_prefix(d); 
    puts("");
    puts("Test ajout iteratif des mots \"battre\", \"bateau \" et \"pour\". ");    
    add_iter(d,"pour",4);
    add_iter(d,"battre",6);
    add_iter(d,"bateau",6);
    print_prefix(d);
    puts("");

    int it = contains_iter(d,"chien",5);
    printf("test contains iter de \"chien\"  = %d\n",it);
    int rec = contains_rec(d,"bateau",6);
    printf("test contains rec de \"bateau\"  = %d\n",rec);
    it=contains_iter(d,"chat",4);
    printf("test contains iter de \"chat\"  = %d\n",it);
    rec = contains_rec(d,"velo",4);
    printf("test contains rec de \"velo\"  = %d\n",rec);

    puts("on supprime iterativement le mot \"chateau\".");
    remove_iter(d,"chateau",7);
    puts("on supprime recursivement le mot \"pour\".");
    remove_rec(d,"pour",4);
    puts("on supprime iterativement un mot qui n'est pas dans le dico (\"clair\") .");
    remove_iter(d,"clair",5);
    puts("on supprime recursivement un mot qui n'est pas dans le dico (\"danger\").");
    remove_rec(d,"danger",6);

    print_prefix(d);
    destroy_dico(&d);

    return 0;
    
}