class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int op=0,cl=0;

        for(char ch:s){
            if(ch=='(')++op;
            else ++cl;

            if(op==cl){
                ans = max(ans,2*cl);
            } else if(cl>op){
                op=cl=0;
            }
        }

        op = cl = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') ++op;
            else ++cl;

            if (op == cl) {
                ans = max(ans, 2 * op);
            } else if (op > cl) {
                op = cl = 0;
            }
        }

        return ans;
    }
};