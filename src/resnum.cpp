#include "resnum.h"


resnum::resnum(void){
    type = RESNUM;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    format = std::string("(vide)");
    taille = 0;
    chemin = std::string("(vide)");
}

void resnum::setFormat (std::string _format){
    format = _format;
}
void resnum::setTaille (unsigned int _taille){
    taille = _taille;
}
void resnum::setChemin (std::string _chemin){
    chemin = _chemin;
}

void resnum::infoDetail (void){
    ressource::infoDetail();

    std::cout << "Format : " << format << std::endl;
    std::cout << "Taille : " << taille << " octets" << std::endl;
    std::cout << "Chemin : " << chemin << std::endl;
}
