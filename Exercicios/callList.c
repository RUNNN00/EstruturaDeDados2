#include <stdio.h>
#include <string.h>

void selectionSort(char c[5][20], int count)
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
    int drawn = 0;
    int count = 0;

    scanf("%d %d", &count, &drawn);
    char names[5][20];

    for (int i = 0; i < count; i++)
        scanf("%s", names[i]);

    // sort
    selectionSort(names, count);

    printf("%s\n", names[drawn - 1]);

    return 0;
}