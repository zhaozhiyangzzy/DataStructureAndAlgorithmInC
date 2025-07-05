#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        int flag = 0;
        if(length == 0){
            return "";
        }
        for(int i=0;i<length;i++){
            if(strs[i].length() == 0){
                return "";
            }
        }

        int index = 0;
        string ret = "";
        int max_len = strs[0].length();
        for(int i=0;i<max_len;i++){
            index = i;
            for(int j=1;j<length;j++){
                if(strs[j][i] != strs[0][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                index--;
                break;
            }
        }
        if(index == -1){
            return "";
        }
        for(int i=0;i<=index;i++){
            ret += strs[0][i];
        }
        return ret;
    }
};

/*
int main(){
    Solution sol;
    vector<string> s1 = {"flower","flow","flight"};
    vector<string> s2 = {"dog","racecar","car"};
    string ret1 = sol.longestCommonPrefix(s1);
    string ret2 = sol.longestCommonPrefix(s2);
    std::cout <<"s1: "<< ret1<<std::endl;
    std::cout <<"s2: "<< rets<<std::endl;
    return 0;
}
*/
