#include "sort.h"
#include <stdlib.h>

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