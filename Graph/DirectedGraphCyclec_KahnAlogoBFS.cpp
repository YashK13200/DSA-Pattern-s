// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it
//  contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an
// edge from vertex u to v.

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
    bool isCyclic(int N, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(N);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        queue<int>q;
        vector<int>indegree(N,0);
        
        // 1.
        for(int i = 0;i<N;i++){
            for(int &v:adj[i]){
                indegree[v]++;
            }
        }
                int count = 0;
        //2,
        for(int i = 0;i<N;i++){
            if(indegree[i] == 0){
                q.push(i); // node in queue
                count++;
            }
            
        }
            //3
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for(int &v : adj[u]){
                    indegree[v]--;
                    
                    if(indegree[v] == 0){
                        q.push(v);
                        count++;
                    }
                }
        }
        if(count == N){ // all nodes visited means no Cycle -> using Kahn Alogorithm Approach(in BFS Style for cycle detetion)
            return false;
        }
        return true;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    
    Solution sol;
    bool hasCycle = sol.isCyclic(V, edges);
    
    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    
    return 0;
}