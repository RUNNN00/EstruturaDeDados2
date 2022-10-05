#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ea.h"

int main(int argc, char** argv){
    
    THEA* th = THEA_Criar(7);

    THEA_Inserir(th, 12, 0);
    THEA_Inserir(th, 5, 0);
    THEA_Inserir(th, 6, 0);
    THEA_Remover(th, 5);
    int pos = THEA_Buscar(th, 6);

    printf("position: %d\n", pos);

    return 0;
}
