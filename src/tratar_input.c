#include "header.h"
#include "utils.h"

bool converter_coordenadas(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas){
    pcoordenadas->n_mini_converted = pdados->mini_tabuleiro - 1;
    pcoordenadas->x_mini_tabuleiro = pcoordenadas->n_mini_converted / 3;
    pcoordenadas->y_mini_tabuleiro = pcoordenadas->n_mini_converted % 3;
    int x_mini_global = (3 * pcoordenadas->x_mini_tabuleiro)+ pdados->x - 1;
    int y_mini_global = (3 * pcoordenadas->y_mini_tabuleiro)+ pdados->y - 1;

    bool jogador = checkTurnos(pdados);
    if(tabuleiro[x_mini_global][y_mini_global] != '_')
        return false;
      
    if (jogador == true){
        setPos(tabuleiro,x_mini_global,y_mini_global,'X');   
    }
    else{
        setPos(tabuleiro,x_mini_global,y_mini_global,'O'); 
    }
    
   return true;
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

void nextquadro(pjogadas pdados,pcoordenadas pcoordenadas){
    pdados->mini_tabuleiro = ((pdados->x- 1) * 3) + (pdados ->y - 1) + 1;
    
    if(pcoordenadas->winnerArray[pdados->mini_tabuleiro - 1] != '_'){
        
        while(pcoordenadas->winnerArray[pdados->mini_tabuleiro - 1] != '_'){
            pdados->mini_tabuleiro = intUniformRnd(1,9);
        }
    }
}