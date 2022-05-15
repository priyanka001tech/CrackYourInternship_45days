class Solution {
private:
    TreeNode* createTree(vector<int>& nums,int l,int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=createTree(nums,l,mid-1);
        root->right=createTree(nums,mid+1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        TreeNode* root=createTree(nums,l,r);
        return root;
        
    }
};
