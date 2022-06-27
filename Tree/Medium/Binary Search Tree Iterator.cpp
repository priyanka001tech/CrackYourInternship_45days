class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node){
        for(;node!=NULL;st.push(node),node=node->left);
        
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp=st.top();
        st.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
