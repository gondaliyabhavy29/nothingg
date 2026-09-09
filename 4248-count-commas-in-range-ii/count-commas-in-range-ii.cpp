class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long temp=n;
        long long len=1000;
      
        while(temp>=len){
            ans+=(temp-len+1);
            len*=1000;
        }
        return ans;
    }
};