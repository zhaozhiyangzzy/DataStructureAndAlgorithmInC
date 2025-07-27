class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        if(length == 0){
            return 0;
        }
        int slow = 0, fast = 0;
        int flag = 0;
        while(slow<length){
            if(nums[slow] != val){
                slow++;
            }
            else{
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            return length;
        }
        else{
            fast = slow+1;
        }
        while(fast<length){
            if(nums[fast]!=val){
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
            else{
                fast++;
            }
        }
        return slow;
    }
};

/*
int main(){
    Solution sol;
    vector<int> nums1 = {3,2,2,3};
    int val1 = 3;
    int ret1 = sol.removeElement(nums1,val1);

    return 0;
}
*/
