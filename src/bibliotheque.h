#ifndef _BIBLIOTHEQUE_H_
#define _BIBLIOTHEQUE_H_

    #include <vector>
    #include <iostream>
    #include <string>
    #include <cstdlib>

    #include "ressource.h"

    #include "livre.h"
    #include "revue.h"
    #include "cd.h"
    #include "vhs.h"
    #include "dvd.h"
    #include "resnum.h"

    void ihm (void);
    std::string lectureTerminal (void);
    void addType (std::vector <ressource *> &list, std::string);

    livre createLivre (void);
    revue createRevue (void);
    vhs createVHS (void);
    cd createCD (void);
    dvd createDVD (void);
    resnum createRESNUM (void);

#endif
