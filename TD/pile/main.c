/**
* Created by dcarrier on 06/01/2020.
*/

#include <stdio.h>
#include "pileTuc.h"

int main(int argc, const char *argv[])
{
    typePileTuc *pileTuc = ptucCreer();
    printf(ptucEstVide(pileTuc) ? "VIDE\n\n" : "PILE NON VIDE\n\n");

    printf("TEST 2\n");
    ptucEmpiler(pileTuc, 'P');
    printf(ptucEstVide(pileTuc) ? "VIDE\n\n" : "PILE NON VIDE\n\n");

    printf("TEST 3\n");
    printf("%c", ptucSommet(pileTuc));
    printf("\n");
    printf(ptucEstVide(pileTuc) ? "VIDE\n\n" : "PILE NON VIDE\n\n");

    printf("TEST 4\n");
    ptucEmpiler(pileTuc, 'I');
    while (!ptucEstVide(pileTuc)) {
        printf("%c", ptucDepiler(pileTuc));
    }
    printf("\n");
}