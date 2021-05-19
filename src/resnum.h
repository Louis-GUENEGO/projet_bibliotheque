#ifndef _RESNUM_H_
#define _RESNUM_H_

    #include "ressource.h"

    class resnum : public ressource {
        
        protected:
            std::string  format;
            unsigned int taille;
            std::string  chemin;

        public:
            resnum (void);
            resnum (unsigned int _ID);

            // Méthodes pour modifier les attributs
            virtual void setFormat (std::string format);
            virtual void setTaille (unsigned int taille);
            virtual void setChemin (std::string chemin);

            // Méthodes pour effectuer des actions
            virtual void infoDetail (void);
            virtual void create     (void);
            virtual void save       (std::ofstream * monFichier);
            virtual char search     (const std::string & str);
    };

#endif
