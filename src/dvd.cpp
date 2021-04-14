#include "dvd.h"

dvd::dvd(void){
    titre = "(vide)";
    duree = 0;
    nbr_pistes = 0;
    auteur = "(vide)";
    maison_prod = "(vide)";
}

void dvd::setTitre (std::string _titre){
    titre = _titre;
}

void dvd::setDuree (int _duree){
    duree = _duree;
}

void dvd::info(void) {
    
}
