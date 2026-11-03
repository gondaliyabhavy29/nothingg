class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ma=0;
        for(int i=0;i<n;i++)ma=max(ma,nums[i]);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ma-nums[i];
        }
        return ans;
    }
};