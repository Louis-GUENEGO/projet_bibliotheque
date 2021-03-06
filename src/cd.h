#ifndef _CD_H_
#define _CD_H_

    #include "vhs.h"

    class cd : public vhs {
        
        protected:
            unsigned int nbrPistes;

        public:
            cd (void);
            cd (unsigned int _ID);

            // Méthodes pour modifier les attributs
            virtual void setNbrPiste (unsigned int nbrPistes);

            // Méthodes pour effectuer des actions
            virtual void infoDetail (void);
            virtual void create     (void);
            virtual void save       (std::ofstream * monFichier);
            virtual char search     (const std::string & str);
    };

#endif
