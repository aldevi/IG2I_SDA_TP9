#include "pile.h"

void initPile( T_Pile * P) {
    P->nbElts=0;
}

int pilepleine(const  T_Pile *P) {
    if(P->nbElts == MAX) return 1;
    else return 0;
}

int pilevide(const  T_Pile *P) {
    if(P->nbElts == 0) return 1;
    else return 0;
}

int empiler( T_Pile *P, T_Elt e) { //renvoie 0 si pile pleine, sinon 1
    if(pilepleine(P)) return 0;
    else {
        P->Elts[P->nbElts] = e;
        P->nbElts++;
        return 1;
    }
}

int depiler( T_Pile *P, T_Elt *pelt) { //renvoie 0 si pile vide, sinon 1
    if(pilevide(P)) return 0;
    else {
        P->nbElts--;
        *pelt = P->Elts[P->nbElts];
        return 1;
    }
}

T_Elt sommet(const  T_Pile *P) {
    return P->Elts[P->nbElts];
}

int hauteur(const  T_Pile *P) {
    return P->nbElts;
}

void afficherPile(  T_Pile *P) {
    int i=0, j;
    T_Elt elt;
    T_Elt tab[MAX];

    //On depile, on affiche et on met dans notre tableau pour rempiler plus tard
    while (depiler(P, &elt)){
        printf("Element %d : %d\n", i, elt);
        tab[i] = elt;
        i++;
    }

    for(j=i-1 ; j >= 0 ; j--) empiler(P, tab[j]);
    
}








