class Solution {
public:
    int preIdx=0,postIdx=0;
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        TreeNode* root=new TreeNode(preorder[preIdx++]);
        if(root->val!=postorder[postIdx]){
            root->left=constructFromPrePost(preorder,postorder);
        }
        if(root->val!=postorder[postIdx]){
            root->right=constructFromPrePost(preorder,postorder);
        }
        postIdx++;
        
        return root;
    }
};
