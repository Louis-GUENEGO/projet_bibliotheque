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
    std::string lectureTerminal (void);

    void addType (std::vector <ressource *> * list, std::string cmd);
    void loadBib (std::vector <ressource *> * list, std::string cmd);

    livre   createLivre     (void);
    revue   createRevue     (void);
    vhs     createVHS       (void);
    cd      createCD        (void);
    dvd     createDVD       (void);
    resnum  createRESNUM    (void);

    livre   lectureLivre    (std::ifstream * monFichier);
    revue   lectureRevue    (std::ifstream * monFichier);
    vhs     lectureVHS      (std::ifstream * monFichier);
    cd      lectureCD       (std::ifstream * monFichier);
    dvd     lectureDVD      (std::ifstream * monFichier);
    resnum  lectureRESNUM   (std::ifstream * monFichier);
#endif
