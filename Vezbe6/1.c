#include <stdio.h>
#include <stdlib.h>

void map(int *a, int n, int(*f)(int));
int increase(int x);
int square(int x);
int change(int x);

int main(){

  int *a;
  int n;

  scanf("%d", &n);

  a = malloc(n * sizeof(int));

  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  map(a, n, square);

  for(int i = 0; i<n; i++){
    printf("%d ", a[i]);
  }

  return 0;
}

void map(int *a, int n, int(*f)(int)){
  
  for(int i=0; i<n; i++){
    a[i] = (*f)((a[i]));
  }
}

int increase(int x){

  return x+1;
}

int square(int x){

  return x*x;
}

int change(int x){

  return -x;
}
