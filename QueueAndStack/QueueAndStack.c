#include <stdio.h>
#include <stdlib.h>
#include "QueueAndStack.h"

void stack_test();
void queue_test();

int main(int argc, char * argv[])
{
    stack_test();
    queue_test();
}

void stack_test(){
    printf("this is stack test\n");
    struct ListNode * stack = stack_init();
    int i = 0;
    for(i=0;i<5;i++)
        push(stack,i);
    for(i=0;i<5;i++)
    {
        struct ListNode * t = pop(stack);
        printf("%d ",t->val);
        free(t);
    }
    destroy_stack(stack);
}

void queue_test(){
    printf("this is queue test\n");
    struct ListNode * queue = queue_init();
    int i = 0;
    for(i=0;i<5;i++)
        enqueue(queue,i);
    for(i=0;i<5;i++)
    {
        struct ListNode * t = dequeue(queue);
        printf("%d ",t->val);
        free(t);
    }
    destroy_queue(queue);
}

/*enqueue at rear, dequeue at head*/

struct ListNode * enqueue(struct ListNode * head,int val){
    struct ListNode * node = malloc(sizeof(struct ListNode));
    node -> val = val;
    struct ListNode * p = head;
    while(p->next != NULL)
        p = p->next;
    p->next = node;
    node->next = NULL;
}

struct ListNode * dequeue(struct ListNode * head){
    if(head->next == NULL)
        return NULL;
    struct ListNode * ret = head->next;
    head->next = ret->next;
    return ret;
}

int peek_queue(struct ListNode * head){
    if(head->next == NULL)
    {
        printf("this queue is empty\n");
        return -1;
    }
    return (head->next)->val;
}

struct ListNode * queue_init(){
    struct ListNode * head = malloc(sizeof(struct ListNode));
    head->val = -1;
    head->next = NULL;
    return head;
}

void destroy_queue(struct ListNode * head){
    while(1){
        struct ListNode * temp = dequeue(head);
        if(temp==NULL){
            break;
        }
        else{
            free(temp);
        }
    }
    free(head);
}


/*pop at head,push at head*/

struct ListNode * pop(struct ListNode * head){
    if(head->next==NULL)
        return NULL;
    struct ListNode * node = head->next;
    head->next = node->next;
    return node;
}

void push(struct ListNode * head,int val){
    struct ListNode * node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = head->next;
    head->next = node;
}

int peek_stack(struct ListNode * head){
    if(head->next==NULL)
    {
        printf("there is no node\n");
        return 0;
    }
    int ret = (head->next)->val;
    return ret;
}

struct ListNode * stack_init(){
    struct ListNode * head = malloc(sizeof(struct ListNode));
    head->val = -1;
    head->next = NULL;
    return head;
}

void destroy_stack(struct ListNode * head){
    while(1){
        struct ListNode * temp = pop(head);
        if(temp == NULL)
            break;
        else
            free(temp);
    }
      free(head);
}
















