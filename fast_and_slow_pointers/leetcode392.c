

bool isSubsequence(char * s, char * t){
  if((s==NULL)|| (t==NULL)){
      return false;
  }
  int i = 0;
  int j = 0;
  int lens = strlen(s); 
  int lent = strlen(t);
  int found = 0;
  bool ret = true;
  if (lens>lent){
    return false;
  }
  for (i=0;i<lens; i++){
    found = 0;
    while(j<lent){
      if(s[i]==t[j]){
        j++;
        found = 1;
        break;
      }
      j++;
    }
    if(found==0){
      ret = false;
      break;
    }
  }
  return ret;
}
