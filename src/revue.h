#ifndef _REVUE_H_
#define _REVUE_H_

    #include "ressource.h"

    class revue : public ressource {
        protected:
            int annee;
            unsigned int nbr_pages;
            std::string collection;
            std::string resume;
            std::string editeur;
            unsigned int nbr_article;

        public:
            revue(void);
            void infoDetail(void);
    };

#endif
