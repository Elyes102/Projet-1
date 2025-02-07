/********
 * Fichier: carre.cpp
 * Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date: 14 janvier 2025 
********/
#include "forme.h"
#include "carre.h"
#include <string>

Carre::Carre(int x1, int y1, int cote1) : Forme(x1, y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
  cote=cote1;
}

Carre::~Carre()
{
}

void Carre::translater(int deltaX, int deltaY)
{
  Forme::translater(deltaX, deltaY);
}
 
void Carre::setCote(int cote1)
{
    cote=cote1;
  
}

string Carre::afficher(string s)
{
	s = "K "+ to_string(getAncrage().x);
	s += " " + to_string(getAncrage().y);
	s += " " + to_string(cote);
	s += "\n";
	return s;
}

int Carre::getCote() const
{
	return cote;
}


double Carre::aire()
{
	return (double) cote*cote;
}




