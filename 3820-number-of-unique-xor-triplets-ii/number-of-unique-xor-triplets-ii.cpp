class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>l1,l2;
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            if(l1.count(nums[i]))continue;
            l1.insert(nums[i]);
            for(int j=i;j<n;j++){
                int val=nums[i]^nums[j];
                if(l2.count(val))continue;
                l2.insert(val);
                for(int k=j;k<n;k++){
                    st.insert(nums[i]^nums[j]^nums[k]);
                }
            }
        }
        return st.size();
    }
};