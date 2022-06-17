#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct dados_jogada jogadas,*pjogadas;

struct dados_jogada
{
    int turnos;
    int mini_tabuleiro;
    char *input_jogadas;
    int x;
    int y;
    
    pjogadas prox;
};

typedef struct todascoordenadas
{
    int n_mini_converted; //minitabuleiro convertido para 0 a 8
    int x_mini_tabuleiro; //pegar no x da jogada e convertê-la para tabueleiro global
    int y_mini_tabuleiro; //pegar no y da jogada e convertê-la para tabueleiro global
    char winnerArray[10]; //array que guarda os minitabuleiros ganhos ou empatados

}coordenadas,*pcoordenadas;


//Começa o jogo
void start_Game();

//Converte as coordenadas dos miitabuleiros para o global
bool converter_coordenadas(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

//Decide o próximo mini tabuleiro a jogar
void nextquadro(pjogadas pdados,pcoordenadas pcoordenadas);

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMat(int nLin, int nCol);
char** criaMatRegras(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMat(char **p, int nLin, int nCol);

//Display do tabuleiro regras
void setupTabuleiroRegras(char** p);

//Mostra regas do jogo
void regrasDoJogo();

//Meter peça no tabuleiro
void setPos(char **p, int x, int y, char c);

//Começo do ciclo de jogo
void playing_game(char **tabuleiro,pjogadas pdados,pjogadas lista,int robo);

//Decidir que tipo de jogada quer
pjogadas antesdeJogada(char** tabuleiro,pjogadas pdados,pjogadas lista,int robo,pcoordenadas pcoordenadas);

//Diz qual o jogador a jogar
bool checkTurnos(pjogadas pdados);

//Verificar se o jogo acabou
char checkWinner(pcoordenadas pcoordenadas);

//Verificar se minitabuleiro tem vencedor
char check_minitabuleiro(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

//Auxilio para check de empate
int checkFreeSpaces(char** tabuleiro,pcoordenadas pcoordenadas);

//Guarda no o array do vencedor o char na posiçao igual ao do minitabuleiro e com a char dele
void arrayWinner(char**tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

//Verificar se a jogada é possível na posição escolhida
bool possiblePlay(char **tabuleiro,pjogadas pdados,int bytes_size,pcoordenadas pcoordenadas);

//Pede a jogada ao jogador
pjogadas pedeJogada(char **tabuleiro,pjogadas pdados,pjogadas lista,int robo,pcoordenadas pcoordenadas);

//Preencher a lista ligada
void preenche_lista(pjogadas p,pjogadas pdados);

//Construir a lista ordenadamente
pjogadas insere_ord(pjogadas p,pjogadas pdados);

//Mostrar informação da lista de acordo com as jogadas a consultar
void mostra_info(pjogadas p,pjogadas pdados,int postjogadas,int robo);

//Quantidade de jogadas anteriores à atual
int jogadas_anteriores(pjogadas pdados);

//Mostrar lista ligada por completo
void mostra_info_ex(pjogadas p);

//Exportação do ficheiro de texto se for com sucesso
bool ficheiro_texto(pjogadas lista);

//Exportação do ficheiro binário
void pause(pjogadas lista,pjogadas pdados);

//Verificar se existe binário
bool verificarbin();

//Reconstrói a lista do jogo anterior através do ficheiro binário
pjogadas recuperarJogo(pjogadas lista,pjogadas pdados,char **tabuleiro,pcoordenadas pcoordenadas);

//Pergunta se quer continuar o jogo anterior
bool querContinuar();

//Liberta a memória ocupada pela lista
void elimina_lista(pjogadas lista);
#endif