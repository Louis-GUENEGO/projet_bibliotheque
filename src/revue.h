#ifndef _REVUE_H_
#define _REVUE_H_

    #include "livre.h"

    class revue : public livre {
        protected:
            std::string editeur;
            unsigned int nbrArticles;

        public:
            revue(void);

            virtual void setEditeur (std::string editeur);
            virtual void setNbrArticles (unsigned int nrbArticles);

            virtual void infoDetail(void);
            virtual void create (void);
            virtual void save (std::ofstream * monFichier);
    };

#endif
