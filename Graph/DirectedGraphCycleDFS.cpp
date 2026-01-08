// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
// check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] 
// denotes an edge from vertex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
// Output: true
// Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0


// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]

// Output: false
// Explanation: no cycle in the graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool isCycleDFS(vector<vector<int>> &adj, int u , vector<bool> &visited,vector<bool> &inRecursion){
      
      visited[u] = true;
      inRecursion[u] = true;
      
      for(int &v : adj[u]){
          // if not visited , then go in Depth and Check
          if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)){
              return true;
          }
          // also if visited and in inRecursion marked true -> cycle 
          else if(inRecursion[v] == true){
              return true;
          }
      }
      inRecursion[u] = false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // Creating Adjaceny List 
      vector<vector<int>> adj(V);

        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        // DFS Logic Starts for Directed Graph 
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
        for(int i = 0;i <V;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << (sol.isCyclic(V, edges) ? "true" : "false") << endl; // Output: true
    return 0;
}