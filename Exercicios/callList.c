#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char **c, int count)
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
    char **names = (char **)malloc(sizeof(char *) * count);

    if (names == NULL)
    {
        printf("error\n");
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        char *name = (char *)malloc(sizeof(char) * 20);
        if (name == NULL)
        {
            printf("error\n");
            return 0;
        }
        char straux[20];
        scanf("%s", straux);
        strcpy(name, straux);
        names[i] = name;
    }

    // sort
    selectionSort(names, count);

    printf("%s\n", names[drawn - 1]);
    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);
    return 0;
}