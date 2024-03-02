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

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            return t[id];
        }else{
            id = funcaoHash(id + 1);
        }
    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for(i=0; i<TAM; i++){
        printf("$d = $d\n", i, t[i]);
    }
}

int main(){
    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                break;
            case 1:
                printf("Qual valor deseja inserir? ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("Qual valor deseja buscar: ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if(retorno != 0){
                    printf("Valor encontrado: %d\n", retorno);
                }else{
                    printf("Valor nao encontrado\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(opcao != 0);

    return 0;
}