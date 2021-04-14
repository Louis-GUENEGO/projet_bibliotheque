#include <iostream>
#include "bibliotheque.h"

int main (int argc, char * argv [] ){

	std::vector <ressource *> list;

	list.push_back(new livre);

	list[0]->setTitre("bonjour");
	list[0]->setAuteur("loulou");
	list[0]->setDuree(30);
	list[0]->info();


	list.pop_back();
	return 0;
}
