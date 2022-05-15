class Solution {
public:
    int sum=0;
    void inorder(TreeNode* root,int l,int r){
        if(root==NULL) return;
        inorder(root->left,l,r);
        if(root->val>=l && root->val<=r){
            sum+=root->val;
        }
        inorder(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        inorder(root,low,high);
        return sum;
    }
};
