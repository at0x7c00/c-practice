#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define TRUE 1
#define FALSE 0
#define DATA_LEN 50
#define OPT_SIZE 4
void error_handling(char *message);
int calcute_result(int data[],int len,char operator);
int main(int argc,char * argv[]){
  int sock;
  int client_sock;
  int params_count;
  char operator;
  int data[DATA_LEN];
  int result;
  socklen_t addr_len;

  int option;
  socklen_t oplen;

  struct sockaddr_in server_addr;
  if(argc != 2){
    printf("Usage %s <PORT>\n",argv[0]);
    return 1;
  }
  sock = socket(PF_INET,SOCK_STREAM,0);

  option = TRUE;
  oplen = sizeof(option);
  setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,(void *)&option,oplen);

  memset(&server_addr,0,sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));

  if(bind(sock,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1){
    error_handling("bind() error");
  }

  if(listen(sock,5) == -1){
    error_handling("listen() error");
  }

  addr_len = sizeof(server_addr);
  client_sock = accept(sock,(struct sockaddr*)&server_addr,&addr_len);
  while(1){
      if(client_sock == -1){
        printf("accept() error.");
        continue;
      }
      read(client_sock,&params_count,1);
      int i = 0;
      printf("Params Count:%d\n",params_count);
      for(;i<params_count;i++){
        read(client_sock,data+i,OPT_SIZE);
        printf("Param %d=%d\n",i+1,data[i]);
      }
      read(client_sock,&operator,1);
      printf("Operator:%c\n",operator);

      result = calcute_result(data,params_count,operator);
      printf("Result=%d\n",result);
      write(client_sock,(char *)&result,sizeof(result));
  }

}

void error_handling(char *message){
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}
int calcute_result(int data[],int len,char operator){
  int res = data[0];
  int i = 1;
  switch(operator){
    case '+':
    for(;i<len;i++){
      res += data[i];
    }
    break;
    for(;i<len;i++){
      res -= data[i];
    }
    case '-':
    break;
    for(;i<len;i++){
      res *= data[i];
    }
    case '*':
    break;
  }
  return res;

}
