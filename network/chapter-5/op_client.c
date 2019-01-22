#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define OPT_SIZE 4
#define MSG_LEN 300
void error_handling(char *message);
int main(int argc,char* argv[]){
  int sock;
  char data[MSG_LEN];
  int params_count;
  int result;
  struct sockaddr_in server_addr;
  if(argc != 3){
    printf("Usage:%s <IP> <PORT>\n",argv[0]);
    return 0;
  }

  sock = socket(PF_INET,SOCK_STREAM,0);
  if(sock == -1){
    error_handling("socket() error");
  }

  memset(&server_addr,0,sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(atoi(argv[2]));



  if(connect(sock,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1){
    error_handling("connect() error");
  }else{
    puts("Connected...");
  }

  while(1){
    fputs("Input params count:",stdout);
    scanf("%d",&params_count);
    data[0] = (char)params_count;

    int i = 0;
    for(;i<params_count;i++){
      printf("Input Param %d:",i+1);
      scanf("%d",(int *)&data[OPT_SIZE*i+1]);
    }
    fgetc(stdin);
    printf("Input Operator:");
    scanf("%c",data + OPT_SIZE*params_count+1);

    write(sock,data,OPT_SIZE*params_count+2);

    read(sock,&result,OPT_SIZE);

    printf("Result from server:%d\n",result);
  }

}

void error_handling(char *message){
  fputs(message,stderr);
  fputc('\n',stderr);
  exit(1);
}
