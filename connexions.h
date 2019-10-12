#ifndef CONNEXIONS_H
#define CONNEXIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct _connexion{
	char* ville1;
	char* ville2;
	int distance;
	int duree;
};
typedef struct _connexion connexion;

//Affiche une connexion
void afficher_connexion(connexion* co);

//Convertit la duree
int recuperer_duree(char* token);

//Lit les connexions
connexion** lecture_connexions();

#endif