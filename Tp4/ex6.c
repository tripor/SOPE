#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int pid;
void alarme(int signo)
{
  printf("alarme!!!\n");
  kill(pid,SIGKILL);
  exit(1);
}

int main(int argc, char const *argv[])
{
  char **coisa=malloc(sizeof(*coisa)*100);
  int i=2;
  while(i<argc)
  {
    coisa[i-2]=malloc(sizeof(char)*strlen(argv[i])+1);
    strcpy(coisa[i-2],argv[i]);
    printf("%s\n",coisa[i-2]);
    i++;
  }
  coisa[i-2]=NULL;
  char pri[1000]="./";
  strcat(pri,coisa[0]);
  strcpy(coisa[0],pri);
  pid=fork();
  if(pid>0)
  {
    alarm(atoi(argv[1]));
    signal(SIGALRM,alarme);
    pause();
  }
  else
  {
    execvp(coisa[0],coisa);
    exit(0);
  }

  exit(0);
}
