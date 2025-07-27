class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        if(length == 0){
            return false;
        }
        bool ret = true;
        vector<char> temp_stack;
        for(int i=0;i<length;i++){
            if(s[i] == '(' || s[i] == '[' || s[i]=='{'){
                temp_stack.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(temp_stack.empty() || temp_stack.back() != '('){
                    ret = false;
                    break;
                }
                else{
                    temp_stack.pop_back();
                }
            }
            else if(s[i]==']'){
                if(temp_stack.empty() || temp_stack.back() != '['){
                    ret = false;
                    break;
                }
                else{
                    temp_stack.pop_back();
                }
            }
            else if(s[i]=='}'){
                if(temp_stack.empty() || temp_stack.back() != '{'){
                    ret = false;
                    break;
                }
                else{
                    temp_stack.pop_back();
                }
            }
            else{
                ret = false;
                break;
            }
        }
        if(!temp_stack.empty()){
            ret = false;
        }
        return ret;
    }
};
/*
int main(){
    Solution sol;
    string s1 = "()";
    bool ret = sol.isValid(s1);
    return 0;
}
}
*/
