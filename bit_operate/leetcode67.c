





char * addBinary(char * a, char * b){
  int len_a = strlen(a);
  int len_b = strlen(b);
  int len_long = 0;
  int len_short = 0;
  char * longd = NULL;
  char * shortd =NULL;
  int i = 0;
  int j = 0;
  int p = 0;
  int carry_flag = 0;
  if (len_a>len_b){
    longd = a;
    shortd = b;
  }
  else{
    longd = b;
    shortd = a;
  }
  len_long = strlen(longd);
  len_short = strlen(shortd);
  char * mid = malloc(sizeof (char)*(len_long+2));
  memset (mid, '0', (len_long+2));
    mid[0]='0';
  mid[len_long+1]='\0';
  p=len_long;
  i = len_long - 1;
  j = len_short - 1;
  while((i>-1)&&(j>-1)){
    int t1 = longd[i]-'0';
    int t2 = shortd[j]-'0';
    int temp = t1+t2+carry_flag;
    if (temp==0){
      mid[p]='0';
      carry_flag = 0;
    }
    else if (temp==1){
      mid[p]='1';
      carry_flag = 0;
    }
    else if (temp==2){
      mid[p]='0';
      carry_flag = 1;
    }
    else{
      //temp=35
      mid[p]='1';
      carry_flag =1;
    }
    i--;j--;p--;
  }
  while(i>-1){
    int t1 = longd[i]-'0';
    int temp = t1 +carry_flag;
    if(temp==0){
      mid[p]='0';
      carry_flag =0;
    }
    else if(temp==1){
      mid[p]='1';
      carry_flag = 0;
    }
    else {
      //temp=2;
      mid[p]='0';
      carry_flag = 1;
    }
      i--;
      p--;
  }
  if(carry_flag==1){
    mid[0]='1';
  }
  if(mid[0]=='1'){
    return mid;
  }
  else{
    char * ret = malloc(sizeof(char)*(len_long+1));
    memset(ret, '0', (len_long+1)); 
    ret[len_long]='\0';
    i=0; 
    j=0;
    for(i=1;i<len_long+1;i++){
      ret[j]=mid[i];
      j++;
    } 
    free(mid);
    return ret;
  }
}
