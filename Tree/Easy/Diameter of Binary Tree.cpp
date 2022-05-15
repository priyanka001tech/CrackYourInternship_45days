class Solution {
public:
    int findAns(TreeNode* root, int &dia){
        if(root==NULL) return 0;
        
        int l=findAns(root->left,dia);
        int r=findAns(root->right,dia);
        
        dia=max(dia,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        findAns(root,dia);
        return dia;
    }
};
