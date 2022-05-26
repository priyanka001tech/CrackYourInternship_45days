class Solution {
public:
    void flood_fill(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& x){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        x.push_back({i, j});
        flood_fill(grid, i+1, j, x);
        flood_fill(grid, i, j+1, x);
        flood_fill(grid, i-1, j, x);
        flood_fill(grid, i, j-1, x);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> x;
        vector<pair<int, int>> y;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++;
                    if(count==1){
                        flood_fill(grid, i, j, x);
                    }
                    else if(count==2){
                        //cout << i << " " << j << endl;
                        flood_fill(grid, i, j, y);
                    }
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<x.size();i++){
            int dist=0;
            for(int j=0;j<y.size();j++){
                dist=abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                mini=min(mini, dist);
            }
            
        }
        return mini;
    }
};
