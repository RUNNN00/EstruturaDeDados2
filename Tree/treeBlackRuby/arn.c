#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "arn.h"

static NOH* NOH_Criar(int chave, int valor){

    NOH* novo = malloc(sizeof(NOH));
    novo->chave = chave;
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->cor = C_VERMELHO;
    return novo;
}

static inline bool NOH_Eh_Vermelho(NOH* N){

    if(N == NULL)
        return false;
    
    return N->cor == C_VERMELHO;
}

static void ARN_InverterCores(NOH *N){

    N->cor = C_VERMELHO;
    N->esq->cor = C_PRETO;
    N->dir->cor = C_PRETO;
}

static NOH* ARN_Rot_Esq(NOH* N){

    NOH* x = N->dir;
    N->dir = x->esq;
    x->esq = N;
    x->cor = N->cor;
    N->cor = C_VERMELHO;
    return x;
}

static NOH* ARN_Rot_Dir(NOH* N){
 
    NOH* x = N->esq;
    N->esq = x->dir;
    x->dir = N;
    x->cor = N->cor;
    N->cor = C_VERMELHO;
    return x;
}

ARN* ARN_Criar(){

    ARN* nova = malloc(sizeof(ARN));
    nova->raiz = NULL;
    return nova;
}

// Retorna o endereço no nó que contém a chave na árvore A.
// Caso a chave não esteja na árvore, retorna NULL
NOH* ARN_Buscar(ARN* A, int chave);


static NOH* ARN_Inserir_R(NOH* N, int chave, int valor){

    if (N == NULL)
        return NOH_Criar(chave, valor);

    if (chave < N->chave)
        N->esq = ARN_Inserir_R(N->esq, chave, valor);
    else if (chave > N->chave)
        N->dir = ARN_Inserir_R(N->dir, chave, valor);
    else
        N->valor = valor;

    if (NOH_Eh_Vermelho(N->dir) && !NOH_Eh_Vermelho(N->esq))
        N = ARN_Rot_Esq(N);
    
    if (NOH_Eh_Vermelho(N->esq) && NOH_Eh_Vermelho(N->esq->esq))
        N = ARN_Rot_Dir(N);

    if (NOH_Eh_Vermelho(N->esq) && NOH_Eh_Vermelho(N->dir))
        ARN_InverterCores(N);

    return N;

}

// Insere o par (chave, valor) na árvore A. 
// Caso a chave já esteja na árvore, o valor é atualizado.
void ARN_Inserir(ARN*A , int chave, int valor){

    A->raiz = ARN_Inserir_R(A->raiz, chave, valor);
    A->raiz->cor = C_PRETO;
}

static void ARN_Imprimir_R(NOH *A, int nivel, char lado){
    int i;
    for(i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) (%d, %d) [%c]\n", lado, A->chave, A->valor, A->cor == C_PRETO ? 'P' : 'V');
        ARN_Imprimir_R(A->esq, nivel+1, 'e');
        ARN_Imprimir_R(A->dir, nivel+1, 'd');
    }
}


// Imprime a árvore 
void ARN_Imprimir(ARN* A){
    ARN_Imprimir_R(A->raiz, 0, 'r');
}

static void ARN_Destruir_R(NOH* N){
    if(N!=NULL){
        ARN_Destruir_R(N->esq);
        ARN_Destruir_R(N->dir);
        free(N);
    }
}

// Desaloca toda memória alocada para a árvore
void ARN_Destruir(ARN* A){
    ARN_Destruir_R(A->raiz);
    free(A);
}

static inline int max(int a, int b){
    return a > b ? a : b;
}

static int ARN_Altura_R(NOH* N){
    if(N != NULL){
        return 1 + max(ARN_Altura_R(N->esq), ARN_Altura_R(N->dir));
    }
    return 0;
}

// Retorna a altura da árvore rubro-negra
int ARN_Altura(ARN* A){
    if(A != NULL){
        return ARN_Altura_R(A->raiz);
    }
    return 0;
}