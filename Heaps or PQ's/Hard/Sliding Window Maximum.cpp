class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        list<int> l;
        int i=0,j=0;
        int n=arr.size();
        while(j<n){
            while(l.size()>0 && l.back()<arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(l.front());
                if(l.front()==arr[i]){
                    l.pop_front();
                    
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
