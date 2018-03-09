#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  char *separado,**guardar=(char**)malloc(1);
  int quantidade=1;
  separado=strtok(argv[1],";|");
  while (separado!=NULL)
  {
    guardar=(char**)realloc(guardar,sizeof(char)*quantidade);
    guardar[quantidade-1]=(char*)malloc(strlen(separado));
    strcpy(guardar[quantidade-1],separado);
    printf("%s\n",guardar[quantidade-1]);
    separado=strtok(NULL,";|");
    quantidade++;
  }
  exit(0);
}
