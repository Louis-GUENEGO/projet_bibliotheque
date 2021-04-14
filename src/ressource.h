#ifndef _RESSOURCE_H_
#define _RESSOURCE_H_

    #include <iostream>
    #include <string>

    class ressource {
        public:
            ressource();

            virtual void setTitre (std::string titre);

            virtual void setAuteur (const char * auteur);

            virtual void setDuree (int duree);

            virtual void info (void) = 0;

        protected:
            enum {LIVRE, REVUE, CD, VHS, DVD, RESNUM} type;
            std::string titre;
    };

#endif
