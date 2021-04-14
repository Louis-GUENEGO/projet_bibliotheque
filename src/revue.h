#include "ressource.h"

#ifndef _REVUE_H_
#define _REVUE_H_

class revue : public ressource
{
 private:
    std::string titre;
    std::string auteur;
    int annee;
    int nbr_pages;
    std::string collection;
    std::string resume;
    std::string editeur;
    int nbr_article;
    
 public:
    revue(std::string titre, std::string auteur, int annee, int nbr_pages, std::string collection, std::string resume, std::string editeur, int nbr_article);
    
    void info(void);
    void infoDetail(void);
    
};

#endif
