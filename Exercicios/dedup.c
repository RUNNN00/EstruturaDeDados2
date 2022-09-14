#include <stdio.h>
#include <stdlib.h>

int *dedup(int *v, int n, int *ns)
{
    //TODO ...
}

int main(int argc, char **argv)
{
    int v[] = {2, 1, 0, 2, 1, 4, 3, 6, 2};
    int ns = 0;
    int *s = dedup(v, 9, &ns);
    for (int i = 0; i < ns; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}