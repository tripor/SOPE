#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void chi(int signo)
{
  int status;
  waitpid(-1,&status,WNOHANG);
  printf("Sinal + waitpid\n");
}

int main(void)
{
  pid_t pid;
  int i, n, status;
  //signal(SIGCHLD, SIG_IGN);
  signal(SIGCHLD, chi);
  for (i=1; i<=10; i++) {
    pid=fork();
    if (pid == 0){
      printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());
      sleep(10); // child working ...
      printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());
      exit(0);
    }
  }
  for (i=1 ;i<=10; i++ ) {
    printf("PARENT: working hard (task no. %d) ...\n",i);
    n=5;
    while((n=sleep(n))!=0);
    printf("PARENT: end of task no. %d\n",i);
    printf("PARENT: waiting for child no. %d ...\n",i);

  }
  exit(0);
}
