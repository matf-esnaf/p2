#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_1 21

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  char *s = malloc(MAX_1 * sizeof(char));
  scanf("%s", s);

  int n;
  scanf("%d", &n);

  if(n<=0){
    error();
  }

  char **s2 = malloc(n * sizeof(char *));
  if(s2 == NULL){
    error();
  }
  for(int i=0; i<n; i++){
    s2[i] = malloc(MAX_1 * sizeof(char));
    if(s2[i] == NULL){
      error();
    }
  }
  


  for(int i=0; i<n; i++){
    scanf("%s", s2[i]);
  }

  int c=0;

  for(int i=0; i<n; i++){
    if(strcmp(s, s2[i]) == 0){
      printf("%d ", i);
      c++;
    }
  }

  if(c==0){
    printf("-1 -1\n");
  }



  for(int i=0; i<n; i++){
    free(s2[i]);
  }

  free(s2);

  return 0;
}
