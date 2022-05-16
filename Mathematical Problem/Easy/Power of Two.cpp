class Solution {
private:
    int setBit(int n){
        int c=0;
        while(n!=0){
            n=n&(n-1);
            c++;
        }
        return c;
    }
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int c=setBit(n);
        if(c==1) return true;
        else return false;
    }
};
