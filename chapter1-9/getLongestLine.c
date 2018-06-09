#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITSIZE 5
int getlinex(char s[]);
void copystr(char from[],char to[]);
char *incArray(char s[],int size);
int arraySize(char s[]);
int x(char longestline[]);
int initSize = INITSIZE;
char line[INITSIZE];
char longestline[INITSIZE];	
int initSize2 = INITSIZE;
main(){

	x(longestline);
}

int x(char longestline[]){
	int len = 0;
	int max = 0;
	while((len = getlinex(line))>0){
		printf("max=%d,len=%d\n", max,len);
		if(len > max){
			printf("-----------------------%d,%d\n",initSize2,len);
			if(len > initSize2){
				longestline = incArray(longestline,initSize2);
			}
			copystr(line,longestline);
			max = len;
			printf("*****%d\n", max);
		}
	}

	printf("max line is (%d):\n%s\n",max,longestline);
}

int getlinex(char s[]){
	int i;
	char c;
	for(i =0;(c=getchar())!=EOF && c !='\n';i++){
		if(i>=initSize){
			s = incArray(s,initSize);
			initSize *= 2;
		}
		s[i] = c;
		printf("%d:%c\n",i,c);
	}
	s[i] = '\0';
	return i;
}
void copystr(char from[],char to[]){
	int i = 0;
	while((to[i]=from[i])!='\0'){
		i++;
	}
	to[i] = '\0';
}
char *incArray(char s[],int size){
	printf("try to increment size of array\n");
	char *newArray = (char *)malloc((sizeof(char))*(size*2));
	printf("increment array to size:%d\n",size*2);
	copystr(s,newArray);
	printf("###%s",newArray);
	return newArray;
}

int arraySize(char s[]){
	int i = 0;
	while(s[i++]!='\0'){

	}
	return i;
}