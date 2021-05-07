#include "bibliotheque.h"

void ihm (void){

    std::vector <ressource *> list;

    std::vector <ressource *> * listsearchinter = &list;

    std::vector <ressource *> * * listsearch = &listsearchinter;

    std::string cmd;

    std::cout << "Entrez votre commande" << std::endl;

    while (1) {
        getline (std::cin, cmd);

        if ( (cmd.compare(0,3,"BYE")==0) || (cmd.compare(0,3,"bye")==0) ) {
            break;
        } else if ( (cmd.compare(0,3,"ADD")==0) || (cmd.compare(0,3,"add")==0) ) {
            addType(&list, cmd);
        } else if ( (cmd.compare(0,4,"LOAD")==0) || (cmd.compare(0,4,"load")==0) ) {
            loadBib(&list, cmd);
        } else if ( (cmd.compare(0,4,"SAVE")==0) || (cmd.compare(0,4,"save")==0) ) {
            saveBib(&list, cmd);
        } else if ( (cmd.compare(0,5,"RESET")==0) || (cmd.compare(0,5,"reset")==0) ) {
            resetBib(&list);
        } else if ( (cmd.compare(0,6,"SEARCH")==0) || (cmd.compare(0,6,"search")==0) ) {
            std::string cmdbuff = cmd.substr(7,cmd.size()-7);
            searchBib(&list,listsearch, cmdbuff);
        } else if ( (cmd.compare(0,6,"CLEAR")==0) || (cmd.compare(0,6,"clear")==0) ) {
            (*listsearch)->clear();
            * listsearch =  &list;
            std::cout << "résultat de recherche réinitialisé" << std::endl;
        } else if ( (cmd.compare(0,6,"LIST")==0) || (cmd.compare(0,6,"list")==0) ) {
            afficheBib(* listsearch);
        } else {
            std::cout << "commande non reconnue" << std::endl;
        }

        std::cout << std::endl;
    }

    return;
}

void afficheBib (std::vector <ressource *> * list){
    std::cout << std::endl << list->size() << " éléments dans la bibliothèque" << std::endl;

    for (unsigned int i = 0; i < list->size() ; i++) {
        std::cout << std::endl;
        (* list)[i]->infoDetail();
    }
    std::cout << std::endl;

    return;
}

void resetBib (std::vector <ressource *> * list) {
    // purge pour éviter les fuites mémoire
    for ( unsigned int i = 0; i < list->size() ; i++ ) {
        delete (* list)[i];
    }
    // reset de la bibliotheque
    list->clear();

    return;
}

void addType (std::vector <ressource *> * list, std::string cmd) {

    if (cmd.size() == 9) {
        if ( (cmd.compare(4,5,"LIVRE")==0) || (cmd.compare(4,5,"livre")==0) ) {
            livre * nouvLivre = new livre;
            nouvLivre->create();
            list->push_back( nouvLivre );

        } else if ( (cmd.compare(4,5,"REVUE")==0) || (cmd.compare(4,5,"revue")==0) ) {
            revue * nouvRevue = new revue;
            nouvRevue->create();
            list->push_back( nouvRevue );
        }

    } else if (cmd.size() == 10) {
        if ( (cmd.compare(4,6,"RESNUM")==0) || (cmd.compare(4,6,"resnum")==0) ) {
            resnum * nouvRESNUM = new resnum;
            nouvRESNUM->create();
            list->push_back( nouvRESNUM );
        }

    } else if (cmd.size() == 7) {
        if ( (cmd.compare(4,3,"VHS")==0) || (cmd.compare(4,3,"vhs")==0) ) {
            vhs * nouvVHS = new vhs;
            nouvVHS->create();
            list->push_back( nouvVHS );

        } else if ( (cmd.compare(4,5,"DVD")==0) || (cmd.compare(4,5,"dvd")==0) ) {
            dvd * nouvDVD = new dvd;
            nouvDVD->create();
            list->push_back( nouvDVD );
        }

    } else if (cmd.size() == 6) {
        if ( (cmd.compare(4,6,"CD")==0) || (cmd.compare(4,6,"cd")==0) ) {
            cd * nouvCD = new cd;
            nouvCD->create();
            list->push_back( nouvCD );
        }

    } else {
        return;
    }
}

void loadBib (std::vector <ressource *> * list, std::string cmd) {

    resetBib(list);

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
                    list->push_back(newLivre);
                } else if (buff.compare(5, 5, "revue") == 0) {
                    revue * newRevue = new revue;
                    newRevue->lecture(monFichier);
                    list->push_back(newRevue);
                } else if (buff.compare(5, 3, "vhs") == 0) {
                    vhs * newVHS = new vhs;
                    newVHS->lecture(monFichier);
                    list->push_back(newVHS);
                } else if (buff.compare(5, 2, "cd") == 0) {
                    cd * newCD = new cd;
                    newCD->lecture(monFichier);
                    list->push_back(newCD);
                } else if (buff.compare(5, 3, "dvd") == 0) {
                    dvd * newDVD = new dvd;
                    newDVD->lecture(monFichier);
                    list->push_back(newDVD);
                } else if (buff.compare(5, 6, "resnum") == 0) {
                    resnum * newRESNUM = new resnum;
                    newRESNUM->lecture(monFichier);
                    list->push_back(newRESNUM);
                }
            }
        }

        std::cout << "chargement de \"" << cmd.substr(5, cmd.size() - 5) << "\" réussis" << std::endl;
    }

    monFichier->close();
    delete monFichier;

    return;
}

void saveBib (std::vector <ressource *> * list, std::string cmd) {

    std::ofstream * monFichier = new std::ofstream;

    monFichier->open ( cmd.substr(5, cmd.size() - 5).c_str());

    if ( monFichier->fail() ) {
        std::cout << "impossible de sauvegarder dans \"" << cmd.substr(5, cmd.size() - 5) << "\"" << std::endl;
    } else {

        for (int i = 0 ; i < list->size() ; i++) {
            (* list)[i]->save(monFichier);
            *monFichier << "\n";
        }
        std::cout << "sauvegarde dans \"" << cmd.substr(5, cmd.size() - 5) << "\" réussis" << std::endl;
    }

    monFichier->close();
    delete monFichier;

    return;
}

void searchBib (std::vector <ressource *> * list, std::vector <ressource *> * * listsearch, const std::string & str){

    std::vector <ressource *> * tmp = new std::vector <ressource *>;

    std::cout << "recherche de \"" << str << "\"" << std::endl;

    for ( unsigned int i = 0; i < (* listsearch)->size() ; i++ ) {
        if ( (* *listsearch)[i] -> search(str) ) {
            (* tmp).push_back( (* *listsearch)[i] );
        }
    }

    if ( * * listsearch != * list ) {
        (*listsearch)->clear();
        delete(*listsearch);
    }

    * listsearch = tmp;

    std::cout << tmp->size() << " éléments trouvé" << std::endl;

    return;
}
