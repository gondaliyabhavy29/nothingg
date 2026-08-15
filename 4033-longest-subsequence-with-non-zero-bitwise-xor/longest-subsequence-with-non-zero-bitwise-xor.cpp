class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int to=0,fz=0;
        for(int c:nums){
            to^=c;
            if(c==0)fz++;
        }
       
        
        
        if(to==0){
            int n=nums.size();
         if(fz==n)return 0;
         else return n-1;
        }
        else return nums.size();
    }
};