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
void insererArbre(void* cle);

#endif //STRUCTURE_DE_DONNEES_ARBREBINAIRE_H
