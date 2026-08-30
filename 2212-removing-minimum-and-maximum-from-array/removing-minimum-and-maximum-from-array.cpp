class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int id1=-1,id2=-1,ma=-1e6,mi=1e6;
        for(int i=0;i<n;i++){
            if(nums[i]>ma){
                id1=i;
                ma=nums[i];
            }
            if(nums[i]<mi){
                mi=nums[i];
                id2=i;
            }
        }
        int m1=max(id1,id2);
        int m2=min(id1,id2);
        int ans=m1+1;
        ans=min(ans,n-m2);
        ans=min(m2+1+n-m1,ans);
        return ans;
    }
};