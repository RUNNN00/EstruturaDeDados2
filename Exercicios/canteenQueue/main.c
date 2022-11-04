#include <stdio.h>
#include <stdlib.h>

/*int pmin(int *v, int ini, int fim)
{
    int menor = ini;
    for (int i = ini + 1; i <= fim; i++)
    {
        if (v[i] < v[menor]) {
            menor = i;
        }
    }
    return menor;
}*/

void trocar(int *v, int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void trocarCount(int *v, int a, int b, int *count)
{
    *count += 1;
    trocar(v, a, b);
}


/*int selectionSort(int *v, int qtd)
{
    int count = qtd;
    for (int i = qtd - 1; i > 0; i--)
    {
        int menor = pmin(v, 0, i);
        trocar(v, menor, i, &count);
    }
    return count;
}*/

int maxHeapify(int* v, int i, int th) {
    int e = 2 * i + 1;
    int d = e + 1;
    int maior = i;
    int count = 0;

    if ((e < th) && (v[e] < v[i]))
        maior = e;
    
    if ((d < th) && (v[d] < v[maior]))
        maior = d;
    
    if (maior != i) {
        trocarCount(v, maior, i, &count);
        maxHeapify(v, maior, th);
    }
    return count;
}

void buildMaxHeap(int* v, int n) {
    for (int i = (n-2)/2; i >= 0; i--) {
        maxHeapify(v, i, n);
    }
}

int heapSort(int *v, int n) {
    int count = 0;
    buildMaxHeap(v, n);
    for (int i = n-1; i > 0; i--) {
        trocar(v, 0, i);
        count += maxHeapify(v, 0, i);
    }
    return count;
}

int main()
{
    int qtds[10];
    int p[10][1000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        scanf("%d", &m);

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &p[i][j]);
        }
        
        qtds[i] = heapSort(p[i], m);
    }

    for (int i = 0; i < n; i++){
        printf("%d\n", qtds[i]);
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}