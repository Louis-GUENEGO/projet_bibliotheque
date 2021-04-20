#include "ressource.h"

ressource::ressource (void) {}

// méthodes virtuelles communes
void ressource::setTitre (std::string _titre) {
    titre = _titre;
}
void ressource::setAuteur (std::string _auteur){
    auteur = _auteur;
}
void ressource::info (void){
    switch (type){
        case LIVRE:
            std::cout << "Livre : ";
            break;

        case REVUE:
            std::cout << "Revue : ";
            break;

        case CD:
            std::cout << "CD : ";
            break;

        case VHS:
            std::cout << "VHS : ";
            break;

        case DVD:
            std::cout << "DVD : ";
            break;

        case RESNUM:
            std::cout << "Ressource numérique : ";
            break;
    }
    std::cout << titre << ", de " << auteur << std::endl;
}

void ressource::infoDetail (void) {
    switch (type){
        case LIVRE:
            std::cout << "Type : livre" << std::endl;
            break;

        case REVUE:
            std::cout << "Type : Revue" << std::endl;
            break;

        case CD:
            std::cout << "Type : CD" << std::endl;
            break;

        case VHS:
            std::cout << "Type : VHS" << std::endl;
            break;

        case DVD:
            std::cout << "Type : DVD" << std::endl;
            break;

        case RESNUM:
            std::cout << "Type : Ressource numérique" << std::endl;
            break;
    }
    std::cout << "Titre : " << titre << std::endl;
    std::cout << "Auteur : " << auteur << std::endl;
}


// méthodes virtuelles Livres (non implémentée dans ressource)
void ressource::setAnnee (int annee){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setNbrPages (unsigned int nbrPages){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setCollection (std::string collection){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setResume (std::string resume){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}

// méthosdes virtueklles revues
void ressource::setEditeur (std::string editeur){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setNbrArticles (unsigned int nrbArticles){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}

// vhs
void ressource::setMaisonProd (std::string maisonProd){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setDuree (unsigned int duree){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}

//CD
void ressource::setNbrPiste (unsigned int nbrPistes){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}

// dvd
void ressource::setNbrChapitres (unsigned int nbrChapitres){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
