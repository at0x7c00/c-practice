#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define BUF_SIZE 100
void error_handling(char *message);
void clear_childproc(int sig);
int main(int argc,char *argv[]){

  //build connect
  int serv_sock,clnt_sock;
  struct sockaddr_in serv_adr,clnt_adr;
  socklen_t adr_sz;

  //read message
  int str_len;
  char buf[BUF_SIZE];

  //process
  pid_t pid;
  struct sigaction act;

  if(argc != 2){
    printf("Usage: %s <port>\n",argv[0]);
    exit(1);
  }

  //regist single handler
  act.sa_handler = clear_childproc;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGCHLD,&act,0);

  serv_sock = socket(PF_INET,SOCK_STREAM,0);

  memset(&serv_adr,0,sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  if(bind(serv_sock,(struct sockaddr *)&serv_adr,sizeof(serv_adr)) == -1){
    error_handling("bind() error");
  }

  if(listen(serv_sock,5) == -1){
    error_handling("listen() error");
  }

  while(1){
    adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&adr_sz);
    if(clnt_sock == -1){
      continue;
    }else{
      printf("new client connected...\n");
    }
    pid = fork();
    if(pid == -1){
      close(clnt_sock);
      printf("create child process error.");
      continue;
    }
    if(pid == 0){
      close(serv_sock);//close serv_sock who was copy from parent process.
      while((str_len = read(clnt_sock,buf,BUF_SIZE))!=0){
        buf[str_len] = '\0';
        printf("%s\n",buf);
        write(clnt_sock,buf,str_len);
        if(strcmp(buf,"Q") == 0){
          break;
        }
      }
      close(clnt_sock);
      puts("client disconnected...\n");
      return 0;
    }else{
      close(clnt_sock);//close clnt_sock who has bean copy to child process.
    }
  }

  close(serv_sock);
  return 0;
}

void error_handling(char *message){
  fputs(message,stderr);
  fputs("\n",stderr);
  exit(1);
}

void clear_childproc(int sig){
  pid_t pid;
  int status;
  pid = waitpid(-1,&status,WNOHANG);
  printf("remove child process:%d\n",pid);
}
