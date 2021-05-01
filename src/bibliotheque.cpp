#include "bibliotheque.h"

void ihm (void){

    std::vector <ressource *> list;

    std::string cmd;

    std::cout << "Entrez votre commande" << std::endl;

    while (1) {
        cmd = lectureTerminal();

        if ( (cmd.compare(0,3,"BYE")==0) || (cmd.compare(0,3,"bye")==0) ) {
            break;
        }

        if ( (cmd.compare(0,3,"ADD")==0) || (cmd.compare(0,3,"add")==0) ) {
            addType(&list, cmd);
        }

        if ( (cmd.compare(0,4,"LOAD")==0) || (cmd.compare(0,4,"load")==0) ) {
            loadBib(&list, cmd);
        }

        std::cout << std::endl << list.size() << " éléments dans la bibliothèque" << std::endl;

        for (unsigned int i = 0; i < list.size() ; i++) {
            std::cout << std::endl;
            list[i]->infoDetail();
        }
        std::cout << std::endl;
    }

    return;
}

std::string lectureTerminal (void) {
    std::string chaine;
    getline (std::cin, chaine);
    return chaine;
}

void addType (std::vector <ressource *> * list, std::string cmd) {

    if (cmd.size() == 9) {
        if ( (cmd.compare(4,5,"LIVRE")==0) || (cmd.compare(4,5,"livre")==0) ) {
            livre * nouvLivre = new livre;
            * nouvLivre = createLivre();
            list->push_back( nouvLivre );
            //delete nouvLivre; // bien joué PD

        } else if ( (cmd.compare(4,5,"REVUE")==0) || (cmd.compare(4,5,"revue")==0) ) {
            revue * nouvRevue = new revue;
            * nouvRevue = createRevue();
            list->push_back( nouvRevue );
        }

    } else if (cmd.size() == 10) {
        if ( (cmd.compare(4,6,"RESNUM")==0) || (cmd.compare(4,6,"resnum")==0) ) {
            resnum * nouvRESNUM = new resnum;
            * nouvRESNUM = createRESNUM();
            list->push_back( nouvRESNUM );
        }

    } else if (cmd.size() == 7) {
        if ( (cmd.compare(4,3,"VHS")==0) || (cmd.compare(4,3,"vhs")==0) ) {
            vhs * nouvVHS = new vhs;
            * nouvVHS = createVHS();
            list->push_back( nouvVHS );

        } else if ( (cmd.compare(4,5,"DVD")==0) || (cmd.compare(4,5,"dvd")==0) ) {
            dvd * nouvDVD = new dvd;
            * nouvDVD = createDVD();
            list->push_back( nouvDVD );
        }

    } else if (cmd.size() == 6) {
        if ( (cmd.compare(4,6,"CD")==0) || (cmd.compare(4,6,"cd")==0) ) {
            cd * nouvCD = new cd;
            * nouvCD = createCD();
            list->push_back( nouvCD );
        }

    } else {
        return;
    }
}



void loadBib (std::vector <ressource *> * list, std::string cmd) {

    list->clear();
    std::ifstream * monFichier = new std::ifstream;

    monFichier->open ( cmd.substr(5, cmd.size() - 5).c_str() , std::fstream::in | std::fstream::out | std::fstream::app);

    if ( monFichier->fail() ) {
        std::cout << "impossible de lire \"" << cmd.substr(5, cmd.size() - 5) << "\"" << std::endl;
    } else {

        std::cout << "ouverture de \"" << cmd.substr(5, cmd.size() - 5) << "\"" << std::endl;

        std::string buff;

        while (!monFichier->eof()) {

            getline(*monFichier, buff);

            if (buff.compare(0,4, "type") == 0) {
                if (buff.compare(5, 5, "livre") == 0) {
                    livre * newLivre = new livre;
                    * newLivre = lectureLivre(monFichier);
                    list->push_back(newLivre);
                } else if (buff.compare(5, 5, "revue") == 0) {
                    revue * newRevue = new revue;
                    * newRevue = lectureRevue(monFichier);
                    list->push_back(newRevue);
                } else if (buff.compare(5, 3, "vhs") == 0) {
                    vhs * newVHS = new vhs;
                    * newVHS = lectureVHS(monFichier);
                    list->push_back(newVHS);
                } else if (buff.compare(5, 2, "cd") == 0) {
                    cd * newCD = new cd;
                    * newCD = lectureCD(monFichier);
                    list->push_back(newCD);
                } else if (buff.compare(5, 3, "dvd") == 0) {
                    dvd * newDVD = new dvd;
                    * newDVD = lectureDVD(monFichier);
                    list->push_back(newDVD);
                } else if (buff.compare(5, 6, "resnum") == 0) {
                    resnum * newRESNUM = new resnum;
                    * newRESNUM = lectureRESNUM(monFichier);
                    list->push_back(newRESNUM);
                }
            }
        }
    }

    monFichier->close();
    delete monFichier;

    return;
}


