#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(void) {
  if(fork()>0)
  {
    write(STDOUT_FILENO,"Hello ",6);
  }
  else
  {
    write(STDOUT_FILENO,"world!",6);
  }

  return 0;
}
