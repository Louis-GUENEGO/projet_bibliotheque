#ifndef _VHS_H_
#define _VHS_H_

    #include "ressource.h"

    class vhs : public ressource {
        protected:
            unsigned int duree;
            std::string maisonProd;

        public:
            vhs(void);
            vhs(unsigned int _ID);

            virtual void setMaisonProd (std::string maisonProd);
            virtual void setDuree (unsigned int duree);

            virtual void infoDetail(void);
            virtual void create (void);
            virtual void save (std::ofstream * monFichier);
            virtual char search (const std::string & str);
    };

#endif
