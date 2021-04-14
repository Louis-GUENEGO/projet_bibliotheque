#include "livre.h"

livre::livre(void){
    ressource::type = LIVRE;
    titre = titre;
    auteur = auteur;
    annee = annee;
    nbrpages = nbr_pages;
    collection = collection;
    resume = resume;
}

livre::livre(std::string titre, std::string auteur, int annee, int nbr_pages, std::string collection, std::string resume){
    ressource::type = LIVRE;
    titre = titre;
    auteur = auteur;
    annee = annee;
    nbrpages = nbr_pages;
    collection = collection;
    resume = resume;
}
