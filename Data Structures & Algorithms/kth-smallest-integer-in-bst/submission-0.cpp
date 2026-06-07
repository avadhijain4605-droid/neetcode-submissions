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
    unordered_map<TreeNode*,pair<int,int>>h;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        h[root]={lh,rh};
        return 1+lh+rh;
    }
    int helper(TreeNode* root,int k){
        if(root==NULL) return 0;
        //if(k==0) return root->val;
        int leftcnt=h[root].first;
        int rightcnt=h[root].second;
        if(k==leftcnt+1) return root->val;
        if(k<=leftcnt) return helper(root->left,k);
        else return helper(root->right,k-leftcnt-1);
    }
    int kthSmallest(TreeNode* root, int k) {
        height(root);
        return helper(root,k);
    }
};
