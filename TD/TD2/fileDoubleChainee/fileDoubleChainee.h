//
// Created by Damien Carrier on 16/01/2020.
//

#ifndef STRUCTURE_DE_DONNEES_FILEDOUBLECHAINEE_H
#define STRUCTURE_DE_DONNEES_FILEDOUBLECHAINEE_H

#include <stdbool.h>

typedef struct noeud {
    void* cle;
    struct noeud* suivant;
    struct noeud* precedent;
} noeud;

typedef struct file {
    noeud* sentinelle;
} file;

file* creerFile();
bool estVide(file* f);
void enfiler(file *f, void *cle);

void *defiler(file *f);

void afficherFile(file *f);

#endif //STRUCTURE_DE_DONNEES_FILEDOUBLECHAINEE_H
