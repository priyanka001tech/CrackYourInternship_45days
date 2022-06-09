class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleUtil(int i, vector<int> adj[], vector<int>& vis, int par){
        vis[i]=1;
        for(auto x:adj[i]){
            if(x!=par){
                if(vis[x]) return true;
                if(!vis[x] && cycleUtil(x, adj, vis, i)){
                    return true;
                }
            } 
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        bool c=false;
        for(int i=0;i<V;i++){
            if(!vis[i] && cycleUtil(i, adj, vis, -1)){
                c = true;
            }
        }
        if(c) return true;
        return false;
    }
};
