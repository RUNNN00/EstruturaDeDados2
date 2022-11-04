#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

int *vetorAleatorio(int n, int seed, int max)
{
    srand(seed);
    int *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        v[i] = (rand() % max) + 1;
    }

    return v;
}

int pmax(int *v, int ini, int fim)
{
    int maior = ini;
    for (int i = ini + 1; i <= fim; i++)
    {
        if (v[i] > v[maior])
            maior = i;
    }
    return maior;
}

void trocar(int *v, int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void selectionSort(int *v, int qtd)
{
    for (int i = qtd - 1; i > 0; i--)
    {
        int maior = pmax(v, 0, i);
        trocar(v, maior, i);
    }
}

void bubbleSort(int *v, int n)
{
    for (int j = n - 1; j >= 1; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (v[i] > v[i + 1])
                trocar(v, i, i + 1);
        }
    }
}

void insertion(int *v, int k)
{
    int i = k - 1;
    int x = v[k];
    while ((i >= 0) && (v[i] > x))
    {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = x;
}

void inserctionSort(int *v, int n)
{
    for (int j = 1; j < n; j++)
    {
        insertion(v, j);
    }
}

void mergeSort(int *v, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *e = malloc(sizeof(int) * (n1 + 1));
    int *d = malloc(sizeof(int) * (n2 + 1));
    int i, j, k;
    
    for (i = 0; i < n1; i++)
        e[i] = v[p + i];
    e[n1] = INT_MAX;

    for (j = 0; j < n2; j++)
        d[j] = v[q + 1 + j];
    d[n2] = INT_MAX;


    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
    {
        if (e[i] <= d[j])
        {
            v[k] = e[i];
            i++;
        }
        else
        {
            v[k] = d[j];
            j++;
        }
    }
    free(e);
    free(d);
}

// heapSort ================================================
void trocar(int* v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void maxHeapify(int* v, int i, int th) {
    int e = (2*i)+1;
    int d = e+1;
    int maior = i;
    if ((e < th) && (v[e] > v[i]))
        maior = e;
    if ((d < th) && (v[d] > v[maior]))
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

int partition(int *v, int p, int r){
    int x = v[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(v[j] <= x){
            trocar(v, i+1, j);
            i++;
        }
    }
    trocar(v, i+1, r);
    return i+1;
}

void QuickSort(int *v, int p, int r){
    if(p < r){
        int q = partition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}

int MaxInfoChave(Info* v, int n){
    int maior = 0;
    for(int i = 1; i < n; i++){
        if(v[i].chave > v[maior].chave){
            i = maior;
        }
    }
    return v[maior].chave;
}

void CountingSort(Info* v, int n){
    int i, j, k, t, acum=0;
    k = MaxInfoChave(v, n);
    int *c = calloc(k+1, sizeof(int));
    Info* s = malloc(sizeof(Info) * n);
    
    for(j = 0; j < n; j++)
        c[v[j].chave]++;
    
    for(i = 0; i <=k; i++){
        t = c[i];
        c[i] = acum;
        acum += t;
    }

    for(i = 0; i < n; i++){
        s[c[v[i].chave]] = v[i];
        c[v[i].chave]++;
    }

    memcpy(v, s, sizeof(Info) * n);
    free(s);
    free(c);
}

void counting_sort(int *v, int n, int div, int base, int *temp){
    int i, t, c[base], acum = 0;
    memset(c, 0, base * sizeof(int));

    #define DIGIT(X) (X / div) % base

    for(i = 0; i < n; i++){
        c[DIGIT(v[i])]++;
    }

    for(i = 0; i < base; i++){
        t = c[i];
        c[i] = acum;
        acum += t;
    }

    for(i = 0; i < n; i++){
        temp[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }
    
    memcpy(v, temp, sizeof(int) * n);

}

void RadixSort(int *v, int n){
    int k, div = 1;
    k = v[pmax(v, 0, n-1)];
    int *temp = malloc(sizeof(int) * n);
    while(k > 0){
        counting_sort(v, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}