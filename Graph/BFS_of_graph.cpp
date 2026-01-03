// Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list 
// adj[][], where each adj[i] represents the list of vertices connected to vertex i. 
// Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left
//  to right according to the given adjacency list, and return a list containing the BFS traversal 
//  of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.

// Examples:

// Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

// Output: [0, 2, 3, 1, 4]
// Explanation: Starting from 0, the BFS traversal will follow these steps: 
// Visit 0 → Output: 0 
// Visit 2 (first neighbor of 0) → Output: 0, 2 
// Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
// Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1
// Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
// Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

// Output: [0, 1, 2, 3, 4]
// Explanation: Starting from 0, the BFS traversal proceeds as follows: 
// Visit 0 → Output: 0 
// Visit 1 (the first neighbor of 0) → Output: 0, 1 
// Visit 2 (the next neighbor of 0) → Output: 0, 1, 2 
// Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3 
// Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void BFS(unordered_map<int, vector<int>> adj, int u , vector<bool> &visited, vector<int> & result){
        
        queue<int>que;
        
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]){
               if(!visited[v]){
                que.push(v);
                visited[v] = true;
                result.push_back(v);
            }
                
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(int u = 0; u < mp.size(); u++){ // u -> __, __ 
             for (int v : mp[u]) {
                adj[u].push_back(v);
            }
        }
        
        vector<int>result;
        vector<bool>visited(mp.size(), false);
        
        BFS(adj,0,visited,result);
        return result;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<vector<int>> graph = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> bfs_result = sol.bfs(graph);
    
    cout << "BFS Traversal: ";
    for (int node : bfs_result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}