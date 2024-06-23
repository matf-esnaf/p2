#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv){

  if(argc != 4){
    error();
  }

  int n = atoi(argv[1]), a = atoi(argv[2]), b = atoi(argv[3]);

  if(a>=b){
    error();
  }

  srand(time(NULL));

  for(int i = 0; i < n; i++){
    int randomNum = rand() % (b - a + 1) + a;
    printf("%d ", randomNum);
  } 

  return 0;
}
