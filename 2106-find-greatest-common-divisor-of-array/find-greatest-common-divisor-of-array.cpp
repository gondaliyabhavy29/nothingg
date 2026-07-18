class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto s=minmax_element(nums.begin(),nums.end());
        return gcd(*s.first,*s.second);
    }
};