// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104

class Solution {
public:
    int numSquares(int n) {
        vector<int>squares;
        queue<pair<int,int>>q;
        vector<int>visited(n+1,0);
        for(int i=1;i<=100;i++){
            if(i*i > n)break;
            if(i*i == n)return 1;
            squares.push_back(i*i);
            q.push({squares[i-1],1});
            visited[squares[i-1]]=1;
        }
        while(!q.empty()){
            int num=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(auto it:squares){
                    if(num+it < n && visited[num+it]==0){
                        q.push({num+it,steps+1});
                        visited[num+it]=1;
                    }
                    else if(num + it == n){
                        return steps + 1;
                    }    
            }
        }
        return -1;
        
    }
};
