#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double sum = 0;
       
       int i = 0;
       int j = 0;
// Initial Window
       for(j = 0; j < k; j++){
        sum += nums[j];
       }
       
       double maxi = sum; // Initialize maxi with the first window sum
       
       // Sliding Window Approach => sum = sum + nums[j] - nums[i]
       while(j < nums.size()){
         sum = sum + nums[j];
         sum = sum - nums[i];
                
                i++;
                j++;
                
                maxi = max(maxi, sum);
       }
       // Return the maximum average
       return (maxi/k);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    cout << "Maximum average of subarray of size " << k << " is: " << sol.findMaxAverage(nums, k) << endl;
    return 0;
}