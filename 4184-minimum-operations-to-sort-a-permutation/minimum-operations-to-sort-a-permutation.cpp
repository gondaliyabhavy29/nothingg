class Solution {
public:
    int minOperations(vector<int>& nums) {
       vector<int>a=nums;
        sort(a.begin(),a.end());
        if(a==nums)return 0;
        int n=nums.size();
        int bre=0,idx=-1;
        for(int i=0;i<n;i++){
           if(nums[i]>nums[(i+1)%n]){
               bre++;
               idx=i;
           }
        }
        int rbre=0,ridx=-1;
        for(int i=0;i<n;i++){
           if(nums[i]<nums[(i+1)%n]){
               rbre++;
               ridx=i;
           }
        }
        int ans=-1;
        if(bre==0)return 0;
        else if(bre==1){
            ans=idx+1;
            int rshi=n-ans;
            ans=min(ans,rshi+2);
        }
        if(rbre==1||rbre==0){
            if(rbre==0){
                ans=1;
            }
            else{
                int c1=((ridx+1)%n)+1;
                int c2=1+(n-1-ridx);
                int cost=min(c1,c2);
                if(ans==-1||cost<ans){
                    ans=cost;
                }
            }
        }
        return ans;
    }
};