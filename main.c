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
        } else if (opcao == 4){
            alterarTarefa(&lt);
        } else if (opcao == 5){
            exportar(lt);
        }
        
    } while (opcao != 0);

    cod = salvarLista(lt, "arquivo");

    if (cod != 0){
        printf("Erro ao salvar lista\n");
    }
}
