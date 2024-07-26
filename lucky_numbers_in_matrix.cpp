// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

// Example 1:

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 2:

// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 3:

// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= n, m <= 50
// 1 <= matrix[i][j] <= 105.
// All elements in the matrix are distinct.

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>rowMin(m,INT_MAX);
        vector<int>colMax(n,INT_MIN);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowMin[i]=min(rowMin[i],matrix[i][j]);
                colMax[j]=max(colMax[j],matrix[i][j]);
            }
        }
        sort(rowMin.begin(),rowMin.end());
        sort(colMax.begin(),colMax.end());
        int l=0,r=0;
        vector<int>ans;
        while(l<m && r<n){
            if(rowMin[l]==colMax[r]){
                ans.push_back(rowMin[l]);
                l++;
                r++;
            }
            else if(rowMin[l] < colMax[r]){
                l++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};
