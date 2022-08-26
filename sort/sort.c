#include "sort.h"

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