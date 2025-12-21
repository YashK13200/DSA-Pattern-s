// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward 
// and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// #include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        // 2 pinter Approach 
        while(i < j){
              char left = s[i]; // first Character 
              char right = s[j]; // last Character 

              if(!isalnum(left)){ // checking alphanumeric => leter + digit
                i++;
                continue;
              }
              if(!isalnum(right)){
                j--;
                continue;
              }
              if(tolower(left) != tolower(right)){
                return false;
              }
              i++;
              j--;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    bool result = sol.isPalindrome(s);  
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}
