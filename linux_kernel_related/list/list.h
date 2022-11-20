struct list_head{
  struct list_ head * next; 
  struct list_ head * prev;
};

#define LIST_HEAD_INIT (name) {&(name), & (name) } 
#define container_of (ptr, type, member) ({ \
  const typeof( ((type *0)->member ) *__mptr = (ptr); \
  (type *) ((char *)__mptr - offsetof (type, member));})
#define list_entry(ptr, type, member) \
  container_of (ptr, type, member)

#define LIST_HEAD(name) \
  struct list_head name = LIST_HEAD_INIT(name)

//traverse
#define list_for_each(pos, head) \
  for (pos=(head) ->next; pos!=(head) ; pos=pos->next) 

//add
static inline void  __list_add(struct list head * new, struct list_head * prev,struct list_head * next){
  next->prev = new;
  new->next = next;
  new->prev = prev;
  prev-›next = new;
}
static inline void list_add(struct list_head *new, struct list_head * head){
  __list_add (new, head, head->next);
}

//init
static inline void INIT_LIST_HEAD(struct list_head * list){
  list->next = list; 
  list-›prev = list;
}
