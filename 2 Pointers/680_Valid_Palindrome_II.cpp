// Given a string s, return true if the s can be palindrome after deleting at 
// most one character from it.

 
// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(int i, int j , string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        // 2 Pointer Approach
        while(i < j){ // for input2 -> abca
           char left = s[i]; //  a
           char right = s[j]; // a

            if(left != right){  // a != a -> false -> go to else statement and modify i and j and check again
             // checking again plaindrome inside substring 
             return checkPalindrome(i+1,j,s) || checkPalindrome(i,j-1,s);
            }
            else{
                i++; 
                j--;
            }
        }
       return true;
    }
};

int main(){
    Solution sol;
    string s = "abca";
    bool result = sol.validPalindrome(s);
    
    cout << (result ? "true" : "false") << endl;
    return 0;
}