// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.

class Solution {
private:
    void bfs(vector<vector<int>>& matrix,queue<pair<pair<int,int>,int> >&q,vector<vector<int> >&ans,int n, int m){
        vector<vector<int> >visited(n,vector<int>(m,0));
        cout<<q.size();
        int dirX[]={+1,0,-1,0};
        int dirY[]={0,-1,0,+1};
        while(!q.empty()){
            auto index=q.front().first;
            int distance=q.front().second;
            q.pop()
            for(int i=0;i<4;i++){
                int currDistance=distance;
                int nrow=index.first + dirX[i];
                int ncol=index.second + dirY[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    currDistance++;
                    q.push({{nrow,ncol},currDistance});
                    ans[nrow][ncol]=currDistance;
                }
            }
        }

    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<pair<int,int>,int> >q;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> >ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        bfs(matrix,q,ans,n,m);
        return ans;
    }
};
