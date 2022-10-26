#include <stdio.h>

int notas[1000];

void resolver(int* v, int N){

    int acc = 0;
    for (int i = 0; i < N; i++) {
        acc += notas[i];
    }

    float media = (float)acc / N;
    int acimaMedia = 0;
    for (int i = 0; i < N; i++) {
        if (notas[i] > media)
            acimaMedia++;
    }
    float p = (float)acimaMedia / N * 100;
    printf("%.3f%%\n", p);
}

int main(){
    int C;

    scanf("%d", &C);

    for(int i = 0; i < C; i++){
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; j++){
            scanf("%d", &notas[j]);
        }
        resolver(notas, N);
    }

    return 0;
}