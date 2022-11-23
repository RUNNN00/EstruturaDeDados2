#include <stdio.h>

typedef struct
{
    char nome[50];
    int o;
    int p;
    int b;
} Pais;


int main() {

    int n;
    Pais p[500];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].nome, &(p[i].o), &(p[i].p), &(p[i].b));
    }

    for (int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", p[i].nome, p[i].o, p[i].p, p[i].b);
    }


    return 0;
}