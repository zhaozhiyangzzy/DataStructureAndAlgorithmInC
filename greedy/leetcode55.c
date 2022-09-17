bool canJump(int* nums, int numsSize){
  int reachable = 0;
  bool ret = 1;
  int i = 0;
  int temp_max_reach = 0;
  for (i=0;i<numsSize;i++){
    temp_max_reach =nums [i] +i;
    if(temp_max_reach > reachable){
      reachable = temp_max_reach;
    }
    if(reachable >= (numsSize-1)){
      ret = 1;
      break;
    }
    if(reachable< (i+1)){
      ret = 0;
      break;
    }
  }
  return ret;
}
/*
int main(){
    int data1[5] = (2,3,1,1,4};
    int data2[5] = (3,2,1,0,4};
    int len = 5;
    bool ret1 = canJump(datal,len);
    bool ret2 = canJump (data2,len) ;
    printf("ret1-%d,ret2-%d\n",ret1,retz);
}
*/
