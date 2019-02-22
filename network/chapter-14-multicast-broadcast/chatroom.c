#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
/*
send: set IP_MULTICAST_TTL and sendto multicast address with a fixed port
receive:set IP_ADD_MEMBERSHIP and recvfrom multicast address on local fixed port
*/
#define BUF_SIZE 300
int read_line(char message[]);
void error_handling(char *msg);
int main(int argc,char *argv[]){

  int send_sock,recv_sock;
  struct sockaddr_in mul_adr;
  struct sockaddr_in local_adr;
  pid_t pid;

  int time_live = 64;

  char buf[BUF_SIZE];
  int str_len;

  pid = fork();
  printf("pid=%d\n",pid);
  if(pid == 0){//receive process
    printf("receive process...\n");
    struct ip_mreq join_addr;
    recv_sock = socket(PF_INET,SOCK_DGRAM,0);
    //bind to local fixed port
    memset(&local_adr,0,sizeof(local_adr));
    local_adr.sin_family = AF_INET;
    local_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_adr.sin_port = htons(atoi(argv[2]));//fixed port

    if(bind(recv_sock,(struct sockaddr*)&local_adr,sizeof(local_adr)) == -1){
      error_handling("receive process:bind() error.");
    }
    //set IP_ADD_MEMBERSHIP
    join_addr.imr_multiaddr.s_addr = inet_addr(argv[1]);//fixed multicast address
    join_addr.imr_interface.s_addr = htonl(INADDR_ANY); //dynamic local address
    setsockopt(send_sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&join_addr,sizeof(join_addr));

    while(1){
      printf("\n");
      str_len = recvfrom(recv_sock,buf,BUF_SIZE - 1,0,NULL,0);
      if(str_len < 0){
        printf("recevie disconnect.\n");
        break;
      }
      buf[str_len] = '\0';
      printf("<%s",buf);
    }
    close(recv_sock);

    return 0;
  }else{//send process
    send_sock = socket(PF_INET,SOCK_DGRAM,0);

    memset(&mul_adr,0,sizeof(mul_adr));
    mul_adr.sin_family = AF_INET;
    mul_adr.sin_addr.s_addr = inet_addr(argv[1]);//fixed multicast address
    mul_adr.sin_port = htons(atoi(argv[2]));     //fiexed port

    //set TTL
    setsockopt(send_sock,IPPROTO_IP,IP_MULTICAST_TTL,(void*)&time_live,sizeof(time_live));

    while(1){
      str_len = read_line(buf);
      if(strcmp(buf,"Quit-sys") == 0){
        break;
      }
      printf(">%s\n",buf);
      //It's not need to bind,Send data to multicast address directly
      sendto(send_sock,buf,str_len,0,(struct sockaddr *)&mul_adr,sizeof(mul_adr));
    }
    close(send_sock);
    return 0;
  }
}

int read_line(char message[]){
  char ch;
  int count = 0;
  while((ch = getchar()) != '\n' && ch != EOF){
    message[count++] = ch;
  }
  message[count] = '\0';
  return count;
}

void error_handling(char *msg){
  fputs(msg,stderr);
  fputs("\n",stderr);
  exit(1);
}
