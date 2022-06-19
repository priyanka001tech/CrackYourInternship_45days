class Solution {
public:
    void findAns(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return; 
        } 
        findAns(root->left,ans);
        ans.push_back(root->val);
        findAns(root->right,ans); 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        findAns(root,ans);
        return ans;
    }
};
 
