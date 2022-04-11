#include "header.h"
#include "utils.h"
#include <stdio.h>


void playing_game(char **tabuleiro,pjogadas pdados){ 
    while(checkWinner() == false){
        bool jogador = checkTurnos(pdados);
        if (jogador == true){
            printf("\nJogador 1 a jogar || Simbolo X ||Turno:%d\n",pdados->turnos);       
        }
        else{
            printf("\nJogador 2 a jogar || Simbolo O || Turno:%d\n",pdados->turnos);
        }
        printf("Mini_tabuleiro %d\n",pdados->mini_tabuleiro);
        pedeJogada(tabuleiro,pdados);
        pdados->turnos++;
    }
}

bool checkTurnos(pjogadas pdados){
    if(pdados->turnos % 2 == 0)
        return false;
    return true;
}

bool checkWinner(){
    return false;
}

void pedeJogada(char **tabuleiro,pjogadas pdados){
    size_t size = 1;
    pdados->input_jogadas = (char*)malloc(size);
    int bytes_size = 0;
    printf("Introduza linha e coluna (ex:1 1,2 3):");
    bytes_size = getline(&pdados->input_jogadas, &size, stdin);
    while (possiblePlay(tabuleiro,pdados,bytes_size) == false){
        printf("Introduza novamente uma linha e coluna (ex:1 1,2 3):");
        bytes_size = getline(&pdados->input_jogadas, &size, stdin);
    };
    mostraMat(tabuleiro,9,9);
}

bool possiblePlay(char **tabuleiro,pjogadas pdados,int bytes_size){ 
    //printf("|%d|",bytes_size);
    if(bytes_size > 4)
        return false;
    if(atoi(&pdados->input_jogadas[1]) == 0 && atoi(&pdados->input_jogadas[3]) == 0) 
        return false;
    sscanf(pdados->input_jogadas,"%d %d",&pdados->x,&pdados->y);
    if(pdados->x != 1 && pdados->x != 2 && pdados->x != 3)
        return false;
    if(pdados->y != 1 && pdados->y != 2 && pdados->y != 3)
        return false;
    return converter_coordenadas(tabuleiro,pdados);
    printf("|%d| |%d|",pdados->x,pdados->y);
}


        
        
    
