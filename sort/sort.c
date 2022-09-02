#include "sort.h"
#include <stdlib.h>
#include <limits.h>

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