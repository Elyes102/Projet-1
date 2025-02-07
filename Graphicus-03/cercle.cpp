/********
 * Fichier: cercle.cpp
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#include "forme.h"
#include "cercle.h"
#include <string>

Cercle::Cercle(int x1, int y1, int rayon1) : Forme(x1, y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
  rayon=rayon1;
}

Cercle::~Cercle()
{
}

void Cercle::translater(int deltaX, int deltaY)
{
  Forme::translater(deltaX, deltaY);
}
 
void Cercle::setRayon(int rayon1)
{
    rayon=rayon1;
  
}

string Cercle::afficher(string s)
{
	s = "C " + to_string(getAncrage().x);
	s += " " + to_string(getAncrage().y);
	s += " " + to_string(rayon);
	s += "\n";
	return s;
}

int Cercle::getRayon() const
{
	return rayon;
}


double Cercle::aire()
{
	return (double) 3.14159*(rayon*rayon);
}




