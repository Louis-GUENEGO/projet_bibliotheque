#ifndef _BIBLIOTHEQUE_H_
#define _BIBLIOTHEQUE_H_

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

    void afficheBib (std::vector <ressource *> * list);
    void addType   (std::vector <ressource *> * list, std::string cmd);
    void loadBib   (std::vector <ressource *> * list, std::string cmd);
    void saveBib   (std::vector <ressource *> * list, std::string cmd);
    void resetBib  (std::vector <ressource *> * list);
    void searchBib (std::vector <ressource *> * * list, const std::string & str, char supp);

#endif
