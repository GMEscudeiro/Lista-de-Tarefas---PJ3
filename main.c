#include <stdio.h>
#include "proj.h"

int main() {
    int cod;
    ListaDeTarefas lt;

    cod = carregarLista(&lt, "arquivo");

    if (cod == 1){
        lt.qtd = 0;
    }

    int opcao;
    do{
        printMenu();
        scanf("%d", &opcao);

        if (opcao == 1){
            criarTarefa(&lt);
        } else if (opcao == 2){
            deletarTarefa(&lt);
        } else if (opcao == 3){
            listarTarefa(lt);
        }
    } while (opcao != 4);

    cod = salvarLista(lt, "arquivo");

    if (cod != 0){
        printf("Erro ao salvar lista\n");
    }
}
