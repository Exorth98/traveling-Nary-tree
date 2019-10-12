#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "connexions.h"
#include "villes.h"
#include "arbre.h"

//Affichage du menu
void afficher_menu();

//Pour lecture d'un string
void vider_buffer(void);

//Permet de choisir un nombre entre certaines bornes
int choisir_nombre(int min , int max, char* nom);

//Execution des options du menu
void option_arbre();
void option_tous();
void option_un();
void option_courts();
void option_rapides();

//Gèere les options du menu principal
void executer_option(int choix);

//Choix des villes
char* choisir_depart();
char* choisir_arrivee();

//Ouverture du menu
void menu();

int main(int argc, char **argv);

#endif
