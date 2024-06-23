#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void error();

int main(){

  int n;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    char *num = malloc(MAX * sizeof(char));
    if(num == NULL){
      error();
    }

    int e = i;

    sprintf(num, "%d", e);
    strcat(num, ".txt");

    FILE *f = fopen(num, "w");
    if(f == NULL){
      error();
    }

    for(int j=0; j<=n; j++){
      if(j%i == 0){
        fprintf(f, "%d ", j);
       } 
    }

    fclose(f);
    free(num);
  }

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}
