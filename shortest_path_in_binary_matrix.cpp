// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

 

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& maze) {
        int n=maze.size();
        int m=maze[0].size();
        if(maze[0][0]!=0 || maze[n-1][m-1]!=0){
            return -1;
        }
        if(n==1 && m==1)return 1;
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
        vector<vector<int> >dist(n,vector<int>(m,INT_MAX));
        pair<int,int>src;
        src.first=0;
        src.second=0;

        pair<int,int>dest;
        dest.first=n-1;
        dest.second=m-1;

        pair<int,pair<int,int> > p;
        p.first=1;
        p.second=src;
        dist[src.first][src.second]=1;
        pq.push(p);
        while(!pq.empty()){
            pair<int,int>cell=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            int dirX[]={-1,0,+1};
            int dirY[]={-1,0,+1};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int nr=cell.first + dirX[i];
                    int nc=cell.second + dirY[j];
                    if(nr==dest.first && nc==dest.second){
                        return dis+1;
                    }
                    if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]==0 && (dis + 1 < dist[nr][nc])){
                        dist[nr][nc]=dis+1;
                        p.first=dist[nr][nc];
                        p.second.first=nr;
                        p.second.second=nc;
                        pq.push(p);
                    }
                }
                
            }
        }
        return -1;
    }
};
