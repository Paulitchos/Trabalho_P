#include "header.h"
#include "utils.h"

void start_Game(){
    jogadas dados;
    pjogadas pdados = &dados;
    pjogadas lista = NULL;
    pdados->turnos = 1;
    size_t size = 2;
    char *string;
    char **tabuleirojogo;
    bool first_interation = true;
    char pos;
    for (int i = 0; i < 9; i++){
        pdados->winnerArray[i] = '_';
        //printf("!%c!",pdados->winnerArray[i]);
    }
    pdados->winnerArray[9] ='\0';
    //printf("|%lu|",sizeof(pdados->winnerArray));
    
    pdados->mini_tabuleiro = intUniformRnd(1,9);
    
    
    regrasDoJogo();

    printf("1- Jogar contra outro jogador\n");
    printf("2- Jogar contra o computador\n"); 

    printf("Introduza o numero da opcao:");
    string = (char*)malloc(size);
    while(strcmp(string,"1\n") != 0 && strcmp(string,"2\n") !=0){
        if (first_interation == false){
            printf("Tem que inserir pelo menos um numero:");
        }
        getline(&string, &size, stdin);
        
        first_interation = false;
        
    }
    if(strcmp(string,"1\n") == 0){
        free(string);
        tabuleirojogo = criaMat(9,9);
        printf("\nTabuleiro Inicial\n");
        printf("O jogo comeca no Mini-Tabuleiro %d\n\n",pdados->mini_tabuleiro);
        mostraMat(tabuleirojogo,9,9);
        playing_game(tabuleirojogo,pdados,lista);
    }
    else if(strcmp(string,"2\n") == 0){
        free(string);
    }
    
}