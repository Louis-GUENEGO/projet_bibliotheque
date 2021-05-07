#include "revue.h"

revue::revue(void){
    type = REVUE;

    titre = std::string("(vide)");
    auteur = std::string("(vide)");

    annee = 0;
    nbrPages = 0;
    collection = std::string("(vide)");
    resume = std::string("(vide)");

    editeur = std::string("(vide)");
    nbrArticles = 0;
}

void revue::setEditeur (std::string _editeur){
    editeur = _editeur;
}
void revue::setNbrArticles (unsigned int _nbrArticles){
    nbrArticles = _nbrArticles;
}

void revue::infoDetail(void){
    livre::infoDetail();
    std::cout << "Editeur : " << editeur << std::endl;
    std::cout << "Nombre d'articles : " << nbrArticles << std::endl;
}

void revue::create (void){
    int bufint;
    std::string chaine;

    std::cout << "Veuillez renseigner le titre de la revue" << std::endl;
    getline (std::cin, chaine);
    this->setTitre(chaine);
    std::cout << "Veuillez renseigner l'auteur de la revue" << std::endl;
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
    std::cout << "Veuillez renseigner la collection de la revue" << std::endl;
    getline (std::cin, chaine);
    this->setCollection(chaine);
    std::cout << "Veuillez renseigner le résumé de la revue" << std::endl;
    getline (std::cin, chaine);
    this->setResume(chaine);

    std::cout << "Veuillez renseigner l'éditeur de la revue" << std::endl;
    getline (std::cin, chaine);
    this->setEditeur(chaine);

    std::cout << "Veuillez renseigner le nombre d'articles dans la revue" << std::endl;
    getline (std::cin, chaine);
    bufint = std::atoi(chaine.c_str());
    if (bufint >= 0) {
        this->setNbrArticles(bufint);
    }

    return;

}

void revue::save (std::ofstream * monFichier){

    *monFichier << "type=revue"                          << "\n";
    *monFichier << "titre="      << this->titre          << "\n";
    *monFichier << "auteur="     << this->auteur         << "\n";
    *monFichier << "resume="     << this->resume         << "\n";
    *monFichier << "collection=" << this->collection     << "\n";
    *monFichier << "nbrPages="   << this->nbrPages       << "\n";
    *monFichier << "annee="      << this->annee          << "\n";
    *monFichier << "editeur="    << this->editeur        << "\n";
    *monFichier << "nbrArticles="<< this->nbrArticles    << "\n";

    return;
}

char revue::search (const std::string & str){
    if ( livre::search(str) ) {
        return 1;
    } else if (this->editeur.find(str, 0) != std::string::npos) {
        return 1;
    } else {
        return 0;
    }
}
