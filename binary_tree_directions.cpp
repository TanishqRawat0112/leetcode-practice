// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:
// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:
// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int countNodes(TreeNode* test){
        if(test->left==NULL && test->right==NULL)return 1;
        int left=0,right=0;
        if(test->left){
            left=countNodes(test->left);
        }
        if(test->right){
            right=countNodes(test->right);
        }
        return 1+left+right;
    }

    TreeNode* getNode(TreeNode* test, int startValue){
        if(!test)return NULL;
        if(test->val==startValue)return test;
        TreeNode* left=getNode(test->left,startValue);
        if(left){
            return left;
        }
        TreeNode* right=getNode(test->right,startValue);
        if(right){
            return right;
        }
        return NULL;
    }

    void findParent(TreeNode* test,unordered_map<TreeNode*,TreeNode*>&parent){
        if(test->left==NULL && test->right==NULL)return;
        if(test->left){
            parent[test->left]=test;
            findParent(test->left,parent);
        }
        if(test->right){
            parent[test->right]=test;
            findParent(test->right,parent);
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* test=root;
        findParent(test,parent);

        test=root;
        TreeNode* startNode=getNode(test,startValue);

        test=root;
        int totalNodes=countNodes(test);
        cout<<"Total Nodes : "<<totalNodes<<endl;
        
        queue<pair<TreeNode*,string>>q;
        vector<int>visited(totalNodes+1,0);
        q.push({startNode,""});
        visited[startNode->val]=1;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            string direction=q.front().second;
            q.pop();
            if(node->val==destValue){
                return direction;
            }
            if(node->left && visited[node->left->val]==0){
                visited[node->left->val]=1;
                q.push({node->left,direction+"L"});
            }
            if(node->right && visited[node->right->val]==0){
                visited[node->right->val]=1;
                q.push({node->right,direction+"R"});
            }
            if(parent.find(node)!=parent.end() && visited[parent[node]->val]==0){
                visited[parent[node]->val]=1;
                q.push({parent[node],direction+"U"});
            }
        }

        return "";


    }
};
