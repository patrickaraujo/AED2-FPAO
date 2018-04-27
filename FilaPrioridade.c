#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridade.h" //  inclui os Protótipos

FilaPrio* cria_FilaPrio(){
    FilaPrio *retorno;
    retorno = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(retorno)
        retorno->qtd = 0;
    return retorno;
}

void libera_FilaPrio(FilaPrio* main){
    free(main);
}

int consulta_FilaPrio(FilaPrio* main, char* nome){
    if(!main || main->qtd == 0)
        return NULL;
    strcpy(nome, main->dados[main->qtd-1].nome);
    return 1;
}

int insere_FilaPrio(FilaPrio* main, char *nome, int prioridade){
    if(!main)
        return NULL;
    if(main->qtd == MAX)  //  fila cheia
        return NULL;

    int i = main->qtd-1;
    while(i >= 0 && main->dados[i].prio >= prioridade){
        main->dados[i+1] = main->dados[i];
        i--;
    }

    strcpy(main->dados[i+1].nome,nome);
    main->dados[i+1].prio = prioridade;
    main->qtd++;
    return 1;
}

int remove_FilaPrio(FilaPrio* main){
    if(!main)
        return NULL;
    if(!main->qtd)
        return 0;
    main->qtd--;
    return 1;
}

int tamanho_FilaPrio(FilaPrio* main){
    if(!main)
        return -1;
    else
        return main->qtd;
}

int estaCheia_FilaPrio(FilaPrio* main){
    if(!main)
        return -1;
    return (main->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio* main){
    if(!main)
        return -1;
    return (main->qtd == 0);
}

void imprime_FilaPrio(FilaPrio* main){
    if(main){
        int i;
        for(i = main->qtd - 1; i >= 0 ; i--)
            printf("Prio: %d \tNome: %s\n", main->dados[i].prio, main->dados[i].nome);
    }
}
