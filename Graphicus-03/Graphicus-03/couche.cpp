/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
 * Date : 14 janvier 2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"
using namespace std;


Couche::Couche(){
    etat = 1;
    for (int i=0; i< vecteurForme.getTaille();i++)
    {
    	vecteurForme[i]=nullptr;
    }
  
}

Couche::~Couche(){}

bool Couche::addForme(Forme* forme)
{
   
   if (etat==2)
   {
       vecteurForme.ajoutObjet(&forme);
	   NombreForme++;

       return true;
   }
   cout << "erreur de AddForme" << endl;
   return false;
}
Forme* Couche::removeForme(int index)
{
   if (etat==2)
   {
      
     if (index >= 0 && index < vecteurForme.getTaille())
     { 
       vecteurForme.retraitObjet(index);
	   NombreForme--;
      return 0;
      
     }
    
   }
   return nullptr;
}

Forme* Couche::getForme(int index)
{
   if (etat!=1)
   {
     if (index >= 0 && index < vecteurForme.getTaille())
     {
        return vecteurForme[index];
     }
   }
   return nullptr;
}

double Couche::airTotal() const
{
     double aireTotale = 0.0;
   if (etat!=1)
   {
     for (int i = 0; i < vecteurForme.getTaille(); i++)
     {
        if (vecteurForme[i] != nullptr)
        {
           aireTotale += vecteurForme[i]->aire();
        }
     }
     return aireTotale;
   }
   else
   {
	   cout << "aire null" << endl;
      aireTotale=0;
      return aireTotale;
   }
  
}
int Couche::getAncrageX()
{
    for (int i = 0; i < vecteurForme.getTaille(); i++)
    { 
		if (vecteurForme[i] != nullptr)
	    
	    	return vecteurForme[i]->getAncrage().x;
	    
	}
	  
}
int Couche::getAncrageY()
{
    for (int i = 0; i < vecteurForme.getTaille(); i++)
    {
		if (vecteurForme[i] != nullptr)
            return vecteurForme[i]->getAncrage().y;
        
    }
	
}
bool Couche::translater(int deltaX, int deltaY)
{

	cout <<"etat:"<< etat << endl;
   if (etat==2)
   {
     for (int i = 0; i < vecteurForme.getTaille(); i++)
     {
        if (vecteurForme[i] != nullptr)
        {
            vecteurForme[i]->translater(deltaX, deltaY);
            cout << "translater dans couche.cpp" << endl;
            return true;
        }
     }
     
   }
   cout << "erreur de translater dans couche.cpp" << endl;
   return false;
}
bool Couche::reinitialiser()
{
   if (etat!=1)
   {
      for (int i = 0; i < vecteurForme.getTaille(); i++)
      {
         delete vecteurForme[i];
         vecteurForme[i] = nullptr;

      }
   etat=1;
   return true;
   }
   return false;
}

bool Couche::changeEtat(int etat1)
{
   if (etat1 > 0 && etat1 <= 3)
   {
       etat=etat1;
      return true;
   }
   return false;
}

bool Couche::getTaille()
{
    if (vecteurForme.getTaille())
    {
        return true;
    }
    return false;
}





string Couche::afficher(string s) const
{
    // s << "État: ";
    if (etat == 1)
    {
        s = "L i\n";
    }
    else if (etat == 2)
    {
        s = "L a\n";
    }
    else if (etat == 3)
    {
        s = "L x\n";
    }
    for (int i = 0; i < vecteurForme.getTaille(); i++)
    {
        if (vecteurForme[i] != nullptr)
        {
            Forme* forme = vecteurForme[i];
            // Carre forme2 = Carre();
             //forme2.afficher(s);
           s += vecteurForme[i]->afficher(s);
            //s << endl;
        }
    }
    return s;
}

int Couche::getNombreForme()
{
	return NombreForme;
}

void Couche::setTaille(int taille1)
{
	vecteurForme.setTaille(taille1);
}
