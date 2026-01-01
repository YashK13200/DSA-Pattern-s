// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a 
// cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumofSquaresOfDigits(int n){
        int sum = 0;
        // n = 19 
        // sum = 0 + 9*9 = 81 + 1 = 82 and so on ...
        while(n > 0){
          int dig = n % 10; // getting last digit
          sum = sum + (dig*dig);
          n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // Slow and Fast Pointer Approach - Pattern 
        int slow = n;        
        int fast = n;

        while(fast != 1){
            slow = sumofSquaresOfDigits(slow);
            fast = sumofSquaresOfDigits(sumofSquaresOfDigits(fast)); 
            // 19 -> 82 -> 68 -> 100 -> 1
        //    slow
        //    fast
        //          slow  fast
        if(fast == 1){
            return true; // happy no.
        }
        if(slow == fast){
            return false; // unhappy no.
        }
        }
        return true;        
    }
};

int main(){
    Solution sol;
    int n = 19;
    if(sol.isHappy(n)){
        cout << n << " is a Happy Number" << endl;
    } else {
        cout << n << " is not a Happy Number" << endl;
    }
    return 0;
}