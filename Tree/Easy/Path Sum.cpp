class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if(root==NULL) return false;
        if(root->val==t && root->left== NULL && root->right==NULL){
            return true;
        }
        return hasPathSum(root->left,t-root->val) || hasPathSum(root->right,t-root->val);
    }
};
