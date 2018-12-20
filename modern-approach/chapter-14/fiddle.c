#include<stdio.h>
#define PRINT(n) printf(#n "= %d\n",n)
#define MK_ID(n) in
#define YOUR_NAME(x) #x
int main(void){
  int i = 100,j = 200;
  int MK_ID(1) = 20;//MK_ID(2) = 0,MK_ID(3) = 0;
  PRINT(j/i);
  char *str0 = YOUR_NAME(tom);
  char *str = "Hello,##YOUR_NAME";
  printf("%d\n",in);
  //printf("%d\n",in);
  //printf("%d\n",i3);

  printf("%s\n",str);
  printf("%s\n",str0);

  printf("__LINE__:%d\n",__LINE__);
  printf("__FILE__:%s\n",__FILE__);
  printf("__DATE__:%s\n",__DATE__);
  printf("__TIME__:%s\n",__TIME__);
  printf("__STDC__:%s\n",__STDC__==1?"C89/c99":"Not C89/C99");

  printf("--------------\n");

  printf("__STDC_HOSTED__:%d\n",__STDC_HOSTED__);
  printf("__STDC_VERSION__:%d\n",__STDC_VERSION__);

  printf("__func__:%s\n",__func__);


  return 0;
}
