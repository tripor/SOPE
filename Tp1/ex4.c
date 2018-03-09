//echo$ ? codigo de retorno do ultimo commando executado

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  for(int i=0;i<atoi(argv[2]);i++)
  {
    printf("Ola %s!\n",argv[1]);
  }
  return 1;
}
