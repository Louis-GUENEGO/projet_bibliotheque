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
    std::cout << titre << ", de " << auteur << std::endl << std::endl;
}
void ressource::infoDetail (void){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}


// méthodes virtuelles Livres (non implémentée dans ressource)
void ressource::setAnnee (int annee){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setNbrPages (unsigned int nbr_pages){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setCollection (std::string collection){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setResume (std::string resume){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
