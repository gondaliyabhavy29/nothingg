class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;
        vector<int>ans;
        for(auto c:nums1)mp1[c]++;
        
        for(auto c:nums2)mp2[c]++;
        for(auto x:mp1){
            int mn=min(mp1[x.first],mp2[x.first]);
            for(int i=0;i<mn;i++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};