class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mul=nums[n-1]*nums[n-2]*nums[n-3];
        int nul=nums[0]*nums[1]*nums[n-1];
        if(mul>nul) return mul;
        else return nul;
        
    }
};
