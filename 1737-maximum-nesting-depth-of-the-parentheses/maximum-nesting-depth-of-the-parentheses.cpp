class Solution {
public:
    int maxDepth(string s) {
        int cur=0,ma=0;
        for(auto c:s){
            if(c=='(')cur++;
            else if(c==')')cur--;
            ma=max(ma,cur);
        }
        return ma;
    }
};