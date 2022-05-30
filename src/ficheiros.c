#include "header.h"
#include <errno.h>

bool ficheiro_texto(pjogadas lista){
    char fichtxt[50];
    FILE *f = NULL;
    

    
    printf("Introduza o seu nome:");
    fgets(fichtxt,sizeof(fichtxt),stdin);
    fichtxt[strlen(fichtxt)-1] = 0;
    f = fopen(fichtxt,"wt");

    if(f == NULL){
        printf("Erro no acesso ao ficheiro %d\n",errno);
        return false;
    } else {
        while(lista != NULL){
            if(lista->turnos % 2 == 0)      
                fprintf(f,"\nO jogador 2 efetuou a jogada(x e y): %d %d no mini-tabuleiro: %d || turno %d",lista->x,lista->y, lista->mini_tabuleiro,lista->turnos);
            else
                fprintf(f,"\nO jogador 1 efetuou a jogada(x e y): %d %d no mini-tabuleiro: %d || turno %d",lista->x,lista->y, lista->mini_tabuleiro,lista->turnos);
            lista = lista->prox;
            }
    }

    fclose(f);
    return true;
}