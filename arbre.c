#include "connexions.h"
#include "villes.h"
#include "arbre.h"

connexion ** connexions = NULL;
ville** villes = NULL;

//on récupère le nom de la ville
ville* get_ville(char* nom_ville)
{
	if(nom_ville == NULL) return NULL;
	if(connexions == NULL) connexions = lecture_connexions();
	if(villes == NULL) villes = constituer_villes(connexions);
	ville* resultat = NULL;
	//Pour chaque ville
	for(int i = 0 ; i < 23 ; i++)
	{
		//On regarde si le nom correspond
		if(strcmp(villes[i]->nom, nom_ville) == 0 ){
			resultat = villes[i];
		}
	}
	return resultat;
}

bool pas_deja_parent(noeud* node, voisin* voi)
{
	noeud* parent = node->parent;
	bool deja_parent = false;
	//Pour chaque parent
	while(parent != NULL && !deja_parent)
	{	//Si le nom correspond
		if(strcmp(parent->city->nom,voi->nom_ville) == 0)
		{
			deja_parent = true;
		}
		parent = parent->parent;
	}
	return !deja_parent;
}

//creer le noeud racine
noeud* creer_noeud_racine(ville* depart)
{
	noeud* node = (noeud*) malloc(sizeof(noeud));
	node->rang = 1;
	node->city = depart;
	node->distance = 0;
	node->duree = 0;
	node->parent = NULL;
	node->enfants = NULL;
	node->prochain_frere = NULL;
	
	return node;
}

//Ajoute un fere en queue de la liste
noeud* ajouter_frere(noeud* enfants, noeud* frere)
{
	noeud* enfants_t = enfants;
	while(enfants_t->prochain_frere !=NULL) enfants_t = enfants_t->prochain_frere;
	enfants_t->prochain_frere = frere;
	return enfants;
}

//Creer une arrivee a partir d'un noeud
arrivee* creer_arrivee(noeud* ville_arr)
{
	arrivee* arr = (arrivee*) malloc(sizeof(arrivee));
	arr->ville_d_arrivee = ville_arr;
	arr->arrivee_suivante = NULL;
	return arr;
}
//Ajoute une arrivee en tete de la liste
arrivee* ajouter_arrivee(arrivee* arrivs, arrivee* arriv)
{
	arriv->arrivee_suivante = arrivs;
	return arriv;
}

//creer un noeud sans les enfants
noeud* creer_noeud(voisin *villeV, noeud* parent, int dist , int duree, int rang)
{
	noeud* node = (noeud*) malloc(sizeof(noeud));
	node->city = get_ville(villeV->nom_ville);
	node->distance = dist;
	node->duree = duree;
	node->parent = parent;
	node->rang = rang;
	node->enfants = NULL;
	node->prochain_frere = NULL;
	
	return node;
}

//Verifie si le noeud ce chemin est déjà prit en compte comme destination
bool deja_arrive(arrivee* arrivs, noeud* node)
{
	bool rep = false;
	arrivee* arrivs_t = arrivs;
	//Pour chaque arrivee
	while(arrivs_t != NULL && !rep)
	{
		//On regarde si ne noeud correspond
		if(arrivs_t->ville_d_arrivee == node) rep = true; 
		arrivs_t = arrivs_t->arrivee_suivante;
	}
	return rep;
}

//associer les enfants à un noeud
arrivee* associer_enfants(trajets* trajs, noeud* node, int limite , char* arriv)
{
	//Initialisation des variables necessaires
	arrivee* arrivs = trajs->arrivees;
	bool est_arrive = false;
	voisin* voisins = node->city->voisins;
	noeud* enfant = NULL;
	
	//Pour chaque voisin de la ville du noeud ( qui doivent devenir ses enfants dans l'arbre)
	while(voisins!=NULL){
		//SI la limite n'est pas atteinte
		if(node->rang < limite){
			//Si On est pas deja a l'arrivee
			if(strcmp(node->city->nom, arriv) != 0){
				est_arrive = false;
				//Si on est pas déjà passé par cette ville
				if(pas_deja_parent(node, voisins)){
					//On ajoute la distance, la durée, et on implémente le rang
					int dist = node->distance + voisins->distance;
					int duree = node->duree + voisins->duree;
					int rang = node->rang + 1;
					//On constitue l'enfant et on l'associe au noeud
					enfant = creer_noeud(voisins, node, dist, duree, rang);
					if (node->enfants == NULL) node->enfants = enfant;
					else node->enfants = ajouter_frere(node->enfants,enfant);
				}
			}
			else est_arrive = true;
			
			//Si on est arrivé a destination et que ce chemin n'est pas noté dans les arrivées
			if(est_arrive && !deja_arrive(arrivs, node)){
				//on ajoute le chemin aux arrivees
				arrivee* arr = creer_arrivee(node);
				if(arrivs == NULL) arrivs = arr;
				else (arrivs = ajouter_arrivee(arrivs, arr));
			}
		}

		//On passe au voisin suivant
		voisins = voisins->voisin_suivant;
	}
	return arrivs;
}

//On initialise le trajet et la ville de départ en fonction du nom de départ
trajets* construire_arbre(char* departN, char* arriv, int limite)
{
	trajets* trajs = (trajets*) malloc(sizeof(trajets));
	trajs->arrivees = NULL;
	ville* villeDep = get_ville(departN);
	noeud* depart = creer_noeud_racine(villeDep);
	trajs->arbre_trajets = depart;
	return completer_arbre(trajs, depart,arriv,limite);
}

