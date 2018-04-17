#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define STDERR 2
#define NUMITER 10000
void * thrfunc(void * arg)
{
 int i;
 fprintf(stderr, "Starting thread %d\n", *(int*) arg);
 char str[12];
 sprintf(str,"%d",*(int*)arg);
 for (i = 1; i <= NUMITER; i++) write(STDERR,str,strlen(str));
 return NULL;
}
int main()
{
 pthread_t ta, tb;
 int i=1;
 pthread_create(&ta, NULL, thrfunc, &i);
 //i=2;
 //pthread_create(&tb, NULL, thrfunc, &i);
 pthread_join(ta, NULL);
 //pthread_join(tb, NULL);
 return 0;
}
