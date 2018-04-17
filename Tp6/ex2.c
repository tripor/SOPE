#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define STDERR 2
#define NUMITER 10000
void * thrfunc(void * arg)
{
  int i=0;
  while((*(int*)arg)>=0)
  {
    printf("%d ",(*(int*)arg));
    (*(int*)arg)--;
    i++;
  }

  pthread_exit(&i);
}
int main()
{
 pthread_t ta, tb;
 int i=50000;
 void * quantidadeA,*quantidadeB;
 pthread_create(&ta, NULL, thrfunc, &i);
 pthread_create(&tb, NULL, thrfunc, &i);
 pthread_join(ta, &quantidadeA);
 pthread_join(tb, &quantidadeB);
 printf("\n%d %d\n",*(int*)quantidadeA,*(int*)quantidadeB);
 return 0;
}
