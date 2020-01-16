//
// Created by Damien Carrier on 14/01/2020.
//

#ifndef STRUCTURE_DE_DONNEES_LISTECHAINEESIMPLE_H
#define STRUCTURE_DE_DONNEES_LISTECHAINEESIMPLE_H

#include <stdbool.h>

typedef struct noeud {
    unsigned char cle;
    struct noeud *suivant;
} noeud;

typedef struct file {
    noeud *debut;
    noeud *fin;
} liste;

liste *lcCreerListe();
bool lcEstVide(liste *l);
noeud *lcInsererApres(noeud *n, unsigned char cle);
unsigned char lcSupprimerSuivant(noeud *n);
void lcSupprimerListe(liste *l);
void lcParcourir(liste *l);
bool lcContient(liste *l, unsigned char cle);
noeud *lcInsererOrdonne(liste *l, unsigned char cle);
bool lcSupprimerCle(liste *l, unsigned char cle);
liste *lcFusionner(liste *liste1, liste *liste2);

#endif //STRUCTURE_DE_DONNEES_LISTECHAINEESIMPLE_H
