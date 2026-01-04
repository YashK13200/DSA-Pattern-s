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

    bool isCycledfs(vector<vector<int>>& adj, int u,vector<bool>& visited, int parent) {

        visited[u] = true; // mark current node as visited

        for (auto v : adj[u]) {
            if (v == parent) continue; // if parent node then continue

            if (visited[v])  { // if already visited and not parent then cycle found
               return true;
            }
            if(isCycledfs(adj,v,visited,u)) return true; // go to depth and check for cycle
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
            if (visited[i] == false && isCycledfs(adj, i, visited, -1))
                return true; // means if node is not visited and dfs return true means there is cycle
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