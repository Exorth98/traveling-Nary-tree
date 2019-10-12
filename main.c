#include "main.h"

trajets* traj = NULL;

//Affichage du menu
void afficher_menu()
{
	printf("\n\n========= MENU =========\n\n");
	printf("1 - Afficher l'arbre des trajets\n");
	printf("2 - Afficher tous les trajets\n");
	printf("3 - Afficher un trajet\n");
	printf("4 - Afficher les plus courts\n");
	printf("5 - Afficher les plus rapides\n");
	printf("6 - Quitter\n\n");
}

void vider_buffer(void)
{
	int c;
	do{c = getchar();}
	while (c != '\n' && c != EOF);
}

//Permet de choisir un nombre entre certaines bornes
int choisir_nombre(int min , int max, char* nom){
	
	int choix = 0;
	//On demande la saisie d'un nombre dans les bornes
	do{
		printf("Choisir ");
		printf("%s",nom);
		printf(" (%d a %d) : ",min,max);
		scanf("%d",&choix);
		vider_buffer();
	//Tant que le nombre donné n'est pas dans les bornes
	}while(choix < min || choix > max );
	
	return choix;
}

void option_arbre() {
	
	noeud* arbre = traj->arbre_trajets;
	printf("\n========== Arbre =========\n\n");
	afficher_arbre(arbre);
}

void option_tous() {

	printf("\n========== Tous les trajets =========\n\n");
	arrivee* arrivees = traj->arrivees;
	if(arrivees != NULL) afficher_arrivees(arrivees);
	else printf("\nAucun trajet trouve pour cette limite ...\n");
}

void option_un() {

	printf("\n========== Un trajet =========\n\n");
	arrivee* arriv = (arrivee*) malloc(sizeof(arrivee));
	if(traj->arrivees != NULL)
	{
			arriv->ville_d_arrivee = traj->arrivees->ville_d_arrivee;
				arriv->arrivee_suivante = NULL;
				afficher_arrivees(arriv);
	}
	else printf("\nAucun trajet trouve pour cette limite ...\n");
}

void option_courts() {

	printf("\n========== Les plus courts =========\n\n");
	arrivee* arrivees = traj->arrivees;
	if(arrivees != NULL){
		arrivee* plus_c = plus_courts(arrivees);
		afficher_arrivees(plus_c);
	}
	else printf("\nAucun trajet trouve pour cette limite ...\n");

}

void option_rapides() {

	printf("\n========== Les plus rapides =========\n\n");
	arrivee* arrivees = traj->arrivees;
	if(arrivees != NULL){
		arrivee* plus_r = plus_rapides(arrivees);
		afficher_arrivees(plus_r);
	}
	else printf("\nAucun trajet trouve pour cette limite ...\n");

}

//Gèere les options du menu principal
void executer_option(int choix){
	
	//Par défaut on ne veut pas quitter
	bool exit = false;
	
	//Selon le choix on execute une fonction correspondant a une fonctionnalité du menu
	switch(choix){
		
		case 1:
			option_arbre();
			break;
		case 2:
			option_tous();
			break;
		case 3:
			option_un();
			break;
		case 4:
			option_courts();
			break;
		case 5:
			option_rapides();
			break;
		case 6:
			exit = true; //On veut quitter
			break;
	}
	
	if(!exit){
		menu(); //Si on ne veut pas quitter, on ré-affiche le menu,
	}
	
	//Sinon le programme se termine avec le "return 0" du main
}

char* choisir_depart()
{
	char dep[] = "XXX";
	do
	{
		printf("Choisir le depart : ");
		gets(dep);
	}while(get_ville(dep) == NULL);
	
	return strdup(dep);
}

char* choisir_arrivee()
{
	char arr[] = "XXX";
	do
	{
		printf("Choisir l'arrivee : ");
		gets(arr);
	}while(get_ville(arr) == NULL);
	
	return strdup(arr);
}

void menu(){

	//On fait choisir une fonctionnalité du menu puis on l'execute
	afficher_menu();
	int choix = choisir_nombre(1,6, "une option");
	executer_option(choix);
}


int main(int argc, char **argv)
{
	char* depart = choisir_depart();
	char* arriv = choisir_arrivee();
	int limite = choisir_nombre(1,100,"La limite d'etapes");
	traj = construire_arbre(depart,arriv,limite);
	menu();
	return 0;
}
