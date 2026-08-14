class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,ma=0;
        map<char,int>mp;
        while(r<s.size()){
           mp[s[r]]++;
           while(mp[s[r]]>2){
            mp[s[l]]--;
            l++;
           }
           ma=max(ma,r-l+1);
           r++;
        }
        return ma;
    }
};