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

void dvd::create (void){
    int bufint;
    std::string chaine;


    std::cout << "Veuillez renseigner le titre du DVD" << std::endl;
    getline (std::cin, chaine);
	this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur du DVD" << std::endl;
    getline (std::cin, chaine);
	this->setAuteur(chaine);
    std::cout << "Veuillez renseigner la maison de production du DVD" << std::endl;
    getline (std::cin, chaine);
	this->setMaisonProd(chaine);

    std::cout << "Veuillez renseigner la durée du DVD" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setDuree(bufint);
    }

    std::cout << "Veuillez renseigner le nombre de chapitres du DVD" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setNbrChapitres(bufint);
    }

    return;
}
