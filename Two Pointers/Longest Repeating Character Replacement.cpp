// MS 
// Map, max_cnt, sliding window (medium)
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mpp;
        int i=0, j=0, mx=0, ans=0;
        while(j<s.size()){
            mpp[s[j]]++;
            mx=max(mx, mpp[s[j]]);
            if((j-i+1)-mx>k){
                mpp[s[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
