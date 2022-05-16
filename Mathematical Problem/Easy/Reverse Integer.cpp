class Solution {
public:
    int reverse(int x) {
        int r;
        long long sum=0;
        int p=abs(x);
        while(p>0){
            r=p%10;
            sum=sum*10+r;
            p=p/10;
        }
        if(sum<INT_MIN or sum>INT_MAX) return 0;
        else if(x>0){
            return sum;
        }
        else{
            return -sum;
        }
        
    }
};
