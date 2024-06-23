#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char full_name[101];
  int grades[11];
  int grades_num;
  float score;

} STUDENT;

void error();
int max(STUDENT *arr, int n);
void write(const STUDENT *s);

int main(int argc, char **argv){
  
  if(argc != 2){
    error();
  }

  FILE *f1 = fopen(argv[1], "r");
  if(f1 == NULL){
    error();
  }

  int n;
  fscanf(f1, "%d", &n);

  STUDENT *arr = malloc(n * sizeof(STUDENT));
    if(arr == NULL){
      error();
  }

  char buffer1[101];
  char buffer2[101];

  for(int i=0; i<n; i++){
    fscanf(f1, "%s%s", buffer1, buffer2);
    strcat(buffer1, " ");
    strcat(buffer1, buffer2);
    strcpy(arr[i].full_name, buffer1);
    
    int j = 0;
    int sum = 0;
    int ocena = 0;

    while(1){
      fscanf(f1, "%d", &ocena);
      if(ocena == 0){
        break;
      }
      arr[i].grades[j] = ocena;
      j++;
      sum += ocena;
      arr[i].grades_num++;
    }
    arr[i].score = (float)sum / arr[i].grades_num;
  }

  int p = max(arr, n);
  write(&arr[p]);

  free(arr);
  fclose(f1);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int max(STUDENT *arr, int n){

  float max =0;
  int ret;

  for(int i =0; i<n; i++){
    if(arr[i].score > max){
      max = arr[i].score;
      ret = i;
    }
  }

  return ret;
}

void write(const STUDENT *s){

  printf("%s %.2f\n", s->full_name, s->score);
}
