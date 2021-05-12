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

    std::cout << "(" << ID << ") ";

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

    std::cout << "ID : " << ID << std::endl;

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

void ressource::lecture (std::ifstream * monFichier){
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            this->setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            this->setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "duree") == 0){
            this->setDuree((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 10, "maisonProd") == 0){
            this->setMaisonProd(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 9, "nbrPistes") == 0){
            this->setNbrPiste((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 6, "taille") == 0) {
            this->setTaille((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 6, "format") == 0) {
            this->setFormat(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "chemin") == 0) {
            this->setChemin(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 12, "nbrChapitres") == 0){
            this->setNbrChapitres((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 8, "nbrPages") == 0){
            this->setNbrPages((unsigned int)atoi( buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ));
        } else if(buff.compare(0, 10, "collection") == 0){
            this->setCollection(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 6, "resume") == 0){
            this->setResume(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 7, "editeur") == 0){
            this->setEditeur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 11, "nbrArticles") == 0){
            this->setNbrArticles( (unsigned int) atoi( buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ) );
        } else if (buff.compare(0, 5, "annee") == 0) {
            this->setAnnee( atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ) );
        }

    } while( buff.size() > 0);

    return;
}
void ressource::create (void){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::save (std::ofstream * monFichier){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
char ressource::search (const std::string & str){
    if (this->titre.find(str, 0) != std::string::npos) {
        return 1;
    } else if (this->auteur.find(str, 0) != std::string::npos) {
        return 1;
    } else {
        return 0;
    }
}

unsigned int ressource::readID (void){
    return ID;
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

//renum
void ressource::setFormat (std::string format){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setTaille (unsigned int taille){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
void ressource::setChemin (std::string chemin){
    std::cout<< "/!\\ méthode non implémentée" << std::endl;
}
