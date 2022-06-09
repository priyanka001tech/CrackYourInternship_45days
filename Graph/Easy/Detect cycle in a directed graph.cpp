class Solution {
  public:
    // Function to detect cycle in a directed graph.
  
    bool cycleUtil(int src, vector<int> adj[], vector<int>& vis, vector<int>& st){
        st[src]=1;
        if(!vis[src]){
            vis[src]=1;
            for(auto i:adj[src]){
                if(st[i]) return true;
                if(!vis[i] && cycleUtil(i, adj, vis, st)){
                    return true;
                } 
            }
        }
        st[src]=0;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> st(V, 0);
        bool c=false;
        for(int i=0;i<V;i++){
            if(!vis[i] && cycleUtil(i, adj, vis, st)){
                c=true;
            }
        }
        if(c) return true;
        else return false;
    }
};
