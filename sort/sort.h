#pragma once

void imprimir(int *v, int size);

typedef struct Info{
    int dado;
    int chave;
} Info;

int *vetorAleatorio(int n, int seed, int max);
void selectionSort(int *v, int qtd);
void bubbleSort(int *v, int n);
void inserctionSort(int *v, int n);
void mergeSort(int *v, int p, int q, int r);
void heapSort(int *v, int n);
void QuickSort(int *v, int p, int r);
void CountingSort(Info* v, int n);
void RadixSort(int *v, int n);