#include <stdio.h>
#include "hash.h"

int main() {
    TabelaHash tabela;
    inicializaTabela(&tabela);

    int valores[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++) {
        inserir(&tabela, &valores[i]);
    }

    imprimirTabela(&tabela);
    return 0;
}
