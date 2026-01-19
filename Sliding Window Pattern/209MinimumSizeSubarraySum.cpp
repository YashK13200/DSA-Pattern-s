// Given an array of positive integers nums and a positive integer target, return 
// the minimal length of a subarray whose sum is greater than or equal to target. If there is no such
// subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int mini = INT_MAX;     // Stores minimum length found so far
        int sum = 0;            // Current window sum

        int i = 0;              // Left pointer of sliding window

        // j is the right pointer of the window
        for (int j = 0; j < nums.size(); j++) {

            // Expand window by adding nums[j]
            sum += nums[j];

            // If current window sum is >= target,
            // try to shrink the window from the left
            while (sum >= target) {

                // Update minimum window size
                mini = min(mini, j - i + 1);

                // Remove element at left pointer
                sum = sum - nums[i];
                // Move left pointer forward
                i++;
            }
        }

        // If no valid subarray found, mini will still be INT_MAX
        // In that case, return 0
        return (mini == INT_MAX ? 0 : mini);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums1) << endl; // Output: 2

    vector<int> nums2 = {1, 4, 4};
    cout << sol.minSubArrayLen(4, nums2) << endl; // Output: 1

    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << sol.minSubArrayLen(11, nums3) << endl; // Output: 0

    return 0;
}