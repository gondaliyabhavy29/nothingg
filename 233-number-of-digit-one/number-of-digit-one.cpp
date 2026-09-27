class Solution {
public:
using ll=long long;
string s;
pair<ll,ll> dp[12][2];
bool vis[12][2];
pair<ll,ll> sol(ll pos,ll ti){
    if(pos==s.size())return {1,0};
    if(vis[pos][ti])return dp[pos][ti];
    vis[pos][ti]=true;
    ll li=s[pos]-'0';
    ll lim=ti?li:9;
    ll cnt=0,sum=0;
    for(int di=0;di<=lim;di++){
        ll nti=ti&&(di==li);
        auto[cc,cs]=sol(pos+1,nti);
        cnt+=cc;
        sum+=cs;
        if(di==1){
            sum+=cc;
        }
    }
return dp[pos][ti]={cnt,sum};
}
    int countDigitOne(int n) {
        if(n<=0)return 0;
        s=to_string(n);
        memset(vis,false,sizeof(vis));
        return (int)sol(0,1).second;
    }
};