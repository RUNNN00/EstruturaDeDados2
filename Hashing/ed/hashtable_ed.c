#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED* HT, int chave){

    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){

    THED* nova = malloc(sizeof(THED));
    nova->m = m;
    nova->n = 0;
    nova->t = malloc(sizeof(ILIST*) * m);
    for (int i = 0; i < m; i++) {
        nova->t[i] = ILIST_Criar(alloc_step);
    }
    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor){

    int h = THED_Hash(HT, chave);
    int tam_antigo = ILIST_Tamanho(HT->t[h]);
    ILIST_Inserir(HT->t[h], chave, valor);
    if (ILIST_Tamanho(HT->t[h]) > tam_antigo)
        HT->n++;
}

void THED_Remover(THED* HT, int chave){

    int h = THED_Hash(HT, chave);
    int tam_antigo = ILIST_Tamanho(HT->t[h]);
    ILIST_Remover(HT->t[h], chave);
    if (ILIST_Tamanho(HT->t[h]) < tam_antigo)
        HT->n--;
}

INOH* THED_Buscar(THED* HT, int chave){

    int h = THED_Hash(HT, chave);
    int pos = ILIST_Buscar(HT->t[h], chave);
    if (pos < 0)
        return NULL;
    return ILIST_Endereco(HT->t[h], pos);
}

void THED_Imprimir(THED* HT){

    printf("===TABELA HASH (M=%ld, N=%ld, alpha=%.2f)===\n",
    HT->m, HT->n, ((float)HT->n)/HT->m);

    for (int i = 0; i < HT->m; i++) {
        printf("LISTA %04d: ", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
}

size_t THED_N(THED* HT){

    return HT->n;
}

ILIST* THED_Chaves(THED* HT){

}

void THED_Destruir(THED* HT){

    for (int i = 0; i < HT->m; i++) {
        ILIST_Destruir(HT->t[i]);
    }
    free(HT->t);
    free(HT);
}
