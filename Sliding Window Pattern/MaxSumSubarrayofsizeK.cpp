// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:
// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.

// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxi = 0;
        
        int i = 0;
        int j = 0;
        
        for(j = 0; j < k; j++){
            sum += arr[j];
            
            maxi = max(maxi,sum);
        }
        
            //Sliding Window Approach => sum = sum + arr[j] - arr[i]
            while(j < arr.size()){ // j = 3
                sum = sum + arr[j];
                sum = sum - arr[i];
                
                i++;
                j++;
                
                maxi = max(maxi,sum);
            }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << "Maximum sum of subarray of size " << k << " is: " << sol.maxSubarraySum(arr, k) << endl;
    return 0;
}