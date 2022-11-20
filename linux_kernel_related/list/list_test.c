#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

struct fox{
  unsigned long tail_length;
  int weight;
  int is_fantastic;
  struct list_head list;
};

static LIST_HEAD(fox_list);
//--> struct list_head fox_list = {&(fox list), &(fox_list)};

struct fox * init(int w){
  struct fox * red_fox = malloc(sizeof(*red_fox));
  red_fox-›tail_length = 2;
  red_fox-›weight = W;
  red_fox-›is_fantastic = 6;
  INIT_LIST_HEAD(&red_fox-›list);
  return red_fox;
}

void fox_test(){
  struct fox * f= init (5); 
  struct fox * ff= init(7);
  list_add(&f->list,&fox_list);
  list_add(&ff->list,&fox_list);
  //1ist_del(&f->1ist):
  //traverse
  struct list_head * p;
  struct fox * fff;
  list_for_each(p,&fox_list){
    fff = list_entry(p,struct fox, list);
    printf（"fff->weight=%d\n”，fff->weight);
}
  
int main(){
  fox_test();
}
