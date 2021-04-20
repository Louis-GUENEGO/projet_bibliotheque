#include "vhs.h"

vhs::vhs(void){
    type = VHS;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    duree = 0;
    maisonProd = std::string("(vide)");
}


void vhs::setMaisonProd (std::string _maisonProd) {
    maisonProd = _maisonProd;
}
void vhs::setDuree (unsigned int _duree) {
    duree = _duree;
}
void vhs::infoDetail (void) {
    ressource::infoDetail();

    std::cout << "Durée : " << duree << std::endl;
    std::cout << "Maison de production : " << maisonProd << std::endl;
}
