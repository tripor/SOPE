#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
int global=1;
int main(void) {
  pid_t pid;
  int i,status=1;
  for(i=1;i<=3;i++)
  {
    pid=fork();
    if(pid>0)
    {
      wait(&status);
      global++;
    }
    else
    {
      if(global==1)
      {
        write(STDOUT_FILENO,"Hello ",6);
      }
      else if(global==2)
      {
        write(STDOUT_FILENO,"my ",3);
      }
      else if(global==3)
      {
        write(STDOUT_FILENO,"friends!",8);
      }
      //break;
      return 0;
    }
  }

  return 0;
}
