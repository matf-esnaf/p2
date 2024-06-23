#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

void matrix(int a[MAX][MAX], int n, int m, int i, int j);

int main(){

  FILE *ulaz = fopen ("ulaz.txt", "r");

  if (ulaz == NULL){
    error();
  }

  int a[MAX][MAX], n, m;

  fscanf(ulaz, "%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      fscanf(ulaz, "%d", &a[i][j]);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){

    int sum = 0;

      for(int k=i-1; k<=i+1; k++){
        for(int l=j-1; l<=j+1; l++){
          if(k>=0 && l>=0 && k<n && l<m){
            sum += a[k][l];
          }
        }
      }
      sum -= a[i][j];

      if(sum == a[i][j]){
        printf("(%d) (%d) (%d)\n", i, j, a[i][j]);
      }
    }
  }


  fclose (ulaz);

  return 0;
}
