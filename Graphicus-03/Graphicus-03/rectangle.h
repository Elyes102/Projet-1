/********
 * Fichier: rectangle.h
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "coordonnee.h"
#include "forme.h"

using namespace std;

class Rectangle : public Forme
{
public:
  Rectangle(int x = 0, int y = 0, int largeur = 1, int hauteur = 1);
  ~Rectangle();
  void translater(int deltaX, int deltaY);
  double aire();
  string afficher(string s);
  void setDimension(int largeur1, int hauteur1);
  int getLargeur() const;
  int getHauteur() const;
  
  
  private:
    int largeur=1;
    int hauteur=1;
};
#endif
