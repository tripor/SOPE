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
struct dados{
  char nomes[100][101];
  int n;
};
int cmpfunc (const void * a, const void * b) {
   return strcmp((char*)a,(char*)b);
}
int readmyline(int desc,char* nome)
{
  char car[1];
  int i=0;
  while(read(desc,car,1) && car!=NULL && car[0]!='\n' )
  {
    nome[i]=car[0];
    i++;
  }
  if(car==NULL || strcmp(nome,"")==0)
  {
    return 1;
  }
  return 0;

}
int main(int argc, char const *argv[])
{
  int desc_ler;
  desc_ler=open(argv[1],O_RDONLY);
  int fd[2],fd2[2];
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
  if(desc_ler!=-1)
  {
    struct dados nome;
    char texto[1000];
    if(fork()>0)
    {
      int i=0;
      int pid;
      if(pid=fork()>0)
      {
        close(fd2[WRITE]);
        dup2(desc_ler,fd2[READ]);
        waitpid(pid,NULL,0);
      }
      else
      {
        close(fd2[READ]);
        dup2(fd2[WRITE],STDOUT_FILENO);
        execlp("cat","cat",argv[1],NULL);
        exit(0);
      }
      /*readmyline(desc_ler,nomes[i]);
      printf("%s\n",nomes[i]);
      i++;
      strcpy(nomes[i],"");
      readmyline(desc_ler,nomes[i]);
      if(strcmp(nomes[i],"")!=0)
        printf("%s\n",nomes[i]);*/
      strcpy(nome.nomes[i],"");
      while(readmyline(desc_ler,nome.nomes[i])==0)
      {
          i++;
          strcpy(nome.nomes[i],"");
      }
      close(fd[READ]);
      i-=2;
      nome.n=i;
      printf("Dados enviados\n");
      write(fd[WRITE],&nome,sizeof(nome));
      wait(NULL);
    }
    else
    {
      close(fd[WRITE]);
      printf("Dados Recebidos\n");
      read(fd[READ],&nome,sizeof(nome));
      qsort(nome.nomes,nome.n,sizeof(*nome.nomes),cmpfunc);
      for(int j=0;j<nome.n;j++)
      {
        printf("%s\n",nome.nomes[j]);
      }
      exit(0);
    }
    close(desc_ler);
  }
  else
  {
      printf("Erro na abertura do ficheiro!\n");
  }
  exit(0);
}
