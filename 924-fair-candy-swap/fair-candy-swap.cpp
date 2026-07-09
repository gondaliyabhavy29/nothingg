class Solution {
public:
    vector<int> fairCandySwap(vector<int>& al, vector<int>& bo) {
        int sa=0,sb=0;
        for(int a:al)sa+=a;
        for(int b:bo)sb+=b;
        int diff=(sb-sa)/2;
        unordered_set<int>setb(bo.begin(),bo.end());
        for(int a:al){
            if(setb.count(a+diff)){
                return {a,a+diff};
            }
        }
        return {};
    }
};