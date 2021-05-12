#include "dvd.h"

dvd::dvd(void) {
    ID = 0;

    type = DVD;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    duree = 0;
    maisonProd = std::string("(vide)");

    nbrChapitres = 0;
}

dvd::dvd(unsigned int _ID) {
    ID = _ID;

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

void dvd::save (std::ofstream * monFichier){

    *monFichier << "type=dvd"                                << "\n";
    *monFichier << "titre="          << this->titre          << "\n";
    *monFichier << "auteur="         << this->auteur         << "\n";
    *monFichier << "duree="          << this->duree          << "\n";
    *monFichier << "maisonProd="     << this->maisonProd     << "\n";
    *monFichier << "nbrChapitres="   << this->nbrChapitres   << "\n";

    return;
}


char dvd::search (const std::string & str){

    if ( vhs::search(str) ) {
        return 1;
    } else {
        return 0;
    }
}
