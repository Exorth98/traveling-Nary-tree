#ifndef ARBRE_H
#define ARBRE_H


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "connexions.h"
#include "villes.h"

typedef struct _noeud
{
	ville* city;
	int distance;
	int duree;
	int rang;
	struct _noeud* enfants; // Adresse du premier enfant
	struct _noeud* prochain_frere;  // Adresse du prochain frère
	struct _noeud* parent; //Adresse du noeud parent
	
}noeud;

typedef struct _arrivee
{
	noeud* ville_d_arrivee;
	struct _arrivee* arrivee_suivante;
}arrivee;

typedef struct{
	noeud* arbre_trajets;
	arrivee* arrivees;
}trajets;

//on récupère le nom de la ville
ville* get_ville(char *nom_ville);

//creer un noeud sans les enfants
noeud* creer_noeud(voisin *villeV, noeud* parent, int dist , int duree , int rang);

//associer les enfants à un noeud
arrivee* associer_enfants(trajets* trajs, noeud* node, int limite , char* arriv);

//ajouter les enfants a chaque noeud
trajets* completer_arbre(trajets* trajs, noeud* depart, char* arrivee, int limite);

//affichage de l'arbre
void afficher_arbre( noeud* arbre);

void afficher_noeud(const noeud* node);

trajets* construire_arbre(char* departN, char* arriv, int limite);

void printOffset(int offset);

void afficher_noeud(const noeud* node);

arrivee* plus_courts(arrivee* arrivees);

arrivee* plus_rapides(arrivee* arrivees);

void afficher_chemin(noeud* villeArr);

void afficher_arrivees(arrivee* const arrivees);

#endif