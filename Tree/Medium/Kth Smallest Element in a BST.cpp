class Solution {
private:
    void inorder(TreeNode* root,vector<int>& nums){
        if(root==NULL) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        return nums[k-1];
    }
};
