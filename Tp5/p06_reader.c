#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
int readline(int fd, char *str);
int main(void)
{
 int fd;
 char str[100];
 mkfifo("/tmp/myfifo",0660);
 fd=open("/tmp/myfifo",O_RDONLY);
 while(readline(fd,str)) printf("%s",str);
 close(fd);
 return 0;
}
int readline(int fd, char *str)
{
 int n;
 do {
   n = read(fd,str,1);
   printf("|%s|\n",str);
 } while (n>0 && *str++ != '\0');
 return (n>0);
}
