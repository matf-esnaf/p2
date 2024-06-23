#include <stdio.h>
#include <stdlib.h>

#define MAX 81

void error(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    int i = 0;
    char line[MAX];

    FILE *knjiga = fopen("knjiga.txt", "r");
    if(knjiga == NULL){
        error();
    }

    while(fgets(line, MAX, knjiga) != NULL){
        i++;
    }

    printf("%d\n", i);

    fclose(knjiga);

    return 0;
}