#ifndef _DVD_H_
#define _DVD_H_

    #include "vhs.h"

    class dvd : public vhs {
        protected:
            unsigned int nbrChapitres;

        public:
            dvd(void);
            virtual void infoDetail (void);

            virtual void setNbrChapitres (unsigned int nbrChapitres);
    };

#endif
