class Solution {
public:
    bool static myComp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> temp(mpp.begin(),mpp.end());
        sort(temp.begin(),temp.end(),myComp);
        
        for(auto i:temp){
            if(k-->0){
                res.push_back(i.first);
            }
        }
        return res;
    }
};
