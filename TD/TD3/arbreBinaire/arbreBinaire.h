//
// Created by Damien Carrier on 20/01/2020.
//

#ifndef STRUCTURE_DE_DONNEES_ARBREBINAIRE_H
#define STRUCTURE_DE_DONNEES_ARBREBINAIRE_H

#include <stdbool.h>

typedef struct noeud {
    void* cle;
    struct noeud* droite;
    struct noeud* gauche;
} noeud;

typedef struct arbre {
    noeud* debut;
    noeud* z;
} arbre;

arbre* creerArbre();
bool estVide(arbre* tree);
void insererArbre(arbre* tree, void* cle);
noeud* rechercher(arbre* tree, void* cle);

/** Parcours */
void parcoursLargeur(arbre *tree);

void suppressionAbr(arbre* tree);

#endif //STRUCTURE_DE_DONNEES_ARBREBINAIRE_H
