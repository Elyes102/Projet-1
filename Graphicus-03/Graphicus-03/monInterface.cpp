/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/


#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* titre)
{
	reinitialiserCanevas();
	effacerInformations();
}

void MonInterface::reinitialiserCanevas()
{
	canevas.reinitialiser();
	canevas.tailleVecteurForme = 0;
	indexCouche = 0;
	info.nbCouches = 0;	
	info.nbFormesCanevas = 0;
	info.nbFormesCouche = 0;
	info.coucheActive = 0;
	info.aireCanevas = 0.0;
	info.etatCouche[couche.getTaille()] = 'i';
	info.aireCouche = 0.0;
	info.formeActive = 0;
	info.coordX = 0;
	info.coordY = 0;
	setInformations(info);
	effacer();
}

void MonInterface::coucheAjouter()
{
	if (canevas.ajouterCouche())
	{

		cout << "ajout de couche reussi" << endl;
		couche.changeEtat(2);
		info.nbCouches++;
		info.etatCouche[couche.getTaille()] = 'a';
		setInformations(info);
		
		
	}
	else
		cout << "erreur d'ajout de couche" << endl;
}

void MonInterface::coucheAjouterFichier()
{
	if (canevas.ajouterCoucheFichier())
	{

		cout << "ajout de couche reussi" << endl;



	}
	else
		cout << "erreur d'ajout de couche" << endl;
}

void MonInterface::coucheRetirer()
{
	if(canevas.retirerCouche())
	{
		cout << "couche retiree" << endl;
		info.etatCouche[couche.getTaille()] = 'i';
		info.nbCouches--;
		info.etatCouche[couche.getTaille()] = 'a';
		setInformations(info);
	}
	else
	{
		cout << "retirerCouche echoue" << endl;
	}
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	canevas.activerCouche(canevas.indexCourant);
	if(couche.translater(deltaX, deltaY))
	{
		cout << "translater reussi" << endl;
	}
	else
	{
		cout << "erreur de translater" << endl;
	}
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	Cercle*cercle =new Cercle(x, y, rayon);

	if (canevas.ajouterForme(cercle))
	{
		cout << "ajout de cercle reussi" << endl;
		//tailleVecteurForme++;
		info.nbFormesCouche = canevas.tailleVecteurForme;
		info.nbFormesCanevas++;
		info.aireCanevas = canevas.aire();
		info.aireCouche = couche.airTotal();
		info.coordX = couche.getAncrageX();
		info.coordY = couche.getAncrageY();
		setInformations(info);
		string s;
		string dessin = canevas.afficher(s).c_str();
		cout << dessin << endl;

		dessiner(dessin.c_str());
	
	}
	else
		cout << "erreur d'ajout de cercle" << endl;
}

void MonInterface::ajouterRectangle(int x, int y, int long_x, int long_y)
{
	Rectangle* rectangle= new Rectangle(x, y, long_x, long_y);

	if (canevas.ajouterForme(rectangle))
	{
		cout << "ajout de rectangle reussi" << endl;
		
		info.nbFormesCouche = canevas.tailleVecteurForme;
		info.nbFormesCanevas++;
		info.aireCanevas = canevas.aire();
		info.aireCouche = couche.airTotal();
		info.coordX = couche.getAncrageX();
		info.coordY = couche.getAncrageY();
		setInformations(info);
		string s;

		string dessin = canevas.afficher(s).c_str();
		cout << dessin << endl;
	
		dessiner(dessin.c_str());
	}
	else
		cout << "erreur d'ajout de rectangle" << endl;
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	
	Carre* carre = new Carre{ x, y, cote };
	if (canevas.ajouterForme(carre))
	{ 
		cout << "ajout de carre reussi" << endl;
		cout << "taille: " << canevas.tailleVecteurForme << endl;
		
		info.nbFormesCouche = canevas.tailleVecteurForme;
		info.nbFormesCanevas++;
		info.aireCanevas = canevas.aire();
		info.aireCouche = couche.airTotal();
		info.coordX = couche.getAncrageX();
		info.coordY = couche.getAncrageY();
		setInformations(info);
		string s;

		string dessin = canevas.afficher(s).c_str();
		cout << dessin << endl;
		
		dessiner(dessin.c_str());
	}
	else
	{
		cout << "erreur d'ajout de carre" << endl;
	}
	
	

}

void MonInterface::retirerForme()
{
	if (canevas.retirerForme())
	{
		cout << "forme retire" << endl;
		info.nbFormesCouche = canevas.tailleVecteurForme;
		info.nbFormesCanevas--;
		info.aireCanevas = canevas.aire();
		setInformations(info);
		if (canevas.tailleVecteurForme == 0)
		{
			effacer();
		}
		
	}
	else
	{
		cout << "retirerForme echoue" << endl;
	}
}
void MonInterface::modePileChange(bool mode)
{
	if (mode == true)
	{
		mode = false;
	}
	else if (mode == false)
	{
		mode = true;
	}
}



void MonInterface::couchePremiere()
{
	int index = canevas.indexCourant;
	cout << index << endl;
	if (index>0)
	{ 
	canevas.activerCouche(0);
	index = 0;
	canevas.indexCourant = index;
	canevas.tailleVecteurForme = canevas.getNombreFormes(); 
	info.coucheActive = index;
	setInformations(info);
	couche.indexForme = 0;
	
	cout << index << endl;
	}
	else
	{
		cout << "erreur" << endl;
	}
}	

