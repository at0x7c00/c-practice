#include<stdio.h>
#define NAME_LEN 50
struct catalog_item{
  int stock_number;
  float price;
  int item_type;
  union{
    struct{
      char title[20];
      char author[20];
      int num_page;
    }book;
    struct{
      char design[20];
    }mug;
    struct{
      char design[20];
      int colors;
      int sizes;
    }shirt;
  };
};
void print_catalog(struct catalog_item item);

enum Satisfy {VERY_BAD = 1,BAD,SOSO,GOOD,PERFECT};

void print_satisfy(enum Satisfy s);
int main(void){
  struct {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
  }part1,part2;



  //1 book,2 mug,3 shirt
  struct catalog_item book = (struct catalog_item){
    .stock_number=20,
    .price=15.8,
    .item_type=1,
    .book.title="Hello",
    .book.author="Tom",
    .book.num_page = 299};

    struct catalog_item mug = (struct catalog_item){
    .stock_number=22,
    .price=45.2,
    .item_type=2,
    .mug.design="Hello"};

    struct catalog_item shirt = (struct catalog_item){
    .stock_number=12,
    .price=89,
    .item_type=3,
    .shirt.design="Hello",
    .shirt.colors = 100,
    .shirt.sizes = 180 };

  print_catalog(book);
  print_catalog(mug);
  print_catalog(shirt);

  enum Satisfy x = 6;
  enum Satisfy y = GOOD;

  printf("x = %d,y= %d\n",x,y);
  print_satisfy(x);
  print_satisfy(y);
  return 0;
}

void print_catalog(struct catalog_item item){
  printf("Type:%s\n",item.item_type == 1 ? "Book" : item.item_type == 2 ? "Mug":"Shirt");
  printf("Price:%5.2f\n",item.price);
  printf("Number:%d\n",item.stock_number);

  switch(item.item_type){
  case 1:
  printf("Title:%s\n",item.book.title);
  printf("Author:%s\n",item.book.author);
  printf("Num Page:%d\n",item.book.num_page);
  break;
  case 2:
  printf("Design:%s\n",item.mug.design);
  break;
  printf("Design:%s\n",item.book.title);
  printf("Colors:%d\n",item.shirt.colors);
  printf("Sizes:%d\n",item.shirt.sizes);
  case 3:
  break;
  }

  printf("----------------------\n");

}


void print_satisfy(enum Satisfy s){
  switch(s){
    case GOOD:printf("Good");
  }

}
