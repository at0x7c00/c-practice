#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void){
  pid_t pid = fork();
  pid_t pid2;
  int status;

  if(pid == 0){
    sleep(15);
    return 100;
  }else{
    printf("pid = %d\n",pid);
    while(!waitpid(pid,&status,WNOHANG)){
      sleep(3);
      puts("waiting for child process end.");
    }
    if(WIFEXITED(status)){
      printf("child process return value:%d\n",WEXITSTATUS(status));
    }
    return 0;
  }
}
