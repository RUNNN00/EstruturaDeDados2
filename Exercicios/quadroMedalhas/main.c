#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char nome[50];
    int o;
    int p;
    int b;
} Pais;

// verificado
void definirPais(Pais *dest, Pais *src)
{

    strcpy(dest->nome, src->nome);
    dest->o = src->o;
    dest->p = src->p;
    dest->b = src->b;
}

// verificado
void trocar(Pais *v, int a, int b)
{
    Pais aux;
    definirPais(&aux, &(v[a]));
    definirPais(&(v[a]), &(v[b]));
    definirPais(&(v[b]), &aux);
}

bool compararPaises(Pais *A, Pais *B) {

    // ouro
    if (A->o > B->o) {
        return true;
    }
    else if (A->o == B->o) {
        // prata
        if (A->p > B->p) {
            return true;
        }
        else if (A->p == B->p) {
            // bronze
            if (A->b > B->b) {
                return true;
            }
            else if (A->b == B->b) {
                // nome
                int i = strcmp(A->nome,B->nome);
                if (i == -1)
                    return true;
            }
        }
    }
    return false;
}

int partition(Pais *v, int e, int d)
{
    Pais x = v[d];
    int i = e - 1;
    for (int j = e; j < d; j++)
    {
        if (!compararPaises(&x, &(v[j])))
        {
            trocar(v, i + 1, j);
            i++;
        }
    }
    trocar(v, i + 1, d);
    return i + 1;
}

void QuickSort(Pais *v, int e, int d)
{
    if (e < d)
    {
        int q = partition(v, e, d);
        QuickSort(v, e, q - 1);
        QuickSort(v, q + 1, d);
    }
}

int main()
{

    int n;
    Pais p[500];

    scanf("%d", &n);

    // input
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", p[i].nome, &(p[i].o), &(p[i].p), &(p[i].b));
    }

    QuickSort(p, 0, n - 1);

    // print
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d\n", p[i].nome, p[i].o, p[i].p, p[i].b);
    }

    return 0;
}