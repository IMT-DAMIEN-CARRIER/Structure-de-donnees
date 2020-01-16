//
// Created by Damien Carrier on 16/01/2020.
//

#include "listeDoubleChainee.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Creer la file
 * @return file*
 */
file* creerFile()
{
    file* f = (file *) malloc(sizeof(file));
    f->sentinelle = (noeud *) malloc(sizeof(noeud));
    f->sentinelle->suivant = f->sentinelle;
    f->sentinelle->precedent = f->sentinelle;

    return f;
}

/**
 * renvoie si la file est vide.
 */
bool estVide(file *f)
{
    return (f->sentinelle == f->sentinelle->precedent);
}

/**
 * enfiler une valeur à la fin.
 */
void  enfiler(file *f, void* cle)
{
    noeud *newNoeud = (noeud *) malloc(sizeof(noeud));
    newNoeud->cle = cle;

    if (!estVide(f)) {
        noeud* lastNoeud = f->sentinelle->precedent;

        newNoeud->precedent = lastNoeud;
        newNoeud->suivant = f->sentinelle;

        lastNoeud->suivant = newNoeud;
        f->sentinelle->precedent = newNoeud;
    } else {
        newNoeud->precedent = f->sentinelle;
        newNoeud->suivant = f->sentinelle;

        f->sentinelle->suivant = newNoeud;
        f->sentinelle->precedent = newNoeud;
    }
}

/**
 * Défile la première valeur.
 */
void defiler(file *f)
{
    if (!estVide(f)) {
        noeud *noeudASuppr = f->sentinelle->suivant;
        noeud *noeudASupprSuivant = noeudASuppr->suivant;

        f->sentinelle->suivant = noeudASupprSuivant;
        noeudASupprSuivant->precedent = f->sentinelle;

        free(noeudASuppr);
    }
}

void afficherFile(file* f)
{
    if (!estVide(f)) {
        noeud* noeudCourant = f->sentinelle->suivant;

        while (f->sentinelle != noeudCourant) {
            printf("%c", *((unsigned char *) noeudCourant->cle));

            if (f->sentinelle != noeudCourant->suivant) {
                printf(" -> ");
            }

            noeudCourant = noeudCourant->suivant;
        }

        printf("\n");
    } else {
        printf("La liste est vide.\n");
    }
}

int main(void)
{
    file* f = creerFile();

    afficherFile(f);

    unsigned char c = 'e';
    enfiler(f, &c);
    afficherFile(f);

    unsigned char *caracter = (unsigned char *) malloc(sizeof(*caracter));

    *caracter = 'f';
    enfiler(f, caracter);
    afficherFile(f);

    *caracter = 'i';
    enfiler(f, caracter);
    afficherFile(f);

    *caracter = 'l';
    enfiler(f, caracter);
    afficherFile(f);

    *caracter = 'e';
    enfiler(f, caracter);
    afficherFile(f);

    defiler(f);
    afficherFile(f);

    return 0;
}