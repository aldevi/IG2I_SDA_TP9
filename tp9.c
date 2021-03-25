// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

void testFile(T_File *file);
int menuFile();

int menu()
{

	int choix;
	printf("\n\n\n SDA1 TP9");
	printf("\n\n\n 1 : tester mon fichier file.c");
	printf("\n 2 : tester mon fichier pile.c");
	printf("\n 3 : afficher et compter les permutations d'une chaine");
	printf("\n 4 : afficher et compter les solutions pour un échiquier ");
	printf("\n 0 :  QUITTER  ");
	printf("\n votre choix ?  ");
	scanf("%d", &choix);
	return choix;
}

int main()
{
	T_File mafile;
	// T_Pile mapile;
	int chx;
	// int taille;
	//char chaine[20];

	do
	{
		chx = menu();
		switch (chx)
		{
		case 1:
			testFile(&mafile); //TP9 partie 1 : à ecrire
			break;
		case 2:
			// testPile(&mapile);
			break;
		case 3:
			//scanf("%s",chaine); //une chaine de longueur <=MAX
			//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
			break;
		case 4:
			//scanf("%d",&taille);//taille echiquier <=MAX
			//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
			break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}

int menuFile()
{
	int choix;
	printf("\n\n----- TEST DES FONCTIONS DES FILES -----\n");
	printf("1 : Afficher file\n");
	printf("2 : Enfiler\n");
	printf("3 : Defiler\n");
	printf("4 : La file est est elle vide ?\n");
	printf("5 : La file est est elle pleine ?\n");
	printf("6 : Afficher le premier élément de la file\n");
	printf("0 : Revenir au menu précédent\n");
	printf("Votre choix : ");
	scanf("%d", &choix);
	return choix;
}

void testFile(T_File *file)
{
	T_Elt elt;
	int chx, result;
	initFile(file);

	do
	{
		chx = menuFile();
		switch (chx)
		{
		case 1:
			// Afficher
			afficherFile(file);
			break;
		case 2:
			// Enfiler
			printf("Elément à enfiler : ");
			scanf("%d", &elt);
			result = ajouter(file, &elt);
			if (result)
			{
				printf("L'élément à était ajouté\n");
			}
			else
			{
				printf("L'élément n'a pu être ajouté\n");
			}
			break;
		case 3:
			// Defiler
			result = retirer(file, &elt);
			if (result)
			{
				printf("Elément défilé : %d\n", elt);
			}
			else
			{
				printf("L'élément n'a pu être défilé\n");
			}
			break;
		case 4:
			// Est vide ?
			if (fileVide(file))
			{
				printf("La file est vide\n");
			}
			else
			{
				printf("La file n'est pas vide\n");
			}
			break;
		case 5:
			// Est pleine ?
			if (filePleine(file))
			{
				printf("La file est pleine\n");
			}
			else
			{
				printf("La file n'est pas pleine\n");
			}
			break;
		case 6:
			// Premier élément
			elt = premier(file);
			printf("Le premier élément de la file est : %d\n", elt);
			break;
		default:
			printf("Saisie invalide\n");
			break;
		}
	} while (chx != 0);
}