#include<stdio.h>

#define PI 3.1415926
int main(void){
    int r = 0;
    float volumn = 0.0f;
    printf("Input radius of sphere:");
    scanf("%d",&r);
    volumn = (4.0f/4.0f) * PI * r * r;
    printf("Volumn of this sphere is :%.2f\n",volumn);
    return 0;
}
