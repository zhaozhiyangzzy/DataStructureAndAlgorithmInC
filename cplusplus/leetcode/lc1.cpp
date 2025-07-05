#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int length = nums.size();
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(nums[i] + nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

/*
int main(){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = sol.twoSum(nums,target);
    if(!result.empty()){
        cout<<"index1: "<< result[0] <<", index2: " << result[1]<<endl;
    }
    else{
        cout <<"no solution found." << endl;
    }
    return 0;
}
*/
