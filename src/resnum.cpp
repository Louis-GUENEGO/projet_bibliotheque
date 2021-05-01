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


    return;
}

void resnum::save (std::ofstream * monFichier){

    *monFichier << "type=resnum"             << "\n";
    *monFichier << "titre="  << this->titre  << "\n";
    *monFichier << "auteur=" << this->auteur << "\n";
    *monFichier << "taille=" << this->taille << "\n";
    *monFichier << "format=" << this->format << "\n";
    *monFichier << "chemin=" << this->chemin << "\n";

    return;
}
