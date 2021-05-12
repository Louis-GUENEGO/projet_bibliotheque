#include "bibliotheque.h"

void ihm (void){

    std::vector <ressource *> bib;

    std::vector <ressource *> * bibsearchinter = &bib;

    std::vector <ressource *> * * bibsearch = &bibsearchinter;

    std::string cmd;

    std::cout << "Entrez votre commande" << std::endl;

    while (1) {
        getline (std::cin, cmd);

        if ( (cmd.compare(0,3,"BYE")==0) || (cmd.compare(0,3,"bye")==0) ) {
            break;
        } else if ( (cmd.compare(0,3,"ADD")==0) || (cmd.compare(0,3,"add")==0) ) {
            addType(&bib, cmd);
        } else if ( (cmd.compare(0,4,"LOAD")==0) || (cmd.compare(0,4,"load")==0) ) {
            loadBib(&bib, cmd);
        } else if ( (cmd.compare(0,4,"SAVE")==0) || (cmd.compare(0,4,"save")==0) ) {
            saveBib(&bib, cmd);
        } else if ( (cmd.compare(0,5,"RESET")==0) || (cmd.compare(0,5,"reset")==0) ) {
            resetBib(&bib);
        } else if ( (cmd.compare(0,6,"SEARCH")==0) || (cmd.compare(0,6,"search")==0) ) {
            if (cmd.size() < 8) {
                std::cout << "recherche vide" << std::endl;
            } else {
                std::string cmdbuff = cmd.substr(7,cmd.size()-7);
                searchBib(&bib,bibsearch, cmdbuff);
            }

        } else if ( (cmd.compare(0,5,"CLEAR")==0) || (cmd.compare(0,5,"clear")==0) ) {
            (*bibsearch)->clear();
            * bibsearch =  &bib;
            std::cout << "résultat de recherche réinitialisé" << std::endl;
        } else if ( (cmd.compare(0,4,"LIST")==0) || (cmd.compare(0,4,"list")==0) ) {
            afficheBib(* bibsearch);
        } else {
            std::cout << "commande non reconnue" << std::endl;
        }

        std::cout << std::endl;
    }

    return;
}

void afficheBib (std::vector <ressource *> * bib){
    std::cout << std::endl << bib->size() << " éléments dans la bibliothèque" << std::endl;

    for (unsigned int i = 0; i < bib->size() ; i++) {
        std::cout << std::endl;
        (* bib)[i]->infoDetail();
    }
    std::cout << std::endl;

    return;
}

void resetBib (std::vector <ressource *> * bib) {
    // purge pour éviter les fuites mémoire
    for ( unsigned int i = 0; i < bib->size() ; i++ ) {
        delete (* bib)[i];
    }
    // reset de la bibliotheque
    bib->clear();

    return;
}

void addType (std::vector <ressource *> * bib, std::string cmd) {

    if (cmd.size() == 9) {
        if ( (cmd.compare(4,5,"LIVRE")==0) || (cmd.compare(4,5,"livre")==0) ) {
            livre * nouvLivre = new livre;
            nouvLivre->create();
            bib->push_back( nouvLivre );

        } else if ( (cmd.compare(4,5,"REVUE")==0) || (cmd.compare(4,5,"revue")==0) ) {
            revue * nouvRevue = new revue;
            nouvRevue->create();
            bib->push_back( nouvRevue );
        }

    } else if (cmd.size() == 10) {
        if ( (cmd.compare(4,6,"RESNUM")==0) || (cmd.compare(4,6,"resnum")==0) ) {
            resnum * nouvRESNUM = new resnum;
            nouvRESNUM->create();
            bib->push_back( nouvRESNUM );
        }

    } else if (cmd.size() == 7) {
        if ( (cmd.compare(4,3,"VHS")==0) || (cmd.compare(4,3,"vhs")==0) ) {
            vhs * nouvVHS = new vhs;
            nouvVHS->create();
            bib->push_back( nouvVHS );

        } else if ( (cmd.compare(4,5,"DVD")==0) || (cmd.compare(4,5,"dvd")==0) ) {
            dvd * nouvDVD = new dvd;
            nouvDVD->create();
            bib->push_back( nouvDVD );
        }

    } else if (cmd.size() == 6) {
        if ( (cmd.compare(4,6,"CD")==0) || (cmd.compare(4,6,"cd")==0) ) {
            cd * nouvCD = new cd;
            nouvCD->create();
            bib->push_back( nouvCD );
        }

    } else {
        std::cout << "type manquant" << std::endl;
        return;
    }
}

