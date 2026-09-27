class Solution {
public:
using ll=long long;
string s;
ll MOD=1e9+7;
ll dp[25][2][402];
ll mn,mx;
ll sol(ll pos,ll ti,ll sum){
    if(pos==s.size()){
        if(sum>=mn&&sum<=mx)return 1;
        return 0;

    }
    if(dp[pos][ti][sum]!=-1)return dp[pos][ti][sum];
    ll li=s[pos]-'0';
    ll lim=ti?li:9;
    ll ans=0;
    for(int di=0;di<=lim;di++){
    ll nti=ti&&(di==li);
    ans+=sol(pos+1,nti,sum+di);
    ans%=MOD;

}
return dp[pos][ti][sum]=ans;
}
ll cnt(string x){
    if(x=="-1"||x=="0")return 0;
    s=x;
    memset(dp,-1,sizeof(dp));
    return sol(0,1,0);
}
    int count(string num1, string num2, int min_sum, int max_sum) {
        mn=min_sum;
        mx=max_sum;
        int k=num1.size()-1;
        while(k>=0&&num1[k]=='0'){
        num1[k]='9';
        k--;
        }
       if(k>=0)num1[k]--;
       int c1=cnt(num2);
       int c2=cnt(num1);
        return (c1-c2+MOD)%MOD;
    }
};