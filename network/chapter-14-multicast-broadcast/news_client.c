#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define MAX_MSG_LEN 100
int read_line(char buf[]);
int main(int argc,char *argv[]){

  int recv_sock;
  struct sockaddr_in addr;
  struct ip_mreq join_addr;

  int str_len;
  char buf[MAX_MSG_LEN];

  recv_sock = socket(PF_INET,SOCK_DGRAM,0);
  memset(&addr,0,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(atoi(argv[2]));

  ///int bind_res = bind(recv_sock,(struct sockaddr *)&addr,sizeof(addr));
  //if(bind_res == -1){
  //  printf("bind() error");
  //  exit(0);
  //}

  join_addr.imr_multiaddr.s_addr = inet_addr(argv[1]);
  join_addr.imr_interface.s_addr = htonl(INADDR_ANY);

  setsockopt(recv_sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&join_addr,sizeof(join_addr));
  while(1){
    str_len = recvfrom(recv_sock,buf,MAX_MSG_LEN - 1,0,NULL,0);
    if(str_len < 0){
      break;
    }
    buf[str_len] = '\0';
    fputs(buf,stdout);
    fputs("\n",stdout);
  }
  close(recv_sock);
  return 0;
}

int read_line(char buf[]){
  char c;
  int i = 0;
  while((c = getchar())!=-1){
    buf[i++] = c;
  }
  buf[i] = '\0';
  return i;
}
