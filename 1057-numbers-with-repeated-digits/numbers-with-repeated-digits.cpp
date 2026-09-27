class Solution {
public:
using ll=long long;
ll dp[12][2][2][1<<10];
string s;
ll sol(ll pos,ll ti,ll st,ll mask){
    if(pos==s.size()){
        return st?1:0;
    }
    if(dp[pos][ti][st][mask]!=-1)return dp[pos][ti][st][mask];

    ll li=s[pos]-'0';
    ll lim=ti?li:9;
    ll ans=0;
    for(int di=0;di<=lim;di++){
        ll nti=ti&&(di==li);
        if(!st&&di==0){
            ans+=sol(pos+1,nti,0,mask);
        }
        else{
            if(mask&(1<<di))continue;
            ll nmask=mask|(1<<di);
            ans+=sol(pos+1,nti,1,nmask);
        }
    }
    return dp[pos][ti][st][mask]=ans;
}
    int numDupDigitsAtMostN(int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        ll dis=sol(0,1,0,0);
        return n-dis;
    }
};