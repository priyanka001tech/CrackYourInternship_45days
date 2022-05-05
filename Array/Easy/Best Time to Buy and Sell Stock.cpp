class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int maxpro=0;
        for(int i=0;i<prices.size();i++){
            mn=min(mn,prices[i]);
            maxpro=max(maxpro,prices[i]-mn);
        }
        return maxpro;
    }
};
