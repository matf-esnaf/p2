#include <stdio.h>
#include <stdlib.h>

void error();

int iterativna_pretraga(int *a, int n, int x);
int rekurzivna_pretraga(int *a, int l, int r, int x);
int compare(const void *x, const void *y);

int main(){

  int n;
  scanf("%d", &n);

  if(n <= 0){
    error();
  }

  int *a;
  a = malloc(n * sizeof(int));
  if(a == NULL){
    error();
  }

  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  int x;
  scanf("%d", &x);

  printf("%d -- iterativna\n", iterativna_pretraga(a, n, x));
  printf("%d -- rekuzivna\n", rekurzivna_pretraga(a, 0, n, x));

  int *pos = bsearch(&x, a, n, sizeof(int), &compare);

  if(pos == NULL){
    printf("-1 -- binarna\n");
  }else{
    printf("%ld -- binarna\n", pos - a);
  }

  free(a);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int iterativna_pretraga(int *a, int n, int x){

  int l = 0;
  int r = n - 1;

  while(l <= r){

    int m = (l + r) / 2;

    if(a[m] == x){
      return m;
    }
    if(a[m] > x){
      r = m - 1;
    }
    if(a[m] < x){
      l = m + 1;
    }
  }

  return -1;
}

int rekurzivna_pretraga(int *a, int l, int r, int x){

  if(r < l){
    return -1;
  }

  int m = (l + r) / 2;

  if(a[m] == x){
    return m;
  }
  
  if(a[m] < x){
    return rekurzivna_pretraga(a, m + 1, r, x);
  }

  return rekurzivna_pretraga(a, l, m-1, x);
}

int compare(const void *x, const void *y){

  int *a = (int *)x, *b = (int *)y;

  return *a - *b;
}
