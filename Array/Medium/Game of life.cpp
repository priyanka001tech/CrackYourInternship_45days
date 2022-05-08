class Solution {
public:
    bool isSafe(int x, int y, int n, int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dx[]={0,1,0,-1,1,1,-1,-1};
        int dy[]={1,0,-1,0,1,-1,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                for(int k=0;k<8;k++){
                    int newx=i+dx[k];
                    int newy=j+dy[k];
                    if(isSafe(newx, newy, n, m) && abs(board[newx][newy])==1){
                        c++;
                    }
                }
                if(board[i][j]==0 && c==3) board[i][j]=2;
                if(board[i][j]==1 && (c<2 || c>3)) board[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=board[i][j]>0 ? 1 : 0;
            }
        }
    }
};
