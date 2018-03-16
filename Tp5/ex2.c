#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define READ     0
#define WRITE    1
struct dados{
  double a;
  double b;
};
int main(int argc, char const *argv[]) {

  int fd[2],fd2[2],result;
  struct dados numero;
  float result_float;
  char tipo[1000];
  pid_t pid;
  if (pipe(fd) < 0)
  {
    fprintf(stderr,"Pipe error\n");
    exit(1);
  }
  if (pipe(fd2) < 0)
  {
    fprintf(stderr,"Pipe error\n");
    exit(1);
  }
  if(pid=fork()>0)
  {
    close(fd[READ]);
    close(fd2[WRITE]);
    printf("Escreva um número: ");
    scanf("%lf",&numero.a);
    printf("Escreva o segundo numero: ");
    scanf("%lf",&numero.b);
    write(fd[WRITE],&numero,sizeof(numero));
    /*read(fd2[READ],tipo,3);
    if(strncmp(tipo,"int",3)==0)
    {
      int a,b;
      read(fd2[READ],&a,sizeof(int));
      read(fd2[READ],&b,sizeof(int));
    }
    else if(strncmp(tipo,"flo",3)==0)
    {
      double a,b;
      read(fd2[READ],&a,sizeof(float));
      read(fd2[READ],&b,sizeof(float));
    }
    else if(strncmp(tipo,"inv",3)==0)
    {
      fprintf(stderr, "Error, invalido\n");
    }*/
    wait(NULL);
  }
  else if(pid==0)
  {
    close(fd2[READ]);
    close(fd[WRITE]);
    read(fd[READ],&numero,sizeof(numero));
    if(numero.b==0)
    {
      write(fd2[WRITE],"inv",3);
      exit(0);
    }
    int aa=(int)numero.a;
    int bb=(int)numero.b;
    if(aa!=numero.a || bb!=numero.b)
    {
      write(fd2[WRITE],"flo",3);
      write(fd2[WRITE],&numero.a,sizeof(float));
      write(fd2[WRITE],&numero.b,sizeof(float));
    }
    else
    {
      write(fd2[WRITE],"int",3);
      write(fd2[WRITE],&aa,sizeof(int));
      write(fd2[WRITE],&bb,sizeof(int));
    }
    exit(0);
  }
  else
  {
    fprintf(stderr, "Fork error\n");
    exit(2);
  }


  return 0;
}
