#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define VET_1_SIZE 1
#define VET_2_SIZE 0
#define VET_3_SIZE 10

void imprimir(int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", v[i]);
        if (i < size)
            printf(", ");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);

    int vet1[VET_1_SIZE] = {4};
    int vet2[VET_2_SIZE] = {};
    int *vet3 = vetorAleatorio(n, 99, n * 100);
    imprimir(vet1, VET_1_SIZE);

    // selectionSort(vet, 10);
    bubbleSort(vet1, VET_1_SIZE);
    imprimir(vet1, VET_1_SIZE);
    printf("\n");

    imprimir(vet2, VET_2_SIZE);
    // selectionSort(vet, 10);
    bubbleSort(vet2, VET_2_SIZE);
    imprimir(vet2, VET_2_SIZE);
    printf("\n");

    imprimir(vet3, n);
    // selectionSort(vet, 10);
    bubbleSort(vet3, n);
    imprimir(vet3, n);
    free(vet3);

    return 0;
}