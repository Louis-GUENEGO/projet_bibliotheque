#ifndef _RESNUM_H_
#define _RESNUM_H_

    #include "ressource.h"

    class resnum : public ressource {
        protected:
            std::string format;
            unsigned int taille;
            std::string chemin;

        public:
            resnum(void);
            virtual void setFormat (std::string format);
            virtual void setTaille (unsigned int taille);
            virtual void setChemin (std::string chemin);
            virtual void infoDetail(void);

            virtual void create (void);
            virtual void save (std::ofstream * monFichier);
    };

#endif
