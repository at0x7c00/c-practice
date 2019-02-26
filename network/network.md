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

# I/O Multiplexing
function `select` can make all fild descriptor together for unified monitoring.
```c
#include<sys/select.h>
#include<sys/time.h>
int select(
  int maxfd,         //count of file descriptors to monitor
  fd_set * readset,  //file descriptors to monitor, see if can read data
  fd_set * writeset, //file descriptors to monitor, see if can write data
  fd_set * exceptset,//file descriptors to monitor, see if an exception has occurred
  const struct timeval * timeout //timeout for select,or it will block until some event hanppen
)
struct timeval {
  long tv_sec;  //seconds
  long tv_usec; //microseconds
}
```
The nice thing about `select` is that it doesn't block. The select function returns only when a client initiates a connection or sends data. At this point, a call to accept does not block, but simply returns.

# Multicast and broadcast
## Set TTL
```c
int send_sock;
int time_live = 64;// ttl
...
send_sock = socket(PF_INET,SOCK_DGRAM,0);
setsocket(send_sock,IPPROTO_IP,IP_MULTICAST_TTL,&time_live,sizeof(time_live));
...
```
## Use socket option to join multicast group
```c
...
int recv_sock;
struct ip_mreq join_adr;
...
recv_sock = socket(PF_INET,SOCK_DGRAM,0);
...
join_adr.imr_multiaddr.s_addr = <multicast_group_addr>;
join_adr.imr_interface.s_addr = <host_to_join_multicast_group>;
setsocket(recv_sockt,IPPROTO_IP,IP_ADDR_MEMBERSHIP,(void*)&join_adr,sizeof(join_adr));
...
```
## Send and receive message
In terms of simple,Send a message to a multicast address(Class D IP address,each of it means a multicast group)  using UDP function `sendto` on the server side.

On the other side,use a UPD socket to listen a multicast address,use `recvfrom` function to recive message.


## Broadcast
Two kinds of broadcast:
* Directed Broadcast: 192.12.34.255
* Local broadcast: 255.255.255.255
Sender:Use UDP , set `SO_BROADCAST` option and send to a broadcast address and a fixed port:
```c
int so_brd = 1;
setsockopt(send_soc,SOL_SOCKET,SO_BROADCAST,(void*)&so_brd,sizeof(so_brd));
```

Receiver: Just use `recvfrom` to listen on a fixed port for UDP message.


# Socket and Standard I/O
There are two kinds of buffer.I/O buffer and Socket buffer.
Using standard I/O function to read and write data is faster than system function.
System functions:
```c
int fd1,fd2;
fd1 = open("news.txt",O_RDONLY);
fd2 = open("cpy.txt",O_WRONLY|O_CREAT|O_TRUNC);
...
read(fd1,buf,sizeof(buf));
...
write(fd2,buf,len);
...
close(fd1);
close(fd2);
```
Standard I/O functions:
```c
FILE * f1;
FILE * f2;
f1 = fopen("news.txt","r");
f2 = fopen("cpy.txt","w);
...
fgets(buf,BUF_SIZE,f1);
...
fputs(buf,f2);
...
fclose(f1);
fclose(f2);
```
Before use standard I/O to read/write socket,we need to transform file descriptor to FILE:
```c
#include<stdio.h>
FILE * fdopen(int fd,const char *mode);
```
FILE also can be transform to file descriptor:
```c
#include<stdio.h>
int fileno(FILE * stream);
```
Then we can use standard I/O to read/write from/to a socket:
```c
int recv_sock;
char message[BUF_SIZE];
...
FILE * readfp = fdopen(recv_sock,"r");
FILE * writefp = fdopen(recv_sock,"w");
...
fgets(message,BUF_SIZE,readfp);
fputs(message,writefp);
fflush(writefp);
...
fclose(readfp);
fclose(writefp);
...
close(recv_sock);
```

# Epoll
Epoll is also file descriptor in nature.use `epoll_create` to create a epoll file descriptor:
```c
#include<sys/epoll.h>
int epoll_create(int size);
```
Then register the file descriptor which need to be monitored into epoll:
```c
#include<sys/epoll.h>
int epoll_ctl(int epfd,int operation,int fd,struct * epoll_event)
```
Available values for operation:
* EPOLL_CTL_ADD
* EPOLL_CTL_DEL
* EPOLL_CTL_MOD
Define of epoll_event:
```c
struct epoll_event event;
event.data.fd = sockfd;
event.events = EPOLLIN;
```
Available values for `events`:
* EPOLLIN:There have data to read in
* EPOLLOUT:The buffer is empty so you can send data
* EPOLLPRI:Received a OOB data
* EPOLLRDHUP:
* EPOLLERR:
* EPOLLET:
* EPOLLONESHOT:
