#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct tarefa {
    char nome_materia[TAM];
    char descricao_tarefa[TAM];
    char data[11]; // eu estava usando int, optei por usar char para não perder o modelo dd/mm/aaaa
} Tarefa;

void adicionar_tarefa(Tarefa lista[], int *cont_tarefas){
    
    printf("Digite as informacoes da nova tarefa abaixo: \n");
    printf("Nome da materia?: ");
    fgets(lista[*cont_tarefas].nome_materia, TAM, stdin);
    lista[*cont_tarefas].nome_materia[strcspn(lista[*cont_tarefas].nome_materia, "\n")] = '\0';

    printf("Descricao da tarefa: ");
    fgets(lista[*cont_tarefas].descricao_tarefa, TAM, stdin);
    lista[*cont_tarefas].descricao_tarefa[strcspn(lista[*cont_tarefas].descricao_tarefa, "\n")] = '\0';

    printf("Data da tarefa: ");
    fgets(lista[*cont_tarefas].data, 11, stdin);
    lista[*cont_tarefas].data[strcspn(lista[*cont_tarefas].data, "\n")] = '\0';

    (*cont_tarefas)++;

}

void listar_tarefas(Tarefa lista[], int *cont_tarefas) {

  printf("Voce tem essas tarefas na sua lista de tarefas: \n");
    if (*cont_tarefas == 0) {
        printf("Sua lista de tarefas esta vazia!\n");

        return;
    }
        for(int i = 0; i < *cont_tarefas; i++) {
        printf("%s\n", lista[i].nome_materia);
        printf("Materia: %s\n Descricao: %s\n Data: %s\n", lista[i].nome_materia, lista[i].descricao_tarefa, lista[i].data);
    }

    printf("=============================================\n");

}

void sair_do_programa(){
    printf("Encerrando programa...");
}

int main(){
    int opcao;

    Tarefa lista[TAM];
    int cont_tarefas = 0;

    while(1){
        printf("========== AGENDA DE ESTUDOS ==========\n");
        printf("Escolha uma das opcoes que voce deseja para utilizar sua agenda:\n");
        printf("1 - Adicionar uma nova tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        switch (opcao) {
        case 1:
            adicionar_tarefa(lista, &cont_tarefas);
            break;
        case 2:
            listar_tarefas(lista, &cont_tarefas);
            break;
        case 3:
            sair_do_programa();
            exit(1);
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}
