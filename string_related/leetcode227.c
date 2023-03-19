
struct list_node{
  int num;
  char op;
  int type; //0-num; 1-operator
  struct list_node * next;
};

struct list_node * node_init(int n,char c,int t){
  struct list_node * temp = malloc(sizeof (struct list_node));
  temp->num = n;
  temp->op = c;
  temp->type = t;
    temp->next=NULL;
  return temp;
}

struct list_node * stack_init(){
  struct list_node * head = node_init(-1,'w', -1);
  return head;
}

struct list_node * pop(struct list_node * s) {
  if (s->next==NULL) {
    return NULL;
  }

  struct list_node * t = s->next;
  s->next = t->next;
  return t;
}

void push (struct list_node * s,struct list_node * node){
  struct list_node * temp = s->next;
  s->next=node;
  node->next=temp;
  return;
}

//1 is empty, 0 is not empty
int stack_is_empty (struct list_node * s) {
  if (s->next==NULL){ 
    return 1;
  }
  else{
    return 0;
  }
}

void stack_free(struct list_node * s){
  while(stack_is_empty(s)!=1){
    struct list_node * t = pop (s) ;
    free(t);
  }
  free (s) ;
}
void peek(struct list_node * s, int * n, char * c, int * t){
  struct list_node * temp = s->next;
  *n = temp->num;
  *c = temp->op;
  *t = temp->type;
  return;
}

int str_to_num(char * t){
  if(t==NULL){
    //printf("t is NULL\n");
    return 0;
  }
  int len = strlen(t);
  int p = 0;
  int num_len = 0;
  char * data;
  int ret = 0;
  while((p<len)&&('0'<=t [p])&&(t[p]<='9')){
    p++;
    num_len++;
  }
  data = malloc(sizeof(char)* (num_len+1));
  strncpy (data, t,num_len) ;
  data[num_len]='\0';
  ret = atoi (data);
  free(data);
  return ret;
}

int priority(char c){
  if((c=='+')||(c=='-')){
    return 0;
  }
  else if((c=='*')||(c=='/')){
    return 1;
  }
  else{
    printf("unsupported op");
    return -1;
  }
}

int compare_op(char c, char cc){
  int p=priority(c);
  int pp=priority(cc);
  if (p>pp){
    return 1;
  }
  else if (p==pp){
    return 0;
  }
  else{
    return -1;
  }
}

int cal(int a, char op,int b){
  if (op=='+'){
    return a+b;
  }
  else if(op=='-'){
    return a-b;
  }
  else if(op=='*'){
    return a*b;
  }
  else if (op=='/'){
    return a/b;
  }
  else{
    //printf(" invalid op\n");
    return -1;
  }
}

void cal_once(struct list_node * number, struct list_node * op){
  //pop op
  struct list_node * tt1 = pop(op);

  //pop need free()
  char ccc = tt1->op;
  //pop num1, num2
  struct list_node * tt2 = pop (number);
  struct list_node * tt3 = pop (number);
  int n1 = tt2->num;
  int n2 = tt3->num;

  //numB = numi op num2
  int n3 = cal (n2, ccc,n1) ;
  struct list_node * tt4 = node_init(n3, 'q',0);
  push (number, tt4);
  free(tt1);
  free(tt2);
  free(tt3);
  return;
}


int calculate(char * s){

  if(s==NULL){
    return 0;
  }
  int len = strlen(s);
  int p = 0;
  int temp = 0;
  int ret = 0;
  int n= -1;
  char cc = 'q';
  int t = 0;
    
  struct list_node * number = stack_init();
  struct list_node * op = stack_init();
  while(p<len){
    if(s[p]==' '){
      p++;
    }
    else if(('0'<=s[p])&&(s[p]<='9')){
      //number: traverse until next char is op or space
      temp = str_to_num(s+p);
      //printf("temp = %d\n" , temp) ;
      while((p<len)&&('0'<=s[p])&&(s[p]<='9')){
        p++;
      }
      struct list_node * temp_node = node_init (temp, 'q' ,0) ;
      push (number, temp_node) ;
  }
  else if((s[p]=='+')||(s[p]=='-')||(s[p]=='*')||(s[p]=='/')){
    char c = s[p];
    //printf("temp char is %c\n", c);
    struct list_node * temp_node = node_init(-1, c,1);
    if (stack_is_empty (op)==1){
      push (op, temp_node);
    }
    else{
      peek(op, &n, &cc, &t) ;
      if (compare_op (c, cc) >0){ //c priority is higher than cc
        push (op, temp_node);
      }
      else{
      //c priority is lower than or equal cc.
        while(stack_is_empty (op) !=1) {
          cal_once (number, op);
          if(stack_is_empty(op)==1){
             push (op, temp_node) ;
             break;
          }
          peek(op, &n , &cc, &t ) ;
          if (compare_op (c, cc)>0){
            push (op, temp_node);
            break;
          }
          else{
            continue;
          }
          }
      }
    }
    p++;
  }
  else{
      //printf ("unknown char\n")
  }
  }
  while(stack_is_empty(op)!=1){
    cal_once (number,op);
  }
  ret = number->next ->num;
  stack_free(number);
  stack_free(op);
  return ret;
}
