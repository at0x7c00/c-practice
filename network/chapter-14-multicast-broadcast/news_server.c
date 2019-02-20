#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define MAX_MSG_LEN 100
int read_line(char buf[]);
int main(int argc,char *argv[]){
  int serv_sock;
  struct sockaddr_in mul_adr;

  int str_len;
  char buf[MAX_MSG_LEN];

  int time_live = 64;

  serv_sock = socket(PF_INET,SOCK_DGRAM,0);
  memset(&mul_adr,0,sizeof(mul_adr));
  mul_adr.sin_family = AF_INET;
  mul_adr.sin_addr.s_addr = inet_addr(argv[1]);
  mul_adr.sin_port = htons(atoi(argv[2]));

  setsockopt(serv_sock,IPPROTO_IP,IP_MULTICAST_TTL,(void*)&time_live,sizeof(time_live));

  while(1){
    str_len = read_line(buf);
    printf("readLine:%s %d",buf,str_len);
    int res = sendto(serv_sock,buf,str_len,0,(struct sockaddr*)&mul_adr,sizeof(mul_adr));
  }
  close(serv_sock);
  return 0;
}

int read_line(char buf[]){
  char c;
  int i = 0;
  while((c = getchar())!='\n' && c != EOF){
    buf[i++] = c;
  }
  buf[i] = '\0';
  return i;
}
