// Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        // 2 pointer Approach
        int i = 0;
        int j = nums.size() - 1;

        int k = nums.size() - 1;

        while(i <= j){

            if(abs(nums[i]) > abs(nums[j])){ // 4 > 10 -> X False
                res[k] = nums[i] * nums[i];
                i++;
            }
            else {
                res[k] = nums[j]*nums[j]; // res[4] = 100
                j--;
            }
            k--;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result = sol.sortedSquares(nums);
    
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}