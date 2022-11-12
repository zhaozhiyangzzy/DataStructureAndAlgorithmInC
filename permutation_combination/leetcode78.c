

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 0->2^n-1 对应的1bit位是各种排列组合
 */
//return '1' bit num
int int_to_bit(int data,int * b, int len){
  int i = 0;
  int ret = 0;
  for(i=len-1;i>-1;i--){
    int temp = data&1;
    if(temp==1){
      ret++;
    } 
    data=-data>>1; 
    b[i]=temp;
  }
  return ret;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

  int row = 1;
  int i = 0, j=0,p=0;
  int len = numsSize;
  int * b = malloc(sizeof(int)*len);
  memset (b,0, numsSize);
  for(i<0;i<numsSize;i++){
    row=row*2;
    }
  *returnSize = row;
  int ** ret = malloc(sizeof(int *) *row);
  int * col = malloc(sizeof(int)*row);
  col [0]=0; 
  ret [0]=NULL;
  for(i=1;i<row;i++){
    int temp_data = 1;
    int t = int_to_bit(i,b,len);
    int * temp_row = malloc(sizeof(int)*t);
    p=0;
    for (j=0; j<len; j++){
      if(b[j]==1){
        temp_row[p]=nums [j];
        p++;
      }
    }
  col[i]=t; 
  ret[i]=temp_row;
  } 
  free(b);
  *returnColumnSizes = col;
  return ret;
}
