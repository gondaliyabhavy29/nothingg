class Solution {
public:
    int numSquares(int n) {
        int cnt=0;
        if(n<=0)return 0;
        vector<int>cp(n+1,INT_MAX);
        cp[0]=0;
      for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            cp[i]=min(cp[i],cp[i-j*j]+1);
        }
      }
      return cp[n];
    }
};