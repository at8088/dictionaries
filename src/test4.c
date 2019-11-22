#include "iterator.h"

int main(int argc, char*argv[]){
    dico d = create_dico();    
    add_rec(d,"merde",5);
    add_rec(d,"merdeux",7);
        
    
   

    add_rec(d,"clair",5);
    add_rec(d,"claire",7);
    add_iter(d,"classe",6);
    add_iter(d,"classer",7);


    iterator * dit = start_iterator(d);
    while (has_next(dit)) printf("-%s\n", next(dit));
    destroy_iterator(&dit);
    destroy_dico(&d);

    return EXIT_SUCCESS ;
}