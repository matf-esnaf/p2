#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void error();
int binary_search(char **a, char *w, int n, int l, int r);
int compare(const void *a, const void *b);

int main(){

  char **a, *w;
  int n;

  scanf("%d", &n);
  if(n <= 0){
    error();
  }

  a = malloc(n * sizeof(char *));
  if(a == NULL){
    free(a);
    error();
  }

  for(int i=0; i<n; i++){
    a[i] = malloc(MAX * sizeof(char));
    if(a[i] == NULL){
      for(int j=0; j<i; j++){
        free(a[i]);
      }
      free(a);
      error();
    }
  }

  for(int i=0; i<n; i++){
    scanf("%s", a[i]);
  }

  w = malloc(MAX * sizeof(char));
  if(w == NULL){
    free(a);
    error();
  }

  scanf("%s", w);

  int y = binary_search(a, w, n, 0, n-1);

  printf("%d -- rekurzivno\n", y);

  char **res = bsearch(w, a, n, sizeof(char *), &compare);

  if(res == NULL){
    printf("-1 -- bsearch\n");
  }else{
    printf("%d -- bsearch\n", (int)(res - a));
  }

  free(a);
  free(w);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int binary_search(char **a, char *w, int n, int l, int r){

  if(r < l){
    return -1;
  }

  int m = (l + r) / 2;

  if(strcmp(a[m], w) == 0){
    return m;
  }

  if(strcmp(a[m], w) < 0){
    return binary_search(a, w, n, l, m-1);
  }

  return binary_search(a, w, n, m+1, r);
}

int compare(const void *a, const void *b){

  char *x = (char *)a;
  char *y = *((char **)b);

  if(strcmp(x, y) == 0){
    return 0;
  }
  
  if(strcmp(x, y) < 0){
    return -1;
  }

  return 1;
}
