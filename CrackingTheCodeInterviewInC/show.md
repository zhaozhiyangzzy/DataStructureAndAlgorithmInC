#This is Cracking The Code Interview In C Language

##problem 01.01 Is Unique LCCI

'''c
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Example 1:

Input: s = "leetcode"
Output: false
Example 2:

Input: s = "abc"
Output: true

'''
  
'''c
#include <string.h>
bool isUnique(char* astr){
    if(strlen(astr)==0)
        return true;
    int p1=0;
    int p2=0;
    int len = strlen(astr);
    for(p1=0;p1<len;p1++)
    {
        for(p2=p1+1;p2<len;p2++)
        {
            if(astr[p2]==astr[p1])
                return false;
        }
    }
    return true;
}  
'''
