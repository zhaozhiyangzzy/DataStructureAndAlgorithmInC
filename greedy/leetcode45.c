int jump(int* nums, int numsSize){
  int i = 0;
  int reachable = 0;
  int temp = 0;
  int ret = 0;
  int * min = malloc(sizeof(int)*numsSize);
  for(i=0;i<numsSize;i++){
    min[i]=numsSize -1;
  }
  min[0]= 0;
  for (i=0;i<numsSize;i++){
    temp = i+nums[i];
    if (temp>reachable){
       reachable = temp;
    }
  //update [i+1, temp]
  int j = i+1;
  while(j<=temp){
    if(j>=numsSize){
        break;
    }
    if(min[j]>(min[i]+1)){
        min[j]= min[i] +1;
    }
    j++;
  }
  if(reachable>=(numsSize-1)){
    ret = min[numsSize-1];
    break;
  }
  }
  return ret;
}
