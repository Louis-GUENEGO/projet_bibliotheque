#ifndef _VHS_H_
#define _VHS_H_

    #include "ressource.h"

    class vhs : public ressource {
        protected:
            unsigned int duree;
            std::string maison_prod;

        public:
            vhs(void);
            void infoDetail(void);
    };

#endif
