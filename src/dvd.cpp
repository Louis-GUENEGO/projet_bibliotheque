#include "dvd.h"

dvd::dvd(void){
    titre = "(vide)";
    duree = 0;
    nbr_pistes = 0;
    auteur = "(vide)";
    maison_prod = "(vide)";
}

void dvd::setDuree (unsigned int _duree){
    duree = _duree;
}

void dvd::infoDetail(void) {

}
