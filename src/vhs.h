#include "ressource.h"

#ifndef _VHS_H_
#define _VHS_H_

class vhs : public ressource
{
 private:
  std::string titre;
  int duree;
  std::string auteur;
  std::string maison_prod;
  
 public:
  vhs(void);
  vhs(std::string titre, int duree, std::string auteur, std::string maison_prod);
  
  void info(void);
  void infoDetail(void);
  
};

#endif
