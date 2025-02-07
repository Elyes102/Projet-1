/********
* Fichier: vecteur.h
* Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
* Date: 4 fevrier 2025
* Description: Declaration de la classe pour un vecteur.
*    La classe gere tout type voulu dans le vecteur
********/

#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <fstream>
#include <string>
//#include "forme.h"
//#include "couche.h"

template <class T>
class Vecteur
{
public:

	Vecteur();
	~Vecteur();
	int getCapacite()const;
	int getTaille()const;
	int getIndex()const;
	void setCapacite(int capacite1);
	void setTaille(int taille1);
	void setItemCourant(int index);
	void viderVecteur();
	bool vecteurVide();
	bool ajoutObjet(T* objettoAdd);
	T *retraitObjet(int indexObjet);
	T *obtenirObjet(int indexObjet);
	string afficher(string s) const;
	int indexItemCourant;
	////Couche *couche[1];
	T** objet;//VERIFIER

	Vecteur& operator += (T newobjet) {
		ajoutObjet(newobjet);
	}

	//TODO: VERIFICATION
	T& operator [] (int index) {
		return *objet[index];
	}
	const T& operator [] (int index) const {
		return *objet[index];
	}
	ostream& operator<<(const Vecteur& v) {
		for (int i = 0; i < v.taille; ++i) {
			cout << v.objet[i] << " ";
		}
		return cout;
	}

	 friend ofstream& operator << (ofstream& s, const Vecteur& v) {
		for (int i = 0; i < v.taille; ++i) {
			s << v.objet[i] << " ";
		}
		return s;
	}
	friend ostringstream& operator << (ostringstream& s, const Vecteur& v) {
		for (int i = 0; i < v.taille; ++i) {
			s << v.objet[i] << " ";
		}
		return s;
	}

	friend istream& operator >> (istream& s, Vecteur& v) {
		v.ajoutObjet(s);
	}

	friend ifstream& operator >> (ifstream& s, Vecteur& v) {
		string ligne;
		while (getline(s, ligne))
		{
			v.ajoutObjet(ligne);
		}
	}
	friend istringstream& operator >> (istringstream& s, Vecteur& v) {
		v.ajoutObjet(s);
	}

	Vecteur& operator ++ () {
		setItemCourant(indexItemCourant++);
	}
	Vecteur& operator -- () {
		setItemCourant(indexItemCourant--);
	}
	void doublerCapacite();
private:
	int capacite;
	int taille;
	

	
};
#include "vecteur.cpp"

#endif