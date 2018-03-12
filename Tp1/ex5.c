//echo$ ? codigo de retorno do ultimo commando executado

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])
{
  int i=0;
  char* var;
  if(argc==1)
  {
    while(envp[i]!=NULL)
    {
      //printf("%s\n",envp[i]);
      /*if(strncmp(envp[i],"USER=",5)==0)
      {
        printf("Hello %s!\n",envp[i]+5);
        break;
      }*/
      i++;
    }
    var=getenv("PATH");
    if(var!=NULL)
    {
      printf("Hello %s!\n",var);
    }
  }
  else
  {
    printf("Hello %s!\n",argv[1]);
  }
  return 0;
}
