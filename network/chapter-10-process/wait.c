#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void){
  pid_t pid = fork();
  pid_t pid2;
  int status;

  if(pid == 0){
    return 100;
  }else{
    printf("pid = %d\n",pid);
    sleep(20);
    pid2 = wait(&status);
    printf("pid2 = %d\n",pid2);
    if(WIFEXITED(status)){
      printf("child process return value:%d\n",WEXITSTATUS(status));
    }
    sleep(5);
    return 0;
  }
}
