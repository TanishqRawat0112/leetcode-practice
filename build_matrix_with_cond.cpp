// You are given a positive integer k. You are also given:

// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.

// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

// The matrix should also satisfy the following conditions:

// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

// Example 1:
// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.
// Example 2:

// Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
// Output: []
// Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
// No matrix can satisfy all the conditions, so we return the empty matrix.
 

// Constraints:

// 2 <= k <= 400
// 1 <= rowConditions.length, colConditions.length <= 104
// rowConditions[i].length == colConditions[i].length == 2
// 1 <= abovei, belowi, lefti, righti <= k
// abovei != belowi
// lefti != righti

class Solution {
private:
    vector<vector<int> >build_matrix(vector<vector<int> >&positions,int k){
        vector<vector<int> >matrix(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            int r=positions[i][0];
            int c=positions[i][1];
            matrix[r][c]=i;
        }
        return matrix;
    }

    vector<vector<int> >find_position(vector<int>&topoRow,vector<int>&topoCol,int k){
        vector<vector<int> >positions(k+1);
        for(int i=0;i<k;i++){
            positions[topoRow[i]].push_back(i);
        }
        for(int i=0;i<k;i++){
            positions[topoCol[i]].push_back(i);
        }
        return positions;
    }

    vector<int> topo_sort(vector<vector<int> >&adj,vector<int>&indegree,int k){
        queue<int>q;
        indegree[0]=1e9;
        for(int i=0;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        if(q.empty())return topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()!=k){
            vector<int>fake;
            return fake;
        }
        return topo;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int> >rows(k+1);
        vector<int>inRow(k+1,0);
        for(int i=0;i<rowConditions.size();i++){
            rows[rowConditions[i][0]].push_back(rowConditions[i][1]);
            inRow[rowConditions[i][1]]++;
        }
        vector<vector<int> >cols(k+1);
        vector<int>inCol(k+1,0);
        for(int i=0;i<colConditions.size();i++){
            cols[colConditions[i][0]].push_back(colConditions[i][1]);
            inCol[colConditions[i][1]]++;
        }

        vector<int> topoRow=topo_sort(rows,inRow,k);
        vector<int> topoCol=topo_sort(cols,inCol,k);
        if(topoRow.size()==0 || topoCol.size()==0){
            return {};
        }

        vector<vector<int> >positions=find_position(topoRow,topoCol,k);
        vector<vector<int> >ans=build_matrix(positions,k);

        return ans;
    }
};
