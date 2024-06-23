#include <stdio.h>
#include <stdlib.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  int *br, *im, n;

  scanf("%d", &n);

  if(n<0){
    error();
  }

  br = malloc(n * sizeof(int));
  im = malloc(n * sizeof(int));
  if(br == NULL || im == NULL){
    error();
  }

  double sum;

  for(int i=0; i<n; i++){
    scanf("%d %d", &br[i], &im[i]);
    sum += br[i]/im[i];
  }

  double avg = sum / n;

  for(int i=0; i<n; i++){
    double raz = br[i]/im[i];
    if(avg < raz){
      printf("%d/%d ", br[i], im[i]);
    }
  }

  free(br);
  free(im);

  return 0;
}
