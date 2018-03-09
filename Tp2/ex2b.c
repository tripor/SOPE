#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define MAX_PASSWD_LEN 20
int main(int argc, char const *argv[])
{
  clock_t begin = clock();


  int desc_ler,desc_escrever;
  char car[1];
  desc_ler=open(argv[1],O_RDONLY);
  if(desc_ler!=-1)
  {
    desc_escrever=open(argv[2],O_WRONLY);
    if(desc_escrever!=-1)
    {
      while(read(desc_ler,car,1) && car!=NULL)
      {
        write(desc_escrever,car,1);
      }
      close(desc_ler);
      close(desc_escrever);
    }
    else
    {
      write(STDOUT_FILENO,"Aconteceu um erro na abertura do ficheiro 2",strlen("Aconteceu um erro na abertura do ficheiro 2"));
      exit(0);
    }
  }
  else
  {
    write(STDOUT_FILENO,"Aconteceu um erro na abertura do ficheiro",strlen("Aconteceu um erro na abertura do ficheiro"));
    exit(0);
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("tempo:%lf\n",time_spent);

}
