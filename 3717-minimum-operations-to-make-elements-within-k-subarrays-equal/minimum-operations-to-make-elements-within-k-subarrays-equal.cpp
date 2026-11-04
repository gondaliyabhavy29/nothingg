class Solution {
public:
    multiset<int> a,b;
    long long sa=0,sb=0;
    void fix(){
        while(a.size()>b.size()+1){
            int v=*a.rbegin();
            a.erase(prev(a.end()));
            sa-=v;
            b.insert(v);
            sb+=v;
        }
        while(b.size()>a.size()){
            int v=*b.begin();
            b.erase(b.begin());
            sb-=v;
            a.insert(v);
            sa+=v;
        }
    }
    void add(int v){
        if(a.empty() || v<=*a.rbegin()){
            a.insert(v);
            sa+=v;
        }
        else{
            b.insert(v);
            sb+=v;
        }
        fix();
    }
    void del(int v){
        auto it=a.find(v);
        if(it!=a.end()){
            a.erase(it);
            sa-=v;
        }
        else{
            b.erase(b.find(v));
            sb-=v;
        }
        fix();
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        vector<long long> y(n-x+1);
        for(int i=0;i<n;i++){
            add(nums[i]);
            if(i>=x) del(nums[i-x]);
            if(i>=x-1){
                long long m=*a.rbegin();
                y[i-x+1]=m*(long long)a.size()-sa+sb-m*(long long)b.size();
            }
        }
        vector<vector<long long>> dp(k+1,vector<long long>(n+1,LLONG_MAX));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                dp[j][i]=dp[j][i-1];
                if(i>=x && dp[j-1][i-x]!=LLONG_MAX) dp[j][i]=min(dp[j][i],dp[j-1][i-x]+y[i-x]);
            }
        }
        return dp[k][n];
    }
};