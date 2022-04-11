#include "header.h"

char** criaMatRegras(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
            p[i][j] = ' ';
    }
    return p;
}

void regrasDoJogo(char** p){
    char **regrasjogo;
    printf("\nNumeros dos Mini-Tabuleiros do Ultimate Tic-Tac-Toe\n");
    regrasjogo = criaMatRegras(9,9);
    setupTabuleiroRegras(regrasjogo);
    putchar('\n');
    putchar('\n');
}

void setupTabuleiroRegras(char** pregras){
    setPos(pregras,1,1,'1');
    setPos(pregras,1,4,'2');
    setPos(pregras,1,7,'3');
    setPos(pregras,4,1,'4');
    setPos(pregras,4,4,'5');
    setPos(pregras,4,7,'6');
    setPos(pregras,7,1,'7');
    setPos(pregras,7,4,'8');
    setPos(pregras,7,7,'9');
    mostraMat(pregras,9,9);
}