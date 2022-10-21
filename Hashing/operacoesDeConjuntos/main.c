#include <stdio.h>
#include <stdlib.h>

#include "hashtable_ea.h"

int* intersecao(int* a, int nA, int* b, int nB, size_t* nSaida){
    THEA* H = THEA_Criar(nB);
    for (int i = 0; i < nB; i++) {
        THEA_Inserir(H, b[i], 0);
    }

    THEA* saida = THEA_Criar(1);

    for (int i = 0; i < nA; i++) {
        if (THEA_Buscar(H, a[i]) >= 0) {
            THEA_Inserir(saida, a[i], 0);
        }
    }

    int* s = THEA_Chaves(saida);
    *nSaida = THEA_N(saida);
    THEA_Destruir(H);
    THEA_Destruir(saida);
    return s;
}

int* uniao(int* a, int nA, int* b, int nB, size_t* nSaida){

    THEA* H = THEA_Criar(nA);
    for (int i = 0; i < nA; i++) {
        THEA_Inserir(H, a[i], 0);
    }
    for (int j = 0; j < nB; j++) {
        THEA_Inserir(H, b[j], 0);
    }
    int* saida = THEA_Chaves(H);
    *nSaida = THEA_N(H);
    THEA_Destruir(H);
    return saida;
}

int* diferenca(int* a, int nA, int* b, int nB, size_t* nSaida){

    
}

int* diferenca_simetrica(int* a, int nA, int* b, int nB, size_t* nSaida){

}

void imprimir_vetor(int *v, int n){
    printf("n = %d\n", n);
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int* vetor_aleatorio(int n, int max, int seed){
    int* saida = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        saida[i] = rand() % max;
    }
    return saida;
}

int main(int argc, char** argv){

    //Teste 1

    int a[] = {1, 4, 2, 3, 1, 1, 5};
    int b[] = {1, 7, 0, 2};
    size_t n = 0;
    // int *i = intersecao(a, 7, b, 4, &n);
    // imprimir_vetor(i, n);

    size_t nu = 0;
    int *u = uniao(a, 7, b, 4, &nu);
    imprimir_vetor(u, nu);

    // size_t nd = 0;
    // int *d = diferenca(a, 7, b, 4, &nd);
    // imprimir_vetor(u, nd);

    // size_t nds = 0;
    // int *ds = diferenca_simetrica(a, 7, b, 4, &nd);
    // imprimir_vetor(ds, nds);    

    //Teste 2

    // int* x = vetor_aleatorio(1000, 10000, 0);
    // int* y = vetor_aleatorio(1000, 10000, 0);
    // size_t nz = 0;
    // int *z = intersecao(x, 1000, y, 1000, &nz);
    // imprimir_vetor(z, nz);


    return 0;
}
