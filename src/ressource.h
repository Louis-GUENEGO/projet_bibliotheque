#ifndef _RESSOURCE_H_
#define _RESSOURCE_H_

    #include <iostream>
    #include <string>

    enum typeRessource {LIVRE, REVUE, CD, VHS, DVD, RESNUM};

    class ressource {

        protected:
            typeRessource type;
            std::string titre;
            std::string auteur;

        public:
            ressource();

            // méthodes virtuelles communes
            virtual void setTitre (std::string titre);
            virtual void setAuteur (std::string auteur);
            virtual void info (void);
            virtual void infoDetail (void);

            // méthodes virtuelles Livres
            virtual void setAnnee (int annee);
            virtual void setNbrPages (unsigned int nbrPages);
            virtual void setCollection (std::string collection);
            virtual void setResume (std::string resume);

            // méthodes virtuelles revues
            virtual void setEditeur (std::string editeur);
            virtual void setNbrArticles (unsigned int nrbArticles);

            // méthodes virtuelles VHS
            virtual void setMaisonProd (std::string maisonProd);
            virtual void setDuree (unsigned int duree);

            // méthodes virtuelles CD
            virtual void setNbrPiste (unsigned int nbrPistes);

            // méthodes virtuelles dvd
            virtual void setNbrChapitres (unsigned int nbrChapitres);
    };

#endif
