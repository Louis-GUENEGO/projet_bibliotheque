#include "livre.h"

livre::livre(void){
    ressource::type = LIVRE;
    titre = std::string("(vide)");
    auteur = std::string("(vide)");
    annee = 0;
    nbr_pages = 0;
    collection = std::string("(vide)");
    resume = std::string("(vide)");
}

livre::livre(std::string titre, std::string auteur, int annee, int nbr_pages, std::string collection, std::string resume){
    ressource::type = LIVRE;
    titre = titre;
    auteur = auteur;
    annee = annee;
    nbr_pages = nbr_pages;
    collection = collection;
    resume = resume;
}
