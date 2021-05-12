#include "cd.h"

cd::cd(void){
    ID = 0;

    type = CD;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    duree = 0;
    maisonProd = std::string("(vide)");

    nbrPistes = 0;
}

cd::cd(unsigned int _ID){
    ID = _ID;

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

void cd::save (std::ofstream * monFichier){

    *monFichier << "type=cd"                         << "\n";
    *monFichier << "titre="      << this->titre      << "\n";
    *monFichier << "auteur="     << this->auteur     << "\n";
    *monFichier << "duree="      << this->duree      << "\n";
    *monFichier << "maisonProd=" << this->maisonProd << "\n";
    *monFichier << "nbrPistes="  << this->nbrPistes  << "\n";

    return;
}

char cd::search (const std::string & str){

    if ( vhs::search(str) ) {
        return 1;
    } else {
        return 0;
    }
}
