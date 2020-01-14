//
// Created by Damien Carrier on 14/01/2020.
//

#include "listeChaineeSimple.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Initialise une liste.
 *
 * @return liste *
 */
liste *lcCreerListe()
{
    liste *lcListe = (liste *) malloc(sizeof(liste));

    lcListe->debut = (noeud *) malloc(sizeof(noeud));
    lcListe->fin = (noeud *) malloc(sizeof(noeud));

    lcListe->debut->suivant = lcListe->fin;
    lcListe->fin->suivant = lcListe->fin;

    return lcListe;
}

/**
 * Test si une liste est vide.
 *
 * @param l
 *
 * @return  bool
 */
bool lcEstVide(liste *l)
{
    return (l->fin == l->debut->suivant);
}

/**
 * Inserer la valeur cle après le noeud n.
 *
 * @param n
 * @param cle
 *
 * @return noeud*
 */
noeud *lcInsererApres(noeud *n, unsigned char cle)
{
    noeud *newNoeud = (noeud *) malloc(sizeof(noeud));

    if (n != n->suivant) {
        newNoeud->cle = cle;
        newNoeud->suivant = n->suivant;
        n->suivant = newNoeud;
    }

    return newNoeud;
}

/**
 * Supprime le noeud après le n.
 *
 * @param n
 *
 * @return unsigned char
 */
unsigned char lcSupprimerSuivant(noeud *n)
{
    noeud *noeudSuivant = n->suivant;

    unsigned char cleNoeudSuppr = 'N';

    if (noeudSuivant != noeudSuivant->suivant) {
        n->suivant = noeudSuivant->suivant;
        cleNoeudSuppr = noeudSuivant->cle;

        free(noeudSuivant);
    }

    return cleNoeudSuppr;
}

/**
 * Supprime la liste complète.
 *
 * @param l
 */
void lcSupprimerListe(liste *l)
{
    if (!lcEstVide(l)) {
        noeud *noeudCourant = l->debut;

        while (l->fin != noeudCourant) {
            noeud *noeudSuivant = noeudCourant->suivant;
            unsigned char charSuppr = lcSupprimerSuivant(noeudCourant);
            noeudCourant = noeudSuivant;
        }

        free(l);
    }
}

/**
 * Parcourt et affiche la liste.
 *
 * @param l
 */
void lcParcourir(liste *l)
{
    if (!lcEstVide(l)) {
        noeud *noeudCourant = l->debut->suivant;

        while (l->fin != noeudCourant) {
            printf("%c", noeudCourant->cle);

            if (l->fin != noeudCourant->suivant) {
                printf(" -> ");
            }

            noeudCourant = noeudCourant->suivant;
        }
    } else {
        printf("La liste est vide.");
    }

    printf("\n");
}

/**
 * Recherche une valeur dans la liste, renvoie vrai si présente faux sinon.
 *
 * @param l
 * @param cle
 *
 * @return bool
 */
bool lcContient(liste *l, unsigned char cle) {
    bool result = false;

    if (!lcEstVide(l)) {
        noeud *noeudCourant = l->debut->suivant;

        while (!result && l->fin != noeudCourant) {
            if (cle == noeudCourant->cle) {
                result = true;
            }

            noeudCourant = noeudCourant->suivant;
        }
    }

    return result;
}

/**
 * Insère une valeur dans la liste.
 *
 * @param l
 * @param cle
 *
 * @return noeud*
 */
noeud *lcInsererOrdonne(liste *l, unsigned char cle)
{
    noeud * newNoeud = (noeud *) malloc(sizeof(noeud));

    if (lcEstVide(l)) {
        newNoeud = lcInsererApres(l->debut, cle);
    } else {
        noeud *noeudCourant = l->debut;

        while (l->fin != noeudCourant->suivant && cle > noeudCourant->suivant->cle) {
            noeudCourant = noeudCourant->suivant;
        }

        newNoeud = lcInsererApres(noeudCourant, cle);
    }

    return newNoeud;
}

/**
 * Supprime une clé si elle existe.
 *
 * @param l
 * @param cle
 *
 * @return bool
 */
bool lcSupprimerCle(liste *l, unsigned char cle)
{
    bool result = false;

    if (lcContient(l, cle)) {
        noeud *noeudCourant = l->debut;

        while (l->fin != noeudCourant) {
            if (cle == noeudCourant->suivant->cle) {
                unsigned char charResult = lcSupprimerSuivant(noeudCourant);
                result = true;
            }

            noeudCourant = noeudCourant->suivant;
        }
    }

    return result;
}

/**
 * Main.
 *
 * @return int
 */
int main(void)
{
    liste *maListeOrdonnee = lcCreerListe();
    noeud *newNoeud = lcInsererApres(lcInsererApres(lcInsererApres(maListeOrdonnee->debut, 'F'), 'I'), 'L');

    newNoeud = lcInsererOrdonne(maListeOrdonnee, 'A');
    newNoeud = lcInsererOrdonne(maListeOrdonnee, 'Z');
    newNoeud = lcInsererOrdonne(maListeOrdonnee, 'K');

    lcParcourir(maListeOrdonnee);

    lcSupprimerListe(maListeOrdonnee);

    lcParcourir(maListeOrdonnee);

    return 0;
}