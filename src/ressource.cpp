#include "ressource.h"

ressource::ressource (void) {
    std::cout << "constructeur ressource" << std::endl;
}

void ressource::setTitre (std::string _titre){
    titre = _titre;
}
