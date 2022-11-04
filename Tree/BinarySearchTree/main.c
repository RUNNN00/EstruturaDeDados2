#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    ABB* a = ABB_Criar();

    ABB_Inserir(a, 30, 30);

    return 0;
}