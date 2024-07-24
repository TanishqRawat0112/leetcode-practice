// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

// Example 1:
// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:
// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// All the elements of graph[i] are unique.
// The input graph is guaranteed to be a DAG.

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()-1;
        vector<vector<int>>adj(n+1);
        int index=0;
        for(auto it:graph){
            for(auto i:it){
                adj[index].push_back(i);
            }
            index++;
        }
        int i=0;
        for(auto it:adj){
            cout<<i<<" : ";
            for(auto node:it){
                cout<<node<<" ";
            }
            i++;
            cout<<endl;
        }
        vector<vector<int>>ans;
        queue<pair<int,vector<int>>>q;
        vector<int>vec;
        vec.push_back(0);
        q.push({0,vec});
        while(!q.empty()){
            int node=q.front().first;
            vector<int> v=q.front().second;
            q.pop();
            if(node==n){
                ans.push_back(v);
                continue;
            }
            for(auto it:adj[node]){
                v.push_back(it);
                q.push({it,v});
                v.pop_back();
            }
        }
        return ans;
    }
};
