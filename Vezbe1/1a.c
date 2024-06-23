#include <stdio.h>
#include <stdlib.h>

void error(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    char c;

    FILE *ulaz = fopen("ulaz.txt", "r");
    if(ulaz == NULL){
        error();
    }

    FILE *izlaz = fopen("izlaz.txt", "w+");
    if(izlaz == NULL){
        error();
    }

    while((c = fgetc(ulaz)) != EOF){
        fputc(c, izlaz);
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}