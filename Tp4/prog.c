#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  for(int i=1;i<=6;i++)
  {
    printf("I'm alive\n");
    sleep(5);
  }
  exit(0);
}
