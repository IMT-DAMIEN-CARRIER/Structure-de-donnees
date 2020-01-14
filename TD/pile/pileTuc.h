/**
* Created by dcarrier on 06/01/2020.
*/

#ifndef PILETUC_H
#define PILETUC_H

#include <stdbool.h>

#define TAILLE_MAX_PTUC 100

typedef struct pileTuc
{
    int s;
    unsigned char valeurs[TAILLE_MAX_PTUC];
} typePileTuc;

typePileTuc *ptucCreer(void);

void ptucLiberer(typePileTuc *pileTuc);

void ptucEmpiler(typePileTuc *, unsigned char);

unsigned char ptucDepiler(typePileTuc *);

bool ptucEstVide(typePileTuc *);

unsigned char ptucSommet(typePileTuc *);

#endif /* PILETUC_H */
