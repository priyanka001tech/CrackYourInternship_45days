class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        for(i=0;i<h.size()-1;i++){
            int x=h[i+1]-h[i];
            if(x>0){
                pq.push(x);
            }
            if(pq.size()>l){
                b-=pq.top();
                pq.pop();
            }
            if(b<0){
                return i;
            }
        }
        return i;
    }
};
