#ifndef _BIBLIOTHEQUE_H_
#define _BIBLIOTHEQUE_H_

    #define DEFAULT_BIB_LOAD "load bib"

    #include <vector>
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <fstream>

    #include "ressource.h"

    #include "livre.h"
    #include "revue.h"
    #include "cd.h"
    #include "vhs.h"
    #include "dvd.h"
    #include "resnum.h"

    void ihm (void);

    void afficheBib (std::vector <ressource *> * bib);
    void addType   (std::vector <ressource *> * bib, std::string cmd);
    void loadBib   (std::vector <ressource *> * bib, std::string cmd);
    void saveBib   (std::vector <ressource *> * bib, std::string cmd);
    void resetBib  (std::vector <ressource *> * bib);
    void searchBib (std::vector <ressource *> * bib, std::vector <ressource *> * * bibsearch, const std::string & str);

    char newIdFree (std::vector <ressource *> * bib);

    void showID   (std::vector <ressource *> * bib, std::string cmd);
    void deleteID   (std::vector <ressource *> * bib, std::string cmd);

    char login (void);

#endif
