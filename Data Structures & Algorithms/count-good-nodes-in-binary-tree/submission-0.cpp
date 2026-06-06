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
    int count(TreeNode* root,int mx){
        if(root==NULL) return 0;
        int ans=0;
        if(root->val>=mx)ans++;
        mx=max(root->val,mx);
        ans+=count(root->left,mx)+count(root->right,mx);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return count(root,-101);
    }
};
