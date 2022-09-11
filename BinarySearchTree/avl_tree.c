

//avl tree related start
struct avl_node;
typedef struct avl_node * position;
struct avl_node{
    int val;
    int height;
    struct avl_node * left;
    struct avl_node * right;
};


struct avl_list_node{
    struct avl_node * val;
    struct avl_list_node * next;
};

//queue related start
struct avl_list_node * avl_init(struct avl_node * v){
    struct avl_list_node * r = malloc(sizeof(struct avl_list_node));
    r->val = v;
    r->next = NULL;
    return r;
}

void avl_enqueue(struct avl_list_node * head,struct avl_list_node * data){
    if(head==NULL){
        return;
    }
    while(head->next!=NULL){
        head = head->next;
    }
    head->next=data;
}

struct avl_list_node * avl_dequeue(struct avl_list_node * head){
    if(head==NULL){
        return NULL;
    }
    if(head->next ==NULL){
        return NULL;
    }

    struct avl_list_node * ret = head->next;
    head->next = ret->next;
    return ret;
}
//queue related end

static int node_height(position p){
    if(p==NULL){
        return -1;
    }
    else{
        return p->height;
    }
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
struct avl_node * avl_node_init(int val){
    struct avl_node * temp = malloc(sizeof(struct avl_node));
    temp->val = val;
    temp->height = 0;  //maybe set to -1?
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

static position single_rotate_with_left(position k2){
    position k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(node_height(k2->left),node_height(k2->right)) + 1;
    k1->height = max(node_height(k1->left),k2->height) + 1;
    return k1;
}

static position single_rotate_with_right(position k1){
    position k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(node_height(k1->left),node_height(k1->right)) + 1;
    k2->height = max(node_height(k2->right),k1->height) + 1;
    return k2;
}

static position double_rotate_with_left(position k3){
    k3->left = single_rotate_with_right(k3->left);
    return single_rotate_with_left(k3);
}

static position double_rotate_with_right(position k1){
    k1->right = single_rotate_with_left(k1->right);
    return single_rotate_with_right(k1);
}

struct avl_node * insert(struct avl_node * root,int value){
    if(root == NULL){
        root = avl_node_init(value);
    }
    else if(value < root->val){
        root->left = insert(root->left,value);
        if(node_height(root->left) - node_height(root->right) == 2){
            if(value < root->left->val){
                root = single_rotate_with_left(root);
            }
            else{
                root = double_rotate_with_left(root);
            }
        }
    }
    else if(value > root->val){
        root->right = insert(root->right,value);
        if(node_height(root->right)-node_height(root->left)==2){
            if(value > root->right->val){
                root = single_rotate_with_right(root);
            }
            else{
                root = double_rotate_with_right(root);
            }
        }
    }
    //else:node already in the tree
    root->height = max(node_height(root->left),node_height(root->right)) + 1;
    return root;
}

/*
void traverse(struct avl_node * root){
    if(root == NULL){
        return;
    }
    traverse(root->left);
    printf("%d,"root->val);
    traverse(root->right);
}

int main(){
    int a = 2;
    struct avl_node * r = NULL;
    r = insert(r,a);
    traverse(r);
}
*/
//avl tree related end
struct avl_node * avl_sortedArrayToBST(int * nums,int numsSize){
    struct avl_node * t = NULL;
    int i = 0;
    for(i=0;i<numsSize;i++){
        t = insert(t,nums[i]);
    }
    return t;
}
