// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
private:
    int bfs(vector<vector<int> >&matrix,queue<pair<pair<int,int>,int> >&q,vector<vector<int> >&visited){
        int time=0;
        pair<int,int>index;
        pair<pair<int,int>,int> indTime;
        int n=matrix.size();
        int m=matrix[0].size();

        int dirX[]={-1,0,0,+1};
        int dirY[]={0,-1,+1,0};

        while(!q.empty()){
            pair<int,int>currIndex=q.front().first;
            time=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nRow=currIndex.first + dirX[i];
                int nCol=currIndex.second + dirY[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]==0 && matrix[nRow][nCol]==1){
                    visited[nRow][nCol]=1;
                    matrix[nRow][nCol]=2;
                    index.first=nRow;
                    index.second=nCol;
                    indTime.first=index;
                    indTime.second=time+1;
                    q.push(indTime);
                }
            }
        }
        //Checking if all the fresh oranges are converted to rotten:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    return -1;
                }
            }
        }

        return time;

    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>matrix=grid;
        queue<pair<pair<int,int>,int> >q;
        pair<int,int>index;
        pair<pair<int,int>,int> indTime;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> >visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==2){
                    index.first=i;
                    index.second=j;
                    indTime.first=index;
                    indTime.second=0;
                    q.push(indTime);
                    visited[i][j]=1;
                }
            }
        }
        return bfs(matrix,q,visited);
    }
};
