#include<stdio.h>
int do_pay(int total,int amount);
int main(void){
    int amount;
    int count_20 = 0;
    int count_10 = 0;
    int count_5 = 0;
    int count_1 = 0;
    printf("Enter a dollar amount:");
    scanf("%d",&amount);
    amount = do_pay(amount,20);
    amount = do_pay(amount,10);
    amount = do_pay(amount,5);
    amount = do_pay(amount,1);
    return 0;
}
int do_pay(int total,int amount){
    int count = 0;
    if(total > amount){
        count = total / amount ;
        printf("$%d bills:%d\n",amount,count);
        total = total - count * amount;
        return total;
    }else{
        printf("$%d bills:0\n",amount);
        return total;
    }
}
