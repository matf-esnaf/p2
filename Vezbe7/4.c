// Mora da se uradi bez bsearch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

typedef struct{

  char ime[21];
  char prezime[21];
  char smer;
  float prosek;

} student;

void error();
int binary(student *a, char *trazeno, int l, int r);

int main(){

  FILE *f1 = fopen("studenti.txt", "r");
  if(f1 == NULL){
    error();
  }

  int n;
  fscanf(f1, "%d", &n);

  student *a;
  a = malloc(n * sizeof(student));
  if(a == NULL){
    error();
  }

  char name[MAX], surname[MAX], module;
  float average;

  for(int i=0; i<n; i++){
    fscanf(f1, "%s %s %c %f", name, surname, &module, &average);

    if(module != 'I' && module != 'R' && module != 'M' && module != 'N' && module != 'V' && module != 'L'){
      error();
    }
  
    if(average < 5.0 || average > 10.0){
      error();
    }

    strcpy(a[i].ime, name);
    strcpy(a[i].prezime, surname);
    a[i].smer = module;
    a[i].prosek = average;
  }

  char *trazeno;
  trazeno = malloc(MAX * sizeof(char));
  if(trazeno == NULL){
    error();
  }

  scanf("%s", trazeno);

  int y = binary(a, trazeno, 0, n-1);

  if(y == -1){
    printf("Ne postoji.\n");
    return -1;
  }

  printf("%s %s %c %f", a[y].ime, a[y].prezime, a[y].smer, a[y].prosek);

  fclose(f1);
  free(a);
  free(trazeno);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int binary(student *a, char *trazeno, int l, int r){

  if(r < l){
    return -1;
  }

  int m = (l + r) / 2;

  if(strcmp(a[m].prezime, trazeno) == 0){
    if(m == 0){
      return m;
    }
    if(strcmp(a[m-1].prezime, trazeno) == 0){
      return binary(a, trazeno, l, m-1);
    }else{
      return m;
    }
  }

  if(strcmp(a[m].prezime, trazeno) < 0){
    return binary(a, trazeno, m+1, r);
  }

  return binary(a, trazeno, l, m-1);
}
