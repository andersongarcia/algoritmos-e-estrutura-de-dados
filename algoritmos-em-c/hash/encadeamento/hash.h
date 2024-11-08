#ifndef HASH_H
#define HASH_H

typedef struct No {
    void* chave;  // Pode ser int* ou char* dependendo da implementação
    struct No* proximo; // Para listas encadeadas
} No;

typedef struct TabelaHash {
    No** tabela;  // Vetor de ponteiros para nós
    int tamanho;
} TabelaHash;

void inicializaTabela(TabelaHash* tabela);
unsigned int hash(void* chave);
void inserir(TabelaHash* tabela, void* valor);
No* buscar(TabelaHash* tabela, void* valor);
void imprimirTabela(TabelaHash* tabela);

#endif // HASH_H