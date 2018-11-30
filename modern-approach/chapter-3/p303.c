#include<stdio.h>
int main(void){
   int p,id,code,num,d;
   printf("Enter ISBN:");
   scanf("%d-%d-%d-%d-%d",&p,&id,&code,&num,&d);

   printf("GS1 prefix:%d\n",p);
   printf("Group identifier:%d\n",id);
   printf("Publisher code:%d\n",code);
   printf("Item number:%d\n",num);
   printf("Check digit:%d\n",d);

}
