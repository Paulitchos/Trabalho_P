#include "header.h"
#include "utils.h"

void playing_game(char **tabuleiro,pjogadas pdados,pjogadas lista){
    char winner_char;
    while((winner_char=checkWinner(pdados)) == '_'){
        bool jogador = checkTurnos(pdados);
        if (jogador == true){
            printf("\nJogador 1 a jogar || Simbolo X ||Turno:%d\n",pdados->turnos);       
        }
        else{
            printf("\nJogador 2 a jogar || Simbolo O || Turno:%d\n",pdados->turnos);
        }
        printf("Mini_tabuleiro %d\n",pdados->mini_tabuleiro);
        lista = antesdeJogada(tabuleiro,pdados,lista);
        pdados->turnos++;
    }

    bool winner = checkTurnos(pdados);
    if(winner_char != '!'){
        if (winner == true){
        printf("\nJogador 1 ganhou o jogo|| Simbolo X\n");       
        }
        else{
        printf("\nJogador 2 ganhou o jogo || Simbolo O\n");
        }
    }
    else{
        printf("\nO jogo foi empate\n");
    }
    
}

bool checkTurnos(pjogadas pdados){
    if(pdados->turnos % 2 == 0)
        return false;
    return true;
}

pjogadas antesdeJogada(char** tabuleiro,pjogadas pdados,pjogadas lista){
    size_t size = 2;
    char *string;
    bool first_interation = true;

    printf("1- Fazer Jogada\n"); 
    printf("2- Rever K jogadas anteriores(K < 10)\n");
    printf("3- Sair do Jogo\n"); 

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
        lista = pedeJogada(tabuleiro,pdados,lista);
    }
    else if(strcmp(string,"2\n") == 0){
        free(string);
        int postjogadas = jogadas_anteriores(pdados);
        if (postjogadas != 0){
            mostra_info(lista,pdados,postjogadas);
        }

        lista = pedeJogada(tabuleiro,pdados,lista);    
    }
    else if(strcmp(string,"3\n") == 0){
        free(string);
    }
    return lista;
}

pjogadas pedeJogada(char **tabuleiro,pjogadas pdados,pjogadas lista){
    coordenadas coordenadas;
    pcoordenadas pcoordenadas = &coordenadas;
    size_t size = 1;
    pdados->input_jogadas = (char*)malloc(size);
    int bytes_size = 0;

    printf("\nIntroduza linha e coluna (ex:1 1,2 3):");
    bytes_size = getline(&pdados->input_jogadas, &size, stdin);
    while (possiblePlay(tabuleiro,pdados,bytes_size,pcoordenadas) == false){
        printf("Introduza novamente uma linha e coluna (ex:1 1,2 3):");
        bytes_size = getline(&pdados->input_jogadas, &size, stdin);
        //printf("%s",pdados->input_jogadas);
    };
    mostraMat(tabuleiro,9,9);
    arrayWinner(tabuleiro,pdados,pcoordenadas);
    lista = insere_ord(lista,pdados);
    //mostra_info_ex(lista);
    nextquadro(pdados);
    return lista;
}

bool possiblePlay(char **tabuleiro,pjogadas pdados,int bytes_size,pcoordenadas pcoordenadas){ 
    //printf("|%d|",bytes_size);
    
    if(bytes_size > 4)
        return false;
    if(atoi(&pdados->input_jogadas[0]) == 0 && atoi(&pdados->input_jogadas[2]) == 0) 
        return false;
    if(pdados->input_jogadas[1] != ' ')
        return false;
    sscanf(pdados->input_jogadas,"%d %d",&pdados->x,&pdados->y);
    if(pdados->x != 1 && pdados->x != 2 && pdados->x != 3)
        return false;
    if(pdados->y != 1 && pdados->y != 2 && pdados->y != 3)
        return false;

    //printf("|%d| |%d|",pdados->x,pdados->y);
    return converter_coordenadas(tabuleiro,pdados,pcoordenadas);   
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

        if(postjogadas < pdados->turnos && postjogadas > 0 && postjogadas < 10)
            possible = true;

        first_interation = false;
    }
    free(string);
    return postjogadas;
}

        
        
    
