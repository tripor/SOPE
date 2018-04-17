#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  clock_t relogio;
  struct tms tempos;
  srand(10);
  int random_number=0,i=0;
  while(random_number!=atoi(argv[2]))
  {
    random_number=rand() % atoi(argv[1]);
    printf("Random number: %d, iteração: %d\n",random_number,i);
    i++;
  }
  sysconf (_SC_CLK_TCK);
  times(&tempos);
  printf("Tempo gasto no processo: %ld\nTempo gasto sistema: %ld\n",tempos.tms_utime, tempos.tms_stime);
  exit(0);
}
