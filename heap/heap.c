#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void pop_helper(struct heap * h,int po);


int main()
{
    int i = 0;
    int test[10];
    struct heap* h = init(10);
    for(i=0;i<10;i++)
    {
       int a = rand()%100;
       test[i] = a;
       printf("%d,",a);
       insert(h,a);
    }
    int * p = h -> data;
    for(i=0;i<11;i++)
    {
       printf("%d,",p[i]);
    }
    printf("\nnow pop\n");
    for(i=0;i<10;i++)
    {
       int t = pop(h);
       printf("%d,",t);
    }
    delete(h);
}

struct heap * init(int capacity){
    struct heap * h = malloc(sizeof(struct heap));
    h -> capacity = capacity;
    h -> temp_num = 0;
    int * data = malloc(sizeof(int)*(capacity+1));
    h -> data = data;
    (h->data)[0] = -1;
    (h->temp_num) = 1;
    return h;
}

void delete(struct heap * h){
    free(h->data);
    free(h);
}
   
void insert(struct heap * h,int number){
    int t = h->temp_num;
    if(t >= (h->capacity +1))
    {
        printf("heap is full , insert fail\n");
        return;
    }
    (h->temp_num)+=1;
    int * p = h -> data;
    p[t] = number;
    while(p[t] < p[t/2]){
        int temp = p[t];
        p[t] = p[t/2];
        p[t/2] = temp;
        t = t/2;
    }
}


int pop(struct heap * h){
    int t = (h->data)[1];
    pop_helper(h,1);
    return t;
}


void pop_helper(struct heap * h, int po){
    int left = po * 2;
    int right = po * 2 + 1;
    int n = h -> temp_num;
    if((left>n) && (right>n))                 //no child
    {
        (h->temp_num) -= 1;
        return;
    }
    else if(right <= n)                       //two children
    {
        int * p = h->data;
        int left_num = p[left];
        int right_num = p[right];
        if(left_num<right_num)
        {
            p[po] = left_num;
            (h->temp_num)-=1;
            pop_helper(h,left);
        }
        else{
            p[po] = right_num;
            (h->temp_num)-=1;
            pop_helper(h,right);
        }
    }
    else{                                         //only left child
        int * p= h->data;
        p[po]=p[left];
        p[left]=0;
        (h->temp_num)-=1;
    }
}













