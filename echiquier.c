#include <string.h>
#include "echiquier.h"
#include "pile.h"
#include "permut.h"

#define V P->Elts[i]
#define V_moins_1 P->Elts[i-1]

// #define rechercheTermine(P)

#define remonter(P, elt) depiler(P, elt) 
#define descendre(P, elt) empiler(P, elt)
#define passer(P, elt) depiler(P, elt), empiler(P, *(elt)+1)
#define noeudTerminal(P, taille) hauteur(P) == taille
#define naPlusDeFrere(P, taille) sommet(P) == taille
#define rechercheTermine(P) pilevide(P)

void echiquier(T_Pile * P, int taille){
    int i = 0;
    T_Elt elt;
    // On repete tant que la recherche n'est pas termine
    do{
        // Tant que le noeud actuel est valide et que l'on n'a pas de doublons
        while(noeudValide(P) && pileValide(P)){
            // printf("Le noeud est valide\n");
            // Si on est sur un noeud terminal, on affiche la solution
            if(noeudTerminal(P, taille)){
                afficherPile(P);
                // On sort de la boucle
                break;
            }
            // Si on n'est pas sur un noeud terminal
            else{
                // On reprend une case
                descendre(P, 1);
            }
        }

        // Tant que la recherche n'est pas terminee et que le noeud courant n'a plus de frere
        while(!rechercheTermine(P) && naPlusDeFrere(P, taille)){
            // On remonte
            remonter(P, &elt);
        }
        
        // Si la recherche n'est pas terminee, on passe au frere suivant
        if(!rechercheTermine(P)){
            passer(P, &elt);
        }
    i++;
    } while (!rechercheTermine(P));
    
}

int noeudValide(T_Pile * P){
    // Noeud valide quand :
    // V3 != V2 ET V3 != V2 + 1 ET V3 != V2 - 1
    // V2 != V1 ET V2 != V1 + 1 ET V2 != V1 - 1

    int i;
    for (i=P->nbElts-1 ; i>0 ; i--){
        //Si on trouve loppose, cest que le noeud nest pas valide
        if((V == V_moins_1) || (V == V_moins_1 - 1) || (V == V_moins_1 + 1)){
            return 0;
        }
    }
    //Si on na pas trouve loppose, cest que le noeud est valide
    return 1;
}