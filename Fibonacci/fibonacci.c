#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t fib_M(int n, uint64_t *M)
{
    if (M[n] != 0)
        return M[n];

    uint64_t r = fib_M(n - 1, M) + fib_M(n - 2, M);
    M[n] = r;
    return r;
}

uint64_t fib(int n)
{
    uint64_t *M = calloc(n + 1, sizeof(uint64_t));
    M[0] = 1;
    M[1] = 1;
    uint64_t r = fib_M(n, M);
    free(M);
    return r;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    printf("fibonacci: %d = %lu\n", n, fib(n));
    return 0;
}