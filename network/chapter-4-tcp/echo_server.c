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
  int client_socket;

  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  socklen_t client_addr_size;

  char message[MAX_MSG_LEN];

  if(argc != 2){
    printf("Usage : %s <port>\n",argv[0]);
    return 1;
  }

  server_socket = socket(PF_INET,SOCK_STREAM,0);
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

  if(listen(server_socket,5) == -1){
    error_handling("listen() error");
  }

  client_addr_size = sizeof(client_addr);
  client_socket = accept(server_socket,
                         (struct sockaddr *)&client_addr,&client_addr_size);

  if(client_socket == -1){
    error_handling("accpet() error");
  }

  while(1){
    ssize_t len = read(client_socket, message, MAX_MSG_LEN);
    if(strcmp("Q",message)==0){
      break;
    }
    write(client_socket,message,len);
    message[len] = '\0';
    printf("%s\n",message);
  }


  close(client_socket);
  close(server_socket);

  return 0;
}

void error_handling(char *message){
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}
