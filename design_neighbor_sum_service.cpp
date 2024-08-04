// You are given a n x n 2D array grid containing distinct elements in the range [0, n2 - 1].

// Implement the neighborSum class:

// neighborSum(int [][]grid) initializes the object.
// int adjacentSum(int value) returns the sum of elements which are adjacent neighbors of value, that is either to the top, left, right, or bottom of value in grid.
// int diagonalSum(int value) returns the sum of elements which are diagonal neighbors of value, that is either to the top-left, top-right, bottom-left, or bottom-right of value in grid.


 

// Example 1:

// Input:

// ["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]

// [[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]

// Output: [null, 6, 16, 16, 4]

// Explanation:



// The adjacent neighbors of 1 are 0, 2, and 4.
// The adjacent neighbors of 4 are 1, 3, 5, and 7.
// The diagonal neighbors of 4 are 0, 2, 6, and 8.
// The diagonal neighbor of 8 is 4.
// Example 2:

// Input:

// ["neighborSum", "adjacentSum", "diagonalSum"]

// [[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]

// Output: [null, 23, 45]

// Explanation:



// The adjacent neighbors of 15 are 0, 10, 7, and 6.
// The diagonal neighbors of 9 are 4, 12, 14, and 15.
 

// Constraints:

// 3 <= n == grid.length == grid[0].length <= 10
// 0 <= grid[i][j] <= n2 - 1
// All grid[i][j] are distinct.
// value in adjacentSum and diagonalSum will be in the range [0, n2 - 1].
// At most 2 * n2 calls will be made to adjacentSum and diagonalSum.

class neighborSum {
    vector<vector<int>>grid;
public:
    neighborSum(vector<vector<int>>& grid1) {
        grid=grid1;
    }
    
    int adjacentSum(int value) {
        int dirX[]={0,1,0,-1};
        int dirY[]={1,0,-1,0};
        int n=grid.size();
        int row,col;
        bool breaker=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    row=i;
                    col=j;
                    breaker=true;
                    break;
                }
            }
            if(breaker)break;
        }
        int adjSum=0;
        for(int i=0;i<4;i++){
            int ni=row+dirX[i];
            int nj=col+dirY[i];
            if(ni>=0 && ni<n && nj>=0 && nj<n){
                adjSum+=grid[ni][nj];
            }
        }
        return adjSum;
    }
    
    int diagonalSum(int value) {
        int dirX[]={-1,+1,+1,-1};
        int dirY[]={+1,+1,-1,-1};
        int n=grid.size();
        int row,col;
        bool breaker=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    row=i;
                    col=j;
                    breaker=true;
                    break;
                }
            }
            if(breaker)break;
        }
        int diagSum=0;
        for(int i=0;i<4;i++){
            int ni=row+dirX[i];
            int nj=col+dirY[i];
            if(ni>=0 && ni<n && nj>=0 && nj<n){
                diagSum+=grid[ni][nj];
            }
        }
        return diagSum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
