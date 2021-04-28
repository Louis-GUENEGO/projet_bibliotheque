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

        if ( (cmd.compare(0,4,"LOAD")==0) || (cmd.compare(0,4,"load")==0) ) {
            loadBib(list, cmd);
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
            resnum * nouvRESNUM = new resnum;
            * nouvRESNUM = createRESNUM();
            list.push_back( nouvRESNUM );
        }

    } else if (cmd.size() == 7) {
        if ( (cmd.compare(4,3,"VHS")==0) || (cmd.compare(4,3,"vhs")==0) ) {
            vhs * nouvVHS = new vhs;
            * nouvVHS = createVHS();
            list.push_back( nouvVHS );

        } else if ( (cmd.compare(4,5,"DVD")==0) || (cmd.compare(4,5,"dvd")==0) ) {
            dvd * nouvDVD = new dvd;
            * nouvDVD = createDVD();
            list.push_back( nouvDVD );
        }

    } else if (cmd.size() == 6) {
        if ( (cmd.compare(4,6,"CD")==0) || (cmd.compare(4,6,"cd")==0) ) {
            cd * nouvCD = new cd;
            * nouvCD = createCD();
            list.push_back( nouvCD );
        }

    } else {
        return;
    }
}



void loadBib (std::vector <ressource *> &list, std::string cmd) {

	list.clear();
	std::cout << list.size() << std::endl;

    std::cout << "loading " << cmd.substr(5, cmd.size() - 5) << std::endl;

    return;
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
