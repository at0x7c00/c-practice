# Process
## Create process
Create process:
```c
pid_t pid = fork();
if(pid == 0){
  //child process code area
}else{
  //parent process code area
}
```
## Zombie process
To avoid zombie process,parent process must use `wait`(block) or `waitpid`(no-block) to receive the value returned from child process.
```c
pid2 = wait(&status);
if(WIFEXITED(status)){
  printf("child process return value:%d\n",WEXITSTATUS(status));
}
```
## Signal
Use `signal` to regist a hander for signal:
```c
void timeout(int sig){
  if(sig == SIGALRM){
    puts("Time out!");
  }
  alarm(2);
}
...
signal(SIGALRM,timeout);
```
> Signal will wake the process up that blocked by call `sleep`!

Deal with child process end signal:
```c
void read_childproc(int sig){
  int status;
  if(sig == SIGCHLD){
    printf("child ended!\n");
    waitpid(-1,&status,WNOHANG);
    if(WIFEXITED(status)){
      printf("child process return value:%d\n", WEXITSTATUS(status));
    }
  }
}
...
signal(SIGCHLD,read_childproc);
```
Or use `sigaction`:
```c
struct sigaction act;
act.sa_handler = read_childproc;
sigemptyset(&act.sa_mask);
act.sa_flags = 0;
sigaction(SIGCHLD,&act,0);
```
## Inter process communication
Use `pipe` to create input/output file descriptor for a process.
```c
#include<unistd.h>
int pipe(int filedes[2]);
```
filedes[0] is output file descriptor;
filedes[1] is input file descriptor.

Every process can use pipe to write and read data.
> Can only parent and child processes use pipe to communication?
> No,Any process who can get referecce of pipe file descriptor can communication with pipe.
