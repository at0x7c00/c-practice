#include<stdio.h>
#include<string.h>
#define MAX_REMINDS  50
#define MAX_MSG 60
int read_line(char *msg,int len);
void printf_remind(char remindmsgs[MAX_REMINDS][MAX_MSG],int number_remind);
int main(void){
  char remindmsgs[MAX_REMINDS][MAX_MSG];
  char msg[MAX_MSG];
  int number_remind = 0;
  int day,i,j;
  char day_str[3];
  while(1){
    if(number_remind>=MAX_REMINDS){
      printf("No space left.");
      break;
    }
    printf("Enter a remind msg(0 to exit):");
    scanf("%2d",&day);
    if(day<=0){
      break;
    }
    read_line(msg,MAX_MSG);
    sprintf(day_str,"%2d",day);
    //查找day的位置i
    for(i=0;i<number_remind;i++){
       if(strcmp(remindmsgs[i],day_str)>0){
         break;
       }
    }
    //腾出位置
    for(j=number_remind;j>i;j--){
      strcpy(remindmsgs[j],remindmsgs[j-1]);
    }
    //插入新的remind项
    printf("write in row:%d\n",i);

    strcpy(remindmsgs[i],day_str);
    strcat(remindmsgs[i],msg);
    number_remind++;
  }
  printf_remind(remindmsgs,number_remind);
  return 0;
}


int read_line(char *msg,int len){
  int i = 0;
  char ch;
  while((ch = getchar())!='\n' && ch != EOF && i < len){
    *msg++ = ch;
    i++;
  }
  *msg = '\0';
  return i;
}

void printf_remind(char remindmsgs[MAX_REMINDS][MAX_MSG],int number_remind){
  //char *p = remindmsgs[0];
  for(int i = 0;i<number_remind;i++){
    printf("%s\n",remindmsgs[i]);
    //p++;
  }
}
