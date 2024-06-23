#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DAT 21

void error(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    char text1[MAX_DAT], text2[MAX_DAT];
    char c, s;
    scanf("%s %s %c", text1, text2, &c);

    if(c != 'u' && c != 'V'){
        error();
    }

    FILE *ulaz, *izlaz;
    ulaz = fopen(text1, "r");
    izlaz = fopen(text2, "w");

    if(ulaz == NULL || izlaz == NULL){
        error();
    }

    while((s = fgetc(ulaz)) != EOF){
        if (c == 'u'){
            fputc(tolower(s), izlaz);
        } else {
            fputc(toupper(s), izlaz);
        }
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}