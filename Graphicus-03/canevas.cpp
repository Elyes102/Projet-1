/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : Elyes ismail(isme2473) et Philippe Lecours(lecp2055) 
 * Date : 14 janvier 2025
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
#include "sstream"

using namespace std;

Canevas::Canevas()
{

}

Canevas::~Canevas()
{
	vecteur.viderVecteur();
}

bool Canevas::ajouterCouche()
{
	
	Couche *couche= new Couche();
	
	bool trouverCoucheActive = false;
	vecteur.ajoutObjet(couche);
	
		

	
	for (int i=0;i < vecteur.getTaille();i++)
	{
		if (vecteur.objet[i]!=nullptr && vecteur.objet[i]->etat==2  ) //verifier
		 {
		 trouverCoucheActive = true;
		 
		}
	}
	if(!trouverCoucheActive){
	vecteur.objet[vecteur.getTaille()-1]->changeEtat(2);
	}
		 	
		return true;
}

bool Canevas::ajouterCoucheFichier()
{

	Couche* couche = new Couche();

	bool trouverCoucheActive = false;
	vecteur.ajoutObjet(couche);

	for (int i = 0; i < vecteur.getTaille() - 1; i++)
	{
		vecteur.objet[i]->changeEtat(1);
	}
	
		vecteur.objet[vecteur.getTaille() - 1]->changeEtat(2);
	

	return true;
}

bool Canevas::retirerCouche()
{
	for (int i=0;i<vecteur.getTaille();i++)
	{

		if (vecteur.objet[i]!=nullptr && vecteur.objet[i]->etat == 2)
		{
		
			reinitialiserCouche(i);
			vecteur.retraitObjet(i);
			return true;
		}
	}
return false;
}


bool Canevas::reinitialiser()
{
	for (int i = 0; i < vecteur.getTaille(); i++)
      {
         delete vecteur.objet[i];
         vecteur.objet[i] = nullptr;

      }
      vecteur.setCapacite(1);
      vecteur.setTaille(0);
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
	vecteur.objet[index]->reinitialiser();
	if(vecteur.objet[index]->etat!=2)
	{
		vecteur.objet[index]->etat=1;
	}
	
   return true;
}


bool Canevas::activerCouche(int index)
{
if(vecteur.objet[index]!=nullptr && index>=0 && vecteur.getTaille()>index)
{
	for(int i=0;i<vecteur.getTaille();i++)
	{
	
		if(vecteur.objet[i]->etat==2)
		{
			desactiverCouche(i);
		}
	}
	
	vecteur.objet[index]->etat=2;
	vecteur.indexItemCourant = index;
	
   return true;
  }
  return false;
}

bool Canevas::desactiverCouche(int index)
{
	vecteur.objet[index]->etat=3;
   return true;
}


bool Canevas::ajouterForme(Forme *p_forme)
{
	
	for(int i=0;i<vecteur.getTaille();i++)
	{

		if(vecteur.objet[i]->etat==2)
		{
			
			vecteur.objet[i]->addForme(p_forme);
			tailleVecteurForme++;
			return true;
		}
		
	}
   return false;
}

bool Canevas::retirerForme()
{
	
	if (vecteur.getTaille()>=0)
	{ 
		for (int i = 0;i < vecteur.getTaille();i++)
		{
			if (vecteur.objet[i]->etat == 2)
			{
				Couche* couche = vecteur.objet[i];
				cout << couche->vecteurForme.getTaille() << endl;
				for (int j = 0;j < couche->vecteurForme.getTaille();j++)
				{
					if (couche->vecteurForme[j] != nullptr)
					{
						vecteur.objet[j]->removeForme(j);
						tailleVecteurForme--;
						return true;
					}
				}
			}
		}
	}
   return false;
}

double Canevas::aire()
{
	double aireTotal=0.0;
	for(int i=0;i<vecteur.getTaille();i++)
	{
		aireTotal+=vecteur.objet[i]->airTotal();
	}
	
		
   return aireTotal;
}

bool Canevas::translater(int deltaX, int deltaY)
{

for(int i=0;i<vecteur.getTaille();i++)
	{
		if(vecteur.objet[i]->etat==2)
		{
			vecteur.objet[i]->translater(deltaX, deltaY);
			return true;
		}
		
	}
   return false;
}

int Canevas::getIndexCourant()
{
	indexCourant = vecteur.indexItemCourant;
	return indexCourant;
	
}

int Canevas::getTaille()
{
	return vecteur.getTaille();
}

string Canevas::afficher(string s)
{

		s += vecteur.afficher(s);
		return s;

}



int Canevas::getNombreFormes()
{
	return vecteur[indexCourant].getNombreForme();
}

















