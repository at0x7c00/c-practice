#include<stdio.h>
int getlinex(char s[],int lim);
void copystr(char from[],char to[]);
main(){

	int len;
	int max;
	char line[10000];
	char longestline[10000];	

	while((len = getlinex(line,10000))>0){
		if(len > max){
			copystr(line,longestline);
			max = len;
		}
	}

	printf("max line is :\n%s\n",longestline);

}

int getlinex(char s[],int lim){
	int i;
	char c;
	for(i =0;i<lim && (c=getchar())!=EOF && c !='\n';i++){
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}
void copystr(char from[],char to[]){
	int i = 0;
	while((to[i]=from[i])!='\0'){
		i++;
	}
}