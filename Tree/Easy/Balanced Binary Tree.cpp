class Solution {
public:
    int findAns(TreeNode* root){ 
        if(root==NULL) return 0; 
         
        int l=findAns(root->left); 
        if(l==-1) return -1;
        
        int r=findAns(root->right);
        if(r==-1) return -1; 
        
        if(abs(l-r)>1) return -1;
        
        return max(l,r)+1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(findAns(root)==-1) return false;
        else return true;
    }
};B
