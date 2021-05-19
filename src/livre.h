#ifndef _LIVRE_H_
#define _LIVRE_H_

    #include "ressource.h"

    class livre : public ressource {

        protected:
            int          annee;
            unsigned int nbrPages;
            std::string  collection;
            std::string  resume;

        public:
            livre (void);
            livre (unsigned int _ID);

            // Méthodes pour modifier les attributs
            virtual void setAnnee      (int annee);
            virtual void setNbrPages   (unsigned int nbrPages);
            virtual void setCollection (std::string collection);
            virtual void setResume     (std::string resume);

            // Méthodes pour effectuer des actions
            virtual void infoDetail (void);
            virtual void create     (void);
            virtual void save       (std::ofstream * monFichier);
            virtual char search     (const std::string & str);
    };

#endif
