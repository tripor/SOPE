#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
int main(void)
{
  int fd;
  char *text1="AAAAA";
  char *text2="BBBBB";

  fd = open("f1.txt",O_CREAT|O_TRUNC|O_WRONLY|O_SYNC,0600);
  if(fd==-1)
    exit(1);
  printf("Escrever a primeira string. Press enter");
  getchar();
  if(write(fd,text1,5)==-1)
    exit(2);
  printf("Escrever a primeira string. Press enter");
  getchar();
  if(write(fd,text2,5)==-1)
    exit(3);
  if(close(fd)==-1)
    exit(4);
  return 0;
}
