#ifndef _DVD_H_
#define _DVD_H_

    #include "vhs.h"

    class dvd : public vhs {
        protected:
            unsigned int nbrChapitres;

        public:
            dvd(void);
            dvd(unsigned int _ID);

            virtual void infoDetail (void);

            virtual void setNbrChapitres (unsigned int nbrChapitres);

            virtual void create (void);
            virtual void save (std::ofstream * monFichier);
            virtual char search (const std::string & str);
    };

#endif
