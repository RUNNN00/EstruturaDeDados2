#include <stdio.h>
#include "sort.h"

void imprimir(int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", v[i]);
        if (i < 9)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    int vet[10] = {4, 2, 9, 12, 2, 0, 16, 22, 1, 14};
    imprimir(vet, 10);
    selectionSort(vet, 10);
    imprimir(vet, 10);

    return 0;
}