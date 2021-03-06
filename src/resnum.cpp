#include "resnum.h"


resnum::resnum (void) {
    etatRessource = LIBRE;
    ID = 0;
    type = RESNUM;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    format = std::string("(vide)");
    taille = 0;
    chemin = std::string("(vide)");
}

resnum::resnum (unsigned int _ID) {
    etatRessource = LIBRE;
    ID = _ID;
    type = RESNUM;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    format = std::string("(vide)");
    taille = 0;
    chemin = std::string("(vide)");
}

void resnum::setFormat (std::string _format) {
    format = _format;
}

void resnum::setTaille (unsigned int _taille ){
    taille = _taille;
}

void resnum::setChemin (std::string _chemin) {
    chemin = _chemin;
}

void resnum::infoDetail (void) {
    ressource::infoDetail();

    std::cout << "Format : " << format << std::endl;
    std::cout << "Taille : " << taille << " octets" << std::endl;
    std::cout << "Chemin : " << chemin << std::endl;
}

void resnum::create (void){
    int bufint;
    std::string chaine;

    std::cout << "Veuillez renseigner le titre de la ressource numérique" << std::endl;
    getline (std::cin, chaine);
	this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur de la ressource numérique" << std::endl;
    getline (std::cin, chaine);
	this->setAuteur(chaine);
    std::cout << "Veuillez renseigner le format de la ressource numérique" << std::endl;
    getline (std::cin, chaine);
	this->setFormat(chaine);
    std::cout << "Veuillez renseigner la taille en octet de la ressource numérique" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setTaille(bufint);
    }
    std::cout << "Veuillez renseigner le chemin de la ressource numérique" << std::endl;
    getline (std::cin, chaine);
	this->setChemin(chaine);
}

void resnum::save (std::ofstream * monFichier) {

    *monFichier << "type=resnum"             << "\n";
    *monFichier << "titre="  << this->titre  << "\n";
    *monFichier << "auteur=" << this->auteur << "\n";
    *monFichier << "taille=" << this->taille << "\n";
    *monFichier << "format=" << this->format << "\n";
    *monFichier << "chemin=" << this->chemin << "\n";
}

char resnum::search (const std::string & str) {

    if ( ressource::search(str) ) {
        return 1;
    } else if (this->format.find(str, 0) != std::string::npos) {
        return 1;
    } else if (this->chemin.find(str, 0) != std::string::npos) {
        return 1;
    } else {
        return 0;
    }
}
