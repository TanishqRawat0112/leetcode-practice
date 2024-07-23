// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

// Example 1:

// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// Example 3:

// Input: matrix = [[1]]
// Output: 1
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

class Solution {
public:
    int dfs(vector<vector<int>>&matrix,vector<vector<int>>&dp,int r,int c){
        if(dp[r][c]!=-1)return dp[r][c];
        int n=matrix.size();
        int m=matrix[0].size();
        cout<<matrix[r][c]<<endl;
        int counter=1;
        int dirX[]={0,+1,0,-1};
        int dirY[]={+1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=r + dirX[i];
            int nc=c + dirY[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[r][c]){
                
                counter=max(counter,1+dfs(matrix,dp,nr,nc));
                
            }
        }
        dp[r][c]=counter;
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int maxPath=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxPath=max(maxPath,dfs(matrix,dp,i,j));
            }
        }
        return maxPath;
    }
};
