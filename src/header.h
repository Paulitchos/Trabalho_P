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
    char winnerArray[8];
    pjogadas prox;
};

typedef struct todascoordenadas
{
    int n_mini_converted;
    int x_mini_tabuleiro;
    int y_mini_tabuleiro;

}coordenadas,*pcoordenadas;


//Começa o jogo
void start_Game();

//Converte as coordenadas dos miitabuleiros para o global
bool converter_coordenadas(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

//Decide o próximo mini tabuleiro a jogar
void nextquadro(pjogadas pdados);

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMat(int nLin, int nCol);
char** criaMatRegras(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMat(char **p, int nLin, int nCol);

void setupTabuleiroRegras(char** p);

//Mostra regas do jogo
void regrasDoJogo();

void setPos(char **p, int x, int y, char c);

char getPos(char **p, int x, int y);

void playing_game(char **tabuleiro,pjogadas pdados);

//Diz qual o jogador a jogar
bool checkTurnos(pjogadas pdados);

bool checkWinner();

char check_minitabuleiro(char** tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

int checkFreeSpaces(char** tabuleiro,pcoordenadas pcoordenadas);

void arrayWinner(char**tabuleiro,pjogadas pdados,pcoordenadas pcoordenadas);

bool possiblePlay(char **tabuleiro,pjogadas pdados,int bytes_size,pcoordenadas pcoordenadas);

void pedeJogada(char **tabuleiro,pjogadas pdados);
#endif