#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define DEBUG 1

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int *vet = vetorAleatorio(n, 99, n * 100);
    //int vet2[] = {3, 5, 6, 0, 4, 7};

    #ifdef DEBUG
    imprimir(vet, n);
    #endif

    // selectionSort(vet, 10);
    //bubbleSort(vet3, n);
    //inserctionSort(vet, n);
    //mergeSort(vet2, 0, 2, 5);
    heapSort(vet, n);
    
    #ifdef DEBUG
    imprimir(vet, n);
    #endif
    
    free(vet);

    return 0;
}