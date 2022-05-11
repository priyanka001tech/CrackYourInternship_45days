class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int i, vector<int>&vis, vector<int> adj[], vector<int>& ans){
        vis[i]=1;
        ans.push_back(i);
        for(auto j: adj[i]){
            if(!vis[j]){
                dfs(j, vis, adj, ans);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V+1, 0);
        dfs(0, vis, adj, ans);
        return ans;
    }
};
