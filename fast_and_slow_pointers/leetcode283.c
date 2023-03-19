

void moveZeroes(int* nums, int numsSize){
  if (nums==NULL){
    return;
  }
  //int flag = 0;
  int i=0,j=0;
  while(i<numsSize){
    if(nums[i]!=0){
      i++;
    }
    else{
      if (j<=i){
        j=i+1;
      }
      else{
//nums [il has meet o
      }
      while((j<numsSize)&&(nums[j]==0)){
        j++;
      }
      if (j==numsSize){
        break;
      }
      else{
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        i++;
        j++;
      }
    }
  }
}
         
