#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main(){

  int n, *a;

  a = unos(&n);
  
  ispis(a, n);

  free(a);
  return 0;
}
