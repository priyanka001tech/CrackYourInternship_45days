class Solution {
public:
    void findAns(TreeNode* root,int l,vector<int>& ans){
        if(root==NULL) return;
        if(l==ans.size()) ans.push_back(root->val);
        
        findAns(root->right,l+1,ans);
        findAns(root->left,l+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findAns(root,0,ans);
        return ans;
    }
};
