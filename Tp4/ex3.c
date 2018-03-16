#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int static valor=0;
int pid;
void cagada(int signo)
{
  printf("cagada: %d\n",signo);
  kill(pid,signo);
}
void add(int signo)
{
  printf("add\n");
  valor++;
  printf("fiz");
}
void dec(int signo)
{
  printf("dec\n");
  valor--;
  printf("fiz");
}
int main(void)
{
  struct sigaction action;
  action.sa_flags = 0;
  while(1){
    pid=fork();
    if(pid>0)
    {
      action.sa_handler = cagada;
      if (sigaction(SIGUSR1,&action,NULL) < 0)
      {
            fprintf(stderr,"Unable to install SIGINT handler\n");
            exit(1);
        }
        action.sa_handler = cagada;
        if (sigaction(SIGUSR2,&action,NULL) < 0)
        {
              fprintf(stderr,"Unable to install SIGINT handler\n");
              exit(1);
        }
      printf("esperando... \n");
        sigset_t sigmask;
        sigfillset(&sigmask);
        sigdelset(&sigmask,SIGUSR1);
        sigdelset(&sigmask,SIGUSR2);
        sigsuspend(&sigmask);
        printf("here\n");
        int val;
      wait(&val);
      valor=WEXITSTATUS(val);
    }
    else
     {
       sigemptyset(&action.sa_mask);
       action.sa_handler = add;
       if (sigaction(SIGUSR1,&action,NULL) < 0)
       {
             fprintf(stderr,"Unable to install SIGINT handler\n");
             exit(1);
         }
         action.sa_handler = dec;
         if (sigaction(SIGUSR2,&action,NULL) < 0)
         {
               fprintf(stderr,"Unable to install SIGINT handler\n");
               exit(1);
         }
       printf("filho a espera\n");
       pause();
       printf("filho %d\n",valor);
       exit(valor);
     }
  }
  exit(0);
}
