#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define READ     0
#define WRITE    1
struct dados{
  char a[100];
  char b[100];
};
int main(int argc, char const *argv[]) {

  int fd[2],result;
  struct dados numero;
  float result_float;
  char print[1000]="pp";
  pid_t pid;
  if (pipe(fd) < 0)
  {
    fprintf(stderr,"Pipe error\n");
    exit(1);
  }
  if(pid=fork()>0)
  {
    close(fd[READ]);

    write(STDOUT_FILENO,"Escreva um número inteiro: ",strlen("Escreva um número inteiro: "));
    fgets(numero.a,100,stdin);
    write(STDOUT_FILENO,"Escreva o segundo numero inteiro: ",strlen("Escreva o segundo numero inteiro: "));
    fgets(numero.b,100,stdin);
    write(fd[WRITE],&numero,sizeof(numero));
    wait(NULL);
  }
  else if(pid==0)
  {
    close(fd[WRITE]);
    read(fd[READ],&numero,sizeof(numero));
    if(numero.b==0)
    {
      fprintf(stderr,"Error, division by 0\n");
      exit(0);
    }
    printf("a+b:%d\n",atoi(numero.a)+atoi(numero.b));
    printf("a-b:%d\n",atoi(numero.a)-atoi(numero.b));
    printf("a*b:%d\n",atoi(numero.a)*atoi(numero.b));
    printf("a/b:%f\n",atoi(numero.a)/(atoi(numero.b)*1.0));
    exit(0);
  }
  else
  {
    fprintf(stderr, "Fork error\n");
    exit(2);
  }


  return 0;
}
