class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int res=0, n=card.size(), s=0;
        for(int i=n-k; i<n;i++) res+=card[i]; // take k right
        int s=res;
        for(int i=0;i<k;i++) {
            s-=card[n-k+i];
            s+=card[i];
            res=max(res,s);
        }
        return res;
    }
};
