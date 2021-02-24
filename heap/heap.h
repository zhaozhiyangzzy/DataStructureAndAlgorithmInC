#include <stdio.h>

struct heap{
    int capacity;
    int temp_num;
    int * data;
};

struct heap * init(int capacity);
void insert(struct heap *h,int number);
int pop(struct heap * h);
void delete(struct heap * h);
