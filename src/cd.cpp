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

void cd::create (void){
    int bufint;
    std::string chaine;

    std::cout << "Veuillez renseigner le titre du CD" << std::endl;
    getline (std::cin, chaine);
	this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur du CD" << std::endl;
    getline (std::cin, chaine);
	this->setAuteur(chaine);
    std::cout << "Veuillez renseigner la maison de production du CD" << std::endl;
    getline (std::cin, chaine);
	this->setMaisonProd(chaine);

    std::cout << "Veuillez renseigner la durée du CD" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setDuree(bufint);
    }

    std::cout << "Veuillez renseigner le nombre de pistes du CD" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setNbrPiste(bufint);
    }

    return;
}
