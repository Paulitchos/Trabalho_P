#include "header.h"

bool converter_coordenadas(char** tabuleiro,pjogadas pdados){
    int n_mini_converted = pdados->mini_tabuleiro - 1;
    int x_mini_tabuleiro = n_mini_converted / 3;
    int y_mini_tabuleiro = n_mini_converted % 3;
    int x_mini_global = (3 * x_mini_tabuleiro)+ pdados->x - 1;
    int y_mini_global = (3 * y_mini_tabuleiro)+ pdados->y - 1;

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

char getPos(char **p, int x, int y){
    return p[x][y];
}