//ajouter les enfants a chaque noeud
trajets* completer_arbre(trajets* trajs, noeud * depart, char* arriv, int limite)
{
	//On associe les enfants au noeud actuel 
	trajs->arrivees = associer_enfants(trajs, depart, limite, arriv);
	noeud* enfants = depart->enfants;
	noeud* enfants_temp = enfants;
	//Pour chaque enfant
	while(enfants_temp != NULL){
		//On les complete egalement
		completer_arbre(trajs, enfants_temp, arriv, limite);
		enfants_temp = enfants_temp->prochain_frere;
	}
	trajs->arbre_trajets = depart;

	return trajs;
}
//Affichage du decalage pour l'arborescence
void printOffset(int offset)
{
	if(offset != 0)
	{
		for(int i = 1; i<offset; i++){
			printf("  ");
		}
		printf("|-");
	}
}

//Affichage du noeud
void afficher_noeud(const noeud* node)
{
	if(node != NULL)
	{
		int offset = node->rang;
		printf("\n");
		printOffset(offset);printf("=== %s ===\n",node->city->nom);
		printOffset(offset);printf("Rang = %d\n", node->rang);
		printOffset(offset);printf("Distance = %d\n", node->distance);
		printOffset(offset);printf("Duree = %d\n", node->duree);
		printOffset(offset);printf("Destinations suivantes : ");
		noeud* enfant = node->enfants;
		while(enfant !=NULL)
		{
			printf("%s ",enfant->city->nom);
			enfant = enfant->prochain_frere;
		}
		printf("\n");
	}
}

//Determiner les trajets les plus courts
arrivee* plus_courts(arrivee* arrivees)
{
	//On prend le premier par défaut
	arrivee* arrivs_t = arrivees;
	arrivee* plus_courts = (arrivee*) malloc(sizeof(arrivee));
	plus_courts->ville_d_arrivee = arrivs_t->ville_d_arrivee;
	plus_courts->arrivee_suivante = NULL;
	
	//pour chaque arrivee
	while(arrivs_t != NULL)
	{
		//On verifie si elle est plus courte
		int dist = arrivs_t->ville_d_arrivee->distance;
		if(dist<plus_courts->ville_d_arrivee->distance)
		{
			plus_courts = (arrivee*) malloc(sizeof(arrivee));
			plus_courts->ville_d_arrivee = arrivs_t->ville_d_arrivee;
			plus_courts->arrivee_suivante = NULL;
		}
//		else if(dist == plus_courts->ville_d_arrivee->distance)
//		{
//			arrivee* autre_courts = (arrivee*) malloc(sizeof(arrivee));
//			autre_courts->ville_d_arrivee = arrivs_t->ville_d_arrivee;
//			autre_courts->arrivee_suivante = NULL;
//			plus_courts = ajouter_arrivee(plus_courts,autre_courts);
//		}
		arrivs_t = arrivs_t->arrivee_suivante;
	}
	return plus_courts;
}

//Determiner les trajets les plus rapides
arrivee* plus_rapides(arrivee* arrivees)
{
	//On prend le premier par défaut
	arrivee* arrivs_t = arrivees;
	arrivee* plus_rapides = (arrivee*) malloc(sizeof(arrivee));
	plus_rapides->ville_d_arrivee = arrivs_t->ville_d_arrivee;
	plus_rapides->arrivee_suivante = NULL;
	
	//pour chaque arrivee
	while(arrivs_t != NULL)
	{
		//On verifie si elle est plus rapide
		int duree = arrivs_t->ville_d_arrivee->duree;
		if(duree<plus_rapides->ville_d_arrivee->duree)
		{
			plus_rapides = (arrivee*) malloc(sizeof(arrivee));
			plus_rapides->ville_d_arrivee = arrivs_t->ville_d_arrivee;
			plus_rapides->arrivee_suivante = NULL;
		}
//		else if(duree == plus_rapides->ville_d_arrivee->duree)
//		{
//			arrivee* autre_rapide = (arrivee*) malloc(sizeof(arrivee));
//			autre_rapide->ville_d_arrivee = arrivs_t->ville_d_arrivee;
//			autre_rapide->arrivee_suivante = NULL;
//			plus_rapides = ajouter_arrivee(plus_rapides,autre_rapide);
//		}
		arrivs_t = arrivs_t->arrivee_suivante;
	}
	return plus_rapides;
}

//Affichage d'un chemin
void afficher_chemin(noeud* villeArr)
{
	while(villeArr != NULL){
		printf("%s <- ",villeArr->city->nom);
		villeArr = villeArr->parent;
	}
}

//Affichage d'un arrivee
void afficher_arrivees(arrivee* const arrivees)
{
	arrivee* arrivs_t = arrivees;
	while(arrivs_t != NULL)
	{
		noeud* villeA = arrivs_t->ville_d_arrivee;
		afficher_chemin(villeA);
		printf("\nEn %d km et %d minutes pour %d etapes",villeA->distance, villeA->duree, villeA->rang);
		printf("\n\n");
		arrivs_t = arrivs_t->arrivee_suivante;
	}
}

//Affichage de l'arbre des trajets en arborescence
void afficher_arbre(noeud* arbre) 
{
	if(arbre != NULL){
		afficher_noeud(arbre);
		noeud* enfant = arbre->enfants;
		while(enfant != NULL){
			afficher_arbre(enfant);
			enfant = enfant->prochain_frere;
		}
	}
}