livre lectureLivre( std::ifstream * monFichier) {

    livre newLivre;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newLivre.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            newLivre.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "annee") == 0){
            newLivre.setAnnee(atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 8, "nbrPages") == 0){
            newLivre.setNbrPages((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if(buff.compare(0, 10, "collection") == 0){
            newLivre.setCollection(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 6, "resume") == 0){
            newLivre.setResume(buff.substr(pos + 1, buff.size() - (pos + 1)));
        }

    } while( buff.size() > 0);

    return newLivre;
}

revue lectureRevue (std::ifstream * monFichier){
    revue newRevue;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newRevue.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            newRevue.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "annee") == 0){
            newRevue.setAnnee(atoi( buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ));
        } else if (buff.compare(0, 8, "nbrPages") == 0){
            newRevue.setNbrPages((unsigned int)atoi( buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ));
        } else if(buff.compare(0, 10, "collection") == 0){
            newRevue.setCollection(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 6, "resume") == 0){
            newRevue.setResume(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 7, "editeur") == 0){
            newRevue.setEditeur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if( buff.compare(0, 11, "nbrArticles") == 0){
            newRevue.setNbrArticles( (unsigned int) atoi( buff.substr(pos + 1, buff.size() - (pos + 1)).c_str() ) );
        }

    } while( buff.size() > 0);

    return newRevue;
}

vhs lectureVHS (std::ifstream * monFichier){
    vhs newVHS;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newVHS.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            newVHS.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "duree") == 0){
            newVHS.setDuree((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 10, "maisonProd") == 0){
            newVHS.setMaisonProd(buff.substr(pos + 1, buff.size() - (pos + 1)));
        }

    } while( buff.size() > 0);

    return newVHS;
}

cd lectureCD (std::ifstream * monFichier) {
    cd newCD;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newCD.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            newCD.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "duree") == 0){
            newCD.setDuree((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 10, "maisonProd") == 0){
            newCD.setMaisonProd(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 9, "nbrPistes") == 0){
            newCD.setNbrPiste((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        }

    } while( buff.size() > 0);

    return newCD;
}

dvd lectureDVD (std::ifstream * monFichier) {
    dvd newDVD;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newDVD.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0){
            newDVD.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 5, "duree") == 0){
            newDVD.setDuree((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 10, "maisonProd") == 0){
            newDVD.setMaisonProd(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 12, "nbrChapitres") == 0){
            newDVD.setNbrChapitres((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        }

    } while (buff.size() > 0);

    return newDVD;
}

resnum lectureRESNUM (std::ifstream * monFichier) {
    resnum newRESNUM;
    int pos;
    std::string buff;

    do {
        getline(*monFichier, buff);
        pos = buff.find('=') ;

        if(buff.compare(0, 5, "titre")==0) {
            newRESNUM.setTitre(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "auteur") == 0) {
            newRESNUM.setAuteur(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "taille") == 0) {
            newRESNUM.setTaille((unsigned int)atoi(buff.substr(pos + 1, buff.size() - (pos + 1)).c_str()));
        } else if (buff.compare(0, 6, "format") == 0) {
            newRESNUM.setFormat(buff.substr(pos + 1, buff.size() - (pos + 1)));
        } else if (buff.compare(0, 6, "chemin") == 0) {
            newRESNUM.setChemin(buff.substr(pos + 1, buff.size() - (pos + 1)));
        }

    } while (buff.size() > 0);

    return newRESNUM;
}






















livre createLivre (void){

    int bufint;

    livre newLivre;
    std::cout << "Veuillez renseigner le titre du livre" << std::endl;
	newLivre.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur du livre" << std::endl;
	newLivre.setAuteur(lectureTerminal());
    std::cout << "Veuillez renseigner le nombre de pages" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newLivre.setNbrPages(bufint);
    }
    std::cout << "Veuillez renseigner l'année de publication" << std::endl;
    newLivre.setAnnee(std::atoi(lectureTerminal().c_str()));
    std::cout << "Veuillez renseigner la collection du livre" << std::endl;
	newLivre.setCollection(lectureTerminal());
    std::cout << "Veuillez renseigner le résumé du livre" << std::endl;
	newLivre.setResume(lectureTerminal());

    return newLivre;
}

