#include "cd.h"

cd::cd(void){
    type = CD;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    duree = 0;
    maisonProd = std::string("(vide)");

    nbrPistes = 0;
}

void cd::setNbrPiste (unsigned int _nbrPistes){
    nbrPistes = _nbrPistes;
}

void cd::infoDetail (void){
    vhs::infoDetail();
    std::cout << "Nombre de pistes : " << nbrPistes << std::endl;
}
