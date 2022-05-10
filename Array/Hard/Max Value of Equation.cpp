class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int maxi=INT_MIN;
        for(int i=0;i<points.size();i++){
            while(!pq.empty() && (points[i][0]-pq.top().second>k)) pq.pop();
            if(!pq.empty()){
                maxi=max(maxi, points[i][1]+points[i][0]+pq.top().first);
            }
            pq.push({points[i][1]-points[i][0], points[i][0]});
        }
        return maxi;
    }
};
