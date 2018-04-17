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

int main(int argc, char const *argv[]) {

  int quantidade=1;

  char ler[1000];
  fgets(ler,1000,stdin);
  ler[strlen(ler)-1]='\0';

  char *separado;
  char **guardar;
  guardar=malloc(sizeof(*guardar)*quantidade);

  guardar[quantidade-1]=(strtok(ler,"|"));
  while(guardar[quantidade-1]!=NULL)
  {
    quantidade++;
    guardar=realloc(guardar,sizeof(*guardar)*quantidade);
    guardar[quantidade-1]=strtok(NULL,"|");
  }
  quantidade--;
  int fd[quantidade-1][2];
  pipe(fd[0]);
  for(int i=0;i<quantidade;i++)
  {
    pipe(fd[i+1]);
    if(fork()==0)
    {
      if(i!=0)
        dup2(fd[i][READ],STDIN_FILENO);
      else
        close(fd[i][READ]);

      if(i!=quantidade-1)
        dup2(fd[i+1][WRITE],STDOUT_FILENO);
      else
        close(fd[i+1][WRITE]);

      close(fd[i][WRITE]);
      close(fd[i+1][READ]);
      int tamanho=1;
      char **save;
      save=malloc(sizeof(*save)*tamanho);

      save[tamanho-1]=(strtok(guardar[i]," "));
      while(save[tamanho-1]!=NULL)
      {
        tamanho++;
        save=realloc(save,sizeof(*save)*tamanho);
        save[tamanho-1]=strtok(NULL," ");
      }
      tamanho--;
      execvp(save[0],save);
    }
    else
    {
      close(fd[i][READ]);
      close(fd[i][WRITE]);
      wait(NULL);
    }
  }

  exit(0);
}
