#include <string.h>
#include "permut.h"
#include "pile.h"

#define passerAuPremierFils(adrP, E) empiler(adrP, E)
#define remonterAuPere(adrP, E) depiler(adrP, E)
#define passerAuFrereSuivant(adrP, adrE) depiler(adrP, adrE), empiler(adrP, *(adrE)+1)
#define naPlusDeFrere(adrP, TailleChaine, ch) sommet(adrP) == ch[((int)(TailleChaine))-1]
#define noeudTerminal(adrP, TailleChaine) hauteur(adrP) == ((int)(TailleChaine))
#define rechercheTermine(adrP) pilevide(adrP)

void permut(T_Pile * P, char * chaine) {
    T_Elt elt;
    int i=0;
    //On repète tant que la recherche n'est pas termine
    do{
        // Tant que la pile est valide -> Pas 2 fois le même élément
        while(pileValide(P)){
            //Si on est sur un noeud terminal, on affiche notre solution
            if(noeudTerminal(P, strlen(chaine))){
                afficherPile(P);
                i++;
                // On sort du while
                break;
            }
            // Si on n'est pas sur un noeud terminal
            else {
                // On reprend une lettre
                passerAuPremierFils(P, chaine[0]);
            }
        }

        // Tant que la recherche n'est pas terminée et que le noeud courant n'a plus de freres on remonte au père
        while(!rechercheTermine(P) && naPlusDeFrere(P, strlen(chaine), chaine)){
            remonterAuPere(P, &elt);
        }

        if(!rechercheTermine(P)) passerAuFrereSuivant(P, &elt);
    }while(!rechercheTermine(P));
    printf("Il y a %d combinaisons\n", i);
}

int pileValide(T_Pile * P){
    int i, j;
    for (i=0 ; i < P->nbElts ; i++){
        for(j=i+1 ; j < P->nbElts ; j++){
            if(P->Elts[i] == P->Elts[j]){
                return 0; //On a un doublon
            }
        }
    }
    return 1; //Aucun doublon trouvé
}