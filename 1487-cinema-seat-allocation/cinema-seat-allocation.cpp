class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        map<int,vector<int>>mp;
        for(auto c:r){
            mp[c[0]].push_back(c[1]);
        }
        int ans=0,cnt=0;
        for(auto c:mp){
            int i=c.first;
            vector<int>v=c.second;
            int pre=0;
            bool is25=false,is47=false,is69=false;
            for(auto c:v){
              if(c>=2&&c<=5)is25=true;
              if(c>=4&&c<=7)is47=true;
              if(c>=6&&c<=9)is69=true;

            }
            if(!is25&&!is69){
                ans+=2;

            }
            else if(!is25||!is69||!is47)ans++;
            cnt++;
        }
        ans+=2*(n-cnt);
        return ans;
    }
};