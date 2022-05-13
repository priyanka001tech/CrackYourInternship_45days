class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxh;
        for(auto& x:points){
            int p=x[0];
            int q=x[1];
            int dist=p*p+q*q;
            maxh.push({dist,p,q});
            
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;
        while(maxh.size()>0){
            auto w=maxh.top();
            ans.push_back({w[1],w[2]});
            maxh.pop();
        }
        return ans;
    }
};
