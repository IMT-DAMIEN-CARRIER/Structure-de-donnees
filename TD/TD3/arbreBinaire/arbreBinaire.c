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
    noeud* node = parent->droite;

    while (node != tree->z) {
        parent = node;

        node = (cle < node->cle) ? node->gauche : node->droite;
    }

    node = malloc(sizeof(noeud));

    node->cle = cle;
    node->droite = tree->z;
    node->gauche = tree->z;

    if (cle < parent->cle) {
        parent->gauche = node;
    } else {
        parent->droite = node;
    }
}

noeud* rechercher(arbre* tree, void* cle)
{
    noeud *node = tree->debut;
    tree->z->cle = cle;

    while (cle != node->cle) {
        node = (cle < node->cle) ? node->gauche : node->droite;
    }

    return node;
}

int main(void)
{
    arbre* tree = creerArbre();

    return 0;
}