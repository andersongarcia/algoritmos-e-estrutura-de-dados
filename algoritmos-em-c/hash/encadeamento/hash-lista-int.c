#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define TAMANHO_TABELA 31

void inicializaTabela(TabelaHash* tabela) {
    tabela->tabela = (No**)malloc(TAMANHO_TABELA * sizeof(No*));
    tabela->tamanho = TAMANHO_TABELA;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->tabela[i] = NULL;
    }
}

unsigned int hash(void* chave) {
    int* int_chave = (int*)chave; 
    return (*int_chave) % TAMANHO_TABELA;
}

void inserir(TabelaHash* tabela, void* valor) {
    int* int_valor = (int*)valor; 
    unsigned int indice = hash(int_valor);
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = int_valor;
    novoNo->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novoNo;
}

No* buscar(TabelaHash* tabela, void* valor) {
    int* int_valor = (int*)valor; 
    unsigned int indice = hash(int_valor);
    No* atual = tabela->tabela[indice];
    while (atual != NULL) {
        if (*(int*)(atual->chave) == *int_valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void imprimirTabela(TabelaHash* tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        No* atual = tabela->tabela[i];
        printf("[%02d] -> ", i);
        while (atual != NULL) {
            printf("%d -> ", *(int*)(atual->chave));
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}