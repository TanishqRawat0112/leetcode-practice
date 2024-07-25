// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

// Example 1:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.

class Solution {
private:
    int bfs(vector<vector<int>>&adj,vector<int>&visited,vector<int>&degree,int node){
        vector<pair<int,int>>v;
        visited[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            v.push_back({curr,degree[curr]});
            for(auto it:adj[curr]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        int minEdges=v.size()-1;
        for(auto it:v){
            if(it.second!=minEdges){
                return 0;
            }
        }
        return 1;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>degree(n,0);
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto it:edges){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans+=bfs(adj,visited,degree,i);
            }
        }
        return ans;
    }
};
