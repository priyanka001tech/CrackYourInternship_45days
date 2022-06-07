class Solution {
public:
    void merge(vector<int>& count, vector<pair<int, int>>& v, int low, int mid, int high){
        int i=low, j=mid+1, k=0;
        vector<pair<int, int>> c(high-low+1);
        while(i<=mid && j<=high){
            if(v[i].first <= v[j].first){
                c[k]=v[j];
                j++;
                k++;
            }
            else{
                count[v[i].second]+=high-j+1;
                c[k]=v[i];
                i++;
                k++;
            }
        }
        while(i<=mid){
            c[k]=v[i];
            k++;
            i++;
        }
        while(j<=high){
            c[k]=v[j];
            k++;
            j++;
        }
        int p=0;
        for (int i = low; i <= high; i++)
            v[i] = c[i-low];
    }
    void mergeSort(vector<int>& count, vector<pair<int, int>>& v, int low, int high){
        if (low >= high) return;
        int mid=low+(high-low)/2;
        mergeSort(count, v, low, mid);
        mergeSort(count, v, mid+1, high);
        merge(count, v, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        vector<int> count(nums.size(), 0);
        mergeSort(count, v, 0, nums.size()-1);
        return count;
    }
};
