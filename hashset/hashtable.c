#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

struct ListNode{
  ElementType Element;
  int val;
  Position Next;
};
Typedef Position List;
struct HashTbl
{
  int TableSize;
  List * TheLists;
};

void list_free(struct ListNode * head);
int aHash(int x);

int main()
{
  HashTable H = InitializeTable(10);
  int i = 0;
  for(i=0;i<10;i++)
  {
    Insert(i*i,H);
  }
  Insert(99,H);
  Find(49,H);
  DestroyTable(H);
}

HashTable InitializeTable(int TableSize){
  HashTable H;
  H = malloc(sizeof(struct HashTbl));
  H -> TableSize = TableSize;
  H -> TheList = malloc(sizeof(List)*H->TableSize);
  
  int i = 0;
  for(i=0;i<H->TableSize;i++){
    H->TheLists[i] = malloc(sizeof(struct ListNode));
  }
  
  return H;
}
  
void DestroyTable(HashTable H){
  if(H==NULL)
    return;
  int tablesize = H->TableSize;
  int i = 0;
  for(i=0;i<tablesize;i++)
  {
    struct ListNode * head = H->TheLists[i];
    list_free(head);
  }
  free(H);
}

void list_free(struct ListNode * head){
  if(head == NULL)
    return;
  list_free(head->Next);
  free(head);
}


int aHash(int x){
  return x%10;
}

void Insert(ElementType Key,HashTable H){
  int p = aHash(Key);
  struct ListNode * po = H->TheList[p];
  struct ListNode * temp = malloc(sizeof(struct ListNode));
  temp -> Element = Key;
  temp -> val = Key -1;
  temp -> Next = po -> Next;
  po -> Next = temp;
}

Position Find(ElementType Key,HashTable H){
  int p = aHash(Key);
  struct ListNode * po = H->TheLists[p];
  while(temp!=NULL){
    if(temp->Element == Key){
      printf("key = %d,value = %d",key,temp->val);
      return temp;
      break;
    }
    temp = temp->Next;
  }
  return NULL;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
