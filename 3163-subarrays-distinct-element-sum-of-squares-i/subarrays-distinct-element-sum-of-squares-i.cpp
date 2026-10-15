class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        set<int>st;
   for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
         st.insert(nums[j]);
         ans+=(st.size()*st.size());
    }
    st.clear();
   }
        return ans;
    }
};