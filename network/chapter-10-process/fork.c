#include<stdio.h>
#include<unistd.h>
int gval = 10;
int main(void){
  pid_t pid;
  int lval = 20;

  gval++,lval+=5;

  pid = fork();
  if(pid == 0){//child process
    gval += 2;
    lval += 2;
  }else{//parent process
    gval -= 2;
    lval -= 2;
  }

  if(pid == 0){
    printf("Child process:gval=%d,lval=%d\n",gval,lval);
  }else{
    printf("Parent process:gval=%d,lval=%d\n",gval,lval);
  }
  return 0;
}
