//Longest_Increasing_Subsequence
static int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int lengthOfLIS(int* nums, int numsSize){
    int ret = 0;
    if(numsSize==0){
        return ret;
    }
    int i = 0;
    int j = 0;
    int dp[numsSize];
    for(i=0;i<numsSize;i++){
        dp[i]=0;
    }
    for(i=0;i<numsSize;i++){
        dp[i]=1;
        for(j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i],dp[j]+1); //
            }
        }
    }
    for(i=0;i<numsSize;i++){
        if(ret<dp[i]){
            ret=dp[i];
        }
    }
    return ret;
}
