#include <iostream>
#include "bibliotheque.h"

int main (int argc, char * argv [] ){

	std::vector <ressource *> list;

	// Test livre
	list.push_back(new livre);
	list[0]->setTitre("TitreDuLivre");
	list[0]->setAuteur("AuteurDuLivre");
	list[0]->setAnnee(420);
	list[0]->setNbrPages(1337);
	list[0]->setCollection("CollectionDuLivre");
	list[0]->setResume("ResumeeDuLivre");
	std::cout << std::endl;
	list[0]->info();
	std::cout << std::endl;
	list[0]->infoDetail();

	// Test revue
	list.push_back(new revue);
	list[1]->setTitre("Titre de la Revue");
	list[1]->setAuteur("Auteur de la Revue");
	list[1]->setAnnee(420);
	list[1]->setNbrPages(1337);
	list[1]->setCollection("Collection de la Revue");
	list[1]->setResume("Resumée de la Revue");
	list[1]->setEditeur("Editeur de la revue");
	list[1]->setNbrArticles(42);
	std::cout << std::endl;
	list[1]->info();
	std::cout << std::endl;
	list[1]->infoDetail();

	// Test VHS
	list.push_back(new vhs);
	list[2]->setTitre("Titre de la VHS");
	list[2]->setAuteur("Auteur de la VHS");
	list[2]->setDuree(42);
	list[2]->setMaisonProd("Maison de production de la VHS");
	std::cout << std::endl;
	list[2]->info();
	std::cout << std::endl;
	list[2]->infoDetail();

	// Test CD
	list.push_back(new cd);
	list[3]->setTitre("Titre de la VHS");
	list[3]->setAuteur("Auteur de la VHS");
	list[3]->setDuree(42);
	list[3]->setMaisonProd("Maison de production de la VHS");
	list[3]->setNbrPiste(1337);
	std::cout << std::endl;
	list[3]->info();
	std::cout << std::endl;
	list[3]->infoDetail();

	// Test DVD
	list.push_back(new dvd);
	list[4]->setTitre("Titre de la VHS");
	list[4]->setAuteur("Auteur de la VHS");
	list[4]->setDuree(420);
	list[4]->setMaisonProd("Maison de production de la VHS");
	list[4]->setNbrChapitres(69);
	std::cout << std::endl;
	list[4]->info();
	std::cout << std::endl;
	list[4]->infoDetail();

	std::cout << std::endl;
	return 0;
}
