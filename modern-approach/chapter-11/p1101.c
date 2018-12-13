#include<stdio.h>
int do_pay(int total,int amount,int *res);
void pay_amount(int dollars,int *tw,int *t,int *f,int *o);
int main(void){
    int amount;
    int count_20 = 0;
    int count_10 = 0;
    int count_5 = 0;
    int count_1 = 0;
    printf("Enter a dollar amount:");
    scanf("%d",&amount);

    pay_amount(amount,&count_20,&count_10,&count_5,&count_1);
    printf("20:%d\n", count_20);
    printf("10:%d\n", count_10);
    printf("5:%d\n", count_5);
    printf("1:%d\n", count_1);
    return 0;
}

void pay_amount(int amount,int *tw,int *t,int *f,int *o){
  amount = do_pay(amount,20,tw);
  amount = do_pay(amount,10,t);
  amount = do_pay(amount,5,f);
  amount = do_pay(amount,1,o);
}

int do_pay(int total,int amount,int *res){
    int count = 0;
    if(total >= amount){
        count = total / amount ;
        //printf("$%d bills:%d\n",amount,count);
        *res = count;
        total = total - count * amount;
        return total;
    }else{
        //printf("$%d bills:0\n",amount);
        return total;
    }
}
