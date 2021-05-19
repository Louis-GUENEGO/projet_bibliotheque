#ifndef _REVUE_H_
#define _REVUE_H_

    #include "livre.h"

    class revue : public livre {

        protected:
            std::string  editeur;
            unsigned int nbrArticles;

        public:
            revue (void);
            revue (unsigned int _ID);

            // Méthodes pour modifier les attributs
            virtual void setEditeur     (std::string editeur);
            virtual void setNbrArticles (unsigned int nrbArticles);

            // Méthodes pour effectuer des actions
            virtual void infoDetail (void);
            virtual void create     (void);
            virtual void save       (std::ofstream * monFichier);
            virtual char search     (const std::string & str);
    };

#endif
