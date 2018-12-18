#include<stdio.h>
char *my_strcpy(char *to,const char *from,int len);
char *my_strcat(char *to,const char *from);
int my_strcmp(const char *to,const char *from);
int my_strlen(const char *s);
void cmp_test(const char *s1,const char *s2);
int main(void){
  char *from = "Hello";
  char to[10];
  char to2[20] = "Hi,";
  my_strcpy(to,from,sizeof(to));
  printf("str:%s\n",to);
  printf("length of str : %d\n",my_strlen(to));

  my_strcat(to2,from);
  printf("str2 : %s\n",to2);
  printf("length of str2 : %d\n",my_strlen(to2));

  char *s1 = "abc";
  char *s2 = "abc";
  char *s3 = "abcd";
  char *s4 = "def";

  cmp_test(s1,s2);
  cmp_test(s1,s3);
  cmp_test(s1,s4);

  cmp_test(s2,s1);
  cmp_test(s3,s1);
  cmp_test(s4,s1);

  return 0;
}

char *my_strcpy(char *to,const char *from,int len){
  int i = 0;
  char *p = to;
  while(i<len){
    *p++ = *from++;
    i++;
  }
  return to;
}

int my_strlen(const char *s){
  const char *p = s;
  while(*p++)
    ;
  return p - s - 1;
}

char *my_strcat(char *to,const char *from){
  int i = 0;
  char *p = to;
  while(*p++)//找到to的'\0'后面
    ;
  p--;//返回到to的'\0'位置
  while(*from){
    *p++ = *from++;
  }
  return to;
}

int my_strcmp(const char *to,const char *from){
  const char *p = to;
  const char *q = from;
  while(*p){
    if(*p != *q){
      return *p - *q > 0 ? 1 : -1;
    }
    q++;
    p++;
    if(!(*q)){//q complate first p > q
      return !(*p) ? 0 : 1;
    }
  }
  return (!*q && !*p) ? 0 : -1;// p compate first so p<q
}

void cmp_test(const char *s1,const char *s2){
  printf("%s compare to %s:%d\n",s1,s2,my_strcmp(s1,s2));
}
