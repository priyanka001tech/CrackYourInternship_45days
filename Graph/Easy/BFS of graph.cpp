class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> vis(V+1,0);
        vector<int> ans;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto i:adj[x]){
                if(vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;
    }
};
