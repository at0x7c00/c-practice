#include<stdio.h>
void copy_string(char *from,char *to);
void main(){
	char *a = "I am a teacher";
	char *b= "I am a student";
	copy_string(a,b);
	printf("%s\n",b);
}

void copy_string(char *from,char *to){
	while((*to = *from)!='\0'){
		from++;
		to++;
	}
}