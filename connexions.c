#include "connexions.h"
#include "villes.h"
#include "arbre.h"

#define TAILLE_LIGNE    256


void afficher_connexion(connexion* co)
{
	printf("%s relie %s sur %d km en %d min\n",co->ville1,co->ville2,co->distance,co->duree);
}

//Convertit la duree sous forme string "hh:mm" en nombre de minutes
int recuperer_duree(char* duree){
	
	char* token2 = strtok (duree, ":");
	int h = atoi(token2);
	token2 = strtok(NULL,":");
	int m = atoi(token2);
	
	return h*60 + m;
}

//Duplique un string
char* dupliquer(char const * token)
{
	char* villeN = strdup(token);
	return villeN;
}

//Lit toutes les connexions
connexion** lecture_connexions()
{
	//Initialisations
	FILE * file;
	char *  token;
	char ligne_lue [TAILLE_LIGNE];
	connexion** connexions = (connexion**) malloc( 72  * sizeof(connexion));

	//Ouverture du fichier
	file = fopen ("connexions.csv", "r");

	if (file != NULL)
	{
		int num_connexion = 1;
		//Pour chaque ligne
		while ((fgets (ligne_lue, TAILLE_LIGNE, file)) != NULL)
		{
			//Si c'est pas la première ligne
			if(num_connexion != 1)
			{
				//On initialize la connexion
				connexion* co = malloc(sizeof(connexion));
				//Ligne totale
				char *   ligne = ligne_lue;
				//1er token (on decoupe selon la ',')
				token = strtok (ligne, ",");
				int i = 1; //indice du token
				while (token != NULL)
				{
					//En fonction du token on affecte a la connexion
					switch(i)
					{
						//ville1
						case 1:
							co->ville1 = dupliquer(token);
							break;
						//ville2
						case 2:
							co->ville2 = dupliquer(token);
							break;
						//distance
						case 3:
							co->distance = atoi(token);
							break;
						//durée
						case 4:
							co->duree = recuperer_duree(token);
							break;
					}
					//On passe au suivant
					token = strtok(NULL,",");
					i++;
				}
				//On ajoute la connexion aux connexions
				connexions[num_connexion-2] = co;
			}
		num_connexion++;
		}
		fclose (file);
	}
	else
	{
		printf("Erreur");
	}
	return connexions;
}