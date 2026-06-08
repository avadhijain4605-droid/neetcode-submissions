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
    int sum=INT_MIN;
    int sumCalculation(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum=sumCalculation(root->left);
        int rightSum=sumCalculation(root->right);
        int localSum=root->val+(leftSum>0?leftSum:0)+(rightSum>0?rightSum:0);
        sum=max(sum,localSum);
        //cout<<root->val<<" "<<leftSum<<" "<<rightSum<<endl;
        return root->val+max(0,max(leftSum,rightSum));
    }
    int maxPathSum(TreeNode* root) {
        sumCalculation(root);
        return sum;
    }
};
