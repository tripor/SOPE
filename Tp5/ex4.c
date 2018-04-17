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
  int fd[2];
  if (pipe(fd) < 0)
  {
    fprintf(stderr,"Pipe error\n");
    exit(1);
  }
  int pid1,pid2;
  pid1=fork();
  if(pid1==0)
  {
    dup2(fd[WRITE], STDOUT_FILENO);
    close(fd[READ]);
    execlp("ls", "ls", argv[1], "-laR", NULL);
    exit(0);
  }
  else
  {
    wait(NULL);
    close(fd[WRITE]);
    int fd2[2];
    if (pipe(fd2) < 0)
    {
      fprintf(stderr,"Pipe error\n");
      exit(1);
    }
    pid2=fork();
    if(pid2==0)
    {
      dup2(fd2[WRITE], STDOUT_FILENO);
      dup2(fd[READ],STDIN_FILENO);
      close(fd2[READ]);
      execlp("grep", "grep", argv[2], NULL);
      exit(0);
    }
    else
    {
      wait(NULL);
      dup2(fd2[READ], STDIN_FILENO);
      close(fd2[WRITE]);
      execlp("sort", "sort", NULL);
    }
  }


  return 0;
}
