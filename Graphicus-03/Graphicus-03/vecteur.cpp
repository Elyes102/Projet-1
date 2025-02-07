/********
* Fichier: vecteur.cpp
* Auteurs: Elyes ismail(isme2473) et Philippe Lecours(lecp2055)
* Date: 4 fevrier 2025
* Description: Implementation des methodes des classes decrites dans
*    vecteur.h.
********/

#include "vecteur.h"
using namespace std;

template <class T>
Vecteur <T>::Vecteur() {
	taille = 0;
	capacite = 2;
	indexItemCourant = 0;
	// Couche *couche= new Couche[capacite];
	objet = new T*[capacite]; //MODIFIER CA PAS CERTAIN MAIS CA L'AIR DE MARCHER
}

template <class T>
Vecteur <T>::~Vecteur() {}

template <class T>
int Vecteur <T>::getCapacite()const {
	return capacite;
}

template <class T>
int Vecteur <T>::getTaille()const {
	return taille;
}

template <class T>
int Vecteur <T>::getIndex()const {
	return indexItemCourant;
}

//REGARDER LES DELETE SUREMENT CORRECT MAIS VERIFIER
template <class T>
void Vecteur <T>::doublerCapacite() {
	int capacite2 = capacite * 2;
	T** objet2 = new T*[capacite2];
	for (int i = 0; i < capacite; i++) {
		objet2[i] = objet[i];
	}
	delete[] objet;
	objet = objet2;
	capacite = capacite2;
}

//REGARDER LES DELETE SUREMENT PAS BON
template <class T>
void Vecteur <T>::viderVecteur() {
	for (int i = 0; i < capacite; i++) {
		delete objet[i];
		objet[i] = nullptr;
	}
}

template <class T>
bool Vecteur <T>::vecteurVide() {
	if (taille == 0) {
		return true;
	}
	else {
		return false;
	}
}


//VERIFIER POUR LE RETOUR AVEC ERREUR...
template <class T>
bool Vecteur <T>::ajoutObjet(T* objettoAdd) {
	if (taille == capacite) {
		doublerCapacite();
	}
	objet[taille] = new T (*objettoAdd);
	taille++;
	return true;
}



template <class T>
T* Vecteur <T>::retraitObjet(int indexObjet) {

	if (indexObjet >= 0 && indexObjet <= taille)
	{
		T* objetRetire = objet[indexObjet];

		for (int i = indexObjet; i < taille; i++)
		{
			objet[i] = objet[i + 1];
		}
		objet[taille] = nullptr;
		taille--;
		return objetRetire;
	}
	else {
		return nullptr;
	}
}

template <class T>
T* Vecteur <T>::obtenirObjet(int indexObjet) {
	if (taille >= indexObjet) {
		return objet[indexObjet];
	}
	else {
		return nullptr;
	}
}


template <class T>
string Vecteur <T>::afficher(string s) const {
	for (int i = 0; i < taille; i++)
	{
		if (objet[i] != nullptr)
		{
			//s << "----- Couche " << i << " -----" << endl;
			s += objet[i]->afficher(s);
			//s << endl;
		}
		else {
			//s << "----- Couche " << i << " est vide-----" << endl;
		}
	}
	return s;
}

template <class T>
void Vecteur <T>::setCapacite(int capacite1)
{
	capacite = capacite1;
}


template <class T>
void Vecteur <T>::setTaille(int taille1)
{
	taille = taille1;
}

template<class T>
void Vecteur<T>::setItemCourant(int index)
{
	if (index > taille || index < 0)
	{
		//message d'erreur d'index
		cout << "Erreur d'index ItemCourant" << endl;
	}
	else
	{
		indexItemCourant = index;
	}
}
