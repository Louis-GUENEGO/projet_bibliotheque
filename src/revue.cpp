#include "revue.h"

revue::revue(void){
    ressource::type = REVUE;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    annee = 0;
    nbrPages = 0;
    collection = std::string("(vide)");
    resume = std::string("(vide)");
    editeur = std::string("(vide)");
    nrbArticles = 0;
}

void revue::setEditeur (std::string _editeur){
    editeur = _editeur;
}
void revue::setNbrArticles (unsigned int _nrbArticles){
    nrbArticles = _nrbArticles;
}

void revue::infoDetail(void){
    livre::infoDetail();
    std::cout << "Editeur : " << editeur << std::endl;
    std::cout << "Nombre d'articles : " << nrbArticles << std::endl;
}
