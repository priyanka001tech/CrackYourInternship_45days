class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        int n=h.size();
        int maxArea=0;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[st.top()]>=h[i])){
                int hei=h[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                maxArea=max(maxArea,hei*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
