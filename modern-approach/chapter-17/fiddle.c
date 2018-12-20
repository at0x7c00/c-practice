#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *read_line();
int main(void){
  char *p = read_line();
  printf("length of input :%d\n",strlen(p));
  printf("%s",p);
  free(p);
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
