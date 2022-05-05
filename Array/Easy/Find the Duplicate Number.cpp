class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int ans;
        for(int i=0;i<arr.size();i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
            else{
                ans = abs(arr[i]);
            }
        }
        return ans;
    }
};
