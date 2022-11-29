#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char* str;
    int size;
} Word;

int main() {

    int n;
    scanf("%d", &n);
    
    char **strings = (char**) malloc(sizeof(char*) * n);

    // input
    for (int i = 0; i < n; i++) {
        char temp;
        strings[i] = (char*) malloc(sizeof(char) * 50);
        scanf("%c", &temp); // temp statemtent to clear buffer
        scanf("%[^\n]", strings[i]);
    }

    Word* words = (Word*) malloc(sizeof(Word) * 25);

    int i = 0;
    char* token = strtok(strings[0], " ");
    while (token != NULL) {
        words[i].size = strlen(token);
        strcpy(words[i].str, token);
        token = strtok(strings[0], " ");
        i++;
    }

    // strings[0] = Top Coder comp Wedn at midnight
    // strings[1] = one three five
    // ...

    // strSplit[0] = Top
    // strSplit[1] = Coder
    // strSplit[2] = comp
    // ...

    // int countC = 0
    // while (strSplit[0][i] != '\0')
    // countC++


    // print
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}