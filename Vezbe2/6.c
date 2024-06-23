#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

  unsigned int a, b;
  char ime[5];

} RECTANGLE;

void error();

int main(int argc, char **argv){

  if(argc != 2){
    error();
  }

  FILE *f1 = fopen(argv[1], "r");
  if(f1 == NULL){
    error();
  }

  int k = 2;

  RECTANGLE *arr = malloc(k * sizeof(RECTANGLE));
  if(arr == NULL){
    error();
  }

  unsigned int a, b;
  char arr2[21];

  int alloc = k;
  int e;
  int i =0;

  while(fscanf(f1, "%u %u %s", &a, &b, arr2) == 3){
    if(i == alloc){
      alloc +=alloc;
      RECTANGLE *arr = realloc(arr, alloc);
      if(arr == NULL){
        error();
      }
    }
    arr[i].a = a;
    arr[i].b = b;
    strcpy (arr[i].ime, arr2);
    i++;
    e = i;
  }

  arr2[0] = '\0';

  unsigned max=0;

  for(int i=0; i<e; i++){
    if(arr[i].a != arr[i].b){
      if((arr[i].a * arr[i].b) > max){
        max = arr[i].a * arr[i].b;
      }
    }else{
      strcat(arr2, arr[i].ime);
      strcat(arr2, " ");
    }
  }

  if(max == 0){
    printf("%s", arr2);
  }else{
    printf("%u %s", max, arr2);
  }
  
  free(arr);
  fclose(f1);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}
