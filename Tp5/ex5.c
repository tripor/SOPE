#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define READ     0
#define WRITE    1
int quantidade=1;
void separar(char* argv,char **guardar)
{
  char *separado;
  guardar=malloc(sizeof(*guardar)*quantidade);
  separado=strtok(argv,";|");
  while (separado!=NULL)
  {
    guardar=realloc(guardar,sizeof(*guardar)*quantidade);
    guardar[quantidade-1]=malloc(strlen(separado));
    strcpy(guardar[quantidade-1],separado);
    printf("%s\n",guardar[quantidade-1]);
    separado=strtok(NULL,";|");
    quantidade++;
  }
}


int main(int argc, char const *argv[]) {
  char ler[101];
  int tamanho;
  do {
    fgets(ler,100,stdin);
    ler[strlen(ler)-1]='\0';
    char **meu;
    tamanho=quantidade;
    separar(ler,meu);
    tamanho=quantidade-tamanho;


  } while(strcmp(ler,"quit")!=0);
  return 0;
}
