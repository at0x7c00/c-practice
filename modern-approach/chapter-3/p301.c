#include<stdio.h>
int main(void){
    int y,m,d;

    printf("Enter a date (mm/dd/yyyy):");
    scanf("%d/%d/%d",&m,&d,&y);
    printf("You entered the date %d/%d/%d\n",m,d,y);

    return 0;
}
