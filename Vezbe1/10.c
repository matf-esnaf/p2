#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
  
  if(argc != 3){
    error();
  }

  FILE *first = fopen(argv[1], "r");
  FILE *second = fopen(argv[2], "r");
  if(first == NULL || second == NULL){
    error();
  }

  char stringOne[MAX], stringTwo[MAX];
  char *holdOne, *holdTwo;

  holdOne = fgets(stringOne, MAX, first);
  holdTwo = fgets(stringTwo, MAX, second);

  int i = 1;

  for(; holdOne != NULL || holdTwo != NULL; i++){
    if(strcmp(stringOne, stringTwo) != 0){
      printf("%d ", i);
    }

    holdOne = fgets(stringOne, MAX, first);
    holdTwo = fgets(stringTwo, MAX, second);
  }

  for(; holdOne != NULL; i++){
    printf("%d ", i);
    holdOne = fgets(stringOne, MAX, first);
  }

  for(; holdTwo != NULL; i++){
    printf("%d ", i); 
    holdTwo = fgets(stringTwo, MAX, second);
  }

  
  fclose(first);
  fclose(second);

  return 0;
}
