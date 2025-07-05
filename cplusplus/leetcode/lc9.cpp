#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)){
            return false;
        }
        long int long_x = (long int)x;

        long int t = x;
        long int p = 0;
        while(t>0){
            p = p*10 + t%10;  // use int will signed integer overflow, use long int
            t=t/10;
        }
        return p == x;
    }
};

/*
int main(){
    Solution sol;
    int x = 121;
    int y = 123;
    bool result1 = sol.isPalindrome(x);
    bool result2 = sol.isPalindrome(y);
    return 0;
}
*/
