class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> mpp;
        int n=points.size();
        int c=0;
        for(int i=0;i<n;i++){
            mpp.clear();
            double x1=points[i][0], y1=points[i][1];
            for(int j=i+1;j<n;j++){
                double x2=points[j][0], y2=points[j][1];
                double m1=y2-y1, m2=x2-x1;
                if(m2==0){
                    mpp[1e9]++;
                }
                else{
                    double a=m1/m2;
                    mpp[a]++;
                }
            }
            for(auto i:mpp){
                //cout << i.first << "-->" << i.second << endl;
                c=max(c,i.second);
                
            }   
        }
        return c+1;
    }
};
