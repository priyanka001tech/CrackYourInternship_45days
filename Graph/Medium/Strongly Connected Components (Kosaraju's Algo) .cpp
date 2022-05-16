class Solution
{
    private:
    vector<int> topo;
    void dfs(int src, vector<int>& vis, vector<int> adj[]){
        vis[src]=1;
        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
        topo.push_back(src);
    }
    void rdfs(int src, vector<int>& vis, vector<int> rev[]){
        vis[src]=1;
        for(auto i:rev[src]){
            if(!vis[i]){
                rdfs(i, vis, rev);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> rev[V];
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                rev[j].push_back(i);
            }
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
        
        vector<int> vis2(V, 0);
        for(int i=V-1;i>=0;i--){
            if(!vis2[topo[i]]){
                rdfs(topo[i], vis2, rev);
                c++;
            }
        }
        return c;
    }
};
