// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

 

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
 

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }

        vector<pair<int,int>>vec;
        for(auto it:mpp){
            vec.push_back({it.second,it.first});
        }

        sort(vec.begin(),vec.end());
        int i=0;
        while(i<vec.size()-1){
            if(vec[i].first==vec[i+1].first){
                int j=i+1;
                while(j<vec.size()){
                    if(vec[i].first!=vec[j].first){
                        reverse(vec.begin()+i,vec.begin()+j);
                        break;
                    }
                   j++;
                }
                if(j>=vec.size()){
                    reverse(vec.begin()+i,vec.begin()+j);
                }
                i=j;
            }
            else{
                i++;
            }
        }
        vector<int>ans;
        for(auto it:vec){
            int checker=it.first;
            int inser=it.second;
            while(checker!=0){
                ans.push_back(inser);
                checker--;
            }
        }
        return ans;

    }
};
