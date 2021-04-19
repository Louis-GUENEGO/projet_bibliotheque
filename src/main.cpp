#include <iostream>
#include "bibliotheque.h"

int main (int argc, char * argv [] ){

	std::cout << std::endl;

	std::vector <ressource *> list;

	// Test livre
	list.push_back(new livre);
	list[0]->setTitre("TitreDuLivre");
	list[0]->setAuteur("AuteurDuLivre");
	list[0]->setAnnee(420);
	list[0]->setNbrPages(1337);
	list[0]->setCollection("CollectionDuLivre");
	list[0]->setResume("ResumeeDuLivre");
	list[0]->info();
	list[0]->infoDetail();



	return 0;
}
