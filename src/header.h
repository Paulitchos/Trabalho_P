#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct dados_jogada{
    int turnos;
    int mini_tabuleiro;
    char *input_jogadas;
    int x;
    int y;
    
}jogadas,*pjogadas;

//Começa o jogo
void start_Game();

bool converter_coordenadas(char** tabuleiro,pjogadas pdados);

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMat(int nLin, int nCol);
char** criaMatRegras(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMat(char **p, int nLin, int nCol);
void setupTabuleiroRegras(char** p);

//Mostra regas do hogo
void regrasDoJogo();

void setPos(char **p, int x, int y, char c);

char getPos(char **p, int x, int y);

void playing_game(char **tabuleiro,pjogadas pdados);

bool checkTurnos(pjogadas pdados);

bool checkWinner();

bool possiblePlay(char **tabuleiro,pjogadas pdados,int bytes_size);

void pedeJogada(char **tabuleiro,pjogadas pdados);
#endif