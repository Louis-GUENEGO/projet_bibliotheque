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
            addType(list, cmd);
        }

        std::cout << list.size() << " éléments dans la bibliothèque" << std::endl;

        for (unsigned int i = 0; i < list.size() ; i++) {
            list[i]->infoDetail();
        }

    }

    return;
}

std::string lectureTerminal (void) {
    std::string chaine;
    getline (std::cin, chaine);
    return chaine;
}

void addType (std::vector <ressource *> &list, std::string cmd) {

    if (cmd.size() == 9) {
        if ( (cmd.compare(4,5,"LIVRE")==0) || (cmd.compare(4,5,"livre")==0) ) {
            livre * nouvLivre = new livre;
            * nouvLivre = createLivre();
            list.push_back( nouvLivre );

        } else if ( (cmd.compare(4,5,"REVUE")==0) || (cmd.compare(4,5,"revue")==0) ) {
            revue * nouvRevue = new revue;
            * nouvRevue = createRevue();
            list.push_back( nouvRevue );
        }

    } else if (cmd.size() == 10) {
        if ( (cmd.compare(4,6,"RESNUM")==0) || (cmd.compare(4,6,"resnum")==0) ) {
            std::cout << "création ressource numérique" << std::endl;
        }

    } else if (cmd.size() == 7) {
        if ( (cmd.compare(4,3,"VHS")==0) || (cmd.compare(4,3,"vhs")==0) ) {
            std::cout << "création VHS" << std::endl;

        } else if ( (cmd.compare(4,5,"DVD")==0) || (cmd.compare(4,5,"dvd")==0) ) {
            std::cout << "création DVD" << std::endl;
        }

    } else if (cmd.size() == 6) {
        if ( (cmd.compare(4,6,"CD")==0) || (cmd.compare(4,6,"cd")==0) ) {
            std::cout << "création CD" << std::endl;
        }

    } else {
        return;
    }
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
    newRevue.setAnnee(std::stoi(lectureTerminal()));
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





vhs createVHS (void){}
cd createCD (void){}
dvd createDVD (void){}
resnum createRESNUM (void){}
