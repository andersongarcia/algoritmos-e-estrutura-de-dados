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

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while (t[id] != 0){
        id = funcaoHash(id + 1);
    }
    if(id < TAM){
        t[id] = valor;
    }
}

int busca(int i)

int main(){
    int tabela[TAM];

    return 0;
}