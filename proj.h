//
// Created by uniflduarte on 15/09/2023.
//

#ifndef PROJETO_PROJ_H
#define PROJETO_PROJ_H

typedef struct{
    int prioridade;
    char tarefa[300];
    char descricao[100];
}Tarefas;

typedef struct {
    Tarefas tarefas[100];
    int qtd;
}ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);

void printMenu();

int salvarLista(ListaDeTarefas lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);

#endif //PROJETO_PROJ_H
