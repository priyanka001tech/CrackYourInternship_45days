// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

class Solution {
private:
    int c=0;
    void solve(TreeNode* root, int t){
        if(root==NULL) return;
        if(root->val==t) c+=1;
        solve(root->left, t-root->val);
        solve(root->right, t-root->val);
    }
public:
    int pathSum(TreeNode* root, int t) {
        if(root){
            solve(root, t);
            pathSum(root->left, t);
            pathSum(root->right, t);
        }
        return c;
    }
};
