#include <stdio.h>
#include "hash.h"

int main() {
    TabelaHash tabela;
    inicializaTabela(&tabela);

    char* valores[] = {"apple", "banana", "orange", "grape", "peach"};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++) {
        inserir(&tabela, valores[i]);
    }

    imprimirTabela(&tabela);
    return 0;
}