class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n=arr.size();
        int res=n+1,sum=0,i=0;
        vector<int>dp(n+1,n);
        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(sum>tar){
                sum-=arr[i++];
            }
            dp[j+1]=dp[j];
            if(sum==tar){
                res=min(res,j-i+1+dp[i]);
                dp[j+1]=min(dp[j],j-i+1);
            }
        }
        return res==n+1?-1:res;
    }
};