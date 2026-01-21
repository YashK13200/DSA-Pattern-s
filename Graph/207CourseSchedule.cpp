// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
//  take course bi first if you want to take 
// course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have 
// finished course 1. So it is impossible.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }
        
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
                
            }
            
        }
        
        if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          unordered_map<int, vector<int>> adj;
        
        vector<int> indegree(numCourses, 0); //kahn's algo
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
            
            //arrow ja raha hai 'a' me
            indegree[a]++;
        }
        
        
        //if cycle is present, not possible
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

// write a main function to test the code
int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "true" : "false") << endl; // Expected output: false
    return 0;
}