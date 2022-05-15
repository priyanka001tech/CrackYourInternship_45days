class Solution {
public:
     bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); 
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricTest(root->left,root->right);
    }
};
