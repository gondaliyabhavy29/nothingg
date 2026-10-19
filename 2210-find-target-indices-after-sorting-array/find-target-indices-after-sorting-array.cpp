class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tar) {
          vector<int>ans;
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++){
            if(nums[i]==tar)ans.push_back(i);
          }
          return ans;
    }
};