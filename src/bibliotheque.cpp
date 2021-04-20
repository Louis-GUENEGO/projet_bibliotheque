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
            std::cout << "création livre" << std::endl;
            livre * truc = new livre;
            *truc = createLivre();
            list.push_back( truc );

        } else if ( (cmd.compare(4,5,"REVUE")==0) || (cmd.compare(4,5,"revue")==0) ) {
            std::cout << "création revue" << std::endl;
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

    livre newLivre;
	newLivre.setTitre("TitreDuLivre");
	newLivre.setAuteur("AuteurDuLivre");
	newLivre.setAnnee(420);
	newLivre.setNbrPages(1337);
	newLivre.setCollection("CollectionDuLivre");
	newLivre.setResume("ResumeeDuLivre");

    return newLivre;
}
