/**
* Created by dcarrier on 06/01/2020.
*/

#include "pileTuc.h"
#include <stdlib.h>

typePileTuc *ptucCreer()
{
    typePileTuc *pileTuc = (typePileTuc *) malloc(sizeof(typePileTuc));
    pileTuc->s = 0;

    return pileTuc;
}

void ptucLiberer(typePileTuc *pileTuc)
{
    free(pileTuc);
}

void ptucEmpiler(typePileTuc *pileTuc, unsigned char valeur)
{
    pileTuc->valeurs[pileTuc->s++] = valeur;
}

unsigned char ptucDepiler(typePileTuc *pileTuc)
{
    return pileTuc->valeurs[--pileTuc->s];
}

bool ptucEstVide(typePileTuc *pileTuc)
{
    return 0 == pileTuc->s;
}

unsigned char ptucSommet(typePileTuc *pileTuc)
{
    return pileTuc->valeurs[pileTuc->s - 1];
}