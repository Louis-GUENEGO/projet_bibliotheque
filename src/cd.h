#include "ressource.h"

#ifndef _CD_H_
#define _CD_H_

class cd : public ressource
{
 private:
  std::string titre;
  int duree;
  int nbr_pistes;
  std::string auteur;
  std::string maison_prod;
  
 public:
  cd(void);
  cd(std::string titre, int duree, int nbr_pistes, std::string auteur, std::string maison_prod);
  
  void info(void);
  void infoDetail(void);
  
};

#endif
