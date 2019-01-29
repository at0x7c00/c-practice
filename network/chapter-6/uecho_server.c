/*
* echo server use UDP
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define MAX_MSG_LEN 1024
void error_handling(char *message);
int main(int argc,char *argv[]){
  int server_socket;

  struct sockaddr_in server_addr,client_addr;
  socklen_t client_addr_len;

  char message[MAX_MSG_LEN];

  if(argc != 2){
    printf("Usage : %s <port>\n",argv[0]);
    return 1;
  }

  server_socket = socket(PF_INET,SOCK_DGRAM,0);
  if(server_socket == -1){
    error_handling("socket() error");
  }

  memset(&server_addr,0,sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));

  if(bind(server_socket,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1){
    error_handling("bind() error");
  }

  while(1){
    client_addr_len = sizeof(client_addr);
    int len = recvfrom(server_socket,message,MAX_MSG_LEN,0,(struct sockaddr*)&client_addr,&client_addr_len);

    sendto(server_socket,message,len,0,(struct sockaddr*)&client_addr,client_addr_len);
    message[len] = '\0';
    printf("%s\n",message);

    if(strcmp("Q",message)==0){
      break;
    }
  }

  close(server_socket);

  return 0;
}

void error_handling(char *message){
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}
