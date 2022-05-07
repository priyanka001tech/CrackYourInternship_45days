class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp={{0,1}};
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if (mpp.end() != mpp.find(sum - k))
            res += mpp[sum - k];
            mpp[sum]++;
        }
        return res;
    }
};
