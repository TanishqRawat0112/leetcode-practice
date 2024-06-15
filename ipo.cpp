// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

// Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

// The answer is guaranteed to fit in a 32-bit signed integer.

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>checker;
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
            pair<int,int>p;
            p.second=profits[i];
            p.first=capital[i];
            checker.push_back(p);
        }
        sort(checker.begin(),checker.end());

        int i=0;
        while(k>0){
            while(i<n && checker[i].first<=w){
                pq.push(checker[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }

                w+=pq.top();
                pq.pop();
                k--;
            
        }
    return w;
    }
};
