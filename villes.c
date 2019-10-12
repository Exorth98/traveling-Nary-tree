#include "villes.h"

#define TAILLE_LIGNE    256

//Affiche une ville
void afficher_ville(ville* vi) {
	if(vi != NULL)
	{
		printf(" === %s ===\n",vi->nom);
		afficher_voisins(vi->voisins);
		printf("\n\n\n");
	}
	else printf("Ville nulle\n");

}

//Affiche tous les voisins
void afficher_voisins(voisin* voisins){
	
	voisin* voisins_t = voisins;
	while(voisins_t != NULL)
	{
		afficher_voisin(voisins_t);
		voisins_t = voisins_t->voisin_suivant;
	}
}

//Affiche un voisin
void afficher_voisin(voisin* voi){
	
	printf("- %s :\n",voi->nom_ville);
	printf("  %d\n",voi->distance);
	printf("  %d\n",voi->duree);
}

//Cree un voisin 
voisin* creer_voisin(char* nom, int dist, int duree){
	voisin* voi = (voisin*) malloc(sizeof(voisin));
	voi->nom_ville = nom;
	voi->distance = dist;
	voi->duree = duree;
	voi->voisin_suivant = NULL;
	
	return voi;
}
//Ajoute un voisin en queue de liste
voisin* ajouter_voisin(voisin* voisins , voisin* voi){
	
	if(voisins == NULL) voisins = voi;
	else
	{
		voisin* voisins_t = voisins;
		while(voisins_t->voisin_suivant !=NULL) voisins_t = voisins_t->voisin_suivant;
		voisins_t->voisin_suivant = voi;
	} 
	return voisins;
}

//Compare les nom de villes
bool sont_meme_ville(char* ville1, char* ville2)
{
	return strcmp(ville1,ville2) == 0;
}

//Enleve la retour a la ligne a la fin du la ligne lue du fichier
char* get_city_without_return(const char * city)
{								//city : "VILLE\n\0"
	int taille = strlen(city); 
	char * dup = strdup(city); 	// "VILLE\n\0"
	dup[taille-1] = '\0';		// "VILLE\0"
	return dup;
}

//Recupere la prochaine connexion pour la ville donnée
connexion* recuperer_connexion(char* nom, connexion** connexions, voisin* voisins){
	
	connexion* rep = NULL;
	bool ok = false;
	for(int i = 0; i<72 && !ok;i++)
	{
		if(connexions[i] != NULL)
		{
			if(sont_meme_ville(connexions[i]->ville1,nom))
			{
				rep = connexions[i];
				connexions[i] = NULL;
				ok = true;
			}
		}
	}
	return rep;
}

//Constitue les villes
ville ** constituer_villes(connexion** connexions)
{
	//initialisations
	FILE * file;
	char ligne_lue [TAILLE_LIGNE];
	ville** villes = (ville**) malloc( 23 * sizeof(ville));

	//Ouverture du fichier
	file = fopen ("villes.csv", "r");

	if (file != NULL)
	{
		int num_ville = 1;
		//Pour chaque ligne
		while ((fgets (ligne_lue, TAILLE_LIGNE, file)) != NULL)
		{
			//SI c'est pas la premiere ligne
			if(num_ville != 1)
			{
				ville* vi = malloc(sizeof(ville));
				voisin* voisins = NULL;
				//Ligne totale
				char *   ligne = ligne_lue;
				char * nom = get_city_without_return(ligne);
				
				//On recupère toutes les connexions de la villes pour lui associer ces voisins
				connexion* co = recuperer_connexion(nom,connexions,voisins);
				while(co != NULL){
					voisin * voi = creer_voisin(co->ville2,co->distance,co->duree);
					voisins = ajouter_voisin(voisins, voi);
					co = recuperer_connexion(nom,connexions,voisins);
				}
				
				vi->nom = nom;
				vi->voisins = voisins;
//				afficher_ville(vi);
				villes[num_ville-2] = vi;
			}
		num_ville++;
		}
		fclose(file);
	}
	else
	{
		printf("Erreur");
	}
	return villes;
}