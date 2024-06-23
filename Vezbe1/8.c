#include <stdio.h>
#include <stdlib.h>

void error(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}


int main(int argc, char **argv){

  if(argc != 3){
    error();
  }

  int a = atoi(argv[1]), b = atoi(argv[2]);

  if(a>b){
    error();
  }

  for(; a<=b; a++){
    printf("%d ", a);
  }


  return 0;
}
