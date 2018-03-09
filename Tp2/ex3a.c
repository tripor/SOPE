#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
int main(int argc, char const *argv[])
{
  clock_t begin = clock();

  int desc_ler,desc_escrever;
  char car[1];
  desc_ler=open(argv[1],O_RDONLY);
  if(desc_ler!=-1)
  {
      while(read(desc_ler,car,1) && car!=NULL)
      {
        write(STDOUT_FILENO,car,1);
      }
    close(desc_ler);
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
