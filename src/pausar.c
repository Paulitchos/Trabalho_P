#include "header.h"

void pause(pjogadas lista){
    FILE * fp;
    int i;
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
        i=1;
        fwrite(&i,sizeof(int),1,fp); //To indicate that there is data to read
        //show(list);
        while (lista !=NULL){
            fwrite(lista ,sizeof(jogadas),1,fp);
            lista = lista -> prox;
        }
    }
    fclose(fp);
    
}