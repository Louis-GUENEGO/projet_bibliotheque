#ifndef _DVD_H_
#define _DVD_H_

    #include "ressource.h"

    class dvd : public ressource {
        protected:
            unsigned int duree;
            unsigned int nbr_pistes;
            std::string maison_prod;

        public:
            dvd(void);
            virtual void setDuree (unsigned int duree);
            virtual void infoDetail(void);
    };

#endif
