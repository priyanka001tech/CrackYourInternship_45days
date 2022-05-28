// O(n * m * logn)
// O(n)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(int i=0;i<flights.size();i++){
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});
        while(!pq.empty()){
            auto [cost, u, w]=pq.top();
            pq.pop();
            if(u==dst) return cost;
            if(w>k) continue;
            for(auto i:g[u]){
                auto [x,y] = i;
                pq.push({cost+y, x, w+1});    
            }
        }
        return -1;
    }
};


// BELLMON FORD 
// O(n*m)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};
