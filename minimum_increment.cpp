//Problem Statement:

//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int inc=nums[i-1]+1-nums[i];
                count+=inc;
                nums[i]=nums[i-1]+1;
            }
        }
        return count;
    }
};
