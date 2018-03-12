#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include<errno.h>
#include <termios.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
int separar(char* o_que,char**guardar)
{
  int quantidade=1;
  char *separado=malloc(2);
  separado=strtok(o_que," ");
  while (separado!=NULL)
  {
    guardar=realloc(guardar,sizeof(*guardar)*(quantidade+1));
    guardar[quantidade-1]=malloc(strlen(separado)*sizeof(char));
    strcpy(guardar[quantidade-1],separado);
    separado=strtok(NULL," ");
    quantidade++;
  }
  free(separado);
  return quantidade-1;
}
void lerTeclado(char* guardar)
{
  char ler[1],ns,devolver[1000]="\0";
  int i=0;
  read(STDIN_FILENO,ler,1);
  do
  {
    devolver[i]=ler[0];
    i++;
    strcat(devolver,&ns);
    read(STDIN_FILENO,ler,1);
  }while(ler[0]!='\n');
  strcpy(guardar,devolver);

}
int main(int argc, char *argv[], char *envp[])
{
  char **guardar=malloc(sizeof(char*)*100);
  guardar[0]="";
  char lido[1000]="";
  int i;
  do {
    free(guardar);
    guardar=malloc(sizeof(*guardar)*1000);
    write(STDOUT_FILENO,"minish >",8);
    lerTeclado(lido);
    int quantidade=separar(lido,guardar);
    if(strcmp(guardar[0],"quit")!=0)
    {
      int pid=fork();
      if(pid>0)
      {
        wait(NULL);
      }
      else
      {
        char **mandar=malloc(sizeof(*mandar)*1000);
        for(i=0;i<quantidade;i++)
        {
          mandar[i]=malloc(1000);
          strcmp(mandar[i],guardar[i]);
        }
        mandar[i]=malloc(1000);
        mandar[i]=NULL;
        execvp(guardar[0],mandar);
        exit(1);
      }
    }
  } while(strcmp(lido,"quit")!=0);
  free(guardar);
  exit(0);
}
