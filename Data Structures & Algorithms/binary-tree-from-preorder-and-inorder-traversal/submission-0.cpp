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
    TreeNode* build(int preS,int preE,vector<int>& pre,int inS,int inE,vector<int>& in,unordered_map<int,int>& mpp){
        if(preS>preE||inS>inE) return NULL;
        int inPos=mpp[pre[preS]];
        int len=inPos-inS;
        TreeNode* root=new TreeNode(pre[preS]);
        root->left=build(preS+1,preS+len,pre,inS,inPos-1,in,mpp);
        root->right=build(preS+len+1,preE,pre,inPos+1,inE,in,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>mpp;
        int n=in.size();
        for(int i=0;i<n;i++)mpp[in[i]]=i;
        return build(0,n-1,pre,0,n-1,in,mpp);
    }
};
