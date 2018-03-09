#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void lerTeclado(char* guardar)
{
  char ler[1],ns,devolver[1000]="\0";
  int i=0;
  read(STDIN_FILENO,ler,1);
  do
  {
    devolver[i]=ler[0];
    i++;
    strcat(devolver,&ns);
    read(STDIN_FILENO,ler,1);
  }while(ler[0]!='\n' && ler[0]!=' ');
  devolver[i]='\0';
  strcpy(guardar,devolver);

}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    int desc_escrever,n,i;
    char car[100]="",clas[2];
    desc_escrever=open(argv[1],O_WRONLY);
    if(desc_escrever!=-1)
    {
      lerTeclado(car);
      n=atoi(car);
      for(i=1;i<=n;i++)
      {
        lerTeclado(car);
        write(desc_escrever,car,strlen(car));
        write(desc_escrever," ",1);
        lerTeclado(car);
        write(desc_escrever,car,strlen(car));
        write(desc_escrever,"\n",1);
      }
      close(desc_escrever);
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
