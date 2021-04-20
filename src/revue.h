#ifndef _REVUE_H_
#define _REVUE_H_

    #include "ressource.h"
    #include "livre.h"

    class revue : public livre {
        protected:
            std::string editeur;
            unsigned int nrbArticles;

        public:
            revue(void);

            virtual void setEditeur (std::string editeur);
            virtual void setNbrArticles (unsigned int nrbArticles);

            virtual void infoDetail(void);
    };

#endif
