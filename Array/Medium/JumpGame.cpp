// Recursive
class Solution {
public:
    bool canJump(vector<int>& nums) {
     
      return solve(0,nums);
        
    }
    
    bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true;
        
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
            
            if(solve(k,nums)){
                return true;
            }
            
        }
        
        return false;
    }
};

//Memoization
class Solution {
    vector<int> memo;
public:
    bool canJump(vector<int>& nums) {
      memo.assign(nums.size(),-1);
      return solve(0,nums);
        
    }
    
    bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true;
        if(memo[i]!=-1) return memo[i];
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
            
            if(solve(k,nums)){
                return memo[i]=true;
            }
            
        }
        
        return memo[i]=false;
    }
};

// Optimal
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1,i,j;
        for(i=n-2;i>=0;i--){
            if(i+nums[i]>=last)last=i;
        }
        return last<=0;
    }
};
