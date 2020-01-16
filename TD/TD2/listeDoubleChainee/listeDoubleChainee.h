//
// Created by Damien Carrier on 16/01/2020.
//

#ifndef STRUCTURE_DE_DONNEES_LISTEDOUBLECHAINEE_H
#define STRUCTURE_DE_DONNEES_LISTEDOUBLECHAINEE_H

#include <stdbool.h>

typedef struct noeud {
    void *cle;
    struct noeud *suivant;
    struct noeud *precedent;
} noeud;

typedef struct file {
    noeud *sentinelle;
} file;

file *creerFile();
bool estVide(file *l);
file* enfiler(file *l, void *cle);
file* defiler(file *l);

#endif //STRUCTURE_DE_DONNEES_LISTEDOUBLECHAINEE_H
