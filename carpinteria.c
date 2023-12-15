#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char *token = malloc(sizeof(char) * 20); 
  char *string = malloc(sizeof(char) * 20 + 1); 

 // strcpy(token,"hola,adios"); 


  string = "hola,adios"; 


  token = strtok(string,",");
  printf("token: %s string: %s",token,string); 



  return 0; 
}
