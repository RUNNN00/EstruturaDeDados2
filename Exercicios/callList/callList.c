#include <stdio.h>
#include <string.h>

void selectionSort(char c[][21], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int aux = strcmp(c[i], c[j]);

            if (aux > 0)
            {
                char temp[20];
                strcpy(temp, c[i]);
                strcpy(c[i], c[j]);
                strcpy(c[j], temp);
            }
        }
    }
}

int main()
{
    int k = 0;
    int n = 0;
    char names[100][21];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {        
        scanf("%s", names[i]);
    }

    // sort
    selectionSort(names, n);

    printf("%s\n", names[k - 1]);

    return 0;
}