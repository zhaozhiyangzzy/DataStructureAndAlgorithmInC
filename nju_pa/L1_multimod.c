#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#define MAXLEN 128


void print_array(int * array, int len){
  int i=0;
  for(i=0;i<len;i++){
    printf("%d,"‚array[i]);
  }
  printf("\n")
}

//data: 1010--›array: 0101
void u64_to_array(uint64_t data,int * array, int len){
  int i = 0;
  for(i=0;i<len; i++){
    if((data & 1)==1){
      array[i]=1;
    }
    else{
      array[i]=0;
    }
    data = data >> 1;
  }
}

uint64_t array_to_u64(int * data, int len){
  uint64_t ret = 0;
  int i = 0;
  for(i=len-1;i>-1;i--){
    ret = ret<<1;
    ret = ret | data[i];
  }
  return ret;
}

/*
a 100011
b 111101
      ^
*/

int u64_compare(int * a,int * b,int len){
  int ret = 0;
  int index = len-1;
  for (index=len-1;index>-1; index--){
    if(a[index]==b[index]){
      continue;
    }
    else if (a[index]>b[index]){
      ret = 1;
      break;
    }
    else{
      //a‹b
      ret = -1;
      break;
    }
  }
    //ret==0--> a==b return ret;
}

uint64_t multmod (uint64_t a,uint64_t b,uint64_t m){
  int data_a[MAXLEN];
  int data_b[MAXLEN];
  int data_m[MAXLEN];
  int result[MAXLEN];
  int i = 0;
  int carry_flag = 0;
  int temp = 0;
  uint64_t ret = 0;
  int len = 65;
  for (i=0;i<MAXLEN;i++){
    data_a[i] = 0;
    data_b[i] = 0;
    data_m[i] = 0;
    result[i] = 0;
  }
  u64_to_array(a, data_a, 64); 
  u64_to_array(b,data_b,64); 
  u64_to_array(m, data_m, 64);
  //add
  while(b!=0){
    carry_flag = 0;
    for(i=0;i<MAXLEN; i++){
      temp = data_a[i] + result[i] + carry_flag;
      int temp_write = 0;
      if (temp==0){
        temp_write = 0;
        carry_flag = 0;
      }
      else if (temp==1){
        temp_write = 1;
        carry_flag = 0;
      }
      else if(temp==2){
        temp_write = 0;
        carry_flag = 1;
      }
      else{
        //temp==3
        temp_write = 1;
        carry_flag = 1;
      }
      result[i] = temp_write;
    }
    b--;
  }
  
  while(u64_compare(result, data_m, MAXLEN) >=0){
    //update once
    for(i=0;i<MAXLEN i++){
      temp = result[i]-data_m[i];
      if (temp==1){
        result[i]=1;
      }
      else if (temp==0){
        result[i]=0;
      }
      else{
        //temp==-1 
        result[i]=1;
        int j = i+1;
        while(result[j]!=1){ 
          result[j]=1;
          j++；
          assert (j<MAXLEN);
        }
        result[i]=0;
      }
    }
  }

  if(result[64]==1){
    assert (0);
  }
  ret = array_to_u64(result,64)：
  return ret;
}
int main(){
  uint64_t a = 0;
  uint64_t b = 5;
  uint64_t m = 11;
  uint64_t t1 = multmod(a,b,m);
  printf("t1=%lu\n", t1);
}
