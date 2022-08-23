#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void hanoi(int n, char origin, char destino, char temp) {
    if (n == 1)
        printf("move disco1 de %c -> %c\n", origin, destino);
    else {
        hanoi(n-1, origin, temp, destino);
        printf("move disco%d de %c -> %c\n", n, origin, destino);
        hanoi(n-1, temp, destino, origin);
    }
}

int main() {

    hanoi(3, 'A', 'C', 'B');

    return 0;
}