revue createRevue (void){
    int bufint;

    revue newRevue;
    std::cout << "Veuillez renseigner le titre de la revue" << std::endl;
    newRevue.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur de la revue" << std::endl;
    newRevue.setAuteur(lectureTerminal());
    std::cout << "Veuillez renseigner le nombre de pages" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newRevue.setNbrPages(bufint);
    }
    std::cout << "Veuillez renseigner l'année de publication" << std::endl;
    newRevue.setAnnee(std::atoi(lectureTerminal().c_str()));
    std::cout << "Veuillez renseigner la collection de la revue" << std::endl;
    newRevue.setCollection(lectureTerminal());
    std::cout << "Veuillez renseigner le résumé de la revue" << std::endl;
    newRevue.setResume(lectureTerminal());

    std::cout << "Veuillez renseigner l'éditeur de la revue" << std::endl;
    newRevue.setEditeur(lectureTerminal());

    std::cout << "Veuillez renseigner le nombre d'articles dans la revue" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newRevue.setNbrArticles(bufint);
    }

    return newRevue;

}





vhs createVHS (void){
    int bufint;

    vhs newVHS;
    std::cout << "Veuillez renseigner le titre de la VHS" << std::endl;
	newVHS.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur de la VHS" << std::endl;
	newVHS.setAuteur(lectureTerminal());
    std::cout << "Veuillez renseigner la maison de production de la VHS" << std::endl;
	newVHS.setMaisonProd(lectureTerminal());

    std::cout << "Veuillez renseigner la durée de la VHS" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newVHS.setDuree(bufint);
    }

    return newVHS;

}


cd createCD (void){
    int bufint;

    cd newCD;
    std::cout << "Veuillez renseigner le titre du CD" << std::endl;
	newCD.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur du CD" << std::endl;
	newCD.setAuteur(lectureTerminal());
    std::cout << "Veuillez renseigner la maison de production du CD" << std::endl;
	newCD.setMaisonProd(lectureTerminal());

    std::cout << "Veuillez renseigner la durée du CD" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newCD.setDuree(bufint);
    }

    std::cout << "Veuillez renseigner le nombre de pistes du CD" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newCD.setNbrPiste(bufint);
    }

    return newCD;
}


dvd createDVD (void){
    int bufint;

    dvd newDVD;
    std::cout << "Veuillez renseigner le titre du DVD" << std::endl;
	newDVD.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur du DVD" << std::endl;
	newDVD.setAuteur(lectureTerminal());
    std::cout << "Veuillez renseigner la maison de production du DVD" << std::endl;
	newDVD.setMaisonProd(lectureTerminal());

    std::cout << "Veuillez renseigner la durée du DVD" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newDVD.setDuree(bufint);
    }

    std::cout << "Veuillez renseigner le nombre de chapitres du DVD" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newDVD.setNbrChapitres(bufint);
    }

    return newDVD;
}


resnum createRESNUM (void){
    int bufint;

    resnum newRESNUM;
    std::cout << "Veuillez renseigner le titre de la ressource numérique" << std::endl;
	newRESNUM.setTitre(lectureTerminal());
    std::cout << "Veuillez renseigner l'auteur de la ressource numérique" << std::endl;
	newRESNUM.setAuteur(lectureTerminal());

    std::cout << "Veuillez renseigner le format de la ressource numérique" << std::endl;
	newRESNUM.setFormat(lectureTerminal());

    std::cout << "Veuillez renseigner la taille en octet de la ressource numérique" << std::endl;
    bufint = std::atoi(lectureTerminal().c_str());
    if (bufint >= 0) {
        newRESNUM.setTaille(bufint);
    }

    std::cout << "Veuillez renseigner le chemin de la ressource numérique" << std::endl;
	newRESNUM.setChemin(lectureTerminal());


    return newRESNUM;
}
