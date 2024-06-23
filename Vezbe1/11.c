#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  srand(time(NULL));   // Initialization, should only be called once.
  int r = rand() % 2;      // Returns a pseudo-random integer between 0 and RAND_MAX.  

  printf("%d\n", r);

  return 0;
}
