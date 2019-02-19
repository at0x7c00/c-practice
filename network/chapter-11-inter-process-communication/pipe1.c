#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(void){
  int fds[2];
  char str[] = "Who are you?";
  pid_t pid;
  char buf[BUF_SIZE];

  pipe(fds);

  pid = fork();

  if(pid == 0){
    write(fds[1],str,sizeof(str));
  }else{
    read(fds[0],buf,BUF_SIZE);
    puts(buf);
  }
  
  return 0;
}
