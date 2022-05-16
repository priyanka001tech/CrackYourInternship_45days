class Solution {
public:
    string convertToTitle(int colNo) {
        string ans="";
        while(colNo!=0){
            colNo-=1;
            int rem=colNo%26;
            ans+= char(65+rem);
            colNo/=26;
            //cout << ans << div-1 << endl;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
