#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<errno.h>
#include<fcntl.h>
#define BUF_SIZE 100
#define EPOLL_SIZE 50
void error_handling(char * message);
void setnonblockingmode(int fd);
int main(int argc,char * argv[]){
  //socket
  int serv_sock,clnt_sock;
  struct sockaddr_in server_addr,clnt_addr;
  socklen_t adr_sz;

  //read/write date
  int str_len;
  char buf[BUF_SIZE];

  //epoll
  int epfd;
  struct epoll_event event;
  struct epoll_event *ep_events;
  int event_cnt;
  int i;

  if(argc != 2){
    printf("Usage:%s  <port>\n",argv[0]);
    exit(1);
  }

  memset(&server_addr,0,sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));

  serv_sock = socket(PF_INET,SOCK_STREAM,0);
  if(bind(serv_sock,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1){
    error_handling("bind() error");
  }

  if(listen(serv_sock,5) == -1){
    error_handling("listen() error");
  }
  //create epoll file descriptor
  epfd = epoll_create(EPOLL_SIZE);
  //register server socket in epoll event
  event.events = EPOLLIN;
  event.data.fd = serv_sock;
  epoll_ctl(epfd,EPOLL_CTL_ADD,serv_sock,&event);

  //create epoll_event to recevie the result that returned by epoll_wait
  ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

  while(1){
    event_cnt = epoll_wait(epfd,ep_events,EPOLL_SIZE,-1);
    if(event_cnt == -1){
      error_handling("epoll_wait() error");
      break;
    }

    for(i = 0;i<event_cnt;i++){
      if(ep_events[i].data.fd == serv_sock){// There is data come from serv_sock
        adr_sz = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock,(struct sockaddr *)&clnt_addr,&adr_sz);
        setnonblockingmode(clnt_sock);
        //register client socket to epoll
        event.events = EPOLLIN|EPOLLET;
        event.data.fd = clnt_sock;
        epoll_ctl(epfd,EPOLL_CTL_ADD,clnt_sock,&event);
        printf("connected client:%d\n",clnt_sock);
      }else{
        while(1){
          // There is data come from client socket
          str_len = read(clnt_sock,buf,BUF_SIZE);
          if(str_len == 0){//close connection
            epoll_ctl(epfd,EPOLL_CTL_DEL,ep_events[i].data.fd,NULL);
            close(ep_events[i].data.fd);
            printf("close client:%d\n",ep_events[i].data.fd);
          }else if(str_len < 0){
            if(errno == EAGAIN){ // Read until EAGAIN!
              break;
            }
          }else{
            printf("receive msg:%s\n",buf);
            write(ep_events[i].data.fd,buf,str_len);
          }
        }
      }//end for receive data from client socket
    }// end for process all file descriptors that returned by epoll_wait
  }//end for while(1)

  close(serv_sock);
  close(epfd);
  return 0;
}

void error_handling(char * message){
  fputs(message,stderr);
  printf("%d %s",errno,strerror(errno));
  fputs("\n",stderr);
  exit(1);
}
void setnonblockingmode(int fd){
  int flag = fcntl(fd,F_GETFL,0);
  fcntl(fd,F_SETFL,flag|O_NONBLOCK);
}
