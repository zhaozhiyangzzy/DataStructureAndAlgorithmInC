#define bool int
#define true 1
#define false 0

struct ListNode{
    int val;
    struct ListNode * next;
};

struct ListNode * enqueue(struct ListNode * head,int val);
struct ListNode * dequeue(struct ListNode head);
int peek_queue(struct ListNode * head);
struct ListNode * queue_init();
void destroy_queue(struct ListNode * head);

struct ListNode * pop(struct ListNode * head);
void push(struct ListNode * head,int val);
int peek_stack(struct ListNode * head);
struct ListNode * stack_init();
void destroy_stack(struct ListNode * head);
  
