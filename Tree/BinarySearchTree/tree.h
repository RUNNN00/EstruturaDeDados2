#pragma once

typedef struct NOH{
    int chave;
    int valor;
    struct NOH *esq, *dir;
}NOH;

typedef struct ABB{
    NOH* raiz;
}ABB;

ABB* ABB_Criar();

// Retorna o endereço no nó que contém a chave na árvore A.
// Caso a chave não esteja na árvore, retorna NULL
NOH* ABB_Buscar(ABB* A, int chave);


// Insere o par (chave, valor) na árvore A. 
// Caso a chave já esteja na árvore, o valor é atualizado.
void ABB_Inserir(ABB*A , int chave, int valor);

// remove a chave da árvore A.
// Caso a chave não esteja na árvore, ela não é alterada.
void ABB_Remover(ABB* A, int chave);

void ABB_Destruir(ABB* A);

void ABB_Imprimir(ABB *A);

void ABB_ImprimirOrdemCrescente(ABB* A);

int ABB_N(ABB* A);