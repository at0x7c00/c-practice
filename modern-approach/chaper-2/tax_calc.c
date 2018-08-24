#include<stdio.h>
#define FEE_RATE 0.05
int main(void){
    float amount;
    printf("Please input amount of Dollor:");
    scanf("%f",&amount);
    amount = amount * (1 + FEE_RATE);
    printf("Amount with tax is : %.2f\n",amount);
    return 0;
}
