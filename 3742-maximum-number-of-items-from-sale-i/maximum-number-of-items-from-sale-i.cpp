class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& ite, int budget) {
        int n=ite.size();
        vector<int>free(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&ite[j][0]%ite[i][0]==0){
                    free[i]++;
                }
            }
        }
        vector<int>dp(budget+1,0);
        for(int i=0;i<n;i++){
            int fac=ite[i][0];
            int pri=ite[i][1];
            int fgain=1+free[i];

            vector<int>ndp=dp;
            for(int w=budget;w>=pri;w--){
                if(dp[w-pri]>0||w-pri==0){
                    ndp[w]=max(ndp[w],ndp[w-pri]+fgain);
                }
            }
            for(int w=pri;w<=budget;w++){
                if(ndp[w-pri]>0){
                    ndp[w]=max(ndp[w],ndp[w-pri]+1);
                }
            }
            swap(ndp,dp);
        }
        int ma=0;
        for(int i=0;i<=budget;i++){
            ma=max(ma,dp[i]);
        }
        return ma;
    }
};