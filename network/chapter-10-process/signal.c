#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
void timeout(int sig){
  if(sig == SIGALRM){
    puts("Time out!");
  }
  alarm(2);
}
void keycontrol(int sig){
  if(sig == SIGINT){
    puts("CTRL+C pressed");
  }
}
void childendup(int sig){
  int status;
  if(sig == SIGCHLD){
    printf("child ended!\n");
    waitpid(-1,&status,WNOHANG);
    if(WIFEXITED(status)){
      printf("child process return value:%d\n", WEXITSTATUS(status));
    }
  }
}
int main(void){
  signal(SIGALRM,timeout);
  signal(SIGINT,keycontrol);
  signal(SIGCHLD,childendup);
  pid_t pid = fork();
  if(pid == 0){
    sleep(1);
    return 256;
  }else{

    alarm(2);
    int i ;
    for(i = 0;i<5;i++){
      puts("wait...");
      sleep(100);
    }
    return 0;
  }
}
