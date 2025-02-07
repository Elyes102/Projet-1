/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "canevas.h"
#include "vecteur.h"
#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include "graphicusGUI.h"
#include <fstream>


class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	void reinitialiserCanevas();
	void coucheAjouter();
	void coucheRetirer();
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int long_x, int long_y);
	void ajouterCarre(int x, int y, int cote);
	void retirerForme();
	void modePileChange(bool mode);
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();
	bool ouvrirFichier(const char* nom);
	bool sauvegarderFichier(const char* nom);
	void coucheAjouterFichier();

private:
	Canevas canevas;
	Couche couche;
	Cercle cercle;
	int tailleVecteurForme = 0;
	int indexCouche = 0;
	Informations info;
	Vecteur<Couche> vecteurTailleCouche;
};

#endif // MONINTERFACE_H