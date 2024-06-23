#include "polynomial.h"

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int *unos(int *n){
  
  scanf("%d", n);

  if(n <= 0){
    error();
  }

  int *arr = malloc(((*n)+1) * sizeof(int));

  for(int i=0; i<=(*n); i++){
    scanf("%d", &arr[i]);
  }

  return arr;
}

void ispis(int *a, int n){




  printf("\n");
}
