#include <stdio.h>
#include <stdlib.h>

void write1(int n);
void write2(int n);

int main(){

  int n;
  scanf("%d", &n);

  write1(n);
  printf("\n");
  write2(n);

  return 0;
}

void write1(int n){

  if(n < 10){
    printf("%d ", n);
    return;
  }

  write1(n/10);
  printf("%d ", n%10);
}

void write2(int n){

  if(n < 10){
    printf("%d ", n);
    exit(EXIT_SUCCESS);
  }

  printf("%d ", n%10);

  write2(n/10);
}
