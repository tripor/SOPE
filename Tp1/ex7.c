#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void imprimirMensagem1()
{
  printf("Executing exit handler 1\n");
  exit(0);
}
void imprimirMensagem2()
{
  printf("Executing exit handler 2\n");
  exit(0);
}

int main(int argc, char* argv[])
{
  atexit(imprimirMensagem1);
  atexit(imprimirMensagem2);
  //abort();
  printf("Main done!\n");
  exit(0);
}
