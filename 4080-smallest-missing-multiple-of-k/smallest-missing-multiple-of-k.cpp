class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int m=k;
        int n=nums.size();
        map<int,int>mp;
        for(auto c:nums)mp[c]++;
        while(true){
           
            if(mp[m]==0)break;
            m+=k;
        }
        return m;
    }
};