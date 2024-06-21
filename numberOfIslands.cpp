  // NUMBER OF ISLANDS:

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

class Solution {
public:
    void dfs(vector<vector<char> >&islands,vector<vector<int> >&visited,int row,int col,int dirX[],int dirY[]){
    visited[row][col]=1;
    for(int k=0;k<4;k++){
        int i=dirX[k];
        int j=dirY[k];
            if(row+i<0 || row+i>=islands.size() || col+j<0 || col+j>=islands[0].size() ){
                continue;
            }
                if(islands[row+i][col+j]=='1'){
                    if(visited[row+i][col+j]==0){
                    dfs(islands,visited,row+i,col+j,dirX,dirY);
                }
            }
        
    }
}
    int numIslands(vector<vector<char>>& islands) {
        int rows=islands.size();
        int columns=islands[0].size();
        vector<vector<int> >visited(rows,vector<int>(columns,0));
        int counter=0;
        int dirX[]={+1,0,0,-1};
        int dirY[]={0,-1,+1,0};

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(islands[i][j]=='1'){
                    if(visited[i][j]==0){
                        dfs(islands,visited,i,j,dirX,dirY);
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};
