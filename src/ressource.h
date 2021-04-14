#ifndef _RESSOURCE_H_
#define _RESSOURCE_H_

    #include <iostream>
    #include <string>

    class ressource {
        public:
            ressource();

            virtual void setTitre (std::string titre) = 0;

            virtual void setAuteur (const char * auteur) = 0;

            virtual void setDuree (int duree) = 0;

            virtual void info (void) = 0;

        protected:
            enum {LIVRE, REVUE, CD, VHS, DVD, RESNUM} type;
            std::string titre;
    };

#endif
