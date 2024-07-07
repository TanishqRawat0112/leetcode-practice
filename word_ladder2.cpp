// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

// Constraints:

// 1 <= beginWord.length <= 5
// endWord.length == beginWord.length
// 1 <= wordList.length <= 500
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
// The sum of all shortest transformation sequences does not exceed 105.

class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string> >ans;
    string b;
private:
    void dfs(string word,vector<string>&s){
        if(word==b){
            reverse(s.begin(),s.end());
            ans.push_back(s);
            reverse(s.begin(),s.end());
            return;
        }
        int steps=mpp[word];
        int sz=word.size();
        for(int i=0;i<sz;i++){
            char original=word[i];
            for(int ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    s.push_back(word);
                    dfs(word,s);
                    s.pop_back();
                }
            }
           word[i]=original;
        } 

    }
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wordList) {
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        b=bw;
        q.push({bw});
        mpp[bw]=1;
        int siz=bw.size();
        st.erase(bw);
        while(!q.empty()){
            string word=q.front();
            int len=mpp[word];
            q.pop();
            if(word==ew){
                break;
            }
            for(int i=0;i<siz;i++){
                char original=word[i];
                for(int ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=len + 1;
                    }
                }
                word[i]=original;
            }
        }
        if(mpp.find(ew)!=mpp.end()){
            vector<string>s;
            s.push_back(ew);
            dfs(ew,s);
        }
        return ans;
    }
};
