#include <stdio.h>
#include <stdlib.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  int *arr;
  int n;

  scanf("%d", &n);

  arr = malloc(n* sizeof(int));

  if(arr == NULL){
    error();
  }

  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(int i=n-1;i>-1; i--){
    printf("%d ", arr[i]);
  }

  free(arr);
  arr = NULL;

  return 0;
}
