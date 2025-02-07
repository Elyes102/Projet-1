/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date : 14 janvier 2025
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "forme.h"
#include "Vecteur.h"
const int MAX_FORMES = 5;



class Couche
{
   public:
     Couche();
      ~Couche(); 
   bool addForme(Forme* forme);
   Forme* removeForme(int index);
   Forme* getForme(int index);
   double airTotal() const;
   bool translater(int deltaX, int deltaY);
   bool reinitialiser();
   bool changeEtat(int etat1);
   bool getTaille();
   void setTaille(int taille1);
   string afficher(string s) const;
   int getNombreForme();
   int getAncrageX();
   int getAncrageY();
   int etat;
   int indexForme = 0;
   //Forme *formes[MAX_FORMES];
   Vecteur<Forme*> vecteurForme;
   
private:
    int NombreForme = 0;
    
};

#endif
