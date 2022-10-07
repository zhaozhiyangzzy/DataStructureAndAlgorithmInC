
int max(int a,int b){
  if(a>b){
    return a;
  }
  else{
    return b;
  }
}

int lengthOfLongestSubstring(char * s){
  int i = 0;
  int len = strlen(s);
  int start = 0;
  int hash[128] = {0};
  int ret = 0;
  for(i=0;i<128;i++){
    hash[i] = -1;
  }
  for(i=0;i<len;i++){
    int p =(int) (s[i]);
  //printf(“p-%din",p);
    if(hash[p] >= start){
      ret = max(ret,i-start);
      start = hash[p]+1;
    }
      hash[p] = i;
    }
    ret = max(ret, len-start);
    return ret;
}
/*
int main()
char data[] = {'a',a','b'}//use strlen --› memory leak!!!
int ret=lengthOfLongestSubstring(data);
}
*/
