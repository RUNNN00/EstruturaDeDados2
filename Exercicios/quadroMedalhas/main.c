#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int o;
    int p;
    int b;
} Pais;

void definirPais(Pais* A, Pais* B) {

    strcpy(A->nome, B->nome);
    A->o = B->o;
    A->p = B->p;
    A->b = B->b;
}

void trocar(Pais *v, int a, int b)
{
    Pais aux;
    definirPais(&aux, &(v[a]));
    definirPais(&(v[a]), &(v[b]));
    definirPais(&(v[b]), &aux);
}

int maxHeapify(Pais* v, int i, int th) {
    int e = 2 * i + 1;
    int d = e + 1;
    int maior = i;

    if ((e < th) && (v[e].o < v[i].o))
        maior = e;
    
    if ((d < th) && (v[d].o < v[maior].o))
        maior = d;
    
    if (maior != i) {
        trocar(v, maior, i);
        maxHeapify(v, maior, th);
    }
}

void buildMaxHeap(int* v, int n) {
    for (int i = (n-2)/2; i >= 0; i--) {
        maxHeapify(v, i, n);
    }
}

void heapSort(int *v, int n) {
    buildMaxHeap(v, n);
    for (int i = n-1; i > 0; i--) {
        trocar(v, 0, i);
        maxHeapify(v, 0, i);
    }
}

int main() {

    int n;
    Pais p[500];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].nome, &(p[i].o), &(p[i].p), &(p[i].b));
    }





    // print
    for (int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", p[i].nome, p[i].o, p[i].p, p[i].b);
    }


    return 0;
}