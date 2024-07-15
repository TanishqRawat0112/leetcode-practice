// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:
// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.

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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<int>>parent;
        unordered_map<int,int>children;

        for(auto it:descriptions){
            if(children.find(it[0])==children.end()){
                children[it[0]]=0;
            }
            children[it[1]]=1;
            if(parent[it[0]].empty()){
                vector<int>child(2,0);
                if(it[2]==1){
                    child[0]=it[1];
                }
                else if(it[2]==0){
                    child[1]=it[1];
                }
                parent[it[0]]=child;
            }
            else{
                if(it[2]==1){
                    parent[it[0]][0]=it[1];
                }
                else if(it[2]==0){
                    parent[it[0]][1]=it[1];
                }
            }
        }

        TreeNode* root = new TreeNode();
        for(auto it:children){
            if(it.second==0){
                root->val=it.first;
                break;
            }
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            int counter=0;
            for(auto it:parent[node->val]){
                TreeNode* newnode = new TreeNode(it);
                if(counter==0){
                    if(it==0){
                        counter++;
                        continue;
                    }
                    q.push(newnode);
                    node->left=newnode;
                    counter++;
                }
                else{
                    if(it==0){
                        continue;
                    }
                    q.push(newnode);
                    node->right=newnode;
                }
            }
        }
        return root;
    }
};
