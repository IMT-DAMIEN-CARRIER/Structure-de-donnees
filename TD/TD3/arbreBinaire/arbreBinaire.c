//
// Created by Damien Carrier on 20/01/2020.
//

#include "arbreBinaire.h"

#include <stdlib.h>
#include <stdio.h>

arbre* creerArbre()
{
    arbre* tree =(arbre *) malloc(sizeof(arbre));
    tree->z = (noeud *) malloc(sizeof(noeud));
    tree->debut = (noeud *) malloc(sizeof(noeud));

    tree->z->gauche = tree->z;
    tree->z->droite = tree->z;

    tree->debut->gauche = tree->z;
    tree->debut->droite = tree->z;

    return tree;
}

bool estVide(arbre* tree)
{
    return tree->debut->droite == tree->z;
}

void insererArbre(arbre* tree, void* cle)
{
    noeud* parent = tree->debut;
    noeud* noeud = parent->droite;

    while (noeud != tree->z) {
        parent = noeud;

        noeud = (cle < noeud->cle) ? noeud->gauche : noeud->droite;
    }

    noeud = malloc(sizeof(noeud));

    noeud->cle = cle;
    noeud->droite = tree->z;
    noeud->gauche = tree->z;

    if (cle < parent->cle) {
        parent->gauche = noeud;
    } else {
        parent->droite = noeud;
    }
}

noeud* rechercher(arbre* tree, void* cle)
{

}

int main(void)
{
    arbre* tree = creerArbre();

    return 0;
}