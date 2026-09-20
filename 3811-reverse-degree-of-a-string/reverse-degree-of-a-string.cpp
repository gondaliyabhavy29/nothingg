class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int cur=26-(c-'a');
            cur*=(i+1);
            ans+=cur;
        }
        return ans;
    }
};