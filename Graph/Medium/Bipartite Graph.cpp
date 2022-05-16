class Solution {
private:
    bool bipartite;
    
    void color(int u, int c, vector<int>& vis, vector<int>& col, vector<int>adj[]){
            if(col[u]!=-1 && col[u]!=c){
                bipartite=false;
                return;
            }   
            col[u]=c;
            if(vis[u]) return;
            vis[u]=1;
            for(auto i:adj[u]){
                color(i, c xor 1, vis, col, adj);
            }
    }
    
public:
    
	bool isBipartite(int V, vector<int>adj[]){
	    bipartite = true;
	    vector<int> vis(V, 0);
	    vector<int> col(V, -1);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            color(i, 0, vis, col, adj);
	        }
	    }
	    return bipartite;
	}

};
