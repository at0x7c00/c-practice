#include<stdio.h>
// pointer to function
int sum(int,int);
int execute(int sum(int,int),int,int);
int main(void){
  int a = 100,b = 200;
  int c = execute(sum,a,b);
  printf("%d\n",c);
  return 0;
}
int execute(int sum(int,int),int a,int b){
  return sum(a,b);
}
int sum(int a,int b){
  return a + b;
}
