class Solution {
public:
    void adjnum(vector<vector<char>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<=n-1 && j<=m-1 && grid[i][j]=='1'){
            grid[i][j]='0';
            adjnum(grid,i+1,j);
            adjnum(grid,i-1,j);
            adjnum(grid,i,j+1);
            adjnum(grid,i,j-1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    adjnum(grid,i,j);
                }
            }
        }
        return count;
    }
};
