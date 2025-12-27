// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     int n = nums.size();
    // Using Hashmap
    unordered_map<int,int>mp;
    for(int i = 0;i<n;i++){
        int lookingFor = target - nums[i]; 
        // reuired Element is already present in the map, so return its index
        if(mp.find(lookingFor) !=mp.end()){
            return {mp[lookingFor],i};
        }
        // req element is not presemt in map, so insert it with its index;
        mp[nums[i]] = i;
    }
    return {-1,-1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}