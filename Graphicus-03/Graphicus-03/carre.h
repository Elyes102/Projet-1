/********
 * Fichier: carre.h
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Carre : public Forme
{
public:
  Carre(int x = 0, int y = 0, int cote = 1);
  ~Carre();
  void translater(int deltaX, int deltaY);
  double aire();
  string afficher(string s);
  void setCote(int cote1);
  int getCote() const;
  
  
  private:
    int cote=1;
 
};
#endif
