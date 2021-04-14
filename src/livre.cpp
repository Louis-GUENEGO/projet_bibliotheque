#include "livre.h"

livre::livre(void){
    ressource::type = LIVRE;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    annee = 0;
    nbrPages = 0;
    collection = std::string("(vide)");
    resume = std::string("(vide)");
}


livre::livre(std::string titre, std::string auteur, int annee, int nbrPages, std::string collection, std::string resume){
    ressource::type = LIVRE;
    titre = titre;
    auteur = auteur;
    annee = annee;
    nbrPages = nbrPages;
    collection = collection;
    resume = resume;
}

void livre::setAuteur (const char * _auteur){
    auteur = std::string(_auteur);
}
void livre::setAnnee (int annee){
    annee = annee;
}
void livre::setNbrPages (int nbrPages){
    nbrPages = nbrPages;
}
void livre::setCollection (const char * _collection){
    collection = std::string(_collection);
}
void livre::setResume (const char * _resume){
    resume = std::string(_resume);
}


void livre::info(void){
    std::cout<< titre << ", " << auteur << std::endl;
}
