class Solution{
    public:
    void rat_in_maze(vector<vector<int>> &m, int x, int y, int n, vector<string>& ans, 
                        string s, vector<vector<int>>& v){
        if(x<0 || y<0 || x>=n || y>=n) return;
        if(v[x][y]==1 or m[x][y]==0) return;
        
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        }
            v[x][y]=1;
            rat_in_maze(m, x+1, y, n, ans, s+"D", v);
            rat_in_maze(m, x, y+1, n, ans, s+"R", v);
            rat_in_maze(m, x, y-1, n, ans, s+"L", v);
            rat_in_maze(m, x-1, y, n, ans, s+"U", v);
            v[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> v(n, vector<int>(n,0));
        string s="";
        rat_in_maze(m,0,0, n, ans, s, v);
        return ans;
    }
};
