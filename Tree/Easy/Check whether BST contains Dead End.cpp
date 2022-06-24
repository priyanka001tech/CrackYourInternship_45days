void storeNodes(Node * root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;
 
    all_nodes.insert(root->data);
 
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }
 
    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(Node *root)
{
    if (root == NULL)
        return false ;
 
    unordered_set<int> all_nodes, leaf_nodes;

    all_nodes.insert(0);
 
    storeNodes(root, all_nodes, leaf_nodes);
 
    for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
    {
        int x = (*i);
 
        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
 
    return false ;
}
