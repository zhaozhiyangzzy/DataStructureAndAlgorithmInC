
int max(int a, int b){
  if(a>b)
    return a;
  else 
      return b;
}

int min(int a,int b){
  if (a>b)
    return b;
  else
    return a;
}


int maxArea(int* height, int heightSize){
  int result = 0;
  int start = 0;
  int end = heightSize - 1;
  while (start<end){
    int temp = min(height[start],height[end]) * (end-start);
  result = max(temp, result);
  if(height[start] <=height[end]){
    start++;
  }
  else{
    end--;
  }
  }
return result;
}
