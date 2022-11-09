#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    ABB* a = ABB_Criar();

    ABB_Inserir(a, 40, 30);
    ABB_Inserir(a, 30, 30);
    ABB_Inserir(a, 60, 30);
    ABB_Inserir(a, 15, 30);
    ABB_Inserir(a, 50, 30);
    ABB_Inserir(a, 90, 30);
    ABB_Inserir(a, 70, 30);
    ABB_Inserir(a, 100, 30);
    ABB_Inserir(a, 18, 30);

    //ABB_Imprimir(a);

    ABB_ImprimirOrdemCrescente(a);

    printf("%d\n", ABB_N(a));

    ABB_Destruir(a);

    return 0;
}