#include "header.h"
#include "utils.h"

bool converter_coordenadas(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas){
    pcoordenadas->n_mini_converted = pdados->mini_tabuleiro - 1;
    pcoordenadas->x_mini_tabuleiro = pcoordenadas->n_mini_converted / 3;
    pcoordenadas->y_mini_tabuleiro = pcoordenadas->n_mini_converted % 3;
    int x_mini_global = (3 * pcoordenadas->x_mini_tabuleiro)+ pdados->x - 1;
    int y_mini_global = (3 * pcoordenadas->y_mini_tabuleiro)+ pdados->y - 1;


    if(tabuleiro[x_mini_global][y_mini_global] != '_')
        return false;

    bool jogador = checkTurnos(pdados);
      
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

int jogadas_anteriores(pjogadas pdados){
    size_t size = 2;
    char *string;
    bool first_interation = true;
    bool possible = false;
    int postjogadas = 0;
    string = (char*)malloc(size);
    if(pdados->turnos == 1){
        printf("\nNão pode consultar jogadas no primeiro turno");
        free(string);
        return 0;
    }
    printf("Introduza k jogadas quer consultar:");
    while(possible == false){
        if (first_interation == false){
            printf("Tem que inserir um numero(k minimo 1 || k maximo 10) e menor que numero de turnos:");
        }
        getline(&string, &size, stdin);
        
        postjogadas = atoi(string);

        if(postjogadas < pdados->turnos && postjogadas > 0 && postjogadas <= 10)
            possible = true;

        first_interation = false;
    }
    free(string);
    return postjogadas;
}