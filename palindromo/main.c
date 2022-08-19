#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palim(char s[], int n)
{
    if (n == 0)
        return true;

    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != s[(n - 1) - i])
            return false;
    }
    return true;
}

bool palim_recursivo(char *s, int ini, int fim)
{
    if ((fim - ini) <= 0)
        return true;
    if (s[ini] != s[fim])
        return false;
    return palim_recursivo(s, ini + 1, fim - 1);
}

int main(int argc, char **argv)
{
    bool palindromo = palim_recursivo(argv[1], 0, strlen(argv[1]) - 1);

    if (palindromo)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}