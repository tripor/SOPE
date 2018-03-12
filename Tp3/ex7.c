#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
  char prog[20];
  printf("hi222222222222\n");
  sprintf(prog,"%s.c",argv[1]);
  execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
  printf("hi222222222222\n");
  exit(1);
}
