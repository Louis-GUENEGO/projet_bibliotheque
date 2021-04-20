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
