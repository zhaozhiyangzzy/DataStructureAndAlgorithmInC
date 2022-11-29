//Bulls_and_Cows_lc299.c
static int number_of_digits(int num){
    int ret = 0;
    if(num==0){
        return 1;
    }
    while(num!=0){
        ret++;
        num = num/10;
    }
    return ret;
}

static int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
char * getHint(char * secret, char * guess){
    if((secret==NULL) || (guess==NULL)){
        return NULL;
    }
    int i=0;
    int j=0;
    int A[10];
    int B[10];
    int lens = strlen(secret);
    int leng = strlen(guess);
    int bulls = 0;
    int cows = 0;
    int number_of_bulls=0;
    int number_of_cows = 0;
    int temp_num = 0;
    if(lens!=leng){
        return NULL;
    }

    for(i=0;i<10;i++){
        A[i] = 0;
        B[i] = 0;
    }

    for(i=0;i<lens;i++){
        if(secret[i]==guess[i]){
            bulls++;
        }
        else{
            int temp = 0;
            temp = secret[i]-'0';
            A[temp]++;
            temp = guess[i] - '0';
            B[temp]++;
        }
    }
    /*
    for(i=0;i<lens;i++){
        printf("a=%d,b=%d\n",A[i],B[i]);
    }
    */
    for(i=0;i<10;i++){
        if(A[i]==0 || B[i]==0){
            continue;
        }
        else{
            int temp_min = min(A[i],B[i]);
            cows=cows+temp_min;
        }
    }
    number_of_bulls = number_of_digits(bulls);
    number_of_cows = number_of_digits(cows);
    //printf("bulls=%d,num=%d,cows=%d,cnum=%d\n",bulls,number_of_bulls,cows,number_of_cows);
    char * x = malloc(sizeof(char)*(number_of_bulls+1));
    x[number_of_bulls]='\0';
    char * y = malloc(sizeof(char)*(number_of_cows+1));
    y[number_of_cows]='\0';

    char * ret = malloc(sizeof(char)*(number_of_bulls+number_of_cows+3));  //A,B,'\0'
 
    temp_num = bulls;
    for(i=number_of_bulls-1;i>-1;i--){
        char temp_c = (char)('0'+ (temp_num%10));
        temp_num = temp_num/10;
        x[i] = temp_c;
    }
    //printf("x=%s\n",x);
    temp_num = cows;
    for(i=number_of_cows-1;i>-1;i--){
        char temp_c = (char)('0'+ (temp_num%10));
        temp_num = temp_num/10;
        y[i] = temp_c;
    }
    //printf("y=%s\n",y);
    for(i=0;i<number_of_bulls;i++){
        ret[i]=x[i];
    }
    ret[number_of_bulls]='A';
    for(i=0;i<number_of_cows;i++){
        ret[number_of_bulls+1+i]=y[i];
    }
    ret[number_of_bulls+number_of_cows+1]='B';
    ret[number_of_bulls+number_of_cows+2]='\0';
    //printf("ret=%s\n",ret);
    free(x);
    free(y);
    return ret;
}
