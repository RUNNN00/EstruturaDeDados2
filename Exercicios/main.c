// Exercico beecrowd 2567 - virus
#include <stdio.h>
#include "../sort/sort.h"

int virusSolution(int* v, int n) {

    inserctionSort(v, n);
    int i = 0;
    int j = n-1;
    int result = 0;
    for (i = 0; i < n / 2; i++) {
        int aux = v[j] - v[i];
        result += aux;
        j--;
    }

    return result;
}

int main() {

    int vet[7] = {8, 1, 5, 7, 12, 6, 2};
    int vet2[6] = {7, 12, 1, 11, 3, 4};

    int result = virusSolution(vet, 7);
    int result2 = virusSolution(vet2, 6);

    printf("vetor 2:\n");
    imprimir(vet2, 6);
    printf("result2: %d\n", result2);

    return 0;
}