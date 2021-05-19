#include "vhs.h"

vhs::vhs (void) {
    etatRessource = LIBRE;
    ID = 0;
    type = VHS;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    duree = 0;
    maisonProd = std::string("(vide)");
}

vhs::vhs (unsigned int _ID) {
    etatRessource = LIBRE;
    ID = _ID;
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

void vhs::create (void) {
    int bufint;
    std::string chaine;

    std::cout << "Veuillez renseigner le titre de la VHS" << std::endl;
    getline (std::cin, chaine);
	this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur de la VHS" << std::endl;
    getline (std::cin, chaine);
	this->setAuteur(chaine);
    std::cout << "Veuillez renseigner la maison de production de la VHS" << std::endl;
    getline (std::cin, chaine);
	this->setMaisonProd(chaine);
    std::cout << "Veuillez renseigner la durée de la VHS" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setDuree(bufint);
    }
}

void vhs::save (std::ofstream * monFichier) {

    *monFichier << "type=vhs"                        << "\n";
    *monFichier << "titre="      << this->titre      << "\n";
    *monFichier << "auteur="     << this->auteur     << "\n";
    *monFichier << "duree="      << this->duree      << "\n";
    *monFichier << "maisonProd=" << this->maisonProd << "\n";
}

char vhs::search (const std::string & str) {

    if ( ressource::search(str) ) {
        return 1;
    } else if (this->maisonProd.find(str, 0) != std::string::npos) {
        return 1;
    } else {
        return 0;
    }
}
