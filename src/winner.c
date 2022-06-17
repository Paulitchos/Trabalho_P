#include "header.h"
#include "utils.h"

char checkWinner(pcoordenadas pcoordenadas){
    int freeglobalspaces = 8;
    //Check linhas
    for(int i = 0;i <9;i+=3){
        if(pcoordenadas->winnerArray[i] == pcoordenadas->winnerArray[i+1] 
        && pcoordenadas->winnerArray[i] == pcoordenadas->winnerArray[i+2] 
        && pcoordenadas->winnerArray[i] != '_' && pcoordenadas->winnerArray[i] != '!')
            return pcoordenadas->winnerArray[i];
    }

    //Check colunas
    for(int i = 0;i <3;i++){
        if(pcoordenadas->winnerArray[i] == pcoordenadas->winnerArray[i+3] 
        && pcoordenadas->winnerArray[i] == pcoordenadas->winnerArray[i+6] 
        && pcoordenadas->winnerArray[i] != '_' && pcoordenadas->winnerArray[i] != '!')
            return pcoordenadas->winnerArray[i];
    }
    //Check diagonais

    if(pcoordenadas->winnerArray[0] == pcoordenadas->winnerArray[4] 
    && pcoordenadas->winnerArray[0] == pcoordenadas->winnerArray[8] 
    && pcoordenadas->winnerArray[0] != '_' && pcoordenadas->winnerArray[0] != '!')
        return pcoordenadas->winnerArray[0];

    if(pcoordenadas->winnerArray[2] == pcoordenadas->winnerArray[4] 
    && pcoordenadas->winnerArray[2] == pcoordenadas->winnerArray[6] 
    && pcoordenadas->winnerArray[2] != '_' && pcoordenadas->winnerArray[2] != '!')
        return pcoordenadas->winnerArray[2];

    //Se todos do tabuleiros já estão preechidos
    for(int i = 0;i <9;i++){
        if(pcoordenadas->winnerArray[i] != '_')
            freeglobalspaces--;      
    }
    if(freeglobalspaces == 0)
        return '!';

    //Senão continua o jogo
    return '_';
}

char check_minitabuleiro(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas){
    char peça,prox_peça;
    int x_global_atual;
    int y_global_atual;

    //Check linhas

    for (int i = 1; i <= 3; i++){
        x_global_atual=(3 * pcoordenadas->x_mini_tabuleiro)+ i - 1;
        y_global_atual = (3 * pcoordenadas->y_mini_tabuleiro) + 1 - 1;
        if(tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual][y_global_atual + 1] 
        && tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual][y_global_atual + 2] 
        && tabuleiro[x_global_atual][y_global_atual] != '_'){
            return tabuleiro[x_global_atual][y_global_atual];
        } 
    }

    //Check colunas

     for (int i = 1; i <= 3; i++){
        x_global_atual=(3 * pcoordenadas->x_mini_tabuleiro)+ 1 - 1;
        y_global_atual = (3 * pcoordenadas->y_mini_tabuleiro) + i - 1;
        if(tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual + 1][y_global_atual] 
        && tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual + 2][y_global_atual] 
        && tabuleiro[x_global_atual][y_global_atual] != '_'){
            return tabuleiro[x_global_atual][y_global_atual];
        } 
    }

    //Check diagonal
    x_global_atual=(3 * pcoordenadas->x_mini_tabuleiro)+ 1 - 1;
    y_global_atual = (3 * pcoordenadas->y_mini_tabuleiro) + 1 - 1;
    
    if (tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual + 1][y_global_atual+1] 
    && tabuleiro[x_global_atual][y_global_atual] == tabuleiro[x_global_atual + 2][y_global_atual+2] 
    && tabuleiro[x_global_atual][y_global_atual] != '_')
        return  tabuleiro[x_global_atual][y_global_atual];
    
    if (tabuleiro[x_global_atual][y_global_atual + 2] == tabuleiro[x_global_atual + 1][y_global_atual + 1] 
    && tabuleiro[x_global_atual][y_global_atual + 2] == tabuleiro[x_global_atual + 2][y_global_atual] 
    && tabuleiro[x_global_atual][y_global_atual + 2] != '_')
        return  tabuleiro[x_global_atual][y_global_atual + 2];
    
    int freespaces = checkFreeSpaces(tabuleiro,pcoordenadas);
    
    if (freespaces == 0)
        return '!';

    return '_';
}

int checkFreeSpaces(char** tabuleiro,pcoordenadas pcoordenadas){
    int freespaces = 9;
    int x_global_atual =(3 * pcoordenadas->x_mini_tabuleiro)+ 1 - 1;
    int y_global_atual = (3 * pcoordenadas->y_mini_tabuleiro) + 1 - 1;
    
    for (int i = x_global_atual; i <x_global_atual+3; i++){
        for (int j = y_global_atual; j < y_global_atual+ 3; j++){
            if(tabuleiro[i][j] != '_')
                freespaces--;
        } 
    }
    return freespaces;
}

void arrayWinner(char**tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas){
    bool jogador = checkTurnos(pdados);
    char winner_quadro = check_minitabuleiro(tabuleiro,pdados,pcoordenadas);
    //printf("\n|%c|\n",winner_quadro);
    if(winner_quadro == 'X' || winner_quadro == 'O'){
        if (jogador == true){
            printf("O Jogador 1 ganhou Quadro %d",pdados->mini_tabuleiro);
            pcoordenadas->winnerArray[pcoordenadas->n_mini_converted] = winner_quadro;
        }
        else{
            printf("O Jogador 2 ganhou Quadro %d",pdados->mini_tabuleiro);
            pcoordenadas->winnerArray[pcoordenadas->n_mini_converted] = winner_quadro;
        }
    }else if(winner_quadro == '!'){
        printf("Empate no Quadro %d",pdados->mini_tabuleiro);
        pcoordenadas->winnerArray[pcoordenadas->n_mini_converted] = winner_quadro;
    }
}

