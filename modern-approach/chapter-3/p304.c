#include<stdio.h>
int main(void){
    int area,prefix,num;
    printf("Enter phone number:[(xxx) xxx-xxxx]:");
    scanf("(%d) %d-%d",&area,&prefix,&num);

    printf("You entered:%d.%d.%d",area,prefix,num);
}
