#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_1 21
#define MAX_2 51
#define MAX_3 257

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(){

  char text[MAX_1];
  scanf("%s", text);

  FILE *ulaz = fopen(text, "r");
  FILE *izlaz = fopen("izlaz.txt", "w");
  if(ulaz == NULL || izlaz == NULL){
    error();
  }

  int n;
  fscanf(ulaz, "%d", &n);

  char string[MAX_2];
  char string_2[MAX_2][MAX_3];

  int k = 0;

  for(int i=0; i<n; i++){
    fscanf(ulaz, "%s", string);
    printf("%s ", string);

    int found = 0;

    for(int j=0; j<i; j++){
      if(strcmp(string, string_2[j]) == 0){
        found = 1;
        break;
      }
    }
      if(found == 0){
        strcpy(string_2[k], string);
        k++;
        fprintf(izlaz, "%s ", string);
      }
  }



  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
