#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_map(char map[10][10]);
void init_map(char map[10][10]);
void move(char map[10][10],int *row,int *col,int dir,char c);
int can_move(char map[10][10],int row,int col);
int can_move_to_dir(char map[10][10],int row,int col,int dir);
int main(void){
  char map[10][10] = {};
  init_map(map);
  //设置种子
  srand((unsigned)time(0));

  int row = 0,col = 0;//起点
  char start = 'A';
  map[row][col] = start;
  while(can_move(map,row,col)){
    int dir = rand() % 4;
    while(!can_move_to_dir(map,row,col,dir)){
      dir = rand() % 4;
    }
    start++;
    if(start==('Z' + 1)){
      start = 'a';
    }
    move(map,&row,&col,dir,start);
  }

  print_map(map);
  return 0;
}

void move(char map[10][10],int *row,int *col,int dir,char c){
  switch(dir){
    case 0:(*row)--;break;
    case 1:(*col)++;break;
    case 2:(*row)++;break;
    case 3:(*col)--;break;
  }
  map[*row][*col] = c;
}
void print_map(char map[10][10]){
  int i = 0;
  for(;i<10;i++){
    int j = 0;
    for(;j<10;j++){
      printf("  %c  ",map[i][j]);
    }
    printf("\n");
  }
}

void init_map(char map[10][10]){
  int i = 0;
  for(;i<10;i++){
    int j = 0;
    for(;j<10;j++){
      map[i][j] = '.';
    }
  }
}

int can_move(char map[10][10],int row,int col){
  if(row - 1 >= 0 && map[row - 1][col] == '.'){//up
    return 1;
  }
  if(row + 1 < 10 && map[row + 1][col] == '.'){//down
    return 1;
  }
  if(col - 1 >= 0 && map[row][col - 1] == '.'){//left
    return 1;
  }
  if(col + 1 < 10 && map[row][col + 1] == '.'){//right
    return 1;
  }
  return 0;
}

int can_move_to_dir(char map[10][10],int row,int col,int dir){
  if(dir == 0 && row - 1 >= 0 && map[row - 1][col] == '.'){//up
    return 1;
  }
  if(dir == 1 && col + 1 < 10 && map[row][col + 1] == '.'){//right
    return 1;
  }
  if(dir == 2 && row + 1 < 10 && map[row + 1][col] == '.'){//down
    return 1;
  }
  if(dir == 3 && col - 1 >= 0 && map[row][col - 1] == '.'){//left
    return 1;
  }
  return 0;
}
