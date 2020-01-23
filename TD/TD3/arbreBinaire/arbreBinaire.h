//
// Created by Damien Carrier on 20/01/2020.
//

#ifndef STRUCTURE_DE_DONNEES_ARBREBINAIRE_H
#define STRUCTURE_DE_DONNEES_ARBREBINAIRE_H

#include <stdbool.h>

typedef struct noeudArbre {
    void *cle;
    struct noeudArbre *droite;
    struct noeudArbre *gauche;
} noeudArbre;

typedef struct arbre {
    noeudArbre *debut;
    noeudArbre *z;
} arbre;

arbre *creerArbre();

bool estVideArbre(arbre *tree);

void insererArbre(arbre *tree, void *cle);

noeudArbre *rechercher(arbre *tree, void *cle);

/** Parcours */
void parcoursLargeur(arbre *tree);

void suppressionAbr(arbre* tree);

#endif //STRUCTURE_DE_DONNEES_ARBREBINAIRE_H