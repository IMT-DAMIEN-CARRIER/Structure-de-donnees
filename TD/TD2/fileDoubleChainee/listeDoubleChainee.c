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
void enfiler(file *f, void* cle)
{
    noeud *newNoeud = (noeud *) malloc(sizeof(noeud));
    newNoeud->cle = cle;

    newNoeud->suivant = f->sentinelle;
    newNoeud->precedent = f->sentinelle->precedent;

    newNoeud->suivant->precedent = newNoeud;
    newNoeud->precedent->suivant = newNoeud;
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

    unsigned char e = 'e';
    enfiler(f, &e);
    afficherFile(f);

    unsigned char *caracter = (unsigned char *) malloc(sizeof(*caracter));

    *caracter = 'f';
    enfiler(f, caracter);
    afficherFile(f);

    unsigned char i = 'i';
    enfiler(f, &i);
    afficherFile(f);

    unsigned char l = 'l';
    enfiler(f, &l);
    afficherFile(f);

    unsigned char ee = 'e';
    enfiler(f, &ee);
    afficherFile(f);

    defiler(f);
    afficherFile(f);

    return 0;
}