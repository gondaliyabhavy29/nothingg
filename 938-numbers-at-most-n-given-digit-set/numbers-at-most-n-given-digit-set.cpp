class Solution {
public:
using ll=long long;
string s;
ll dp[12][2];
ll sol(ll pos,ll ti,vector<int>& d){
    if(pos==s.size())return 1;
    if(dp[pos][ti]!=-1)return dp[pos][ti];
    ll li=s[pos]-'0';
    ll lim=ti?li:9;
    ll ans=0;
    for(auto di:d){

    if(di>lim)break;
       ll nti=ti&&(di==li);
      ans+=sol(pos+1,nti,d);
    }
    return dp[pos][ti]=ans;
}
    int atMostNGivenDigitSet(vector<string>& dig, int n) {
        s=to_string(n);
        vector<int>d;
        for(auto c:dig){
            d.push_back(c[0]-'0');
        }
        memset(dp,-1,sizeof(dp));
        ll ans= sol(0,1,d);
        int m=s.size();
        for(int len=1;len<m;len++){
            ans+=pow(d.size(),len);
        }
        
        return ans;
    }
};