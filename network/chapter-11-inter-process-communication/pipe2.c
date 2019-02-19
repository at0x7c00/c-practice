#include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 30

int main(void){
  int fds[2];
  char str[] = "Who are you?";
  char str2[] = "Thank you for your message.";
  pid_t pid;
  char buf[BUF_SIZE];

  pipe(fds);

  pid = fork();

  if(pid == 0){
    write(fds[1],str,sizeof(str));
    sleep(2);
    read(fds[0],buf,BUF_SIZE);
    printf("Parent process output:%s\n",buf);
  }else{
    read(fds[0],buf,BUF_SIZE);
    write(fds[1],str2,sizeof(str2));
    printf("Child process output:%s\n",buf);
    sleep(3);
  }

  return 0;
}
