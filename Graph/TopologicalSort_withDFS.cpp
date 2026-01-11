// Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 
// 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. 
// Return the topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
// for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. 
// If your returned Topological sort is correct then the output will be true else false.

// Examples:
// Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]

// Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
// Output: true
// Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void DFS(vector<vector<int>> &adj, int u , vector<bool> &visited, stack<int> &st){
      visited[u] = true;
      
      // u ke baccho ke pahle stack mae dalo , phir u
      for(int &v : adj[u]){
          if(!visited[v]){
              DFS(adj, v, visited, st);
          }
      }
      st.push(u);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>visited(V,false);
        stack<int>st;
        
        vector<vector<int>>adj(V);
        // Adjacency List 
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i = 0;i<V;i++){
            if(!visited[i]) // if not visited i go for it dfs
            DFS(adj,i,visited,st);
        }
        
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> edges(M, vector<int>(2));
        for (int i = 0; i < M; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        Solution obj;
        vector<int> res = obj.topoSort(N, edges);
        
        // Function to check if the returned topological order is correct
        auto check = [&](vector<int> &res, int V, vector<vector<int>> &edges) {
            if (V != res.size())
                return false;
            vector<int> pos(V, -1);
            for (int i = 0; i < V; i++) {
                pos[res[i]] = i;
            }
            for (auto edge : edges) {
                if (pos[edge[0]] > pos[edge[1]])
                    return false;
            }
            return true;
        };
        
        cout << check(res, N, edges) << endl;
    }
    return 0;
}