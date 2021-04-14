#include "ressource.h"

#ifndef _RESNUM_H_
#define _RESNUM_H_

enum enumFichier{PDF, DOC, PPT, MP3, MP4}

class resnum : public ressource
{
 private:
  std::string titre;
  std::string auteur;
  enumFichier fichier;
  int taille_oct;
  std::string chemin;
  
 public:
  resnum(void);
  resnum(std::string titre, std::string auteur, enumFichier fichier, int taille_oct, std::string chemin);
  
  void info(void);
  void infoDetail(void);
  
};

#endif
