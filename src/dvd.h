#include "ressource.h"

#ifndef _DVD_H_
#define _DVD_H_

class dvd : public ressource
{
 private:
  std::string titre;
  int duree;
  int nbr_pistes;
  std::string auteur;
  std::string maison_prod;
  
 public:
  dvd(void);
  dvd(std::string titre, int duree, int nbr_pistes, std::string auteur, std::string maison_prod);
  
  void info(void);
  void infoDetail(void);
  
};

#endif
