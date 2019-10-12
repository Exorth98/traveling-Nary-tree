#ifndef VILLES_H
#define VILLES_H


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "connexions.h"

struct _voisin
{
	
	char* nom_ville;
	int distance;
	int duree;
	
	struct _voisin * voisin_suivant;
	
};

typedef struct _voisin voisin;

typedef struct {
	
	char* nom;
	voisin* voisins;
	
}ville;

//Compare les noms de villes
bool sont_meme_ville(char* ville1, char* ville2);

//Affiche une ville
void afficher_ville(ville* vi);

//Affiche tous les voisins
void afficher_voisins(voisin* voisins);

//Affiche un voisin
void afficher_voisin(voisin* voi);

//Creer un voisin
voisin* creer_voisin(char* nom, int dist, int duree);

//Ajouter un voisin en queue de liste
voisin* ajouter_voisin(voisin* voisins , voisin* voi);

//Constitue les villes
ville ** constituer_villes( connexion** connexions);

//Recupere la prochaine connexion pour une ville donnée
connexion* recuperer_connexion(char* nom, connexion** connexions, voisin* voisins);

#endif