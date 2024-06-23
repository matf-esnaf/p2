#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void error();

int main(int argc, char **argv){

  for(int i=1; i<argc; i++){
    if(argv[i][1] != '/'){
      error();
    }
    if(isalpha(argv[i][0]) || isalpha(argv[i][2])){
      error();
    }
  }


  for(int i=1; i<argc; i++){
    float x = atoi(&argv[i][0]);
    float y = atoi(&argv[i][2]);

    printf("%.2f ", x/y);
  }

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}
