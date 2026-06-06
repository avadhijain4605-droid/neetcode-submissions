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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL||q==NULL) return false;
        bool flag=p->val==q->val;
        return flag&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&&subRoot==nullptr) return true;
        else if(root==nullptr||subRoot==nullptr) return false;
        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot)) return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
