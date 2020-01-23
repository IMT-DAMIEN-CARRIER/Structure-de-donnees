//
// Created by Damien Carrier on 20/01/2020.
//

#include "arbreBinaire.h"
#include "../../TD2/fileDoubleChainee/fileDoubleChainee.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * Creer un arbre binaire.
 *
 * @return arbre*
 */
arbre* creerArbre()
{
    arbre *tree = (arbre *) malloc(sizeof(arbre));
    tree->z = (noeudArbre *) malloc(sizeof(noeudArbre));
    tree->debut = (noeudArbre *) malloc(sizeof(noeudArbre));

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
bool estVideArbre(arbre *tree) {
    return tree->debut->droite == tree->z;
}

/**
 * Inserer un nouveau noeudArbre avec la valeur clé dans l'arbre.
 *
 * @param tree
 * @param cle
 */
void insererArbre(arbre* tree, void* cle) {
    noeudArbre *parent = tree->debut;
    noeudArbre *node = parent->droite;

    while (node != tree->z) {
        parent = node;

        node = (cle < node->cle) ? node->gauche : node->droite;
    }

    node = malloc(sizeof(noeudArbre));

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
 * Recherche le noeudArbre qui contient la valeur clé.
 *
 * @param tree
 * @param cle
 *
 * @return noeudArbre *
 */
noeudArbre *rechercher(arbre *tree, void *cle) {
    noeudArbre *node = tree->debut;
    tree->z->cle = cle;

    while (cle != node->cle) {
        node = (cle < node->cle) ? node->gauche : node->droite;
    }

    return node;
}

void parcoursLargeur(arbre *tree) {
    if (!estVideArbre(tree)) {
        file *maFile = (file *) malloc(sizeof(file));
        noeudArbre *noeudCourant = tree->debut;

        enfiler(maFile, noeudCourant->cle);

        while (!estVide(maFile)) {
            noeudCourant = defiler(maFile);
            printf("%c", *((unsigned char *) noeudCourant->cle));

            if (noeudCourant->gauche != tree->z) {
                enfiler(maFile, noeudCourant->gauche);
            }

            if (noeudCourant->droite != tree->z) {
                enfiler(maFile, noeudCourant->droite);
            }
        }
    }
}

void suppressionAbr(arbre *tree) {

}

/**
 *
 * @return int
 */
int main(void) {
    arbre *tree = creerArbre();

    unsigned char e = 'e';
    insererArbre(tree, &e);

    e = 'a';
    insererArbre(tree, &e);

    printf("%c <- %c -> %c \n",
           *((unsigned char *) tree->debut->gauche->cle),
           *((unsigned char *) tree->debut->cle),
           *((unsigned char *) tree->debut->droite->cle)
    );

    return 0;
}