#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  for(int i=0; i<argc; i++){
    if(argv[i][0] == '-'){
      for(int j=1; j<strlen(argv[i]); j++){
        printf("%c ", argv[i][j]);
      }
    }
  }

  return 0;
}
