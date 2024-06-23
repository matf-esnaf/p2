#include <stdlib.h>
#include <stdio.h>

#define MAX 81

void error(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    char c[MAX];

    FILE *ulaz = fopen("1_ulaz.txt", "r");
    if(ulaz == NULL){
        error();
    }
    FILE *izlaz = fopen("izlaz.txt", "w");
    if(izlaz == NULL){
        error();
    }

    while (fgets(c, MAX, ulaz) != NULL){
        fprintf(izlaz, "%s", c);
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}