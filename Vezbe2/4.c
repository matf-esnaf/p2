#include <stdio.h>
#include <stdlib.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  int n, m;
  scanf("%d %d", &n, &m);

  int **arr = malloc(n * sizeof(int *));
  if(arr == NULL){
    error();
  }
  for(int i=0; i<n; i++){
    arr[i] = malloc(m * sizeof(int));
    if(arr[i] == NULL){
      error();
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  int sum=0, max=0;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", arr[i][j]);
      if(arr[i][j] > max){
        max = arr[i][j];
      }
    }
    sum += max;
    max = 0;
    printf("\n");
  }

  printf("%d ", sum);

  for(int i=0; i<n; i++){
    free(arr[i]);
  }

  free(arr);

  return 0;
}
