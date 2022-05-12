struct edge{
	int a, b, cost;
};
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
		vector<edge>Edges;
		for(auto i: edges){
			edge p;
			p.a = i[0];
			p.b = i[1];
			p.cost = i[2];
			Edges.push_back(p);
		}
		int INF = INT_MAX;
	    vector<int> d(n);
	    vector<int> p(n, -1);
	    int x;
	    for (int i = 0; i < n; ++i) {
	        x = -1;
	        for (edge e : Edges) {
	            if (d[e.a] + e.cost < d[e.b]) {
	                d[e.b] = d[e.a] + e.cost;
	                p[e.b] = e.a;
	                x = e.b;
	            }
	        }
	    }	    
	    if(x == -1)return 0;
	    return 1;
	}
