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
    vector<int> topoSort(int N, vector<vector<int>>& edges) {
        // code here
        
        // Adjaceny List
       vector<vector<int>> adj(N);
      
           for(auto e : edges){
               adj[e[0]].push_back(e[1]); // Directed Graph
            //   adj[e[1]].push_back(e[0]);
           }
       
        // Topological Sort Using BFS -> Kahn Algorithm
        
        queue<int>q;
        vector<int>indegree(N, 0);
        
        // 1. 
        for(int u = 0; u < N; u++){
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }
        // 2, que fill , with 0 indegree
        for(int i = 0;i<N;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // 3 BFS
        vector<int>result;
        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();
            
            for(int &v : adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    q.push(v);
                }
        }
        }
        return result;
    }
};

// write correct main function to run the code
int main() {
    int V = 4;
    int E = 3;

    vector<vector<int>> edges = {
        {3, 0},
        {1, 0},
        {2, 0}
    };

    Solution sol;
    vector<int> topo = sol.topoSort(V, edges);

    cout << "Topological Order: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}