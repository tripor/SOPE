#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char **coisa=malloc(sizeof(*coisa)*100);
  int i=1,status;
  while(i<argc)
  {
    coisa[i-1]=malloc(sizeof(char)*strlen(argv[i])+1);
    strcpy(coisa[i-1],argv[i]);
    printf("%s\n",coisa[i-1]);
    i++;
  }
  for(int i=0;i<argc-1;i++)
  {
    int pid=fork();
    if(pid>0)
    {

    }
    else
    {
      char pri[1000]="./";
      strcat(pri,coisa[i]);
      strcpy(coisa[i],pri);
      execlp(pri,pri,NULL);
      exit(0);
    }
  }
  int j=0;
  while(j<argc)
  {
    waitpid(-1,&status,0);
    if(WEXITSTATUS(status)!=0)
    {
      kill(-1,SIGKILL);
    }
    j++;
  }
  exit(0);
}
