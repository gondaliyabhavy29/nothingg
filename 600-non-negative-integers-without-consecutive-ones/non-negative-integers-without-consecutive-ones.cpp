class Solution {
public:
using ll=long long;
ll dp[35][2][2];
string s;
int solve(int pos,int pre,int ti){
    if(pos==s.size())return 1;
    if(dp[pos][pre][ti]!=-1)return dp[pos][pre][ti];
    int li=s[pos]-'0';
    int lim=ti?li:1;
    ll ans=0;
    for(int di=0;di<=lim;di++){
        ll nti=ti&&(di==li);
        if(di==pre&&di==1)continue;
        ans+=solve(pos+1,di,nti);
    }
    return dp[pos][pre][ti]=ans;
}
    int findIntegers(int n) {
        s="";
        while(n>0){
            s+=('0'+(n&1));
            n>>=1;
        }
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1);
    }
};