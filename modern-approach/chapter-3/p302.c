#include<stdio.h>
int main(void){
    int num;
    float price;
    int y,m,d;
    
    printf("Enter item number:");
    scanf("%d",&num);
    printf("Enter unit price:");
    scanf("%f",&price);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d",&m,&d,&y);

    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");

    printf("%d\t$%7.2f\t%d/%d/%d\n",num,price,m,d,y);

    return 0;
}
