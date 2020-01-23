//
// Created by Damien Carrier on 20/01/2020.
//

#include "arbreBinaire.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * Creer un arbre binaire.
 *
 * @return arbre*
 */
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

/**
 * Renvoie si l'arbre est vide ou non.
 *
 * @param tree
 *
 * @return bool
 */
bool estVide(arbre* tree)
{
    return tree->debut->droite == tree->z;
}

/**
 * Inserer un nouveau noeud avec la valeur clé dans l'arbre.
 *
 * @param tree
 * @param cle
 */
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

/**
 * Recherche le noeud qui contient la valeur clé.
 *
 * @param tree
 * @param cle
 *
 * @return noeud *
 */
noeud* rechercher(arbre* tree, void* cle)
{
    noeud *node = tree->debut;
    tree->z->cle = cle;

    while (cle != node->cle) {
        node = (cle < node->cle) ? node->gauche : node->droite;
    }

    return node;
}

void suppressionAbr(arbre* tree)
{
}

/**
 *
 * @return int
 */
int main(void)
{
    arbre* tree = creerArbre();

    return 0;
}