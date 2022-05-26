class Solution{
  public:
  int maxHist(int row[],int R,int C)
    {
        stack<int> result;
     
        int top_val;
        int max_area = 0; 
        int area = 0; 
        int i = 0;
        while (i < C) {
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);
     
            else {
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;
     
                if (!result.empty())
                    area = top_val * (i - result.top() - 1);
                max_area = max(area, max_area);
            }
        }
     
        while (!result.empty()) {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
     
            max_area = max(area, max_area);
        }
        return max_area;
    }
    
    int maxArea(int A[MAX][MAX], int R, int C) {
        int result = maxHist(A[0],R,C);
        for (int i = 1; i < R; i++) {
            for (int j = 0; j < C; j++)
                if (A[i][j])
                    A[i][j] += A[i - 1][j];
                    
            result = max(result, maxHist(A[i],R,C));
        }
     
        return result;
    }
};
