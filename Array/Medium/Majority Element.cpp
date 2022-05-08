class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int c=0;
        for(auto i:mpp){
            int x=n/2;
            if(i.second>x){
                c=i.first;
            }
        }
        return c;
    }
};
