class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int row_start=0,row_end=n-1,col_start=0,col_end=m-1;
        while(row_start<=row_end && col_start<=col_end){
            for(int i=col_start;i<=col_end;i++){
                ans.push_back(matrix[row_start][i]);
            }
            row_start++;
            
            for(int k=row_start;k<=row_end;k++){
                ans.push_back(matrix[k][col_end]);
            }
            col_end--; 
            
            if(row_start<=row_end){
                for(int j=col_end;j>=col_start;j--){
                    ans.push_back(matrix[row_end][j]);
                }
                row_end--;
            }
            
            if(col_start<=col_end){
                for(int m=row_end;m>=row_start;m--){
                    ans.push_back(matrix[m][col_start]);
                }
                col_start++;
            }            
        }
        return ans;
    }
};
