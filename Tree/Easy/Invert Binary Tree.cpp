class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        
        return root;
    }
};
