// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sigint_handler(int signo)
{
  printf("\nIn SIGINT handler ...\n");
}
int main(void)
{
  struct sigaction acao;
  acao.sa_handler=sigint_handler;
  sigemptyset(&acao.sa_mask);
  acao.sa_flags=0;
  if (sigaction(SIGINT,&acao,NULL) < 0)
  {
    fprintf(stderr,"Unable to install SIGINT handler\n");
    exit(1);
  }
  printf("Sleeping for 30 seconds ...\n");
  sleep(30);
  printf("Waking up ...\n");
  exit(0);
}
