class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for(int x:nums)sq.push_back(1LL*x*x);
        int h = sq.size()/2;
        nth_element(sq.begin(),sq.begin()+h,sq.end()); 
        long long to = accumulate(sq.begin(),sq.end(),0LL);
        long long sm = accumulate(sq.begin(),sq.begin()+h,0LL);
        return to-2*sm; 
    }
};