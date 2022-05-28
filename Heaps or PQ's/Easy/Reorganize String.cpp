class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mpp;
        for(auto i:s) mpp[i]++;
        priority_queue<pair<int, char>> pq;
        for(auto i:mpp){
            pq.push(make_pair(i.second, i.first));
        }
        pair<int, char> g={-1,'#'};
        string ans="";
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans+=temp.second;
            temp.first--;
            if(g.first>0){
                pq.push(g);
            }
            g=temp;
        }
        if(ans.size()==s.size()) return ans;
        return "";
    }
    
};
