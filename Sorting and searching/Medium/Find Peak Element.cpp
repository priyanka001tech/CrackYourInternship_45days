class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        
        while(l<h){
            int mid=(l+h)>>1;
            int mid2=mid+1;
            
            if(nums[mid]<nums[mid2]){
                l=mid2;
            }
            else{
                h=mid;
            }
            
        }
        return l;
    }
};
