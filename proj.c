#include <stdio.h>
#include "proj.h"

//Essa funcao cria tarefa e salva na struct lista de tarefas
int criarTarefa(ListaDeTarefas *lt){
    printf("Tarefa:");
    scanf("%s", &lt->tarefas[lt->qtd].categoria);
    printf("Descricao da Tarefa:");
    scanf(" %s", &lt->tarefas[lt->qtd].descricao);
    printf("Prioridade da Tarefa:");
    scanf(" %d", &lt->tarefas[lt->qtd].prioridade);
    printf("Estado da Tarefa:\n");
    printf("1 - nao iniciado\n");
    printf("2 - em desenvolvimento\n");
    printf("3 - completo\n");
    scanf(" %d", &lt->tarefas[lt->qtd].estado);
    printf("\n");
    lt->qtd += 1;
    return 0;
};

//Essa funcao exclui as tarefas que foram criadas anteriormente
int deletarTarefa(ListaDeTarefas *lt){
    int opcao;
    printf("Qual tarefa deseja deletar?");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > lt->qtd) {
        printf("Numero invalido.\n");
        return 1;
    }
    //Esse laço sobrescreve a tarefa que deseja excluir pela proxima tarefa na lista
    for (int i = opcao - 1; i < lt->qtd - 1; i++) {
        lt->tarefas[i] = lt->tarefas[i + 1];
    }

    lt->qtd--;
    printf("Tarefa %d excluida com sucesso!\n", opcao);
    return 0;
};

