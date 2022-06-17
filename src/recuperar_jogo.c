#include "header.h"

bool verificarbin(){
    FILE * fp = fopen("jogo.bin","rb");
    if (fp == NULL){ 
        printf("\nNão existe jogo.bin\n");
        return false;
    }
    fclose(fp);
    return true;
}

pjogadas recuperarJogo(pjogadas lista,pjogadas pdados,char **tabuleiro,pcoordenadas pcoordenadas){
    FILE * fp = fopen("jogo.bin","rb");
    int maxTurnos;
    int read;
  

    if (fp == NULL){ 
        printf("Nao conseguiu recuperar jogo.bin\n");
        return NULL;
    }
    fread(&read, sizeof(int), 1, fp);
    if (read == 0){
        printf("\nNao tem dados para recuperar, recomecar jogo");
        return lista;
    }
    fread(&maxTurnos,sizeof(int),1,fp);
    //printf("%d",maxTurnos);
    while(maxTurnos != 0){
        fread(&pdados-> turnos, sizeof(int), 1, fp);
        fread(&pdados -> mini_tabuleiro,sizeof(int),1,fp);
        fread(&pdados -> x,sizeof(int),1,fp);
        fread(&pdados -> y,sizeof(int),1,fp);
        //printf("%d || %d || %d || %d ", pdados-> turnos,pdados->mini_tabuleiro,pdados->x,pdados->y);
        converter_coordenadas(tabuleiro,pdados,pcoordenadas);
        arrayWinner(tabuleiro,pdados,pcoordenadas);
        lista = insere_ord(lista,pdados);
        maxTurnos--;
    }
    //mostra_info_ex(lista);
    pdados->turnos++;
    fclose(fp);
    return lista;
}

bool querContinuar(){
    size_t size = 2;
    char *string;
    bool first_interation = true;

    printf("Quer continuar o jogo anterior(Y | N):");
    string = (char*)malloc(size);

    while(strcmp(string,"Y\n") != 0 && strcmp(string,"N\n") !=0){
        if (first_interation == false){
            printf("Tem que inserir pelo menos um char:");
        }   
    getline(&string, &size, stdin);
    first_interation = false;
    }

    if(strcmp(string,"N\n") == 0){
            free(string);
            return false;
    }
    else if(strcmp(string,"Y\n") == 0){
            free(string);
            return true;
    }
    return false;
}
