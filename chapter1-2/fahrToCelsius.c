#include<stdio.h>
float fahrToCelsius(int fahr);

int main(){
	int i;
	printf("fahr\tcelsius\n");
	for(i = 0;i<100;i+=20){

		printf("%d\t%.2f\n",i,fahrToCelsius(i));

	}

	return 0;
}

float fahrToCelsius(int fahr){
	return (fahr - 32) / 1.8;
}