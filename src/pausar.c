#include "header.h"
#include <stdio.h>

void pause(pjogadas lista,pjogadas pdados){
    FILE * fp;
    int i;
    int maxturno = pdados->turnos - 1;
    printf("Escrever estado do jogo para jogo.bin...");
    fp = fopen("jogo.bin","wb");
    if (fp == NULL) {
        fclose(fp);
    }

    if (lista==NULL){
        i=0;
        fwrite(&i,sizeof(int),1,fp); //To indicate that there is no data to read
        printf("Sem dados para gravar, abort\n");
    } else {
        //printf("Entrou");
        //i=1;
        //fwrite(&i,sizeof(int),1,fp); //To indicate that there is data to read
        fwrite(&maxturno,sizeof(int),1,fp);
        
        while (lista !=NULL){
            fwrite(&lista->turnos ,sizeof(int),1,fp);
            fwrite(&lista->mini_tabuleiro ,sizeof(int),1,fp);
            fwrite(&lista->x ,sizeof(int),1,fp);
            fwrite(&lista->y ,sizeof(int),1,fp);
            //printf("%d || %d || %d || %d ", lista-> turnos,lista->mini_tabuleiro,lista->x,pdados->y);
            lista = lista -> prox;
        }
    }
    fclose(fp);
    
}