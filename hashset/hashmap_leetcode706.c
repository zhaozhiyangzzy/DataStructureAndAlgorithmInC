

#define hashsize 199
struct list_node{
  int key;
  int value;
  struct list_node * next;
};
typedef struct list_node * position;
typedef struct{
  int size;
  position * tablehead;
}MyHashMap;

struct list_node * node_init(int k,int v){
  struct list_node * temp = malloc(sizeof(struct list_node));
  temp->key = k;
  temp->value = v;
  temp->next = NULL;
  return temp;
}


//exist: not insert,return -1; not exist: insert, return 1
int enqueue (struct list_node * head, struct list_node * data){
  int exist = 0;
  int ret = 0;
  struct list_node * temp = head;
  while (temp->next!=NULL){     if((temp->next->key) == (data->key)){
      temp->next->value=data->value;
    exist = 1;
    ret = -1;
    break;
  }
  temp=temp->next;
  }
  if(exist==0){
    temp->next = data;
    ret = 1;
  }
  return ret;
}
//exist: delete, return 1; not exist: not delete, return -1
int dequeue(struct list_node * head, int k){
  int exist = 0;
  int ret = 0;
  struct list_node * d = NULL;
  struct list_node * temp = head;
  while(temp->next!=NULL){
    d = temp->next;
    if(d->key == k){
      exist = 1;
      ret = 1;
      temp->next = d->next;
      free(d);
      break;
    } 
    temp=temp->next;
  }
  if(exist == 0){
    ret = -1;
  }
  return ret;
}

int hashfunction(int data){
    return data % hashsize;
}

MyHashMap* myHashMapCreate() {
  int i = 0;
  MyHashMap * obj = malloc(sizeof(MyHashMap));
 obj->size = hashsize;
  position * t = malloc(sizeof (position)*hashsize);
  for(i=0;i<hashsize;i++){
    struct list_node * temp = node_init(-1,-1);
    t[i] = temp;
  }

  obj->tablehead = t;
  return obj;
}

void myHashMapPut(MyHashMap* obj, int key,int value) {
  int index = hashfunction(key);
  int enqueue_flag = 0;
  position temp = obj->tablehead [index];
  position data = node_init(key,value);     enqueue_flag = enqueue (temp, data);
  if (enqueue_flag==-1){
    //exist;
    //free(data);
  }
}

int myHashMapGet (MyHashMap * obj,int key){
  int index = hashfunction(key);
  int ret = -1;
  position temp = obj->tablehead [index];
  while (temp->next!=NULL){
    if(temp->next->key == key){ ret =    temp->next->value;
      break;
    }
    temp = temp->next;
  }
  return ret;
}
    
void myHashMapRemove(MyHashMap* obj, int key) {
  int index = hashfunction(key);
  int dequeue_flag = 0;
  position temp = obj->tablehead [index];
  dequeue_flag = dequeue (temp, key);
  if (dequeue_flag==-1){
    //printf("not exist, nothing to remove \n");
}
}


void myHashMapFree(MyHashMap* obj) {
  int i = 0;
  int num = obj->size;
  position * p = obj->tablehead;
  for(i=0;i<num;i++){
    struct list_node * t = p[i];
    while(t->next !=NULL){
      struct list_node * d = t->next;
      t->next = d->next;
      free(d);
    }
    free(t);
  }
  free(p);
  free(obj);
}


/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
