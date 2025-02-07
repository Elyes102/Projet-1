/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : Elyes ismail(isme2473) et Philippe Lecours(lecp2055) 
 * Date : 14 janvier 2025
 * Description: Declaration de la classe Canevas. La classe Canevas gere un 
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"



using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool ajouterCouche();
   bool retirerCouche();

   bool ajouterCoucheFichier();

   bool reinitialiser();
   bool reinitialiserCouche(int index);
   
   bool activerCouche(int index);
   bool desactiverCouche(int index);
   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme();
   
   double aire();
   bool translater(int deltaX, int deltaY);
   string afficher(string s);
   int getIndexCourant();
   int getTaille();
   int getNombreFormes();
   int tailleVecteurForme=0;
   int indexCourant=0;

private:   
   Vecteur<Couche> vecteur;
   Vecteur<Forme*> vecteurForme;
   
};

#endif
