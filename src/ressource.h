#ifndef _RESSOURCE_H_
#define _RESSOURCE_H_

    #include <iostream>
    #include <string>

    enum typeRessource {LIVRE, REVUE, CD, VHS, DVD, RESNUM};

    class ressource {
        public:
            ressource();

            // méthodes virtuelles communes
            virtual void setTitre (std::string titre);
            virtual void setAuteur (std::string auteur);
            virtual void info (void);
            virtual void infoDetail (void);

            // méthodes virtuelles Livres
            virtual void setAnnee (int annee);
            virtual void setNbrPages (unsigned int nbr_pages);
            virtual void setCollection (std::string collection);
            virtual void setResume (std::string resume);

            // méthodes virtuelles DVD

        protected:
            typeRessource type;
            std::string titre;
            std::string auteur;
    };

#endif
