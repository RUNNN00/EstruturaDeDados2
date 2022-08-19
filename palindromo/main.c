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

int main(int argc, char** argv)
{
    bool palindromo = palim(argv[1], strlen(argv[1]));

    if (palindromo)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}