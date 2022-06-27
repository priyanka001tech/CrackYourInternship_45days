class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(root==NULL)
        {
            return {};
        }
        vector<vector<int>> a;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int> x;
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                x.push_back(root->val);
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }
            }
            a.push_back(x);
            
        }
        return a;
    }
};
