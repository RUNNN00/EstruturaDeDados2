#include <stdlib.h>
#include "hashtable_ea.h"

int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{

    THEA *nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->n = 0;
    nova->t = calloc(m, sizeof(ELEM));
    for (int i = 0; i < m; i++)
    {
        nova->t[i].estado = E_LIVRE;
    }
    return nova;
}

int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int k = 0;
    int h = THEA_Buscar(TH, chave);
    if (h < 0) {
        if (TH->m == TH->n)
            return -1;
        h = THEA_Buscar(TH, chave);
        while (TH->t[h].estado == E_OCUPADO) {
            //PEgar do moodle
        }
    }
}

int THEA_Buscar(THEA *TH, int chave)
{
    int k = 0;
    int h = THEA_Hash(TH, chave, k);
    while (TH->t[h].estado != E_LIVRE)
    {
        if ((TH->t[h].estado == E_OCUPADO) && (TH->t[h].chave == chave))
            return h;
        k++;
        h = THEA_Hash(TH, chave, k);
        if (k == TH->m)
            return -1;
    }
    return -1;
}

void THEA_Remover(THEA *TH, int chave)
{
    int pos = THEA_Buscar(TH, chave);
    if (pos >= 0) {
        TH->t[pos].estado = E_APAGADO;
        TH->n--;
    }
}

void THEA_Imprimir(THEA* TH) {


}