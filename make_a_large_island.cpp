// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

 

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.

class DisjointSet{
    public:
    vector<int>size,parent;
    DisjointSet(int n){
        for(int i=0;i<n;i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v){
            size[ulp_u]++;
            return;
        }

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};

class Solution {
    bool isValid(int ni,int nj,int n){
        return ni>=0 && ni<n && nj>=0 && nj<n;
    }
public:
    int largestIsland(vector<vector<int>>& matrix) {
        int n=matrix.size();
        DisjointSet ds(n*n);
        int dirX[]={1,0,-1,0};
        int dirY[]={0,1,0,-1};
        vector<vector<int> >visited(n,vector<int>(n,0));
        //checking for the ones here :
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                for(int k=0;k<4;k++){
                    int ni=i+dirX[k];
                    int nj=j+dirY[k];
                    if(isValid(ni,nj,n) && matrix[ni][nj]==1){
                        int node=i*n + j;
                        int adjNode=ni*n + nj;
                        if(ds.findParent(node)!=ds.findParent(adjNode)){
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
    }

        //checking for the zero:
        int maxSize=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    int totalIslands=0;
                    unordered_map<int,int>mpp;
                    for(int k=0;k<4;k++){
                        int ni=i + dirX[k];
                        int nj=j+dirY[k];
                        if(isValid(ni,nj,n) && matrix[ni][nj]==1){ 
                                int node=i*n + j;
                                int adjNode=ni*n + nj;
                                int par=ds.findParent(adjNode);
                                
                                if(mpp.find(par)==mpp.end()){
                                    mpp[par]=1;
                                    totalIslands+=ds.size[ds.findParent(adjNode)];
                                }
                        }
                    }
                    maxSize=max(maxSize,totalIslands+1);
                }
            }
        }
        int maxVec=*max_element(ds.size.begin(),ds.size.end());
        return max(maxSize,maxVec);
    }
};
