#include <stdio.h>
#include <stdlib.h>

/* Tabela Hash linear com vetor */

#define TAM 31

void inicializarTabela(int t[]){
    int i;
    for(i=0; i<TAM; i++){
        t[i] = 0;
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int valor){
    int id = funcaoHash(valor);
    tabela[id] = valor;
}

int main(){
    int tabela[TAM];

    return 0;
}