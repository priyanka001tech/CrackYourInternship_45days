class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int src){
        vis[src]=1;
        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int c=0;
        vector<vector<int>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                c++;
            }
        }
        return c-1;
    }
};
