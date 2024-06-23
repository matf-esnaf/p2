#include <stdio.h>
#include <stdlib.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv){  

  if(argc != 2){
    error();
  }

  int n = atoi(argv[1]);

  FILE *f1 = fopen("numbers.txt", "r");
  if(f1 == NULL){
    error();
  }

  int *arr = malloc(n * sizeof(int));

  int e;

  for(int i=0; ;){

    if(i == n){
      n+=n;
      arr = realloc(arr, n * sizeof(int));
    }

    int x;
    fscanf(f1, "%d", &x);
    
    if(x == 0){
      e = i;
      break;
    }
    arr[i] = x;
    i++;
  } 

  int x;

  if(e%2 == 0){
    x = arr[e/2]/arr[e/2 - 1];
  }else{
    x = arr[e/2];
  }

  for(int i=0; i<e; i++){
    if(arr[i]>x){
      printf("%d ", arr[i]);
    }
  }

  fclose(f1);
  free(arr);

  return 0;
}
