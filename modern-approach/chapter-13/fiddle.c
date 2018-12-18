#include<stdio.h>
int main(void){
  char *p = "Hello";
  //允许下班访问字符数组中的字符
  printf("%s\n", p);
  printf("%c\n", p[0]);
  printf("%c\n", p[1]);

  //
  char str1[] = "Hello";
  char *str2 = "Hello";

  printf("size of str1:%d\n", sizeof(str1));
  printf("size of str2:%d\n", sizeof(str2));
  return 0;
}

int read_line(char str[],int len){
  char ch;
  int i;
  while((ch = getchar())!='\n' && ch != EOF && i<len){
    str[i++] = ch;
  }
  str[i] = '\0'
  return i;
}
