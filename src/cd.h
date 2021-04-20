#ifndef _CD_H_
#define _CD_H_

    #include "vhs.h"

    class cd : public vhs {
        protected:
            unsigned int nbrPistes;

        public:
            cd(void);
            virtual void setNbrPiste (unsigned int nbrPistes);
            virtual void infoDetail (void);
    };

#endif
