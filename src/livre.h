#ifndef _LIVRE_H_
#define _LIVRE_H_

    #include "ressource.h"

    class livre : public ressource
    {
     private:
        std::string titre;
        std::string auteur;
        int annee;
        int nbr_pages;
        std::string collection;
        std::string resume;

     public:
        livre(void);
        livre(std::string titre, std::string auteur, int annee, int nbr_pages, std::string collection, std::string resume);

        

        void info(void);
        void infoDetail(void);
    };

#endif
