class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        bool f=0;
        vector<int> v;
        if(p1==p2 && p2==p3 && p3==p4) return false;
        int p, q, r, s, t, u;
        p=(p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        q=(p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        r=(p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]);
        s=(p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]);
        t=(p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]);
        u=(p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]);
        v.push_back(p);v.push_back(q);v.push_back(r);v.push_back(s);
        v.push_back(t);v.push_back(u);
        
        sort(v.begin(), v.end());
        for(auto i:v) cout << i << endl;
        if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3] && v[3]==v[0] && 
          v[0]+v[1]==v[5]){
            f=1;
        }
        return f;
    }
};


// Another Sol

class Solution {
public:
    // helper function to calculate distance between two points
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // keep points in an array to be able to get them by index
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> lengths;
        
        for (int i=0; i<4; i++) {
            for (int j=i+1; j<4; j++) {
                double curr = dist(points[i], points[j]);
                if (curr != 0)
                    lengths.insert(curr);
                
                // if distance is zero - we got a duplicated point
                else
                    return false;
            }
        }
        // We are supposed to end with only two different lengths: the sides and the diagonals
        return lengths.size() == 2;
    }
};
