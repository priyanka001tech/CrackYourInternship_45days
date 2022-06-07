class Solution {
public:
    bool isFindLargest(vector<int>& nums, int m, int mid){
        int c=1, s=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(mid<nums[i]) return false;
            else if(s+nums[i]>mid){
                c++;
                s=nums[i];
            }
            else{
                s+=nums[i];
            }
        }
        if(c>m) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0, h=0, ans=0;
        for(int i=0;i<nums.size();i++){
            h+=nums[i];
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(isFindLargest(nums, m, mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
