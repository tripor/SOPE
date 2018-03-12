#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include<errno.h>
int main(int argc, char *argv[], char *envp[])
{
 pid_t pid;
 if (argc != 2) {
   printf("usage: %s dirname\n",argv[0]);
   exit(1);
 }
 pid=fork();
 if (pid > 0)
    printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
 else if (pid == 0){
   //execlp("ls","ls","-laR",argv[1],NULL);
   //execl("/bin/ls","ls","-laR",argv[1],NULL);
   /*char *coisa[4];
   coisa[0]="ls";
   coisa[1]="-laR";
   coisa[2]=argv[1];
   coisa[3]=NULL;
   execvp("ls",coisa);*/
   /*char *coisa[4];
   coisa[0]="ls";
   coisa[1]="-laR";
   coisa[2]=argv[1];
   coisa[3]=NULL;
   execv("/bin/ls",coisa);*/
   char *coisa[4];
   coisa[0]="ls";
   coisa[1]="-laR";
   coisa[2]=argv[1];
   coisa[3]=NULL;
   char *env_args[2];
   env_args[0]="PATH=/bin/ls";
   env_args[1]=NULL;
   execve("/bin/ls",coisa,envp);
   printf("Command not executed !\n");
   printf("Erro execve %d: %s\n", errno, strerror(errno));
   exit(1);
 }
 exit(0);
}
