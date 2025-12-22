// Write a function that reverses a string. The input string is given as an array
//  of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
       int i = 0;
       int j = s.size() - 1;
       // 2 pointer 
       while(i < j){
        char tmp = s[i]; // tmp = h
        s[i] = s[j];    //  s[i] = o 
        s[j] = tmp;     //  s[j] = h
        i++;
        j--;
       }
    }
};

int main(){
    Solution sol;
    vector<char> s = {'h','e','l','l','o'};
    // vector<char> s = {'H','a','n','n','a','h'};
    sol.reverseString(s);  
    for(char c : s){
        cout << c << " "; // Output: o l l e h
    }
    cout << endl;
    return 0;
}