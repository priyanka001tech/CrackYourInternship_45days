// Recursion

class Solution {
public:
    
    int numTrees(int n) {
        int res=0;
        if(n<=1) return 1;
        for(int i=0;i<n;i++){
            res+=numTrees(i)*numTrees(n-i-1);
        }
        return res;
    }
};

//Recursive

class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        int res=0;
        
        for(int i=1; i<=n; ++i)
            res += solve(i-1, dp)*solve(n-i, dp);
        
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};
