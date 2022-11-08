#include "tree.h"
#include <stdlib.h>

ABB* ABB_Criar() {
    ABB* nova = malloc(sizeof(ABB));
    nova->raiz = NULL;
    return nova;
}

NOH* NOH_Criar(int chave, int valor){
    NOH* novo = malloc(sizeof(NOH));
    novo->chave = chave;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Retorna o endereço no nó que contém a chave na árvore A.
// Caso a chave não esteja na árvore, retorna NULL
NOH* ABB_Buscar(ABB* A, int chave);

static NOH* inserir(NOH* N, int chave, int valor) {
    if (N == NULL) {
        return NOH_Criar(chave, valor);
    }
    if (chave == N->chave) {
        N->valor = valor;
    }
    else {
        if (chave < N->chave) {
            N->esq = inserir(N->esq, chave, valor);
        }
        else {
            N->dir = inserir(N->dir, chave, valor);
        }
    }
    return N;

}


// Insere o par (chave, valor) na árvore A. 
// Caso a chave já esteja na árvore, o valor é atualizado.
void ABB_Inserir(ABB*A , int chave, int valor);

static NOH* ABB_Min_(NOH* N) {
    if (N == NULL) {
        return NULL;
    }
    NOH* p = N;
    while (p->esq != NULL) {
        p = p->esq;
    }
}

static NOH* ABB_Remover_R(NOH* N, int chave) {
    if (N == NULL)
        return NULL;
    if (chave < N->chave)
        N->esq = ABB_Remover_R(N->esq, chave);
    else {
        if (chave > N->chave)
            N->dir = ABB_Remover_R(N->dir, chave);
        else {
            NOH* t = NULL;
            // N->chave é a chave a ser removida
            if (N->esq == NULL) {
                //caso 1, caso 2 (filho a direita)
                t = N->dir;
                free(N);
                return t;
            }
            if (N->dir == NULL) {
                //caso 2 (filho a esquerda)
                t = N->esq;
                free(N);
                return t;
            }
            //caso 3 sub-tree a esquerda e a direita
            t = ABB_Min_(N->dir); // econtrar o sucesssor
            N->valor = t->valor;
            N->chave = t->chave;
            N->dir = ABB_Remover_R(N->dir, t->chave); // remover o sucessor recursivamente
        }
    }
    return N;
}

// remove a chave da árvore A.
// Caso a chave não esteja na árvore, ela não é alterada.
void ABB_Remover(ABB* A, int chave) {
    A->raiz = ABB_Remover_R(A->raiz, chave);
}

void ABB_Destruir(ABB* A);

void ABB_Imprimir_R(NOH *A, int nivel, int lado){
    int i;
    for(int i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) (%d, %d)\n", lado, A->chave, A->valor);
        ABB_Imprimir_R(A->esq, nivel+1, 'e');
        ABB_Imprimir_R(A->dir, nivel+1, 'd');
    }
}

void ABB_Imprimir(ABB *A){
    ABB_Imprimir_R(A->raiz, 0, 'r');
}
