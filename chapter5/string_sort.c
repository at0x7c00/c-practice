#include<stdio.h>
#include<string.h>
void string_sort(char *name[],int n);
void print_str(char *name[],int n);
void main(){
	char *name[] = {"z","a","d","X","A","H"};

	//this is stored in constant area,so cannot write!
	/*
	scanf("%s",name[0]);
	scanf("%s",name[1]);
	scanf("%s",name[2]);
	scanf("%s",name[3]);
	*/
	
	string_sort(name,6);
	print_str(name,6);
}

void string_sort(char *name[],int n){
	int i;
	int j;
	char *tmp;
	for(i = 0;i<n;i++){
		for(j = i+1;j<n;j++){
			if(strcmp(name[j],name[i])<0){
				tmp = name[j];
				name[j] = name[i];
				name[i] = tmp;
			}
		}
	}
}

void print_str(char *name[],int n){
	int i;
	for(i = 0;i<n;i++){
		printf("%s\n", name[i]);
	}
}