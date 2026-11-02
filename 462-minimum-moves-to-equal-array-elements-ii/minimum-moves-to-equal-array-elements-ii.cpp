class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
        int med = nums[n/2], moves = 0;
        for (int x : nums) moves += abs(x - med);
        return moves;
    }
};