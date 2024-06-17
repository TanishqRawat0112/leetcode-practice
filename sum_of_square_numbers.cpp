//POTD: 17 June 2024

// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5

// Example 2:
// Input: c = 3
// Output: false
 

// Constraints:
// 0 <= c <= 231 - 1

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int right=sqrt(c);
        long long int left=0;
        while(left<=right){
            long long int checker=(right*right)+(left*left);
            if(checker==c){
                break;
            }
            else if(checker>c){
                right--;
            }
            else{
                left++;
            }
        }
        // cout<<"left-->"<<left<<" & right-->"<<right<<endl;
        if(left>right){
            return false;
        }
        return true;
    }
};
