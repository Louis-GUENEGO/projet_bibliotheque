#include "dvd.h"

dvd::dvd(void) {
    type = DVD;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    duree = 0;
    maisonProd = std::string("(vide)");

    nbrChapitres = 0;
}

void dvd::setNbrChapitres (unsigned int _nbrChapitres) {
    nbrChapitres = _nbrChapitres;
}
void dvd::infoDetail(void) {
    vhs::infoDetail();
    std::cout << "Nombre de chapitres : " << nbrChapitres << std::endl;
}
