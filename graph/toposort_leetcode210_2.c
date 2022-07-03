struct list_node {
    int v;
    struct list_node * next;
};

struct list_node * node_init(int v_value){
    struct list_node * t = malloc(sizeof(struct list_node));
    t->v = v_value;
    t->next = NULL;
    return t;
}

void node_insert(struct list_node * head, struct list_node * temp){
    struct list_node * t = head->next;
    if(t==NULL){
        head->next= temp;
    }
    else{
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
    }
}

void graph_free(struct list_node * graph[],int v){
    int i = 0;
    for(i=0;i<v;i++){
        struct list_node * head = graph[i];
        struct list_node * p = head->next;
        while(p!=NULL){
            head->next=p->next;
            free(p);
            p=head->next;
        }
        free(head);
    }
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    bool ret = true;
    bool found_flag = false;
    int row = prerequisitesSize;
    int col = (* prerequisitesColSize);
    int v = numCourses;
    int ** data = prerequisites;
    int i=0,j=0;
    int * indegree = malloc(sizeof(int)*v);
    int * toponum = malloc(sizeof(int)*v);
    int * course_order = malloc(sizeof(int)*v);
    for(i=0;i<v;i++){
        indegree[i]=0;
        toponum[i]=0;
        course_order[i]=0;
    }
    //memset(indegree,0,v);
    //memset(toponum,0,v);  //-->memset indegree[i] and toponum[i] != 0
    //int d[v]={0};  //not ok
    //init graph start
    //struct list_node g[v]
    struct list_node * graph[v];    //ok
    for(i=0;i<v;i++){
        struct list_node * temp = node_init(i);
        graph[i]=temp;
    }
    for(i=0;i<row;i++){
        int src = data[i][1];
        int dest = data[i][0];
        //printf("src=%d,dest=%d\n",src,dest);
        struct list_node * temp = node_init(dest);
        node_insert(graph[src],temp);
    }
    //init graph end

    //traverse graph,cal indegree
    for(i=0;i<v;i++){
        struct list_node * t = graph[i];
        struct list_node * p = t->next;
        while(p!=NULL){
            int dest = p->v;
            indegree[dest]++;
            p=p->next;
        }
    }
    /*
    debug
    for(i=0;i<v;i++){
        printf("indegree[i]=%d\n",indegree[i]);
    }
    */
    //topo sort
    for(i=0;i<v;i++){
        found_flag=false;
        for(j=0;j<v;j++){
            if(indegree[j]==0){
                found_flag=true;
                break;
            }
        }
        if(found_flag==true){
            indegree[j]=-1;  //clear,prevent double traverse
            toponum[j]=i;
            course_order[i]=j;  //add
            struct list_node * del = graph[j]->next;
            while(del!=NULL){
                int p = del->v;
                indegree[p]--;  //if indegree[p]==0,may add to linked list (next pop)
                del=del->next;
            }
        }
        else{
            ret=false;
            break;
        }
    }
    graph_free(graph,v);
    free(indegree);
    free(toponum);
    if(ret==false){
        (*returnSize)=0;
        free(course_order);
        return NULL;
    }
    else{
        (*returnSize)=v;
        return course_order;
    }
}

/*
int main(){
    int test1_num = 2;
    int t1[1][2]={{0,1}};
    int * p1[1];
    p1[0]=t1[0];

    int test2_num = 2;
    int t2[2][2]={{0,1},{1,0}};
    int * p2[2];
    p2[0]=t2[0];
    p2[1]=t2[1];

    int colsize =2;
    bool ret1=canFinish(test1_num,p1,1,&colsize);
    bool ret2=canFinsish(test2_num,p2,2,&colsize);

    printf("ret1=%d,ret2=%d\n",ret1,ret2);
}
*/
