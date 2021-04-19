#ifndef _RESNUM_H_
#define _RESNUM_H_

    #include "ressource.h"

    enum enumFichier{PDF, DOC, PPT, MP3, MP4};

    class resnum : public ressource {
        protected:
            enumFichier fichier;
            int taille_oct;
            std::string chemin;

        public:
            resnum(void);
            void infoDetail(void);
    };

#endif
