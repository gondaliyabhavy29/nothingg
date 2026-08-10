class Solution {
public:
    int coinChange(vector<int>& c, int x) {
        if(x<0)return -1;
        if(x==0)return 0;
        sort(c.begin(),c.end());
        int n=c.size();
        vector<int>dp(x+1,x);
        dp[0]=0;
        for(int i=1;i<=x;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<n;j++){
                if(i-c[j]<0)break;
                
                   if(dp[i-c[j]]!=INT_MAX) dp[i]=min(dp[i],1+dp[i-c[j]]);
                
            }
        }
        return dp[x]>x?-1:dp[x];
    }
};