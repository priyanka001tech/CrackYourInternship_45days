class Solution {
public:
    void fillAlgo(vector<vector<int>>& image, int sr, int sc, int newColor,int &color){
        int n=image.size();
        int m=image[0].size();
        if(sr<0 || sc<0 || sr>=n || sc>=m || image[sr][sc]!=color) return;
        
        image[sr][sc]=newColor;
        
        fillAlgo(image, sr+1, sc, newColor, color);
        fillAlgo(image, sr, sc+1, newColor, color);
        fillAlgo(image, sr-1, sc, newColor, color);
        fillAlgo(image, sr, sc-1, newColor, color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int color=image[sr][sc];
         if (image[sr][sc] != newColor){
             fillAlgo(image,sr,sc,newColor,color);
         }
         return image;
    }
};
