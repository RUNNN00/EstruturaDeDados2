#include <stdio.h>
#include <stdlib.h>

#include "buscas.h"

int main() {
    
    int n = 1000000;
    int *v = malloc(sizeof(int) * n);

    if (v == NULL) {
        printf("estorou!!!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        v[i] = i;
    }

    printf("%d\n", buscaBin(v, 0, n-1, 70));

    return 0;
}