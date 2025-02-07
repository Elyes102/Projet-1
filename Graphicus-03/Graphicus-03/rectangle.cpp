/********
 * Fichier: rectangle.cpp
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#include "forme.h"
#include "rectangle.h"
#include <string>

Rectangle::Rectangle(int x1, int y1, int largeur1, int hauteur1) : Forme(x1, y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
  largeur=largeur1;
  hauteur=hauteur1;
}

Rectangle::~Rectangle()
{
}

void Rectangle::translater(int deltaX, int deltaY)
{
  Forme::translater(deltaX, deltaY);
}
 
void Rectangle::setDimension(int largeur1, int hauteur1)
{
    largeur=largeur1;
    hauteur=hauteur1;
}

string Rectangle::afficher(string s)
{
	s = "R " + to_string(getAncrage().x);
	s += " " + to_string(getAncrage().y);
	s += " " + to_string(largeur);
	s += " " + to_string(hauteur);
	s += "\n";

	return s;
}

int Rectangle::getLargeur() const
{
  return largeur;
}
int Rectangle::getHauteur() const
{
  return hauteur;
}

double Rectangle::aire()
{
	return (double) largeur*hauteur;
}




