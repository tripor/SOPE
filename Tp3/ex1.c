#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int global=1;
int main(void) {
 int local = 2;
 if(fork() > 0) {
 printf("1PID = %d; PPID = %d\n", getpid(), getppid());
 global++;
 local--;
 printf("1PID = %d - global = %d ; local = %d\n", getpid(), global, local);
 } else {
 printf("2PID = %d; PPID = %d\n", getpid(), getppid());
 global--;
 local++;
 printf("2PID = %d - global = %d ; local = %d\n", getpid(), global, local);
 }
 return 0;
}
