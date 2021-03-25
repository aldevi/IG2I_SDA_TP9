#include "file.h"

void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete = -1;
    ptrF->Queue = -1;
}

int retirer(T_File *ptrF, T_Elt *ptrE) //si pas vide, en tete de file
{
    if (!fileVide(ptrF))
    {
        *ptrE = ptrF->Elts[ptrF->Tete];
        if (ptrF->Queue == ptrF->Tete)
        {
            initFile(ptrF);
        }
        else if (ptrF->Tete == MAX - 1)
        {
            ptrF->Tete = 0;
        }
        else
        {
            ptrF->Tete++;
        }

        return 1;
    }
    return 0;
}

int ajouter(T_File *ptrF, T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (!filePleine(ptrF))
    {
        if (fileVide(ptrF))
        {
            ptrF->Tete = 0;
        }

        if (ptrF->Queue == MAX - 1)
        {
            ptrF->Queue = 0;
        }
        else
        {
            ptrF->Queue++;
        }
        ptrF->Elts[ptrF->Queue] = *ptrE;

        return 1;
    }
    return 0;
}

int fileVide(const T_File *prtF) // qd Tete == 0
{

    return prtF->Tete == -1 && prtF->Queue == -1;
}

int filePleine(const T_File *ptrF) // qd MAX elts dans la file
{
    int result = (ptrF->Tete == 0 && ptrF->Queue == MAX - 1) || (ptrF->Tete == ptrF->Queue + 1);

    return result;
}

T_Elt premier(T_File *ptrF) //valeur en tete de file
{
    if (!fileVide(ptrF))
    {
        return ptrF->Elts[ptrF->Tete];
    }
    return 0;
}

void afficherFile(T_File *ptrF)
{
    if (!fileVide(ptrF))
    {
        int i = ptrF->Tete;
        while (i != ptrF->Queue)
        {
            afficherElt(&(ptrF->Elts[i]));
            if (i == MAX - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }

        afficherElt(&(ptrF->Elts[i]));
    }
    else
    {
        printf("La file est vide");
    }
}
