#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21
#define MAX_1 101

void error();

int main(int argc, char **argv){
  
  char *text = malloc(MAX * sizeof(char));
  if(text == NULL){
    error();
  }

  strcpy(text, argv[1]);

  FILE *f = fopen(text, "r");
  if(f == NULL){
    error();
  }

  char *word = malloc(MAX * sizeof(char));
  int n;

  scanf("%d", &n); 
  scanf("%s", word);
  
  char *string = malloc(MAX_1 * sizeof(char));
  char *string2 = malloc(MAX * sizeof(char));
  char *string3 = malloc(MAX_1 * sizeof(char));

  while(fgets(string, MAX_1, f) != NULL){
    
    int counter = 0;

    string[strcspn(string, "\n")] = '\0';
    strcpy(string3, string);

    string2 = strtok(string3, " ");
    while(string2 != NULL){
      if(strcmp(word, string2) == 0){
        counter++;
      }
      string2 = strtok(NULL, " ");
    }
    
    if(counter == n){
      printf("%s\n", string);
    }
  }

  free(text);
  free(word);
  free(string);
  free(string2);
  free(string3);

  fclose(f);

  return 0;
}

void error(){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}
