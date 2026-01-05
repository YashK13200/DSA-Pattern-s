// Given an undirected graph with V vertices and E edges, represented as a 2D 
// vector edges[][], where each entry edges[i] = [u, v] denotes an edge between 
// vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
 
// 1 -> 2 -> 0 -> 1 is a cycle.
// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation: 
 
// No cycle in the graph.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCycleBFS(vector<vector<int>>& adj, int u,vector<bool>& visited) {

         queue<pair<int,int>>qq;
         
         qq.push({u, -1});
         visited[u] = true;
         
         while(!qq.empty()){
             pair<int,int> P = qq.front();
             qq.pop();
             
             int source = P.first;
             int parent = P.second;
             
             for(int &v : adj[source]){
                 if(visited[v] == false){
                      visited[v] = true;
                     qq.push({v,source});
                 }
                 
                 else if(v != parent) // means v is not equal to parent and can be cycle
                 {
                     return true;
                 }
             }
         }
           return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V); // Adjacency list
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCycleBFS(adj, i, visited))
                return true; // means if node is not visited and bfs return true means there is cycle
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << (sol.isCycle(V, edges) ? "true" : "false") << endl; // Output: true
    return 0;
}