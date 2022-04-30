#include "header.h"

pjogadas insere_ord(pjogadas p,pjogadas pdados){
    pjogadas novo, aux;
    
    // 1. Alocar espaço   
    novo = malloc(sizeof(jogadas));
  
    // 2. Preencher dados do livro  
    preenche_lista(novo,pdados);
    
    // 3. Inserir ordenadamente na lista  
    
    if(p == NULL){  // Inserção à cabeça
       novo->prox = p;
       p = novo;
    }
    else{
        printf("\n|test|\n");
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    
    return p;   
}

void preenche_lista(pjogadas p,pjogadas pdados){
    p->turnos = pdados->turnos;  
    p->mini_tabuleiro = pdados->mini_tabuleiro;
    p->x = pdados->x;
    p->y = pdados->y;
    for (int i = 0; i < 9; i++){
        p->winnerArray[i] = pdados->winnerArray[i];
    }
    p->prox = NULL;
}
void mostra_info_ex(pjogadas p){
    
    printf("\n");
    while(p != NULL){
        printf("\nO jogador 2 efetuou a jogada(x e y): %d %d no mini-tabuleiro: %d",p->x,p->y, p->mini_tabuleiro);
        p = p->prox;
    }
}
void mostra_info(pjogadas p,pjogadas pdados,int postjogadas){
    printf("hello");
    int turno = pdados->turnos;
    while(p != NULL){
        for (int i = 1; i <  turno - postjogadas; i++){
            p = p->prox;
        }
        if(p->turnos % 2 == 0)      
            printf("\nO jogador 2 efetuou a jogada(x e y): %d %d no mini-tabuleiro: %d",p->x,p->y, p->mini_tabuleiro);
        else
            printf("\nO jogador 1 efetuou a jogada(x e y): %d %d no mini-tabuleiro: %d",p->x,p->y, p->mini_tabuleiro);
        p = p->prox;
    }
}