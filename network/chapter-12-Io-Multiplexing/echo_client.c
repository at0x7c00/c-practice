#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define MAX_MSG_LEN 1024
void error_handling(char *message);
int read_line(char *message,int max);
int main(int argc,char* argv[]){
  int sock;
  struct sockaddr_in server_addr;
  char message[MAX_MSG_LEN];
  int str_len;

  if(argc != 3){
    printf("Usage : %s <IP> <port>\n",argv[0]);
    return 1;
  }

  sock = socket(PF_INET,SOCK_STREAM,0);
  if(sock == -1){
    error_handling("socket() error");
  }

  memset(&server_addr,0,sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(atoi(argv[2]));

  if(connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1){
    error_handling("connect() error");
  }
  puts("connected...");
  while(1){
    int len = read_line(message,MAX_MSG_LEN);
    write(sock,message,len);
    str_len = read(sock,message,MAX_MSG_LEN);
    message[str_len] = '\0';
    if(strcmp(message,"Q")==0){
      break;
    }
    printf("%s\n",message);
  }

  if(str_len == -1){
    error_handling("read() error");
  }
  //printf("Message from server:%s\n",message);
  close(sock);
  return 0;
}

void error_handling(char *message){
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}

int read_line(char *message,int max){
  int ch;
  int count = 0;
  while((ch = getchar())!='\n' && ch != EOF){
    message[count++] = ch;
  }
  return count;
}
