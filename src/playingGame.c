#include "header.h"
#include "utils.h"

void playing_game(char **tabuleiro,pjogadas pdados,pjogadas lista,int robo){
    coordenadas coordenadas;
    pcoordenadas pcoordenadas = &coordenadas;

    for (int i = 0; i < 9; i++){
        pcoordenadas->winnerArray[i] = '_';
        //printf("!%c!",pdados->winnerArray[i]);
    }
    pcoordenadas->winnerArray[9] ='\0';

    char winner_char;
    bool final;

    bool bin = verificarbin();
    
    if (bin){
        bool decisao = querContinuar();

        if (decisao){
            lista = recuperarJogo(lista,pdados,tabuleiro,pcoordenadas);
            printf("\nTabuleiro de Jogo Recuperado\n");
            mostraMat(tabuleiro,9,9);
        }
   
    }

    while((winner_char=checkWinner(pcoordenadas)) == '_'){
        bool jogador = checkTurnos(pdados);

        if (robo == 0 || jogador == true){
            if (jogador == true)
                printf("\nJogador 1 a jogar || Simbolo X ||Turno:%d\n",pdados->turnos);
            
            else
                printf("\nJogador 2 a jogar || Simbolo O || Turno:%d\n",pdados->turnos);
            
        } else{

            printf("\nComputador a jogar || Simbolo O || Turno:%d\n",pdados->turnos);
          
        }

        printf("Mini_tabuleiro %d\n",pdados->mini_tabuleiro);
        lista = antesdeJogada(tabuleiro,pdados,lista,robo,pcoordenadas);
        pdados->turnos++;
    }

    bool winner = checkTurnos(pdados);
    if(winner_char != '!'){

        if (winner != true || robo == 0){

            if(winner)
                printf("\nJogador 2 ganhou o jogo|| Simbolo O\n");
            else
                printf("\nJogador 1 ganhou o jogo || Simbolo X\n");

        } else {

            printf("\nO computador ganhou o jogo|| Simbolo O\n");
            
        }         
        
    }
    else{
        printf("\nO jogo foi empate\n");
    }
    
    final = ficheiro_texto(lista);
    libertaMat(tabuleiro,9);
    elimina_lista(lista);
    if (final)
        printf("\nExportou o ficheiro de texto com sucesso");
    else
        printf("\nOcorreu erro a exportar o ficheiro :(");
}

bool checkTurnos(pjogadas pdados){
    if(pdados->turnos % 2 == 0)
        return false;
    return true;
}

pjogadas antesdeJogada(char** tabuleiro,pjogadas pdados,pjogadas lista,int robo,pcoordenadas pcoordenadas){
    size_t size = 2;
    char *string;
    bool first_interation = true;
    bool jogador = checkTurnos(pdados);

    if (robo == 0 || jogador == true){
        printf("1- Fazer Jogada\n"); 
        printf("2- Rever K jogadas anteriores(K < 10)\n");
        printf("3- Sair do Jogo\n"); 

        printf("Introduza o numero da opcao:");
        string = (char*)malloc(size);
        while(strcmp(string,"1\n") != 0 && strcmp(string,"2\n") !=0 && strcmp(string,"3\n") !=0){
            if (first_interation == false){
                printf("Tem que inserir pelo menos um numero:");
            }   
        getline(&string, &size, stdin);
        first_interation = false;
        
        }
        if(strcmp(string,"1\n") == 0){
            free(string);
            lista = pedeJogada(tabuleiro,pdados,lista,robo,pcoordenadas);
        }
        else if(strcmp(string,"2\n") == 0){
            free(string);
            int postjogadas = jogadas_anteriores(pdados);
            if (postjogadas != 0){
                mostra_info(lista,pdados,postjogadas,robo);
            }

            lista = pedeJogada(tabuleiro,pdados,lista,robo,pcoordenadas);    
        }
        else if(strcmp(string,"3\n") == 0){
            free(string);
            pause(lista,pdados);
            libertaMat(tabuleiro,9);
            elimina_lista(lista);
            exit(EXIT_SUCCESS);
        }

    } else{
      lista = pedeJogada(tabuleiro,pdados,lista,robo,pcoordenadas);
    }
    
    return lista;
}

pjogadas pedeJogada(char **tabuleiro,pjogadas pdados,pjogadas lista,int robo,pcoordenadas pcoordenadas){
    size_t size = 1;
    bool jogador = checkTurnos(pdados);
    bool good_robo_play = false;

    if (robo == 0 || jogador == true){
        pdados->input_jogadas = (char*)malloc(size);
        int bytes_size = 0;

        printf("\nIntroduza linha e coluna (ex:1 1,2 3):");
        bytes_size = getline(&pdados->input_jogadas, &size, stdin);
        while (possiblePlay(tabuleiro,pdados,bytes_size,pcoordenadas) == false){
            printf("Introduza novamente uma linha e coluna (ex:1 1,2 3):");
            bytes_size = getline(&pdados->input_jogadas, &size, stdin);
            //printf("%s",pdados->input_jogadas);
        }; 
    } else{
        while (good_robo_play == false){
            pdados->x = intUniformRnd(1,3);
            pdados->y = intUniformRnd(1,3);
            good_robo_play = converter_coordenadas(tabuleiro,pdados,pcoordenadas);
        }
    }
    free(pdados->input_jogadas);
    mostraMat(tabuleiro,9,9);
    arrayWinner(tabuleiro,pdados,pcoordenadas);
    lista = insere_ord(lista,pdados);
    //mostra_info_ex(lista);
    nextquadro(pdados,pcoordenadas);
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


        
        
    
