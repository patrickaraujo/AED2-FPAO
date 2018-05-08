#include <stdio.h>
#include <stdlib.h>

#include "FilaPrioridade.h"


int main(){
    int n = 6;

    struct paciente itens[6];


    strcpy(itens[0].nome, "Andre");    itens[0].prio = 1;
    strcpy(itens[1].nome, "Bianca");    itens[1].prio = 2;
    strcpy(itens[2].nome, "Carlos");    itens[2].prio = 5;
    strcpy(itens[3].nome, "Nilza");    itens[3].prio = 8;
    strcpy(itens[4].nome, "Inacio");    itens[4].prio = 6;
    strcpy(itens[5].nome, "Edu");    itens[5].prio = 4;

    FilaPrio* fp = cria_FilaPrio();

    int i;
    for (i = 0; i < n; i++){
        printf("%d) Prioridade: %d\tNome: %s\n", i, itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome, itens[i].prio);
    }

    printf("\nPacientes\n");

    imprime_FilaPrio(fp);

    printf("\nRemovendo: \n", n);
    for (i = 0; i < n; i++){
        remove_FilaPrio(fp);
        imprime_FilaPrio(fp);
        printf("\nRemovendo: \n");
    }

    libera_FilaPrio(fp);

    return 0;
}
