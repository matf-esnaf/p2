#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

void error();

int main(){

  FILE *f1 = fopen("ulaz.txt", "r");
  if(f1 == NULL){
    error();
  }

  int a;
  float b;
  char *s1, *s2, *s3;
  s1 = malloc(MAX * sizeof(char));
  s2 = malloc(MAX * sizeof(char));
  s3 = malloc((MAX + MAX) * sizeof(char));
  
  while(fscanf(f1, "%d.%s%s%f", &a, s1, s2, &b) != EOF){
    strcat(s1, " ");
    strcat(s1, s2);
    strcpy(s3, s1);
    printf("%s\n", s3);
  }

  fclose(f1);
  free(s1);
  free(s2);
  free(s3);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}
