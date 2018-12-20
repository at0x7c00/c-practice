#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *read_line();
struct Message{
  int id;
  char *content;
};
/*****************************************
read line and save to a fixed length array.
********************************************/
int main(void){
  int size;
  printf("Enter message array size:");

  scanf("%d",&size);

  //struct Message *p = calloc(size,sizeof(struct Message));
  struct Message *msgs = malloc(size * sizeof(struct Message));
  int i =1;
  while(i<=size){
    //printf("Enter a message:%d",i);
     char *content = read_line();
     if(strlen(content)==0){
       continue;
     }
     struct Message msg;
     msg.id = i;
     msg.content = content;
     msgs[i - 1] = msg;
     //free(content);
    i++;
  }
  i = 0;
  while(i<size){
    printf("[%d]:%s\n",msgs[i].id,msgs[i].content);
    i++;
  }
  free(msgs);
  return 0;
}
char *read_line(){
  int init_size = 10;
  int count = 0;
  char *p = (char *)malloc(init_size);
  char ch;
  while((ch = getchar())!='\n' && ch != EOF){
    p[count] = ch;
    count++;
    if(count>=init_size-1){
      init_size*=2;
      p = realloc(p,init_size);
      printf("extend space to %d\n",init_size);
    }
  }
  p[count] = '\0';
  return p;
}
