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
    return tree->
}

void insererArbre(void* cle)
{

}

int main(void)
{
    arbre* tree = creerArbre();

    return 0;
}