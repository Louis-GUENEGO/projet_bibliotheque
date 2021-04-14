#include <iostream>
#include "bibliotheque.h"

int main (int argc, char * argv [] ){

	std::vector <ressource *> list;

	list.push_back(new livre);
	list.pop_back();

	std::cout << list.size() << std::endl;
	return 0;
}
