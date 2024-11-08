#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char* str_chave = (char*)chave; 
    unsigned int hash = 0;
    for (const char* p = str_chave; *p != '\0'; p++) {
        hash += (unsigned char)*p; // Soma os valores ASCII dos caracteres
    }
    return hash % TAMANHO_TABELA; 
}

void inserir(TabelaHash* tabela, void* valor) {
    char* str_valor = (char*)valor; 
    unsigned int indice = hash(str_valor);
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = str_valor;
    novoNo->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novoNo;
}

No* buscar(TabelaHash* tabela, void* valor) {
    char* str_valor = (char*)valor; 
    unsigned int indice = hash(str_valor);
    No* atual = tabela->tabela[indice];
    while (atual != NULL) {
        if (strcmp((char*)atual->chave, str_valor) == 0) { 
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
            printf("%s -> ", (char*)atual->chave); 
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}