// There are n cities. Some of them are connected, while some are not. If city a is connected 
// directly with city b, and city b is connected directly with city c, then city a is connected 
// indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside
//  of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and 
// the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Example 2:
// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;

    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
       visited[u] = true;
     // Visit all neighbors
        for(int &v : adj[u]) { 
        if(!visited[v])
        dfs(adj, v, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);

        //make graph -> Adj list 
    unordered_map<int, vector<int>> adj;

      for(int i = 0; i<n; i++) {
      for(int j = 0; j<n; j++) {
         if(isConnected[i][j] == 1) {
           adj[i].push_back(j);
           adj[j].push_back(i);

         }
      }
      }
      // Code is just Similar to doing DFS , just we add a counter to count number of components
      int count = 0;

      for(int i = 0; i<n; i++) {

       if(!visited[i]) {
         dfs(adj, i, visited); // Perform DFS
         count++; // Increment province count
       }
      }

     return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected1) << endl; // Output: 2

    vector<vector<int>> isConnected2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected2) << endl; // Output: 3

    return 0;
}