#ifndef _CD_H_
#define _CD_H_

    #include "ressource.h"

    class cd : public ressource {
        protected:
            unsigned int duree;
            unsigned int nbr_pistes;
            std::string maison_prod;

        public:
            cd(void);
            virtual void infoDetail(void);
    };

#endif
