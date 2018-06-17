#include"apue.h"
#include<dirent.h>

void printdir(char *dir,int level);
int isFile(const char* name);

void main(int argc, char *argv[]){
	

	if(argc != 2){
		err_quit("usage:ls director_name");
	}

	printdir(argv[1],0);	
}

void printdir(char *file_name,int level){
	if(isFile(file_name)){
		return;
	}
	DIR *dp;
	struct dirent *dirp;
	int i;
	//printf("try to open file:%s",file_name);
	if( (dp = opendir( file_name )) == NULL){
		//err_sys("can't open %s",file_name);
	}

	while( (dirp = readdir(dp)) != NULL){
		for(i = 0;i < level;i++){
			printf(" ");
		}
		printf("%s\n",dirp->d_name);
		file_name = strcat(file_name,"/");
		//printf(">>>%s",file_name);
		printdir(strcat(file_name,dirp->d_name),++level);
	}

	closedir(dp);
}


int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return 0;
    }

    return 1;
}