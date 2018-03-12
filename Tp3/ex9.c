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
int main(int argc, char *argv[], char *envp[])
{
 pid_t pid;
 if (argc != 3) {
   printf("usage: %s dirname\n",argv[0]);
   exit(1);
 }
 pid=fork();
 if (pid > 0){
      int valor;
      printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
      wait(&valor);
      printf("Valor de retorno: %d\n",WEXITSTATUS(valor));
      if(WIFEXITED(valor))
      {
        printf("Normalmente\n");
      }
      else if(WIFSIGNALED(valor))
      {
        printf("Anormal\n");
      }
 }
 else if (pid == 0){
   int desc;
   desc=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT|O_SYNC,0600);
   char *coisa[4];
   dup2(desc,STDOUT_FILENO);
   coisa[0]="ls";
   coisa[1]="-laR";
   coisa[2]=argv[1];
   coisa[3]=NULL;
   execve("/bin/ls",coisa,envp);
   printf("Command not executed !\n");
   close(desc);
   exit(1);
 }
 exit(0);
}
