#include <stdio.h>
#include <stdlib.h>

void inputString(char **frase, int size);
void printString(char *frase);

int main(void) {
    char *frase = malloc(10*sizeof (char));
    int size = 10;
    if(frase == NULL){
        return 1;
    }
    inputString(&frase,size);
    printString(frase);

    free(frase);

     return 0;
}
void inputString(char **frase, int size){
    int i = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        if (i >= size - 1) {  // realloc if needed
            size *= 2;
            *frase = realloc(*frase, size * sizeof(char));

            if (*frase == NULL) {
                exit(1);
            }
        }
        (*frase)[i++] = ch;
    }
    (*frase)[i] = '\0';
}
void printString(char *frase){
    int i = 0;
    while (*(frase+i) != '\0'){
        printf("%c",*(frase+(++i)));
    }
}
