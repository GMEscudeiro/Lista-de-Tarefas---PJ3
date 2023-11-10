#ifndef PROJETO_PROJ_H
#define PROJETO_PROJ_H

typedef struct{
    int prioridade;
    char categoria[100];
    char descricao[300];
    int estado;
}Tarefas;

typedef struct {
    Tarefas tarefas[100];
    int qtd;
}ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);
int alterarTarefa(ListaDeTarefas *lt);
int filtrar(ListaDeTarefas lt, int opcao);

void printMenu();

int salvarLista(ListaDeTarefas lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);
int exportar(ListaDeTarefas lt);

#endif //PROJETO_PROJ_H