void loadBib (std::vector <ressource *> * bib, std::string cmd) {

    if (cmd.size() < 6) {
        std::cout << "nom du fichier manquant" << std::endl;
    } else {
        resetBib(bib);

        std::ifstream * monFichier = new std::ifstream;

        monFichier->open ( cmd.substr(5, cmd.size() - 5).c_str() );

        if ( monFichier->fail() ) {
            std::cout << "impossible de charger \"" << cmd.substr(5, cmd.size() - 5) << "\"" << std::endl;
        } else {
            std::string buff;

            while (!monFichier->eof()) {

                getline(*monFichier, buff);

                if (buff.compare(0,4, "type") == 0) {
                    if (buff.compare(5, 5, "livre") == 0) {
                        livre * newLivre = new livre;
                        newLivre->lecture(monFichier);
                        bib->push_back(newLivre);
                    } else if (buff.compare(5, 5, "revue") == 0) {
                        revue * newRevue = new revue;
                        newRevue->lecture(monFichier);
                        bib->push_back(newRevue);
                    } else if (buff.compare(5, 3, "vhs") == 0) {
                        vhs * newVHS = new vhs;
                        newVHS->lecture(monFichier);
                        bib->push_back(newVHS);
                    } else if (buff.compare(5, 2, "cd") == 0) {
                        cd * newCD = new cd;
                        newCD->lecture(monFichier);
                        bib->push_back(newCD);
                    } else if (buff.compare(5, 3, "dvd") == 0) {
                        dvd * newDVD = new dvd;
                        newDVD->lecture(monFichier);
                        bib->push_back(newDVD);
                    } else if (buff.compare(5, 6, "resnum") == 0) {
                        resnum * newRESNUM = new resnum;
                        newRESNUM->lecture(monFichier);
                        bib->push_back(newRESNUM);
                    }
                }
            }

            std::cout << "chargement de \"" << cmd.substr(5, cmd.size() - 5) << "\" réussis" << std::endl;
        }

        monFichier->close();
        delete monFichier;

    }

    return;

}

void saveBib (std::vector <ressource *> * bib, std::string cmd) {

    if (cmd.size() < 6) {
        std::cout << "nom du fichier manquant" << std::endl;
    } else {

        std::ofstream * monFichier = new std::ofstream;

        monFichier->open ( cmd.substr(5, cmd.size() - 5).c_str());

        if ( monFichier->fail() ) {
            std::cout << "impossible de sauvegarder dans \"" << cmd.substr(5, cmd.size() - 5) << "\"" << std::endl;
        } else {

            for (int i = 0 ; i < bib->size() ; i++) {
                (* bib)[i]->save(monFichier);
                *monFichier << "\n";
            }
            std::cout << "sauvegarde dans \"" << cmd.substr(5, cmd.size() - 5) << "\" réussis" << std::endl;
        }

        monFichier->close();
        delete monFichier;

    }

    return;
}

void searchBib (std::vector <ressource *> * bib, std::vector <ressource *> * * bibsearch, const std::string & str){

    std::vector <ressource *> * tmp = new std::vector <ressource *>;

    std::cout << "recherche de \"" << str << "\"" << std::endl;

    for ( unsigned int i = 0; i < (* bibsearch)->size() ; i++ ) {
        if ( (* *bibsearch)[i] -> search(str) ) {
            (* tmp).push_back( (* *bibsearch)[i] );
        }
    }

    if ( * * bibsearch != * bib ) {
        (*bibsearch)->clear();
        delete(*bibsearch);
    }

    * bibsearch = tmp;

    std::cout << tmp->size() << " éléments trouvé" << std::endl;

    return;


}
