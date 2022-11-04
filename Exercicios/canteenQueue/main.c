#include <stdio.h>
#include <stdlib.h>

void trocar(int *v, int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int maxHeapify(int* v, int i, int th) {
    int e = 2 * i + 1;
    int d = e + 1;
    int maior = i;

    if ((e < th) && (v[e] < v[i]))
        maior = e;
    
    if ((d < th) && (v[d] < v[maior]))
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

int main()
{
    int **compare;
    int **p;
    int *sizes;
    int n;
    scanf("%d", &n);

    p = (int**) malloc(sizeof(int*) * n);
    compare = (int**) malloc(sizeof(int*) * n);
    sizes = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        scanf("%d", &m);

        p[i] = (int*) malloc(sizeof(int) * m);
        compare[i] = (int*) malloc(sizeof(int) * m);
        sizes[i] = m;

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &p[i][j]);
            compare[i][j] = p[i][j];
        }
        
        heapSort(p[i], m);
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < sizes[i]; j++) {
            if (p[i][j] == compare[i][j])
                count += 1;
        }
        printf("%d\n", count);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < sizes[i]; j++) {
    //         printf("%d ", p[i][j]);
    //     }
    //     printf("\n");
    // }

    free(compare);
    free(p);
    free(sizes);

    return 0;
}