int filtrar(ListaDeTarefas lt, int opcao){
    int debug = 0;
    int filtro;
    char categoria[100];
    if(opcao == 0){
        for (int i = 0; i < lt.qtd; i++){
            printf("Tarefa %d: \n", i + 1);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n" , lt.tarefas[i].prioridade);
            if(lt.tarefas[i].estado == 1){
                printf("Estado: Nao iniciado");
            }else if(lt.tarefas[i].estado == 2){
                printf("Estado: Em desenvolvimento");
            }else{
                printf("Estado: Completo");
            }
            printf("\n");
        }
        debug = 1;
    }else if(opcao == 1){
        printf("Qual prioridade deseja filtrar?\n");
        scanf("%d", &filtro);
        for (int i = 0; i < lt.qtd; i++) {
            if (lt.tarefas[i].prioridade == filtro) {
                printf("Tarefa %d: \n", i + 1);
                printf("Categoria: %s\n", lt.tarefas[i].categoria);
                printf("Descricao: %s\n", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                if (lt.tarefas[i].estado == 1) {
                    printf("Estado: Nao iniciado\n");
                } else if (lt.tarefas[i].estado == 2) {
                    printf("Estado: Em desenvolvimento\n");
                } else {
                    printf("Estado: Completo\n");
                }
                printf("\n");
                debug = 1;
            }
        }
    }else if(opcao == 2){
        printf("Qual estado deseja filtrar?\n");
        scanf("%d", &filtro);
        for (int i = 0; i < lt.qtd; i++) {
            if (lt.tarefas[i].estado == filtro) {
                printf("Tarefa %d: \n", i + 1);
                printf("Categoria: %s\n", lt.tarefas[i].categoria);
                printf("Descricao: %s\n", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                if (lt.tarefas[i].estado == 1) {
                    printf("Estado: Nao iniciado\n");
                } else if (lt.tarefas[i].estado == 2) {
                    printf("Estado: Em desenvolvimento\n");
                } else {
                    printf("Estado: Completo\n");
                }
                printf("\n");
                debug = 1;
            }
        }
    }else if(opcao == 3){
        printf("Qual categoria deseja filtrar?\n");
        scanf("%s", &categoria);
        int p = 0;
        while(p < 6){
            for (int i = 0; i < lt.qtd; i++) {
                if (strcmp(lt.tarefas[i].categoria, categoria) == 0){
                    debug = 1;
                    if(lt.tarefas[i].prioridade == p+1){
                        printf("Tarefa %d: \n", i + 1);
                        printf("Categoria: %s\n", lt.tarefas[i].categoria);
                        printf("Descricao: %s\n", lt.tarefas[i].descricao);
                        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                        if (lt.tarefas[i].estado == 1) {
                            printf("Estado: Nao iniciado\n");
                        } else if (lt.tarefas[i].estado == 2) {
                            printf("Estado: Em desenvolvimento\n");
                        } else {
                            printf("Estado: Completo\n");
                        }
                        printf("\n");
                        debug = 1;
                    }
                }
            }
            p += 1;
        }
    }else if(opcao == 4){
        printf("Qual categoria deseja filtrar?\n");
        scanf("%s", &categoria);
        printf("Qual prioridade deseja filtrar?\n");
        scanf("%d", &filtro);
        for (int i = 0; i < lt.qtd; i++) {
            if (lt.tarefas[i].prioridade == filtro && (strcmp(lt.tarefas[i].categoria, categoria) == 0)) {
                printf("Tarefa %d: \n", i + 1);
                printf("Categoria: %s\n", lt.tarefas[i].categoria);
                printf("Descricao: %s\n", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                if (lt.tarefas[i].estado == 1) {
                    printf("Estado: Nao iniciado\n");
                } else if (lt.tarefas[i].estado == 2) {
                    printf("Estado: Em desenvolvimento\n");
                } else {
                    printf("Estado: Completo\n");
                }
                printf("\n");
                debug = 1;
            }
        }
    }

    if (!debug) {
        printf("Nenhuma tarefa encontrada com o filtro escolhido.");
    }

    return 0;
};

//Essa funcao lista as tarefas presentes na struct ListaDeTarefas
int listarTarefa(ListaDeTarefas lt){
    int opcao;
    printf("Como deseja filtrar a listagem?\n");
    printf("0 - Sem filtro\n");
    printf("1 - Filtrar por prioridade\n");
    printf("2 - Filtrar por estado\n");
    printf("3 - Filtrar por categoria\n");
    printf("4 - Filtrar por prioridade e categoria\n");
    scanf("%d", &opcao);
    filtrar(lt, opcao);
    return 0;
};

int alterarTarefa(ListaDeTarefas *lt){
    int tarefa;
    int campo;
    printf("Qual tarefa deseja alterar?");
    scanf("%d", &tarefa);

    if (tarefa < 1 || tarefa > lt->qtd) {
        printf("Numero invalido.\n");
        return 1;
    }

    printf("Qual campo deseja alterar?\n");
    printf("1 - Categoria\n");
    printf("2 - Descricao\n");
    printf("3 - Prioridade\n");
    printf("4 - Estado\n");
    scanf("%d", &campo);

    if(campo == 1){
        printf("Insira a nova categoria:");
        scanf("%s", &lt->tarefas[tarefa-1].categoria);
    }
    if(campo == 2){
        printf("Insira a nova descricao:");
        scanf("%s", &lt->tarefas[tarefa-1].descricao);
    }
    if(campo == 3){
        printf("Insira a nova prioridade:");
        scanf("%d", &lt->tarefas[tarefa-1].prioridade);
    }
    if(campo == 4){
        printf("Insira o novo estado:\n");
        printf("1 - nao iniciado\n");
        printf("2 - em desenvolvimento\n");
        printf("3 - completo\n");
        scanf("%d", &lt->tarefas[tarefa-1].estado);
    }

}

//A funcao apenas printa as opcoes disponiveis
void printMenu(){
    printf("1 - Criar Tarefa\n");
    printf("2 - Deletar Tarefa\n");
    printf("3 - Listar Tarefas\n");
    printf("4 - Alterar Tarefas\n");
    printf("5 - Exportar Tarefas\n");
    printf("0 - Sair\n");
    printf("Digite a opcao que voce quer executar:");
};

//Essa funcao salva as tarefas da struct em um arquivo binario
int salvarLista(ListaDeTarefas lt, char nome[]){
    FILE *arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fwrite(&lt, sizeof(ListaDeTarefas), 1, arquivo);
    fclose(arquivo);
    return 0;

}

//A funcao carrega os itens do arquivo e passa para a struct do programa
int carregarLista(ListaDeTarefas *lt, char nome[]){
  FILE *arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fread(lt, sizeof(ListaDeTarefas), 1, arquivo);
    fclose(arquivo);
    return 0;
};

int exportar(ListaDeTarefas lt){
    FILE *f = fopen("tarefas.txt", "w");
    int opcao;
    printf("Com qual filtro deseja exportar as tarefas?\n");
    printf("1 - Filtrar por prioridade\n");
    printf("2 - Filtrar por categoria\n");
    printf("3 - Filtrar por prioridade e categoria\n");
    scanf("%d", &opcao);
    int debug = 0;
    int filtro;
    char categoria[100];
    if(opcao == 1){
        printf("Qual prioridade deseja filtrar?\n");
        scanf("%d", &filtro);
        for (int i = 0; i < lt.qtd; i++) {
            if (lt.tarefas[i].prioridade == filtro) {
                fprintf(f,"Tarefa %d: \n", i + 1);
                fprintf(f,"Categoria: %s\n", lt.tarefas[i].categoria);
                fprintf(f,"Descricao: %s\n", lt.tarefas[i].descricao);
                fprintf(f,"Prioridade: %d\n", lt.tarefas[i].prioridade);
                if (lt.tarefas[i].estado == 1) {
                    fprintf(f,"Estado: Nao iniciado\n");
                } else if (lt.tarefas[i].estado == 2) {
                    fprintf(f,"Estado: Em desenvolvimento\n");
                } else {
                    fprintf(f,"Estado: Completo\n");
                }
                fprintf(f,"\n");
                debug = 1;
            }
        }
    }else if(opcao == 2){
        printf("Qual categoria deseja filtrar?\n");
        scanf("%s", &categoria);
        int p = 0;
        while(p < 6){
            for (int i = 0; i < lt.qtd; i++) {
                if (strcmp(lt.tarefas[i].categoria, categoria) == 0){
                    debug = 1;
                    if(lt.tarefas[i].prioridade == p+1){
                        fprintf(f,"Tarefa %d: \n", i + 1);
                        fprintf(f,"Categoria: %s\n", lt.tarefas[i].categoria);
                        fprintf(f,"Descricao: %s\n", lt.tarefas[i].descricao);
                        fprintf(f,"Prioridade: %d\n", lt.tarefas[i].prioridade);
                        if (lt.tarefas[i].estado == 1) {
                            fprintf(f,"Estado: Nao iniciado\n");
                        } else if (lt.tarefas[i].estado == 2) {
                            fprintf(f,"Estado: Em desenvolvimento\n");
                        } else {
                            fprintf(f,"Estado: Completo\n");
                        }
                        fprintf(f,"\n");
                        debug = 1;
                    }
                }
            }
            p += 1;
        }
    }else if(opcao == 3){
        printf("Qual categoria deseja filtrar?\n");
        scanf("%s", &categoria);
        printf("Qual prioridade deseja filtrar?\n");
        scanf("%d", &filtro);
        for (int i = 0; i < lt.qtd; i++) {
            if (lt.tarefas[i].prioridade == filtro && (strcmp(lt.tarefas[i].categoria, categoria) == 0)) {
                fprintf(f,"Tarefa %d: \n", i + 1);
                fprintf(f,"Categoria: %s\n", lt.tarefas[i].categoria);
                fprintf(f,"Descricao: %s\n", lt.tarefas[i].descricao);
                fprintf(f,"Prioridade: %d\n", lt.tarefas[i].prioridade);
                if (lt.tarefas[i].estado == 1) {
                    fprintf(f,"Estado: Nao iniciado\n");
                } else if (lt.tarefas[i].estado == 2) {
                    fprintf(f,"Estado: Em desenvolvimento\n");
                } else {
                    fprintf(f,"Estado: Completo\n");
                }
                fprintf(f,"\n");
                debug = 1;
            }
        }
    }

    if (!debug) {
        printf("Nenhuma tarefa encontrada com o filtro escolhido.");
    }
};