#include "livre.h"

livre::livre(void){
    type = LIVRE;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    annee = 0;
    nbrPages = 0;
    collection = std::string("(vide)");
    resume = std::string("(vide)");
}

void livre::setAnnee (int _annee){
    annee = _annee;
}
void livre::setNbrPages (unsigned int _nbrPages){
    nbrPages = _nbrPages;
}
void livre::setCollection (std::string _collection){
    collection = _collection;
}
void livre::setResume (std::string _resume){
    resume = _resume;
}

void livre::infoDetail(void){
    ressource::infoDetail();

    std::cout << "Année : " << annee << std::endl;
    std::cout << "Nombre de pages : " << nbrPages << std::endl;
    std::cout << "Collection : " << collection << std::endl;
    std::cout << "Resumée : " << resume << std::endl;
}

void livre::create (void){
    int bufint;
    std::string chaine;

    std::cout << "Veuillez renseigner le titre du livre" << std::endl;
    getline (std::cin, chaine);
	this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur du livre" << std::endl;
    getline (std::cin, chaine);
	this->setAuteur(chaine);
    std::cout << "Veuillez renseigner le nombre de pages" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setNbrPages(bufint);
    }
    std::cout << "Veuillez renseigner l'année de publication" << std::endl;
    getline (std::cin, chaine);
    this->setAnnee(std::atoi(chaine.c_str()));
    std::cout << "Veuillez renseigner la collection du livre" << std::endl;
    getline (std::cin, chaine);
	this->setCollection(chaine);
    std::cout << "Veuillez renseigner le résumé du livre" << std::endl;
    getline (std::cin, chaine);
	this->setResume(chaine);

    return;
}

void livre::save (std::ofstream * monFichier){

    *monFichier << "type=livre"                      << "\n";
    *monFichier << "titre="      << this->titre      << "\n";
    *monFichier << "auteur="     << this->auteur     << "\n";
    *monFichier << "resume="     << this->resume     << "\n";
    *monFichier << "collection=" << this->collection << "\n";
    *monFichier << "nbrPages="   << this->nbrPages   << "\n";
    *monFichier << "annee="      << this->annee      << "\n";

    return;
}
