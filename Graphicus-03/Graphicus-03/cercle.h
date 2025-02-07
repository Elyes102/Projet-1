/********
 * Fichier: cercle.h
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Cercle : public Forme
{
public:
  Cercle(int x = 0, int y = 0, int rayon = 1);
  ~Cercle();
  void translater(int deltaX, int deltaY);
  double aire();
  string afficher(string s);
  void setRayon(int rayon1);
  int getRayon() const;
  
  
  private:
    int rayon;
 
};
#endif
