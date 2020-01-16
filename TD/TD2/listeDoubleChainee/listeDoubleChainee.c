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
file *creerFile()
{
    file* file = (file *) malloc(sizeof(file));
    file->sentinelle->suivant = file->sentinelle;
    file->sentinelle->precedent = file->sentinelle;

    return file;
}

/**
 * renvoie si la file est vide.
 */
bool estVide(file *f)
{
    return (f->sentinelle == f->sentinelle->precedent && f->sentinelle == f->sentinelle->suivant);
}

/**
 * enfiler une valeur à la fin.
 */
file*  enfiler(file *f, void *cle)
{
    noeud* noeudPrecedent = f->sentinelle->precedent;
    noeud* newNoeud = (noeud *) malloc (sizeof(noeud));
    
    newNoeud->cle = cle;
    newNoeud->precedent = noeudPrecedent;
    newNoeud->suivant->suivant = f->sentinelle;
    f->sentinelle->precedent = newNoeud;
    noeudPrecedent->suivant = newNoeud;

    return f;
}

/**
 * Défile la première valeur.
 */
file* defiler(file *f)
{
    if (!estVide(f)) {
        noeud *noeudASuppr = f->sentinelle->suivant;
        noeud *noeudASupprSuivant = noeudASuppr->suivant;

        f->sentinelle->suivant = noeudASupprSuivant;
        noeudASupprSuivant->precedent = f->sentinelle;

        free(noeudASuppr);
    }

    return f;
}

int main(void)
{
    liste* liste = creerFile();

    return 0;
}