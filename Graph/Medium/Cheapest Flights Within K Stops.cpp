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
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        for(int i=0; i<=k; i++) {
            vector<int> temp(n);
            copy(dist.begin(), dist.end(), temp.begin());
            for(auto e : edges) {
                if(dist[e[0]]==INT_MAX)
                    continue;
                if(temp[e[1]]>dist[e[0]]+e[2])
                    temp[e[1]]=dist[e[0]]+e[2];
            }
            copy(temp.begin(), temp.end(), dist.begin());
        }
        if(dist[dst]==INT_MAX)
            return -1;
        return dist[dst];
    }
};
