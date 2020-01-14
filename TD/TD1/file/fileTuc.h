/**
* Created by dcarrier on 06/01/2020.
*/

#ifndef FILETUC_H
#define FILETUC_H

#define TAILLE_MAX_FTUC 100

typedef struct fileTuc
{
    int first;
    int last;
    unsigned char valeurs[TAILLE_MAX_PTUC];
} typeFileTuc;

#endif //FILETUC_H
