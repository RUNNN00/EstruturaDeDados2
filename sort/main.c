#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define DEBUG 1

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
    //int *vet = vetorAleatorio(n, 99, n * 100);
    int vet2[] = {3, 5, 6, 0, 4, 7};

    #ifdef DEBUG
    imprimir(vet2, n);
    #endif

    // selectionSort(vet, 10);
    //bubbleSort(vet3, n);
    //inserctionSort(vet, n);
    mergeSort(vet2, 0, 2, 5);
    
    #ifdef DEBUG
    imprimir(vet2, n);
    #endif
    
    //free(vet);

    return 0;
}