#ifndef _LIVRE_H_
#define _LIVRE_H_

    #include "ressource.h"

    class livre : public ressource
    {
     private:

        std::string auteur;
        int annee;
        int nbrPages;
        std::string collection;
        std::string resume;

     public:
        livre(void);
        livre(std::string titre, std::string auteur, int annee, int nbr_pages, std::string collection, std::string resume);

        virtual void setTitre (std::string titre);
        virtual void setAuteur (const char * auteur);
        void setAnnee (int annee);
        void setNbrPages (int nbr_pages);
        void setCollection (const char * collection);
        void setResume (const char * resume);

        virtual void setDuree (int duree);

        virtual void info(void);
        void infoDetail(void);
    };

#endif
