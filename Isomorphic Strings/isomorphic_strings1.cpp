//Using Map data structure:

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mpp;
        int hash[150];
        for(int i=0;i<26;i++){
            hash[i]=0;
        }
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i]){
                    return false;
                }
                else{
                    continue;
                }
            }
            else{
                if(hash[t[i]]==0){
                    mpp[s[i]]=t[i];
                    hash[t[i]]=1;
                }
                else{
                    return false;
                }
            }
            
        }
        return true;

    }
};
