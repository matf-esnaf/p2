#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_1 21
#define MAX_2 51
#define MAX_3 257

void error(){
  fprintf(stderr, "-1\n");
}

int main(){

  char text[MAX_1];
  scanf("%s", text);

  FILE *ulaz = fopen(text, "r");
  FILE *izlaz = fopen("izlaz.txt", "w");

  int n;
  fscanf(ulaz, "%d", &n);

  char string[MAX_3][MAX_2];

  for(int i=0; i<n; i++){
    fscanf(ulaz, "%s", string[i]);
    printf("%s ", string[i]);

    if(strstr(string[i], string[0]) != NULL){
     if(strstr(string[i], "_") != NULL){
      fprintf(izlaz, "%s ", string[i]);
      }
    }
  }

  fclose(ulaz);
  fclose(izlaz);

return 0;
}
