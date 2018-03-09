#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <time.h>
#define MAX_PASSWD_LEN 20
int main(int argc, char const *argv[])
{
  clock_t begin = clock();
  FILE *ler,*escrever;
  char car[1];
  ler=fopen(argv[1],"r");
  if(ler!=NULL)
  {
    escrever=fopen(argv[2],"w");
    if(escrever!=NULL)
    {
      while(fread(car,1,1,ler) && car!=NULL)
      {
        fwrite(car,1,1,escrever);
      }
      fclose(ler);
      fclose(escrever);

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