void MonInterface::couchePrecedente()
{

	int index = canevas.indexCourant;
	cout << index << endl;
	if (index>0)
	{
	index-- ;
	canevas.activerCouche(index);
	canevas.indexCourant = index;
	canevas.tailleVecteurForme = canevas.getNombreFormes(); 
	couche.indexForme = 0;
	info.coucheActive = index;
	setInformations(info);
	}
	cout << index << endl;
}

void MonInterface::coucheSuivante()
{

	int index = canevas.indexCourant;
	cout << index << endl;
	if (index < canevas.getTaille()-1)
	{
		index++;
		canevas.activerCouche(index);

		canevas.indexCourant = index;
		canevas.tailleVecteurForme = canevas.getNombreFormes();
		couche.indexForme = 0;
		info.coucheActive = index;
		setInformations(info);
	}
	
	else 
	{
		cout << "erreur" << endl;
	}
}
void MonInterface::coucheDerniere()
{
	int index = canevas.indexCourant;
	cout << index << endl;
	if(index>0)
	{ 
	canevas.activerCouche(canevas.getTaille()-1);
	index = canevas.getTaille()-1;
	canevas.indexCourant = index;
	canevas.tailleVecteurForme = canevas.getNombreFormes(); 
	info.coucheActive = index;
	couche.indexForme = 0;
	setInformations(info);
	cout << index << endl;
	}
	else
	{
		cout << "erreur" << endl;
	}

}

void MonInterface::formePremiere()
{
	int index = couche.indexForme;
	cout << index << endl;
	index = 0;
	couche.indexForme = index;
	info.formeActive = index;
	setInformations(info);
	cout << index << endl;

}

void MonInterface::formePrecedente()
{
	cout << couche.indexForme << endl;
	if (couche.indexForme > 0)
	{
		couche.indexForme--;
		info.formeActive = couche.indexForme;
		setInformations(info);
	}
	cout << couche.indexForme << endl;

}

void MonInterface::formeSuivante()
{
	
	cout <<"taille: " << canevas.tailleVecteurForme << endl;
	if (couche.indexForme <canevas.tailleVecteurForme)
	{
		couche.indexForme++;
		info.formeActive = couche.indexForme;
		setInformations(info);
	}
	cout << couche.indexForme << "inchange" << endl;
	

}

void MonInterface::formeDerniere()
{
	int index = couche.indexForme;
	cout << index << endl;
	index = canevas.tailleVecteurForme;
	couche.indexForme = index;
	info.formeActive =index;
	setInformations(info);
	cout << index << endl;

}

bool MonInterface::ouvrirFichier(const char* nom)
{
	ifstream fichier(nom);
	if (!fichier)
	{
		cout << "erreur d'ouverture de fichier" << endl;
		return false;
	}

	string line;
	
	while (getline(fichier, line))
	{
		if (line[0] == 'L')
		{
			coucheAjouterFichier();
		}

		if (line[0] == 'C' )
		{
			int cpt=0;
			string a;
			string b;
			string c;
			for (int i = 1; i < line.size(); i++)
			{
				
					if (line[i] == ' ')
					{
						cpt++;

						
					}
					else
					{
						if (cpt == 1)
						{
							a += line[i];

						}
						if (cpt == 2)
						{
							b += line[i];

						}
						if (cpt == 3)
						{
							c += line[i];
						}
					}

				

			}
			
			int a1=stoi(a);
			int b1=stoi(b);
			int c1=stoi(c);

			ajouterCercle(a1,b1, c1);

		}

		if (line[0] == 'R')
		{
			int cpt = 0;
			string a;
			string b;
			string c;
			string d;
			for (int i = 1; i < line.size(); i++)
			{

				if (line[i] == ' ')
				{
					cpt++;


				}
				else
				{
					if (cpt == 1)
					{
						a += line[i];

					}
					if (cpt == 2)
					{
						b += line[i];

					}
					if (cpt == 3)
					{
						c += line[i];
					}
					if (cpt == 4)
					{
						d += line[i];
					}
				}



			}

			int a1 = stoi(a);
			int b1 = stoi(b);
			int c1 = stoi(c);
			int d1 = stoi(d);
			ajouterRectangle(a1, b1,c1, d1 );
		}

		if (line[0] == 'K')
		{
			int cpt = 0;
			string a;
			string b;
			string c;
			for (int i = 1; i < line.size(); i++)
			{

				if (line[i] == ' ')
				{
					cpt++;


				}
				else
				{
					if (cpt == 1)
					{
						a += line[i];

					}
					if (cpt == 2)
					{
						b += line[i];

					}
					if (cpt == 3)
					{
						c += line[i];
					}
				}



			}

			int a1 = stoi(a);
			int b1 = stoi(b);
			int c1 = stoi(c);
			ajouterCarre(a1, b1 , c1);
		}
	}
	
}

bool MonInterface::sauvegarderFichier(const char* nom)
{
	ofstream fichier(nom);
	if (!fichier)
	{
		cout << "erreur de sauvegarde du fichier" << endl;
		return false;
	}
	string s;

	string dessin = canevas.afficher(s).c_str();

	fichier << dessin << endl;
	

	return false;
}

