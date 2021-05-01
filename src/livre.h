#ifndef _LIVRE_H_
#define _LIVRE_H_

    #include "ressource.h"

    class livre : public ressource {
        protected:

            int annee;
            unsigned int nbrPages;
            std::string collection;
            std::string resume;

        public:
            livre(void);

            virtual void setAnnee (int annee);
            virtual void setNbrPages (unsigned int nbrPages);
            virtual void setCollection (std::string collection);
            virtual void setResume (std::string resume);

            virtual void infoDetail (void);
            virtual void create (void);
            virtual void save (std::ofstream * monFichier);
    };

#endif
