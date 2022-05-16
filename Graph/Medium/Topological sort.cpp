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
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i, vis, adj);
	        }
	    }
	    reverse(topo.begin(), topo.end());
	    return topo;
	}
};
