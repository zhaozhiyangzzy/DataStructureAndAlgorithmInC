/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//1.cal tree's height (how much layers)
//2.first traverse: cal how many nodes there are int each layer
//3.second traverse: store each node in array

struct TreeNode * node_init(int data){
    struct TreeNode * temp = malloc(sizeof(struct TreeNode));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct general_list_node{
    struct TreeNode * val;
    struct general_list_node * next;
};

//queue related operate:node init,enqueue,dequeue,maybe need free
struct general_list_node * gen_init(struct TreeNode * v){
    struct general_list_node * r = malloc(sizeof(struct general_list_node));
    r->val = v;
    r->next = NULL;
    return r;
}

void gen_enqueue(struct general_list_node * head,struct general_list_node * data){
    if(head==NULL){
        return;
        //return NULL;
        //or return data???
    }
    while(head->next!=NULL){
        head = head->next;
    }
    head->next = data;
}

struct general_list_node * gen_dequeue(struct general_list_node * head){
    if(head==NULL){
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }

    struct general_list_node * ret = head->next;
    head->next=ret->next;
    return ret;
}


int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int node_height (struct TreeNode * root){
  if (root == NULL){
    return 0;
  }
  return max(node_height (root->left),node_height(root->right)) + 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
  //1.cal tree's height (how much layers)
  int h = 0; //tree's height
  int * column_num = NULL;
  int layer = 1;
  int next_layer = 0;
  int layer_index = 0;
  struct general_list_node * q = gen_init (NULL);
  struct general_list_node * temp=gen_init(root);
  struct general_list_node * temp_head = gen_init(root);
  struct TreeNode * temp_val = NULL;
  int ** ret_data = NULL;
  int * temp_row = NULL;
  int temp_row_index = 0;
  h = node_height(root);
  *returnSize = h;
  column_num = malloc(sizeof(int)*h);
  if (root==NULL){
    return NULL;
  }
  //2.first traverse: cal how many nodes there are int each layer 
  gen_enqueue (q, temp_head);
  while(q->next!=NULL){
  //printf("layer-%d\n", layer);
    next_layer=0;
    column_num[layer_index] = layer;
    layer_index++;
  while(layer>0){
    temp = gen_dequeue (q) ;
    layer--;
    temp_val = temp->val;
    if(temp_val->left!=NULL){ 
        next_layer++;
        // enqueue
        gen_enqueue(q,gen_init(temp_val->left));
    }
    if (temp_val->right!=NULL){
        next_layer++;
        //enqueue
        gen_enqueue (q, gen_init (temp_val->right));
    }
  }
  layer = next_layer;
}
    
  //3.second traverse : store each node in array
  ret_data = malloc(sizeof(int *)*h);
  gen_enqueue (q, temp_head);
  layer_index=0;
  while(q->next!=NULL){
    layer = column_num[layer_index];
    //printf("layer-%d\n" ‚layer);
    temp_row = malloc(sizeof(int)*layer);
    ret_data[layer_index] = temp_row;
    temp_row_index = 0;
    layer_index++;
    while (layer>0){
      temp = gen_dequeue (q);
      layer--;
      temp_val = temp->val;
      temp_row[temp_row_index] = temp_val->val;
      temp_row_index++;
      if(temp_val->left != NULL){
          gen_enqueue(q, gen_init(temp_val->left));
        }
      if(temp_val->right!=NULL){
        gen_enqueue(q, gen_init(temp_val->right));
      }
    }
  }
    *returnColumnSizes = column_num;
    //printf("level order finishin");
    return ret_data;
}
