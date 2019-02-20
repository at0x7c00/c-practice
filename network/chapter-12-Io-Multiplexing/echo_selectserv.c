#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<sys/select.h>
void error_handling(char *message);
#define BUF_SIZE 100

int main(int argc,char *argv[]){
  //to build connection
  int serv_sock,clnt_sock;
  struct sockaddr_in serv_adr,clnt_adr;
  socklen_t adr_sz;
  //select
  int fd_max;
  struct timeval timeout;
  int select_res,fd_num;
  fd_set reads,cpy_reads;
  //read and write data
  int str_len;
  char buf[BUF_SIZE];

  if(argc!=2){
    printf("Usage:%s <port>",argv[0]);
    exit(1);
  }

  serv_sock = socket(PF_INET,SOCK_STREAM,0);
  if(serv_sock == -1){
    error_handling("sock() error");
  }

  memset(&serv_adr,0,sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  if(bind(serv_sock,(const struct sockaddr *)&serv_adr,sizeof(serv_adr)) == -1){
    error_handling("bind() error");
  }

  if(listen(serv_sock,5) == -1){
    error_handling("listen() error");
  }

  FD_ZERO(&reads);
  FD_SET(serv_sock,&reads);
  fd_max = serv_sock;


  while(1){

    cpy_reads = reads;
    timeout.tv_sec = 5;
    timeout.tv_usec = 5000;

    select_res = select(fd_max+1,&cpy_reads,0,0,&timeout);
    if(select_res == -1){
      error_handling("select() error");
    }
    if(select_res == 0){
      puts("select timeout.");
      continue;
    }
    for(fd_num = 0;fd_num < fd_max + 1;fd_num++){
      if(FD_ISSET(fd_num,&cpy_reads)){
          if(fd_num == serv_sock){
            adr_sz = sizeof(clnt_sock);
            clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&adr_sz);
            FD_SET(clnt_sock,&reads);
            if(fd_max<clnt_sock){
              fd_max = clnt_sock;
            }
            printf("client connected:%d\n",clnt_sock);
          }else{
            str_len = read(fd_num,buf,BUF_SIZE);
            if(str_len == 0){//read EOF,close connection
              FD_CLR(fd_num,&reads);
              close(fd_num);
              printf("close connection:%d\n",fd_num);
            }else{
              write(fd_num,buf,str_len);
            }
          }
      }
    }// end for
  }//end while
  close(serv_sock);
  return 0;
}

void error_handling(char *message){
  fputs(message,stderr);
  fputs("\n",stderr);
  exit(1);
}
