class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
       int f=0;    
       sort(a, a+n);
       sort(b, b+n);
       reverse(b, b+n);
       for(int i=0;i<n;i++){
           if(a[i]+b[i]>=k) continue;
           else{
               f=1;
               break;
           }
       }
       if(f) return false;
       return true;
    }
};
