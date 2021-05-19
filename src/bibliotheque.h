#ifndef _BIBLIOTHEQUE_H_
#define _BIBLIOTHEQUE_H_

    #define DEFAULT_BIB_LOAD "load bib" // commande de chargement automatique

    // bibliothèques standards
    #include <vector>
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <fstream>

    // objet ressource et sous objets
    #include "ressource.h"
    #include "livre.h"
    #include "revue.h"
    #include "cd.h"
    #include "vhs.h"
    #include "dvd.h"
    #include "resnum.h"

    // interface homme machine
    void ihm (void);

    // fonctions pour les commandes complexes
    void afficheBib (std::vector <ressource *> * bib);
    void addType    (std::vector <ressource *> * bib, std::string cmd);
    void loadBib    (std::vector <ressource *> * bib, std::string cmd);
    void saveBib    (std::vector <ressource *> * bib, std::string cmd);
    void resetBib   (std::vector <ressource *> * bib);
    void searchBib  (std::vector <ressource *> * bib, std::vector <ressource *> * * bibsearch, const std::string & str);
    char login      (void);
    void showID     (std::vector <ressource *> * bib, std::string cmd);
    void deleteID   (std::vector <ressource *> * bib, std::string cmd);

    // fonctions auxiliaires
    char newIdFree  (std::vector <ressource *> * bib);

#endif
